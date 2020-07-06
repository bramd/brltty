/*
 * libbrlapi - A library providing access to braille terminals for applications.
 *
 * Copyright (C) 2006-2020 by
 *   Samuel Thibault <Samuel.Thibault@ens-lyon.org>
 *   Sébastien Hinderer <Sebastien.Hinderer@ens-lyon.org>
 *
 * libbrlapi comes with ABSOLUTELY NO WARRANTY.
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

package org.a11y.brlapi.clients;
import org.a11y.brlapi.*;

import java.io.InterruptedIOException;
import java.util.concurrent.TimeoutException;

public class EchoClient extends Client {
  public final static byte MINIMUM_READ_TIMEOUT =  1;
  public final static byte DEFAULT_READ_TIMEOUT = 10;
  public final static byte MAXIMUM_READ_TIMEOUT = 30;

  private boolean echoDriverKeys = false;
  private byte readTimeout = DEFAULT_READ_TIMEOUT;

  public EchoClient (String... arguments) {
    super(arguments);
    addRepeatingParameter("tty");

    addOption("commands",
      (operands) -> {
        echoDriverKeys = false;
      }
    );

    addOption("keys",
      (operands) -> {
        echoDriverKeys = true;
      }
    );

    addOption("timeout",
      (operands) -> {
        readTimeout = Parse.asByte(
          "read timeout", operands[0],
          MINIMUM_READ_TIMEOUT, MAXIMUM_READ_TIMEOUT
        );
      },
      "number of seconds"
    );
  }

  @Override
  protected final void extendUsageSummary (StringBuilder usage) {
    super.extendUsageSummary(usage);

    usage.append('\n')
         .append("The read timeout must be an integer number of seconds")
         .append(" within the range ").append(MINIMUM_READ_TIMEOUT)
         .append(" through ").append(MAXIMUM_READ_TIMEOUT)
         .append(". ")

         .append("If not specified, ")
         .append(DEFAULT_READ_TIMEOUT)
         .append(" is assumed. ")
         ;
  }

  private int[] ttyPath = null;

  @Override
  protected void processParameters (String[] parameters)
            throws SyntaxException
  {
    int count = parameters.length;
    ttyPath = new int[count];

    for (int i=0; i<count; i+=1) {
      ttyPath[i] = Parse.asInt("tty path component", parameters[i]);
    }
  }

  private final void show (Connection connection, String text) {
    printf("%s\n", text);
    connection.write(text, Constants.CURSOR_OFF);
  }

  @Override
  protected final void runClient (Connection connection) throws ProgramException {
    ttyMode(
      connection, echoDriverKeys,
      (tty) -> {
        show(tty,
          String.format(
            "press keys (timeout is %d seconds)", readTimeout
          )
        );

        while (true) {
          long code;

          try {
            code = tty.readKeyWithTimeout((readTimeout * 1000));
          } catch (InterruptedIOException exception) {
            continue;
          } catch (TimeoutException exception) {
            break;
          }

          String text =
            echoDriverKeys?
            new DriverKeycode(code).toString():
            new CommandKeycode(code).toString();

          show(tty, text);
        }
      },
      ttyPath
    );
  }
}
