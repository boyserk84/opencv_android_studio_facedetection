//
// Created by Nate K on 2019-07-21.
//
#include <jni.h>
/* Header for class com_nateserk_facedetection_sample_DetectionBasedTracker */

#ifndef FACEDETECTION_DETECTIONBASEDTRACKER_JNI_H
#define FACEDETECTION_DETECTIONBASEDTRACKER_JNI_H
#ifdef __cplusplus
extern "C" {
#endif
/*
 * Class:     com_nateserk_facedetection_sample_DetectionBasedTracker
 * Method:    nativeCreateObject
 * Signature: (Ljava/lang/String;F)J
 */
JNIEXPORT jlong JNICALL Java_com_nateserk_facedetection_sample_DetectionBasedTracker_nativeCreateObject
  (JNIEnv *, jclass, jstring, jint);

/*
 * Class:     com_nateserk_facedetection_sample_DetectionBasedTracker
 * Method:    nativeDestroyObject
 * Signature: (J)V
 */
JNIEXPORT void JNICALL Java_com_nateserk_facedetection_sample_DetectionBasedTracker_nativeDestroyObject
  (JNIEnv *, jclass, jlong);

/*
 * Class:     com_nateserk_facedetection_sample_DetectionBasedTracker
 * Method:    nativeStart
 * Signature: (J)V
 */
JNIEXPORT void JNICALL Java_com_nateserk_facedetection_sample_DetectionBasedTracker_nativeStart
  (JNIEnv *, jclass, jlong);

/*
 * Class:     com_nateserk_facedetection_sample_DetectionBasedTracker
 * Method:    nativeStop
 * Signature: (J)V
 */
JNIEXPORT void JNICALL Java_com_nateserk_facedetection_sample_DetectionBasedTracker_nativeStop
  (JNIEnv *, jclass, jlong);

  /*
   * Class:     com_nateserk_facedetection_sample_DetectionBasedTracker
   * Method:    nativeSetFaceSize
   * Signature: (JI)V
   */
  JNIEXPORT void JNICALL Java_com_nateserk_facedetection_sample_DetectionBasedTracker_nativeSetFaceSize
  (JNIEnv *, jclass, jlong, jint);

/*
 * Class:     com_nateserk_facedetection_sample_DetectionBasedTracker
 * Method:    nativeDetect
 * Signature: (JJJ)V
 */
JNIEXPORT void JNICALL Java_com_nateserk_facedetection_sample_DetectionBasedTracker_nativeDetect
  (JNIEnv *, jclass, jlong, jlong, jlong);

#ifdef __cplusplus
}
#endif
#endif //FACEDETECTION_DETECTIONBASEDTRACKER_JNI_H