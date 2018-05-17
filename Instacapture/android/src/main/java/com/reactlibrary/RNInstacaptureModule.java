
package com.reactlibrary;

import android.app.Activity;
import android.graphics.Bitmap;
import android.util.Base64;
import android.widget.Toast;

import com.facebook.react.bridge.Promise;
import com.facebook.react.bridge.ReactApplicationContext;
import com.facebook.react.bridge.ReactContextBaseJavaModule;
import com.facebook.react.bridge.ReactMethod;
import com.facebook.react.bridge.Callback;
import com.tarek360.instacapture.Instacapture;
import com.tarek360.instacapture.listener.SimpleScreenCapturingListener;

import java.io.ByteArrayOutputStream;

public class RNInstacaptureModule extends ReactContextBaseJavaModule {

  private final ReactApplicationContext reactContext;

  public RNInstacaptureModule(ReactApplicationContext reactContext) {
    super(reactContext);
    this.reactContext = reactContext;
  }

  @ReactMethod
  public void capture (final Promise onCaptureComplete) {
    // An example native method that you will expose to React
    // https://facebook.github.io/react-native/docs/native-modules-android.html#the-toast-module
    Activity activity = getCurrentActivity();

    if (activity == null) {
      return;
    }

    Instacapture.capture(activity, new SimpleScreenCapturingListener() {
      @Override
      public void onCaptureComplete(Bitmap bitmap) {
        super.onCaptureComplete(bitmap);
        onCaptureComplete.resolve(encodeToBase64(bitmap));

      }

      @Override
      public void onCaptureFailed(Throwable e) {
        super.onCaptureFailed(e);
        onCaptureComplete.reject(e);
      }
    }, null);
  }

  private static String encodeToBase64(Bitmap image) {
    ByteArrayOutputStream baos = new ByteArrayOutputStream();
    image.compress(Bitmap.CompressFormat.JPEG, 100, baos);
    byte[] b = baos.toByteArray();
    return Base64.encodeToString(b, Base64.DEFAULT);
  }


  @Override
  public String getName() {
    return "RNInstacapture";
  }
}