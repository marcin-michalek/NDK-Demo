package pl.marcin.michalek.ndkdemo.data;

import android.util.Log;

/**
 * Just a dummy class containing an array of float values and a boolean telling if they have been
 * processed.
 */
public class Values {

    private static final int VALUES_SIZE = 100;

    private boolean areProcessed = false;
    public float[] values = new float[VALUES_SIZE];

    public Values() {
        for (int i = 0; i < VALUES_SIZE; i++) {
            values[i] = 10f * i;
        }
    }

    /**
     * @return Sum of all sqrts from values.
     */
    public float sumOfSqrts() {
        float sum = 0f;

        double startTime = System.nanoTime();

        for (int i = 0; i < values.length; ++i) {
            sum += Math.sqrt(values[i]);
        }

        double endTime = System.nanoTime();

        double deltaTime = endTime - startTime;

        Log.d("DELTA_TIME", String.format("Java execution: %f", deltaTime));

        return sum;
    }

    public boolean isAreProcessed() {
        return areProcessed;
    }
}
