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

public class WriteTextClient extends PauseClient {
  public WriteTextClient (String... arguments) {
    super(arguments);
    addRepeatingParameter("text");
  }

  private String text = null;

  @Override
  protected final void processParameters (String[] parameters) {
    StringBuilder builder = new StringBuilder();

    for (String parameter : parameters) {
      if (builder.length() > 0) builder.append(' ');
      builder.append(parameter);
    }

    text = builder.toString();
  }

  @Override
  protected final void runClient (Connection connection) 
            throws ProgramException
  {
    ttyMode(
      connection, false,
      (tty) -> {
        printf("%s\n", text);
        tty.write(text, Constants.CURSOR_OFF);
        pause(tty, getPauseTimeout());
      }
    );
  }
}
