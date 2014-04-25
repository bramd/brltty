/*
 * BRLTTY - A background process providing access to the console screen (when in
 *          text mode) for a blind person using a refreshable braille display.
 *
 * Copyright (C) 1995-2014 by The BRLTTY Developers.
 *
 * BRLTTY comes with ABSOLUTELY NO WARRANTY.
 *
 * This is free software, placed under the terms of the
 * GNU General Public License, as published by the Free Software
 * Foundation; either version 2 of the License, or (at your option) any
 * later version. Please see the file LICENSE-GPL for details.
 *
 * Web Page: http://mielke.cc/brltty/
 *
 * This software is maintained by Dave Mielke <dave@mielke.cc>.
 */

#include "prologue.h"

#include <string.h>
#include <errno.h>

#include "log.h"
#include "parameters.h"
#include "async_alarm.h"

#include "brl_driver.h"
#include "brldefs-mt.h"

BEGIN_KEY_NAME_TABLE(all)
  KEY_NAME_ENTRY(MT_KEY_LeftUp, "LeftUp"),
  KEY_NAME_ENTRY(MT_KEY_LeftSelect, "LeftSelect"),
  KEY_NAME_ENTRY(MT_KEY_LeftDown, "LeftDown"),

  KEY_NAME_ENTRY(MT_KEY_RightUp, "RightUp"),
  KEY_NAME_ENTRY(MT_KEY_RightSelect, "RightSelect"),
  KEY_NAME_ENTRY(MT_KEY_RightDown, "RightDown"),

  KEY_NAME_ENTRY(MT_KEY_CursorLeft, "CursorLeft"),
  KEY_NAME_ENTRY(MT_KEY_CursorUp, "CursorUp"),
  KEY_NAME_ENTRY(MT_KEY_CursorRight, "CursorRight"),
  KEY_NAME_ENTRY(MT_KEY_CursorDown, "CursorDown"),

  KEY_SET_ENTRY(MT_SET_RoutingKeys1, "RoutingKey1"),
  KEY_SET_ENTRY(MT_SET_StatusKeys1, "StatusKey1"),

  KEY_SET_ENTRY(MT_SET_RoutingKeys2, "RoutingKey2"),
  KEY_SET_ENTRY(MT_SET_StatusKeys2, "StatusKey2"),
END_KEY_NAME_TABLE

BEGIN_KEY_NAME_TABLES(all)
  KEY_NAME_TABLE(all),
END_KEY_NAME_TABLES

DEFINE_KEY_TABLE(all)

BEGIN_KEY_TABLE_LIST
  &KEY_TABLE_DEFINITION(all),
END_KEY_TABLE_LIST

#define MT_IDENTITY_PACKET_SIZE 0X100
#define MT_STATUS_PACKET_SIZE 8

#define MT_ROUTING_KEYS_SECONDARY 100
#define MT_ROUTING_KEYS_NONE 0XFF

#define MT_MODULE_SIZE 8
#define MT_MODULES_MAXIMUM 10
#define MT_CELLS_MAXIMUM (MT_MODULES_MAXIMUM * MT_MODULE_SIZE)

typedef struct {
  int (*beginProtocol) (BrailleDisplay *brl);
  void (*endProtocol) (BrailleDisplay *brl);

  int (*logDeviceIdentity) (BrailleDisplay *brl);
  int (*setHighVoltage) (BrailleDisplay *brl, int on);

  int (*handleInput) (BrailleDisplay *brl);
} ProtocolOperations;

struct BrailleDataStruct {
  const ProtocolOperations *protocol;

  unsigned char oldCells[MT_CELLS_MAXIMUM];
  unsigned char newCells[MT_CELLS_MAXIMUM];

  unsigned char cellCount;
  unsigned char textCount;
  unsigned char statusCount;

  int writeModule[MT_MODULES_MAXIMUM];
  unsigned char moduleCount;

  uint32_t navigationKeys;
  unsigned char routingKey;

  union {
    struct {
      AsyncHandle statusAlarm;
    } usb;
  } proto;
};

static void
setCellCount (BrailleDisplay *brl, unsigned char count) {
  brl->data->moduleCount = (brl->data->cellCount = count) / MT_MODULE_SIZE;

  switch (count) {
    case 42:
      brl->data->statusCount = 2;
      break;

    default:
      brl->data->statusCount = 0;
      break;
  }

  brl->data->textCount = brl->data->cellCount - brl->data->statusCount;
  brl->textColumns = brl->data->textCount;
  brl->statusColumns = brl->data->statusCount;
}

static void
handleNavigationKeys (BrailleDisplay *brl, uint32_t keys) {
  if (keys & 0X80) keys &= ~0X8B;
  keys &= ~0X20;
  enqueueUpdatedKeys(brl, keys, &brl->data->navigationKeys, MT_SET_NavigationKeys, 0);
}

static void
handleRoutingKeyEvent (BrailleDisplay *brl, unsigned char key, int press) {
  if (key != MT_ROUTING_KEYS_NONE) {
    MT_KeySet routing;
    MT_KeySet status;

    if (key < brl->data->cellCount) {
      routing = MT_SET_RoutingKeys1;
      status = MT_SET_StatusKeys1;
    } else if ((key >= MT_ROUTING_KEYS_SECONDARY) &&
               (key < (MT_ROUTING_KEYS_SECONDARY + brl->data->cellCount))) {
      key -= MT_ROUTING_KEYS_SECONDARY;
      routing = MT_SET_RoutingKeys2;
      status = MT_SET_StatusKeys2;
    } else {
      logMessage(LOG_WARNING, "unexpected routing key: %u", key);
      return;
    }

    {
      MT_KeySet set;

      if (key < brl->data->statusCount) {
        set = status;
      } else {
        key -= brl->data->statusCount;
        set = routing;
      }

      enqueueKeyEvent(brl, set, key, press);
    }
  }
}

static void
handleRoutingKey (BrailleDisplay *brl, unsigned char key) {
  if (key != brl->data->routingKey) {
    handleRoutingKeyEvent(brl, brl->data->routingKey, 0);
    handleRoutingKeyEvent(brl, key, 1);
    brl->data->routingKey = key;
  }
}

static int setUsbStatusAlarm (BrailleDisplay *brl);
#define MT_USB_REQUEST_RECIPIENT UsbControlRecipient_Device
#define MT_USB_REQUEST_TYPE UsbControlType_Vendor

static ssize_t
tellUsbDevice (
  BrailleDisplay *brl, unsigned char request,
  const void *data, size_t length
) {
  return gioTellResource(brl->gioEndpoint,
                         MT_USB_REQUEST_RECIPIENT, MT_USB_REQUEST_TYPE,
                         request, 0, 0, data, length);
}

static ssize_t
askUsbDevice (
  BrailleDisplay *brl, unsigned char request,
  void *buffer, size_t size
) {
  return gioAskResource(brl->gioEndpoint,
                        MT_USB_REQUEST_RECIPIENT, MT_USB_REQUEST_TYPE,
                        request, 0, 0, buffer, size);
}

static ssize_t
getUsbStatusPacket (BrailleDisplay *brl, unsigned char *packet) {
  return askUsbDevice(brl, 0X80, packet, MT_STATUS_PACKET_SIZE);
}

ASYNC_ALARM_CALLBACK(handleUsbStatusAlarm) {
  BrailleDisplay *brl = parameters->data;
  unsigned char packet[MT_STATUS_PACKET_SIZE];

  asyncDiscardHandle(brl->data->proto.usb.statusAlarm);
  brl->data->proto.usb.statusAlarm = NULL;

  memset(packet, 0, sizeof(packet));

  if (getUsbStatusPacket(brl, packet))  {
    logInputPacket(packet, sizeof(packet));
    handleRoutingKey(brl, packet[0]);
    handleNavigationKeys(brl, (packet[2] | (packet[3] << 8)));
    setUsbStatusAlarm(brl);
  } else {
    enqueueCommand(BRL_CMD_RESTARTBRL);
  }
}

static int
setUsbStatusAlarm (BrailleDisplay *brl) {
  return asyncSetAlarmIn(&brl->data->proto.usb.statusAlarm,
                         BRAILLE_INPUT_POLL_INTERVAL,
                         handleUsbStatusAlarm, brl);
}

static int
beginUsbProtocol (BrailleDisplay *brl) {
  brl->data->proto.usb.statusAlarm = NULL;
  setUsbStatusAlarm(brl);

  return 1;
}

static void
endUsbProtocol (BrailleDisplay *brl) {
  if (brl->data->proto.usb.statusAlarm) {
    asyncCancelRequest(brl->data->proto.usb.statusAlarm);
    brl->data->proto.usb.statusAlarm = NULL;
  }
}

static int
logUsbDeviceIdentity (BrailleDisplay *brl) {
  static const unsigned char data[] = {0};

  return tellUsbDevice(brl, 0X04, data, sizeof(data)) != -1;
}

static int
setUsbHighVoltage (BrailleDisplay *brl, int on) {
  const unsigned char data[] = {on? 0XFF: 0X7F};

  return tellUsbDevice(brl, 0X01, data, sizeof(data)) != -1;
}

static int
handleUsbInput (BrailleDisplay *brl) {
  unsigned char buffer[MT_IDENTITY_PACKET_SIZE];
  ssize_t result = gioReadData(brl->gioEndpoint, buffer, sizeof(buffer), 0);

  if (result != -1) {
    logMessage(LOG_INFO, "Device Identity: %.*s", (int)result, buffer);
  }

  return 1;
}

static const ProtocolOperations usbProtocolOperations = {
  .beginProtocol = beginUsbProtocol,
  .endProtocol = endUsbProtocol,

  .logDeviceIdentity = logUsbDeviceIdentity,
  .setHighVoltage = setUsbHighVoltage,

  .handleInput = handleUsbInput
};

static int
connectResource (BrailleDisplay *brl, const char *identifier) {
  static const UsbChannelDefinition usbChannelDefinitions[] = {
    { /* all models */
      .vendor=0X0452, .product=0X0100,
      .configuration=1, .interface=0, .alternative=0,
      .inputEndpoint=1, .outputEndpoint=0
    },

    { .vendor=0 }
  };

  GioDescriptor descriptor;
  gioInitializeDescriptor(&descriptor);

  descriptor.usb.channelDefinitions = usbChannelDefinitions;
  descriptor.usb.options.applicationData = &usbProtocolOperations;

  if (connectBrailleResource(brl, identifier, &descriptor, NULL)) {
    brl->data->protocol = gioGetApplicationData(brl->gioEndpoint);
    return 1;
  }

  return 0;
}

static void
disconnectResource (BrailleDisplay *brl) {
  disconnectBrailleResource(brl, NULL);
}

static int
brl_construct (BrailleDisplay *brl, char **parameters, const char *device) {
  if ((brl->data = malloc(sizeof(*brl->data)))) {
    memset(brl->data, 0, sizeof(*brl->data));

    if (connectResource(brl, device)) {
      brl->data->protocol->logDeviceIdentity(brl);

      if (brl->data->protocol->setHighVoltage(brl, 1)) {
        unsigned char statusPacket[MT_STATUS_PACKET_SIZE];

        if (getUsbStatusPacket(brl, statusPacket)) {
          setCellCount(brl, statusPacket[1]);

          {
            unsigned int moduleNumber;

            for (moduleNumber=0; moduleNumber<brl->data->moduleCount; moduleNumber+=1) {
              brl->data->writeModule[moduleNumber] = 1;
            }
          }

          {
            static const DotsTable dots = {
              0X80, 0X40, 0X20, 0X10, 0X08, 0X04, 0X02, 0X01
            };

            makeOutputTable(dots);
          }

          {
            const KeyTableDefinition *ktd = &KEY_TABLE_DEFINITION(all);

            brl->keyBindings = ktd->bindings;
            brl->keyNameTables = ktd->names;
          }

          brl->data->navigationKeys = 0;
          brl->data->routingKey = MT_ROUTING_KEYS_NONE;

          if (brl->data->protocol->beginProtocol(brl)) return 1;
        }

        brl->data->protocol->setHighVoltage(brl, 0);
      }

      disconnectResource(brl);
    }

    free(brl->data);
  } else {
    logMallocError();
  }
  
  return 0;
}

static void
brl_destruct (BrailleDisplay *brl) {
  brl->data->protocol->endProtocol(brl);
  brl->data->protocol->setHighVoltage(brl, 0);
  disconnectResource(brl);
  free(brl->data);
}

static int
brl_writeWindow (BrailleDisplay *brl, const wchar_t *text) {
  const unsigned char *source = brl->data->newCells;
  unsigned char *target = brl->data->oldCells;
  unsigned int moduleNumber;

  memcpy(&brl->data->newCells[brl->data->statusCount], brl->buffer, brl->data->textCount);

  for (moduleNumber=0; moduleNumber<brl->data->moduleCount; moduleNumber+=1) {
    if (cellsHaveChanged(target, source, MT_MODULE_SIZE, NULL, NULL, &brl->data->writeModule[moduleNumber])) {
      unsigned char cells[MT_MODULE_SIZE];

      translateOutputCells(cells, source, MT_MODULE_SIZE);
      if (tellUsbDevice(brl, 0X0A+moduleNumber, cells, MT_MODULE_SIZE) == -1) return 0;
    }

    source += MT_MODULE_SIZE;
    target += MT_MODULE_SIZE;
  }

  return 1;
}

static int
brl_readCommand (BrailleDisplay *brl, KeyTableCommandContext context) {
  return brl->data->protocol->handleInput(brl)? EOF: BRL_CMD_RESTARTBRL;
}
