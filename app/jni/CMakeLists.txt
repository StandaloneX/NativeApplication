cmake_minimum_required(VERSION 3.26.4)

project(native-activity)

add_library(native_app_glue STATIC ${ANDROID_NDK}/sources/android/native_app_glue/android_native_app_glue.c)

set(CMAKE_SHARED_LINKER_FLAGS "${CMAKE_SHARED_LINKER_FLAGS} -u ANativeActivity_onCreate")

file(GLOB_RECURSE native-activity_SRC
    "*.hpp"
    "*.cpp")

add_library(native-activity SHARED ${native-activity_SRC})

target_include_directories(native-activity
    PRIVATE
    ${ANDROID_NDK}/sources/android/native_app_glue
    PRIVATE
    ${native-activity_SRC})

target_link_libraries(native-activity
    android
    native_app_glue
    log)