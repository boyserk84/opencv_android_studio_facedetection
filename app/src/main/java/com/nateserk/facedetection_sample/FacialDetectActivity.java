package com.nateserk.facedetection_sample;

import androidx.appcompat.app.AppCompatActivity;

import android.os.Bundle;
import android.util.Log;

import org.opencv.android.CameraBridgeViewBase;
import org.opencv.core.Mat;

/**
 * FacialDetectActivity.java
 *
 * Handle all facial detection (and possibly recognition) within this activity.
 */
public class FacialDetectActivity extends AppCompatActivity implements CameraBridgeViewBase.CvCameraViewListener2 {
    static{
        System.loadLibrary("opencv_java4");
    }

    public static final String TAG = "FacialDetectActivity";
    public static final int ACTIVITY_CODE = 1;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        Log.d(TAG, "onCreate is called!");

        setContentView(R.layout.activity_facial_detect);
    }

    @Override
    public void onCameraViewStarted(int width, int height) {
        Log.d(TAG, "CameraView has started!");
    }

    @Override
    public Mat onCameraFrame(CameraBridgeViewBase.CvCameraViewFrame inputFrame) {
        return null;
    }

    @Override
    public void onCameraViewStopped() {
        Log.d(TAG, "CameraView has stopped!");
    }
}
