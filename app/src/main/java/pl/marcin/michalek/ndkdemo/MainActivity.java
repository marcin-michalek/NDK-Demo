package pl.marcin.michalek.ndkdemo;

import android.app.Activity;
import android.os.Bundle;
import android.widget.TextView;

public class MainActivity extends Activity {

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);

        // create a TextView and set it as content view
        // text is acquired from native library
        TextView tv = new TextView(this);
        tv.setText(String.valueOf(nativeAdd(1, 1)));
        setContentView(tv);
    }

    /**
     * Declaration of native method defined in jni library.
     * @return Hello world string
     */
    public native String nativeStringFromJNI();

    /**
     * @param a First element
     * @param b Second Element
     * @return Sum of two elements
     */
    public native int nativeAdd(int a, int b);

    /**
     * Loads generated native libraries to {@link MainActivity} with its functions.
     */
    static {
        System.loadLibrary("hello-jni");
    }
}
