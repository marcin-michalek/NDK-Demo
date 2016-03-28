#include <string.h>
#include <jni.h>
#include <android/log.h>

// use cpp syntax but prevent compiler from changing method names
extern "C" {
/*
 * Definition of function used in MainActivity. Name must match pattern:
 *      Java_pkg_name_ClassWhereItsUsed_functionName
 * Two standard arguments for all JNI methods.
 */
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

}