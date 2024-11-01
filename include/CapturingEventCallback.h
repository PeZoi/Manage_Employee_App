/**
 * \file CapturingEventCallback.h
 */
#pragma once
#ifndef IRIS_CAPTURING_EVENT_CALLBACK_H__
#define IRIS_CAPTURING_EVENT_CALLBACK_H__
#ifndef DOXYGEN_SHOULD_SKIP_THIS
#ifndef _WIN32
#define __cdecl __attribute__((cdecl))
#endif
#endif /* DOXYGEN_SHOULD_SKIP_THIS */

#include "IrisDef.h"

namespace iic
{
    /**
    * Defines a call-back method, namely invoke, that processes information sent from 
    * internal capturing process.<br>
    * When StartCapture is called with a non-<CODE>null</CODE> CapturingEventCallback, 
    * a thread is activated to automatically query events from the capturing process 
    * inside the device.<br>
    * Whenever there is any new streaming image, capturing status or error, invoke is 
    * called with relevant events passed to it.<br>
    *
    * @param [in] callbackParam Callback parameter registered together with callback function.
    * @param [out] error Report error code if that happens.
    * @param [out] captureStatus Current capture status.
    * @param [out] imageCount The number of streaming images received.
    * @param [out] imageFormat The format of streaming image.
    * @param [out] eyeSubtypes The eye label for each image.
    * @param [out] imageData The image data of each one.
    * @param [out] imageLen The image length of each one.
    * @param [out] imageWidth The image width of each one.
    * @param [out] imageHeight The image height of each one.
    *
    * @see CaptureStatus, ImageFormat, EyeSubtype
    */
    typedef void (__cdecl *CapturingEventCallback)(
        void* callbackParam,              //callback parameter registered together with callback function.
        int* error,                       //report error code if that happens
        iic::CaptureStatus* captureStatus,//report current capture status
        int imageCount,                   //report number of streaming images received
        iic::ImageFormat imageFormat,     //format of streaming image
        iic::EyeSubtype eyeSubtypes[],    //eye label for each image
        const unsigned char* imageData[], //image data of each one
        int imageLen[],                   //image length of each one
        int imageWidth[],                 //image width of each one
        int imageHeight[]                 //image height of each one
        );

    /**CaptureCallbackOption struct*/
    struct CaptureCallbackOption
    {
        /**Capturing event callback method*/
        CapturingEventCallback cbMethod;
        /**Callback parameter*/
        void* cbParam;
        /**Non-zero value for registering to receive streaming images*/
        int receiveStreamingImage;
        /**Factor for downscale streaming image to have smaller dimension*/
        int imageDownscaleFactor;
        /**Desired format of streaming image (e.g RAW or JPEG)*/
        iic::ImageFormat streamingImageFormat;
        /**Quality of compressed streaming image, in scale [1, 100]*/
        int streamingImageCompressionQuality;
        /**Max frame rate of streaming images, in range [1, 30]; the actual frame rate may be lower than the requested value.*/
        int maxFrameRate;
    };

} //namespace

#endif //IRIS_CAPTURING_EVENT_CALLBACK_H__
