/**
 * Copyright (c) 2020 The Brave Authors. All rights reserved.
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
 */

package org.chromium.chrome.browser.util;

import android.content.Context;
import android.graphics.Color;
import android.graphics.Canvas;
import android.graphics.Bitmap;
import android.graphics.LinearGradient;
import android.graphics.Paint;
import android.graphics.PorterDuff;
import android.graphics.PorterDuffXfermode;
import android.graphics.Shader;

import org.chromium.chrome.R;
import org.chromium.chrome.browser.util.ConfigurationUtils;

import static org.chromium.chrome.browser.util.ViewUtils.dpToPx;

public class ImageUtils {
    public static Bitmap topOffset(Bitmap src, int offsetY) {
        Bitmap outputimage = Bitmap.createBitmap(src.getWidth(), src.getHeight() + offsetY, Bitmap.Config.ARGB_8888);
        Canvas canvas = new Canvas(outputimage);
        canvas.drawBitmap(src, 0, offsetY, null);
        return outputimage;
    }

    public static Bitmap addGradient(Context context, Bitmap src, int gradientHeight) {
        int w = src.getWidth();
        int h = src.getHeight();
        Bitmap result = Bitmap.createBitmap(src,0,0,w,h);
        Canvas canvas = new Canvas(result);

        // Top gradient
        int height;

        if(ConfigurationUtils.isLandscape(context)) {
            height = ((2*h)/3)+ gradientHeight;
        } else {
            height = (h/3)+ gradientHeight;
        }

        Paint topPaint = new Paint();
        LinearGradient topShader = new LinearGradient(0,0,0,height, context.getResources().getColor(R.color.black_alpha_50), Color.TRANSPARENT, Shader.TileMode.CLAMP);
        topPaint.setShader(topShader);
        topPaint.setXfermode(new PorterDuffXfermode(PorterDuff.Mode.DARKEN));
        canvas.drawRect(0,0,w,height,topPaint);

        //Bottom gradient
        Paint bottomPaint = new Paint();
        LinearGradient bottomShader = new LinearGradient(0,2*(h/3),0,h, Color.TRANSPARENT, context.getResources().getColor(R.color.black_alpha_30), Shader.TileMode.CLAMP);
        bottomPaint.setShader(bottomShader);
        bottomPaint.setXfermode(new PorterDuffXfermode(PorterDuff.Mode.DARKEN));
        canvas.drawRect(0,2*(h/3),w,h,bottomPaint);

        return result;
    }
}