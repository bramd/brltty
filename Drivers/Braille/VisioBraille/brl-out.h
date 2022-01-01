/*
 * BRLTTY - A background process providing access to the console screen (when in
 *          text mode) for a blind person using a refreshable braille display.
 *
 * Copyright (C) 1995-2022 by The BRLTTY Developers.
 *
 * BRLTTY comes with ABSOLUTELY NO WARRANTY.
 *
 * This is free software, placed under the terms of the
 * GNU Lesser General Public License, as published by the Free Software
 * Foundation; either version 2.1 of the License, or (at your option) any
 * later version. Please see the file LICENSE-LGPL for details.
 *
 * Web Page: http://brltty.app/
 *
 * This software is maintained by Dave Mielke <dave@mielke.cc>.
 */

[0] = 0X20,
[BRL_DOT1] = 0X41,
[BRL_DOT1 | BRL_DOT2] = 0X42,
[BRL_DOT1 | BRL_DOT2 | BRL_DOT3] = 0X4C,
[BRL_DOT1 | BRL_DOT2 | BRL_DOT3 | BRL_DOT4] = 0X50,
[BRL_DOT1 | BRL_DOT2 | BRL_DOT3 | BRL_DOT4 | BRL_DOT5] = 0X51,
[BRL_DOT1 | BRL_DOT2 | BRL_DOT3 | BRL_DOT4 | BRL_DOT5 | BRL_DOT6] = 0X2F,
[BRL_DOT1 | BRL_DOT2 | BRL_DOT3 | BRL_DOT4 | BRL_DOT5 | BRL_DOT6 | BRL_DOT7] = 0XEF,
[BRL_DOT1 | BRL_DOT2 | BRL_DOT3 | BRL_DOT4 | BRL_DOT5 | BRL_DOT6 | BRL_DOT7 | BRL_DOT8] = 0X6F,
[BRL_DOT1 | BRL_DOT2 | BRL_DOT3 | BRL_DOT4 | BRL_DOT5 | BRL_DOT6 | BRL_DOT8] = 0XAF,
[BRL_DOT1 | BRL_DOT2 | BRL_DOT3 | BRL_DOT4 | BRL_DOT5 | BRL_DOT7] = 0X11,
[BRL_DOT1 | BRL_DOT2 | BRL_DOT3 | BRL_DOT4 | BRL_DOT5 | BRL_DOT7 | BRL_DOT8] = 0X91,
[BRL_DOT1 | BRL_DOT2 | BRL_DOT3 | BRL_DOT4 | BRL_DOT5 | BRL_DOT8] = 0XD1,
[BRL_DOT1 | BRL_DOT2 | BRL_DOT3 | BRL_DOT4 | BRL_DOT6] = 0X40,
[BRL_DOT1 | BRL_DOT2 | BRL_DOT3 | BRL_DOT4 | BRL_DOT6 | BRL_DOT7] = 0X00,
[BRL_DOT1 | BRL_DOT2 | BRL_DOT3 | BRL_DOT4 | BRL_DOT6 | BRL_DOT7 | BRL_DOT8] = 0X80,
[BRL_DOT1 | BRL_DOT2 | BRL_DOT3 | BRL_DOT4 | BRL_DOT6 | BRL_DOT8] = 0XC0,
[BRL_DOT1 | BRL_DOT2 | BRL_DOT3 | BRL_DOT4 | BRL_DOT7] = 0X10,
[BRL_DOT1 | BRL_DOT2 | BRL_DOT3 | BRL_DOT4 | BRL_DOT7 | BRL_DOT8] = 0X90,
[BRL_DOT1 | BRL_DOT2 | BRL_DOT3 | BRL_DOT4 | BRL_DOT8] = 0XD0,
[BRL_DOT1 | BRL_DOT2 | BRL_DOT3 | BRL_DOT5] = 0X52,
[BRL_DOT1 | BRL_DOT2 | BRL_DOT3 | BRL_DOT5 | BRL_DOT6] = 0X5b,
[BRL_DOT1 | BRL_DOT2 | BRL_DOT3 | BRL_DOT5 | BRL_DOT6 | BRL_DOT7] = 0X1B,
[BRL_DOT1 | BRL_DOT2 | BRL_DOT3 | BRL_DOT5 | BRL_DOT6 | BRL_DOT7 | BRL_DOT8] = 0X9B,
[BRL_DOT1 | BRL_DOT2 | BRL_DOT3 | BRL_DOT5 | BRL_DOT6 | BRL_DOT8] = 0XDB,
[BRL_DOT1 | BRL_DOT2 | BRL_DOT3 | BRL_DOT5 | BRL_DOT7] = 0X12,
[BRL_DOT1 | BRL_DOT2 | BRL_DOT3 | BRL_DOT5 | BRL_DOT7 | BRL_DOT8] = 0X92,
[BRL_DOT1 | BRL_DOT2 | BRL_DOT3 | BRL_DOT5 | BRL_DOT8] = 0XD2,
[BRL_DOT1 | BRL_DOT2 | BRL_DOT3 | BRL_DOT6] = 0X56,
[BRL_DOT1 | BRL_DOT2 | BRL_DOT3 | BRL_DOT6 | BRL_DOT7] = 0X16,
[BRL_DOT1 | BRL_DOT2 | BRL_DOT3 | BRL_DOT6 | BRL_DOT7 | BRL_DOT8] = 0X96,
[BRL_DOT1 | BRL_DOT2 | BRL_DOT3 | BRL_DOT6 | BRL_DOT8] = 0XD6,
[BRL_DOT1 | BRL_DOT2 | BRL_DOT3 | BRL_DOT7] = 0X0C,
[BRL_DOT1 | BRL_DOT2 | BRL_DOT3 | BRL_DOT7 | BRL_DOT8] = 0X8C,
[BRL_DOT1 | BRL_DOT2 | BRL_DOT3 | BRL_DOT8] = 0XCC,
[BRL_DOT1 | BRL_DOT2 | BRL_DOT4] = 0X46,
[BRL_DOT1 | BRL_DOT2 | BRL_DOT4 | BRL_DOT5] = 0X47,
[BRL_DOT1 | BRL_DOT2 | BRL_DOT4 | BRL_DOT5 | BRL_DOT6] = 0X37,
[BRL_DOT1 | BRL_DOT2 | BRL_DOT4 | BRL_DOT5 | BRL_DOT6 | BRL_DOT7] = 0XF7,
[BRL_DOT1 | BRL_DOT2 | BRL_DOT4 | BRL_DOT5 | BRL_DOT6 | BRL_DOT7 | BRL_DOT8] = 0X77,
[BRL_DOT1 | BRL_DOT2 | BRL_DOT4 | BRL_DOT5 | BRL_DOT6 | BRL_DOT8] = 0XB7,
[BRL_DOT1 | BRL_DOT2 | BRL_DOT4 | BRL_DOT5 | BRL_DOT7] = 0X07,
[BRL_DOT1 | BRL_DOT2 | BRL_DOT4 | BRL_DOT5 | BRL_DOT7 | BRL_DOT8] = 0X87,
[BRL_DOT1 | BRL_DOT2 | BRL_DOT4 | BRL_DOT5 | BRL_DOT8] = 0XC7,
[BRL_DOT1 | BRL_DOT2 | BRL_DOT4 | BRL_DOT6] = 0X36,
[BRL_DOT1 | BRL_DOT2 | BRL_DOT4 | BRL_DOT6 | BRL_DOT7] = 0XF6,
[BRL_DOT1 | BRL_DOT2 | BRL_DOT4 | BRL_DOT6 | BRL_DOT7 | BRL_DOT8] = 0X76,
[BRL_DOT1 | BRL_DOT2 | BRL_DOT4 | BRL_DOT6 | BRL_DOT8] = 0XB6,
[BRL_DOT1 | BRL_DOT2 | BRL_DOT4 | BRL_DOT7] = 0X06,
[BRL_DOT1 | BRL_DOT2 | BRL_DOT4 | BRL_DOT7 | BRL_DOT8] = 0X86,
[BRL_DOT1 | BRL_DOT2 | BRL_DOT4 | BRL_DOT8] = 0XC6,
[BRL_DOT1 | BRL_DOT2 | BRL_DOT5] = 0X48,
[BRL_DOT1 | BRL_DOT2 | BRL_DOT5 | BRL_DOT6] = 0X38,
[BRL_DOT1 | BRL_DOT2 | BRL_DOT5 | BRL_DOT6 | BRL_DOT7] = 0XF8,
[BRL_DOT1 | BRL_DOT2 | BRL_DOT5 | BRL_DOT6 | BRL_DOT7 | BRL_DOT8] = 0X78,
[BRL_DOT1 | BRL_DOT2 | BRL_DOT5 | BRL_DOT6 | BRL_DOT8] = 0XB8,
[BRL_DOT1 | BRL_DOT2 | BRL_DOT5 | BRL_DOT7] = 0X08,
[BRL_DOT1 | BRL_DOT2 | BRL_DOT5 | BRL_DOT7 | BRL_DOT8] = 0X88,
[BRL_DOT1 | BRL_DOT2 | BRL_DOT5 | BRL_DOT8] = 0XC8,
[BRL_DOT1 | BRL_DOT2 | BRL_DOT6] = 0X32,
[BRL_DOT1 | BRL_DOT2 | BRL_DOT6 | BRL_DOT7] = 0XF2,
[BRL_DOT1 | BRL_DOT2 | BRL_DOT6 | BRL_DOT7 | BRL_DOT8] = 0X72,
[BRL_DOT1 | BRL_DOT2 | BRL_DOT6 | BRL_DOT8] = 0XB2,
[BRL_DOT1 | BRL_DOT2 | BRL_DOT7] = 0X02,
[BRL_DOT1 | BRL_DOT2 | BRL_DOT7 | BRL_DOT8] = 0X82,
[BRL_DOT1 | BRL_DOT2 | BRL_DOT8] = 0XC2,
[BRL_DOT1 | BRL_DOT3] = 0X4B,
[BRL_DOT1 | BRL_DOT3 | BRL_DOT4] = 0X4D,
[BRL_DOT1 | BRL_DOT3 | BRL_DOT4 | BRL_DOT5] = 0X4E,
[BRL_DOT1 | BRL_DOT3 | BRL_DOT4 | BRL_DOT5 | BRL_DOT6] = 0X59,
[BRL_DOT1 | BRL_DOT3 | BRL_DOT4 | BRL_DOT5 | BRL_DOT6 | BRL_DOT7] = 0X19,
[BRL_DOT1 | BRL_DOT3 | BRL_DOT4 | BRL_DOT5 | BRL_DOT6 | BRL_DOT7 | BRL_DOT8] = 0X99,
[BRL_DOT1 | BRL_DOT3 | BRL_DOT4 | BRL_DOT5 | BRL_DOT6 | BRL_DOT8] = 0XD9,
[BRL_DOT1 | BRL_DOT3 | BRL_DOT4 | BRL_DOT5 | BRL_DOT7] = 0X0E,
[BRL_DOT1 | BRL_DOT3 | BRL_DOT4 | BRL_DOT5 | BRL_DOT7 | BRL_DOT8] = 0X8E,
[BRL_DOT1 | BRL_DOT3 | BRL_DOT4 | BRL_DOT5 | BRL_DOT8] = 0XCE,
[BRL_DOT1 | BRL_DOT3 | BRL_DOT4 | BRL_DOT6] = 0X58,
[BRL_DOT1 | BRL_DOT3 | BRL_DOT4 | BRL_DOT6 | BRL_DOT7] = 0X18,
[BRL_DOT1 | BRL_DOT3 | BRL_DOT4 | BRL_DOT6 | BRL_DOT7 | BRL_DOT8] = 0X98,
[BRL_DOT1 | BRL_DOT3 | BRL_DOT4 | BRL_DOT6 | BRL_DOT8] = 0XD8,
[BRL_DOT1 | BRL_DOT3 | BRL_DOT4 | BRL_DOT7] = 0X0D,
[BRL_DOT1 | BRL_DOT3 | BRL_DOT4 | BRL_DOT7 | BRL_DOT8] = 0X8D,
[BRL_DOT1 | BRL_DOT3 | BRL_DOT4 | BRL_DOT8] = 0XCD,
[BRL_DOT1 | BRL_DOT3 | BRL_DOT5] = 0X4F,
[BRL_DOT1 | BRL_DOT3 | BRL_DOT5 | BRL_DOT6] = 0X5A,
[BRL_DOT1 | BRL_DOT3 | BRL_DOT5 | BRL_DOT6 | BRL_DOT7] = 0X1A,
[BRL_DOT1 | BRL_DOT3 | BRL_DOT5 | BRL_DOT6 | BRL_DOT7 | BRL_DOT8] = 0X9A,
[BRL_DOT1 | BRL_DOT3 | BRL_DOT5 | BRL_DOT6 | BRL_DOT8] = 0XDA,
[BRL_DOT1 | BRL_DOT3 | BRL_DOT5 | BRL_DOT7] = 0X0F,
[BRL_DOT1 | BRL_DOT3 | BRL_DOT5 | BRL_DOT7 | BRL_DOT8] = 0X8F,
[BRL_DOT1 | BRL_DOT3 | BRL_DOT5 | BRL_DOT8] = 0XCF,
[BRL_DOT1 | BRL_DOT3 | BRL_DOT6] = 0X55,
[BRL_DOT1 | BRL_DOT3 | BRL_DOT6 | BRL_DOT7] = 0X15,
[BRL_DOT1 | BRL_DOT3 | BRL_DOT6 | BRL_DOT7 | BRL_DOT8] = 0X95,
[BRL_DOT1 | BRL_DOT3 | BRL_DOT6 | BRL_DOT8] = 0XD5,
[BRL_DOT1 | BRL_DOT3 | BRL_DOT7] = 0X0B,
[BRL_DOT1 | BRL_DOT3 | BRL_DOT7 | BRL_DOT8] = 0X8B,
[BRL_DOT1 | BRL_DOT3 | BRL_DOT8] = 0XCB,
[BRL_DOT1 | BRL_DOT4] = 0X43,
[BRL_DOT1 | BRL_DOT4 | BRL_DOT5] = 0X44,
[BRL_DOT1 | BRL_DOT4 | BRL_DOT5 | BRL_DOT6] = 0X34,
[BRL_DOT1 | BRL_DOT4 | BRL_DOT5 | BRL_DOT6 | BRL_DOT7] = 0XF4,
[BRL_DOT1 | BRL_DOT4 | BRL_DOT5 | BRL_DOT6 | BRL_DOT7 | BRL_DOT8] = 0X74,
[BRL_DOT1 | BRL_DOT4 | BRL_DOT5 | BRL_DOT6 | BRL_DOT8] = 0XB4,
[BRL_DOT1 | BRL_DOT4 | BRL_DOT5 | BRL_DOT7] = 0X04,
[BRL_DOT1 | BRL_DOT4 | BRL_DOT5 | BRL_DOT7 | BRL_DOT8] = 0X84,
[BRL_DOT1 | BRL_DOT4 | BRL_DOT5 | BRL_DOT8] = 0XC4,
[BRL_DOT1 | BRL_DOT4 | BRL_DOT6] = 0X33,
[BRL_DOT1 | BRL_DOT4 | BRL_DOT6 | BRL_DOT7] = 0XF3,
[BRL_DOT1 | BRL_DOT4 | BRL_DOT6 | BRL_DOT7 | BRL_DOT8] = 0X73,
[BRL_DOT1 | BRL_DOT4 | BRL_DOT6 | BRL_DOT8] = 0XB3,
[BRL_DOT1 | BRL_DOT4 | BRL_DOT7] = 0X03,
[BRL_DOT1 | BRL_DOT4 | BRL_DOT7 | BRL_DOT8] = 0X83,
[BRL_DOT1 | BRL_DOT4 | BRL_DOT8] = 0XC3,
[BRL_DOT1 | BRL_DOT5] = 0X45,
[BRL_DOT1 | BRL_DOT5 | BRL_DOT6] = 0X35,
[BRL_DOT1 | BRL_DOT5 | BRL_DOT6 | BRL_DOT7] = 0XF5,
[BRL_DOT1 | BRL_DOT5 | BRL_DOT6 | BRL_DOT7 | BRL_DOT8] = 0X75,
[BRL_DOT1 | BRL_DOT5 | BRL_DOT6 | BRL_DOT8] = 0XB5,
[BRL_DOT1 | BRL_DOT5 | BRL_DOT7] = 0X05,
[BRL_DOT1 | BRL_DOT5 | BRL_DOT7 | BRL_DOT8] = 0X85,
[BRL_DOT1 | BRL_DOT5 | BRL_DOT8] = 0XC5,
[BRL_DOT1 | BRL_DOT6] = 0X31,
[BRL_DOT1 | BRL_DOT6 | BRL_DOT7] = 0XF1,
[BRL_DOT1 | BRL_DOT6 | BRL_DOT7 | BRL_DOT8] = 0X71,
[BRL_DOT1 | BRL_DOT6 | BRL_DOT8] = 0XB1,
[BRL_DOT1 | BRL_DOT7] = 0X01,
[BRL_DOT1 | BRL_DOT7 | BRL_DOT8] = 0X81,
[BRL_DOT1 | BRL_DOT8] = 0XC1,
[BRL_DOT2] = 0X2C,
[BRL_DOT2 | BRL_DOT3] = 0X3B,
[BRL_DOT2 | BRL_DOT3 | BRL_DOT4] = 0X53,
[BRL_DOT2 | BRL_DOT3 | BRL_DOT4 | BRL_DOT5] = 0X54,
[BRL_DOT2 | BRL_DOT3 | BRL_DOT4 | BRL_DOT5 | BRL_DOT6] = 0X5D,
[BRL_DOT2 | BRL_DOT3 | BRL_DOT4 | BRL_DOT5 | BRL_DOT6 | BRL_DOT7] = 0X1D,
[BRL_DOT2 | BRL_DOT3 | BRL_DOT4 | BRL_DOT5 | BRL_DOT6 | BRL_DOT7 | BRL_DOT8] = 0X9D,
[BRL_DOT2 | BRL_DOT3 | BRL_DOT4 | BRL_DOT5 | BRL_DOT6 | BRL_DOT8] = 0XDD,
[BRL_DOT2 | BRL_DOT3 | BRL_DOT4 | BRL_DOT5 | BRL_DOT7] = 0X14,
[BRL_DOT2 | BRL_DOT3 | BRL_DOT4 | BRL_DOT5 | BRL_DOT7 | BRL_DOT8] = 0X94,
[BRL_DOT2 | BRL_DOT3 | BRL_DOT4 | BRL_DOT5 | BRL_DOT8] = 0XD4,
[BRL_DOT2 | BRL_DOT3 | BRL_DOT4 | BRL_DOT6] = 0X5C,
[BRL_DOT2 | BRL_DOT3 | BRL_DOT4 | BRL_DOT6 | BRL_DOT7] = 0X1C,
[BRL_DOT2 | BRL_DOT3 | BRL_DOT4 | BRL_DOT6 | BRL_DOT7 | BRL_DOT8] = 0X9C,
[BRL_DOT2 | BRL_DOT3 | BRL_DOT4 | BRL_DOT6 | BRL_DOT8] = 0XDC,
[BRL_DOT2 | BRL_DOT3 | BRL_DOT4 | BRL_DOT7] = 0X13,
[BRL_DOT2 | BRL_DOT3 | BRL_DOT4 | BRL_DOT7 | BRL_DOT8] = 0X93,
[BRL_DOT2 | BRL_DOT3 | BRL_DOT4 | BRL_DOT8] = 0XD3,
[BRL_DOT2 | BRL_DOT3 | BRL_DOT5] = 0X21,
[BRL_DOT2 | BRL_DOT3 | BRL_DOT5 | BRL_DOT6] = 0X3D,
[BRL_DOT2 | BRL_DOT3 | BRL_DOT5 | BRL_DOT6 | BRL_DOT7] = 0Xfd,
[BRL_DOT2 | BRL_DOT3 | BRL_DOT5 | BRL_DOT6 | BRL_DOT7 | BRL_DOT8] = 0X7D,
[BRL_DOT2 | BRL_DOT3 | BRL_DOT5 | BRL_DOT6 | BRL_DOT8] = 0XBD,
[BRL_DOT2 | BRL_DOT3 | BRL_DOT5 | BRL_DOT7] = 0XE1,
[BRL_DOT2 | BRL_DOT3 | BRL_DOT5 | BRL_DOT7 | BRL_DOT8] = 0X61,
[BRL_DOT2 | BRL_DOT3 | BRL_DOT5 | BRL_DOT8] = 0XA1,
[BRL_DOT2 | BRL_DOT3 | BRL_DOT6] = 0X3C,
[BRL_DOT2 | BRL_DOT3 | BRL_DOT6 | BRL_DOT7] = 0XFC,
[BRL_DOT2 | BRL_DOT3 | BRL_DOT6 | BRL_DOT7 | BRL_DOT8] = 0X7C,
[BRL_DOT2 | BRL_DOT3 | BRL_DOT6 | BRL_DOT8] = 0XBC,
[BRL_DOT2 | BRL_DOT3 | BRL_DOT7] = 0XFB,
[BRL_DOT2 | BRL_DOT3 | BRL_DOT7 | BRL_DOT8] = 0X7B,
[BRL_DOT2 | BRL_DOT3 | BRL_DOT8] = 0XBB,
[BRL_DOT2 | BRL_DOT4] = 0X49,
[BRL_DOT2 | BRL_DOT4 | BRL_DOT5] = 0X4A,
[BRL_DOT2 | BRL_DOT4 | BRL_DOT5 | BRL_DOT6] = 0X57,
[BRL_DOT2 | BRL_DOT4 | BRL_DOT5 | BRL_DOT6 | BRL_DOT7] = 0X17,
[BRL_DOT2 | BRL_DOT4 | BRL_DOT5 | BRL_DOT6 | BRL_DOT7 | BRL_DOT8] = 0X97,
[BRL_DOT2 | BRL_DOT4 | BRL_DOT5 | BRL_DOT6 | BRL_DOT8] = 0XD7,
[BRL_DOT2 | BRL_DOT4 | BRL_DOT5 | BRL_DOT7] = 0X0A,
[BRL_DOT2 | BRL_DOT4 | BRL_DOT5 | BRL_DOT7 | BRL_DOT8] = 0X8A,
[BRL_DOT2 | BRL_DOT4 | BRL_DOT5 | BRL_DOT8] = 0XCA,
[BRL_DOT2 | BRL_DOT4 | BRL_DOT6] = 0X39,
[BRL_DOT2 | BRL_DOT4 | BRL_DOT6 | BRL_DOT7] = 0XF9,
[BRL_DOT2 | BRL_DOT4 | BRL_DOT6 | BRL_DOT7 | BRL_DOT8] = 0X79,
[BRL_DOT2 | BRL_DOT4 | BRL_DOT6 | BRL_DOT8] = 0XB9,
[BRL_DOT2 | BRL_DOT4 | BRL_DOT7] = 0X09,
[BRL_DOT2 | BRL_DOT4 | BRL_DOT7 | BRL_DOT8] = 0X89,
[BRL_DOT2 | BRL_DOT4 | BRL_DOT8] = 0XC9,
[BRL_DOT2 | BRL_DOT5] = 0X3A,
[BRL_DOT2 | BRL_DOT5 | BRL_DOT6] = 0X2E,
[BRL_DOT2 | BRL_DOT5 | BRL_DOT6 | BRL_DOT7] = 0XEE,
[BRL_DOT2 | BRL_DOT5 | BRL_DOT6 | BRL_DOT7 | BRL_DOT8] = 0X6E,
[BRL_DOT2 | BRL_DOT5 | BRL_DOT6 | BRL_DOT8] = 0XAE,
[BRL_DOT2 | BRL_DOT5 | BRL_DOT7] = 0XFA,
[BRL_DOT2 | BRL_DOT5 | BRL_DOT7 | BRL_DOT8] = 0X7A,
[BRL_DOT2 | BRL_DOT5 | BRL_DOT8] = 0XBA,
[BRL_DOT2 | BRL_DOT6] = 0X3F,
[BRL_DOT2 | BRL_DOT6 | BRL_DOT7] = 0XFF,
[BRL_DOT2 | BRL_DOT6 | BRL_DOT7 | BRL_DOT8] = 0X7F,
[BRL_DOT2 | BRL_DOT6 | BRL_DOT8] = 0XBF,
[BRL_DOT2 | BRL_DOT7] = 0XEC,
[BRL_DOT2 | BRL_DOT7 | BRL_DOT8] = 0X6C,
[BRL_DOT2 | BRL_DOT8] = 0XAC,
[BRL_DOT3] = 0X27,
[BRL_DOT3 | BRL_DOT4] = 0X2A,
[BRL_DOT3 | BRL_DOT4 | BRL_DOT5] = 0X26,
[BRL_DOT3 | BRL_DOT4 | BRL_DOT5 | BRL_DOT6] = 0X30,
[BRL_DOT3 | BRL_DOT4 | BRL_DOT5 | BRL_DOT6 | BRL_DOT7] = 0XF0,
[BRL_DOT3 | BRL_DOT4 | BRL_DOT5 | BRL_DOT6 | BRL_DOT7 | BRL_DOT8] = 0X70,
[BRL_DOT3 | BRL_DOT4 | BRL_DOT5 | BRL_DOT6 | BRL_DOT8] = 0XB0,
[BRL_DOT3 | BRL_DOT4 | BRL_DOT5 | BRL_DOT7] = 0XE6,
[BRL_DOT3 | BRL_DOT4 | BRL_DOT5 | BRL_DOT7 | BRL_DOT8] = 0X66,
[BRL_DOT3 | BRL_DOT4 | BRL_DOT5 | BRL_DOT8] = 0XA6,
[BRL_DOT3 | BRL_DOT4 | BRL_DOT6] = 0X5E,
[BRL_DOT3 | BRL_DOT4 | BRL_DOT6 | BRL_DOT7] = 0X1E,
[BRL_DOT3 | BRL_DOT4 | BRL_DOT6 | BRL_DOT7 | BRL_DOT8] = 0X9E,
[BRL_DOT3 | BRL_DOT4 | BRL_DOT6 | BRL_DOT8] = 0XDE,
[BRL_DOT3 | BRL_DOT4 | BRL_DOT7] = 0XEA,
[BRL_DOT3 | BRL_DOT4 | BRL_DOT7 | BRL_DOT8] = 0X6A,
[BRL_DOT3 | BRL_DOT4 | BRL_DOT8] = 0XAA,
[BRL_DOT3 | BRL_DOT5] = 0X29,
[BRL_DOT3 | BRL_DOT5 | BRL_DOT6] = 0X3E,
[BRL_DOT3 | BRL_DOT5 | BRL_DOT6 | BRL_DOT7] = 0XFE,
[BRL_DOT3 | BRL_DOT5 | BRL_DOT6 | BRL_DOT7 | BRL_DOT8] = 0X7E,
[BRL_DOT3 | BRL_DOT5 | BRL_DOT6 | BRL_DOT8] = 0XBE,
[BRL_DOT3 | BRL_DOT5 | BRL_DOT7] = 0XE9,
[BRL_DOT3 | BRL_DOT5 | BRL_DOT7 | BRL_DOT8] = 0X69,
[BRL_DOT3 | BRL_DOT5 | BRL_DOT8] = 0XA9,
[BRL_DOT3 | BRL_DOT6] = 0X2D,
[BRL_DOT3 | BRL_DOT6 | BRL_DOT7] = 0XED,
[BRL_DOT3 | BRL_DOT6 | BRL_DOT7 | BRL_DOT8] = 0X6D,
[BRL_DOT3 | BRL_DOT6 | BRL_DOT8] = 0XAD,
[BRL_DOT3 | BRL_DOT7] = 0XE7,
[BRL_DOT3 | BRL_DOT7 | BRL_DOT8] = 0X67,
[BRL_DOT3 | BRL_DOT8] = 0XA7,
[BRL_DOT4] = 0X22,
[BRL_DOT4 | BRL_DOT5] = 0X25,
[BRL_DOT4 | BRL_DOT5 | BRL_DOT6] = 0X24,
[BRL_DOT4 | BRL_DOT5 | BRL_DOT6 | BRL_DOT7] = 0XE4,
[BRL_DOT4 | BRL_DOT5 | BRL_DOT6 | BRL_DOT7 | BRL_DOT8] = 0X64,
[BRL_DOT4 | BRL_DOT5 | BRL_DOT6 | BRL_DOT8] = 0XA4,
[BRL_DOT4 | BRL_DOT5 | BRL_DOT7] = 0XE5,
[BRL_DOT4 | BRL_DOT5 | BRL_DOT7 | BRL_DOT8] = 0X65,
[BRL_DOT4 | BRL_DOT5 | BRL_DOT8] = 0XA5,
[BRL_DOT4 | BRL_DOT6] = 0X23,
[BRL_DOT4 | BRL_DOT6 | BRL_DOT7] = 0XE3,
[BRL_DOT4 | BRL_DOT6 | BRL_DOT7 | BRL_DOT8] = 0X63,
[BRL_DOT4 | BRL_DOT6 | BRL_DOT8] = 0XA3,
[BRL_DOT4 | BRL_DOT7] = 0XE2,
[BRL_DOT4 | BRL_DOT7 | BRL_DOT8] = 0X62,
[BRL_DOT4 | BRL_DOT8] = 0XA2,
[BRL_DOT5] = 0X5F,
[BRL_DOT5 | BRL_DOT6] = 0X2B,
[BRL_DOT5 | BRL_DOT6 | BRL_DOT7] = 0XEB,
[BRL_DOT5 | BRL_DOT6 | BRL_DOT7 | BRL_DOT8] = 0X6B,
[BRL_DOT5 | BRL_DOT6 | BRL_DOT8] = 0XAB,
[BRL_DOT5 | BRL_DOT7] = 0X1F,
[BRL_DOT5 | BRL_DOT7 | BRL_DOT8] = 0X9F,
[BRL_DOT5 | BRL_DOT8] = 0XDF,
[BRL_DOT6] = 0X28,
[BRL_DOT6 | BRL_DOT7] = 0XE8,
[BRL_DOT6 | BRL_DOT7 | BRL_DOT8] = 0X68,
[BRL_DOT6 | BRL_DOT8] = 0XA8,
[BRL_DOT7] = 0XE0,
[BRL_DOT7 | BRL_DOT8] = 0X60,
[BRL_DOT8] = 0XA0
