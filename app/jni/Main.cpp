#include <android_native_app_glue.h>
#include <android/log.h>

#define LOGI(...) __android_log_print(ANDROID_LOG_INFO, "your-tag", __VA_ARGS__);

void android_main(android_app* ptr_SystemState)
{
    LOGI("Hello World!");
}