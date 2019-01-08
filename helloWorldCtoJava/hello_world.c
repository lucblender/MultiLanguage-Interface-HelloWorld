#include <stdio.h>
#include <jni.h>

JNIEnv* create_vm(JavaVM **jvm)
{
    JNIEnv* env;
    JavaVMInitArgs args;
    JavaVMOption options;
    args.version = JNI_VERSION_1_6;
    args.nOptions = 1;
    options.optionString = "-Djava.class.path=./";
    args.options = &options;
    args.ignoreUnrecognized = 0;
    int rv;
    rv = JNI_CreateJavaVM(jvm, (void**)&env, &args);
    if (rv < 0 || !env)
        printf("Unable to Launch JVM %d\n",rv);
    else
        printf("Launched JVM! :)\n");
    return env;
}

void invoke_class(JNIEnv* env)
{
    jclass hello_world_class;
    jmethodID main_method;
    jmethodID listener_method;
    const char* cstr = "<DataNotification>\n <LongInvokeIdAndPriority Value=\"000001BE\" />\n <DateTime Value=\"07E0020F0111052DFF800000\" />\n  <NotificationBody>\n    <DataValue>\n      <Structure Qty=\"05\">\n        <OctetString Value=\"4142434446464748494A\" />\n        <DoubleLongUnsigned Value=\"00000000\" />\n        <Structure Qty=\"02\">\n          <Integer Value=\"00\"/>\n          <Enum Value=\"1B\" />\n        </Structure>\n        <LongUnsigned Value=\"0010\" />\n        <Structure Qty=\"02\">\n          <Integer Value=\"FE\" />\n          <Enum Value=\"21\" />\n        </Structure>\n      </Structure>\n    </DataValue>\n  </NotificationBody>\n</DataNotification>";
    jstring jstr = (*env)->NewStringUTF(env, cstr);
    
    hello_world_class = (*env)->FindClass(env, "helloWorld");
    main_method = (*env)->GetStaticMethodID(env, hello_world_class, "main", "([Ljava/lang/String;)V");
    listener_method = (*env)->GetStaticMethodID(env, hello_world_class, "listener_xml_counter", "(Ljava/lang/String;)V");

    (*env)->CallStaticVoidMethod(env, hello_world_class, main_method, NULL);
    (*env)->CallStaticVoidMethod(env, hello_world_class, listener_method, jstr);
}

int main(int argc, char **argv)
{
    JavaVM *jvm;
    JNIEnv *env;
    env = create_vm(&jvm);
    if(env == NULL)
        return 1;
    invoke_class(env);
    return 0;
}

