Face Detection with OpenCV Android App
===

Sample Android app integrated with OpenCV library to utilize realtime face detection and machine learning.

I will show you how to integrate OpenCV Android SDK into your existing Android studio project.

Prerequisite
===
- Android Studio with `CMake` and `NDK` installed.
- Basic knowledge of JNI (Java Native Interface).
- OpenCV SDK (Download at https://opencv.org/releases/)
- Android device (recommended Android N or higher).

My Setup
===
- Android Studio `3.4.2`
- OpenCV Android SDK version `4.1.0`
- CMake version `3.10.2`
- Android NDK `20`
- LLDB `3.1`

OpenCV Integration Guide
===

## Import `OpenCV` Project as your module
# Extract OpenCV SDK

# Open your Android Studio project.

# Right click your project -> `New` -> `Module` -> `Import Gradle Project`.

# Select `sdk/java` as a source directory.

# Uncheck `Replace jars with dependencies` and `Replace library sources with dependencies`.

## Copy over `so` files to your project.
https://stackoverflow.com/questions/27406303/opencv-in-android-studio

# Copy `sdk/native/libs` folder to your Android project under 'app/src/main'

# Rename the copied folder to `jniLibs`

## Static load OpenCV library

# Add the following to your Android activity (i.e. MainActivity.java)
```
static {
    System.loadLibrary("opencv_java4");
}
```

# Invalidate cache and rebuild the project

## Try if you can reference OpenCV package in your project

# The simple test is to just import one of OpenCV packages to your Android activity.
i.e.
```
import org.opencv.android.Core;
```







* Recompile `detection_based_tracker`

# Open `build.gradle` under your `module:app` and add the following under `default config` section
```
android {
    defaultConfig {
        ...
        externalNativeBuild {
            cmake {
                arguments "-DOpenCV_DIR=" + project(':opencv').projectDir + "/native/jni",
"-DANDROID_TOOLCHAIN=clang",
"-DANDROID_STL=c++_static"
                targets "detection_based_tracker"
            }
        }
    }
}
```

# Copy over `sdk/jni/native` folder to your Android project's OpenCV folder under `native/jni`.




