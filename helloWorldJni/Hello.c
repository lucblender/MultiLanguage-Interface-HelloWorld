#include <jni.h>
#include "Hello.h"
#include "HelloImpl.h"

JNIEXPORT void JNICALL Java_Hello_sayHello (JNIEnv *env, jobject obj) {
    sayHello();
    return;
}