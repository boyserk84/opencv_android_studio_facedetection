Face Detection with OpenCV Android App
===

Sample Android app integrated with OpenCV library to utilize realtime face detection and machine learning.

This guide will show you how to integrate OpenCV Android SDK into your existing Android studio project.

Prerequisite
===
- Android Studio with `CMake` and `NDK` installed.
- Basic knowledge of JNI (Java Native Interface).
- OpenCV SDK (Download at https://opencv.org/releases/)
- *Highly recommend* Android device (recommended Android N or higher). IMO, using an emulator works but it is not adequate.

My Setup
===
- Android Studio `3.4.2`
- OpenCV Android SDK version `4.1.0`
- CMake version `3.10.2`
- Android NDK `20`
- LLDB `3.1`


If you'd like to run the project, just clone this repo.

Otherwise, the following instructions will guide through steps for OpenCV integration from a scratch.


OpenCV Integration
===

## Import `OpenCV` Project as your module

 1. Extract OpenCV SDK

 1. Open your Android Studio project.

 1. Right click your project -> `New` -> `Module` -> `Import Gradle Project`.

 1. Select `sdk/java` as a source directory.

 1. Uncheck `Replace jars with dependencies` and `Replace library sources with dependencies`.

## Modify `Build.gradle` from `module:openCV`
NOTE: This is from OpenCV project, not your app.

 1. Replace the following
```
apply plugin: 'com.android.application'
```
with
```
apply plugin: 'com.android.library'
```

 1. Remove the line with `applicationId` from `Build.gradle`.

 1. Add the following under `dependencies` section to `Build.gradle` from `module:app` (not OpenCV project)
```
dependencies {
    ...
    implementation project(':opencv')
}
```

## Copy over `so` files to your project.
Reference https://stackoverflow.com/questions/27406303/opencv-in-android-studio

 2. Copy `sdk/native/libs` folder to your Android project under 'app/src/main'

 2. Rename the copied folder to `jniLibs`

## Statically load OpenCV library into your application project

 3. Add the following to your Android activity (i.e. MainActivity.java)
```
static {
    System.loadLibrary("opencv_java4");
}
```
 3. Invalidate cache and rebuild the project
  3. Try if you can reference OpenCV package in your project and rebuild. The simple test is to just import one of OpenCV packages to your Android activity.
i.e.
```
import org.opencv.android.Core;
```



Compile and Integrate C/C++ to Android Studio Project via JNI (Java Native Interface)
===
This is required if you'd like to utilize or use OpenCV beyond Java API.
For instance, you'd like to do hardware-intensive task such as using a camera to capture image or video.
Facial detection is definitely one of those tasks.

JNI will bridge between your project's Android Java and OpenCV library's C/C++.


# TBA

* Recompile `detection_based_tracker`

** Open `build.gradle` under your `module:app` and add the following under `default config` section
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

** Copy over `sdk/jni/native` folder to your Android project's OpenCV folder under `native/jni`.


Motivation
===
This project is adapted from the actual Hackathon at work during the summer of 2019 (July 17 to July 19).
I did OpenCV integration into the existing `Unity-Android` project.
I just wanted to see if I could incorporate `OpenCV` into the project and learned the basic of facial detection and machine learning.
Although the project in this repo does not have Unity portion, it should give you a groundwork to build on top of it
and help avoiding spending too much times (mis) configure your project and search through StackOverflow and Google for the solution.


Authors & Contributors
===
[Nate Kemavaha](https://github.com/boyserk84) Author
