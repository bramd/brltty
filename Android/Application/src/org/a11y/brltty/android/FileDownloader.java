/*
 * BRLTTY - A background process providing access to the console screen (when in
 *          text mode) for a blind person using a refreshable braille display.
 *
 * Copyright (C) 1995-2020 by The BRLTTY Developers.
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

package org.a11y.brltty.android;

import android.util.Log;
import android.os.AsyncTask;

import java.net.URL;
import java.io.File;

import java.net.URLConnection;
import java.net.HttpURLConnection;

import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
import java.io.FileOutputStream;

public class FileDownloader {
  private final static String LOG_TAG = FileDownloader.class.getName();

  protected final String sourceURL;
  protected final File targetFile;

  public FileDownloader (String url, File file) {
    sourceURL = url;
    targetFile = file;
  }

  private static void copy (InputStream input, OutputStream output) throws IOException {
    byte[] buffer = new byte[0X1000];
    int length;

    while ((length = input.read(buffer)) != -1) {
      output.write(buffer, 0, length);
    }
  }

  protected void onDownloadStarted () {
  }

  protected void onDownloadFinished () {
  }

  protected void onDownloadFailed (String message) {
  }

  public final void startDownload () {
    new AsyncTask<Object, Object, String>() {
      @Override
      protected void onPreExecute () {
        onDownloadStarted();
      }

      @Override
      protected String doInBackground (Object... arguments) {
        try {
          URL url = new URL(sourceURL);
          HttpURLConnection connection = (HttpURLConnection)url.openConnection();
          connection.setRequestMethod("GET");
          connection.connect();

          try {
            InputStream input = connection.getInputStream();

            try {
              File file = targetFile;
              file.delete();

              try {
                OutputStream output = new FileOutputStream(file);

                try {
                  copy(input, output);
                  output.flush();
                  file = null;
                } finally {
                  output.close();
                  output = null;
                }
              } finally {
                if (file != null) file.delete();
              }
            } finally {
              input.close();
              input = null;
            }
          } finally {
            connection.disconnect();
            connection = null;
          }
        } catch (IOException exception) {
          String message = exception.getMessage();
          Log.w(LOG_TAG, String.format("file download failed: %s: %s", sourceURL, message));
          return message;
        }

        return null;
      }

      @Override
      protected void onPostExecute (String message) {
        if (message == null) {
          onDownloadFinished();
        } else {
          onDownloadFailed(message);
        }
      }
    }.execute();
  }
}
