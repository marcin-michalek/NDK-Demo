#include <jni.h>
#include <android/log.h>
#include <time.h>
#include <math.h>

// use cpp syntax but prevent compiler from changing method names
extern "C" {
/*
 * Definition of function used in MainActivity. Name must match pattern:
 *      Java_pkg_name_ClassWhereItsUsed_functionName
 * Two standard arguments for all JNI methods.
 */

// return time in millis
static double now_timestamp(void) {

    struct timespec res;
    clock_gettime(CLOCK_REALTIME, &res);
    return (double) res.tv_nsec;

}

jstring
Java_pl_marcin_michalek_ndkdemo_MainActivity_nativeStringFromJNI(JNIEnv *env, jobject thiz) {
    //env
    // provides various JNI functions, for ex. NewStringUTF

    // thiz
    //Static – reference to class where method is defined
    //Instance – object on which the native method is invoked

    return env->NewStringUTF("Hello from JNI !");
}


jint
Java_pl_marcin_michalek_ndkdemo_MainActivity_nativeAdd(JNIEnv *env, jobject thiz,
                                                       jint a, jint b) {
    // OS native method call
    __android_log_print(ANDROID_LOG_DEBUG, "LOG_TAG", "Native sum");

    // returns sum of arguments
    return a + b;
}

jfloat
Java_pl_marcin_michalek_ndkdemo_MainActivity_nativeValuesSum(JNIEnv *env, jobject thiz,
                                                             jobject obj) {

    // get Values class
    jclass cls = env->GetObjectClass(obj);

    // get id of values array field from Values class ("[F" - float array)
    // expensive call!
    jfieldID fieldId = env->GetFieldID(cls, "values", "[F");

    // get array by field ud
    jobject valuesArray = env->GetObjectField(obj, fieldId);

    // starting to measure from here, because usually above code is extracted to "init" method
    double startTime = now_timestamp();

    // cast it to a jfloatArray
    jfloatArray *fArray = reinterpret_cast<jfloatArray *>(&valuesArray);

    // get length for loop
    jsize len = env->GetArrayLength(*fArray);

    // get the elements
    float *data = env->GetFloatArrayElements(*fArray, 0);
    float sum = 0.0f;

    for (int i = 0; i < len; ++i) {
        sum += sqrtf(data[i]);
    }

    // RELEASE!
    env->ReleaseFloatArrayElements(*fArray, data, 0);

    double endTime = now_timestamp();

    double deltaTime = endTime - startTime;

    __android_log_print(ANDROID_LOG_DEBUG, "DELTA_TIME", "Native execution: %f", deltaTime);

    return sum;
}

}