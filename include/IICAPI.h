/**
 * \file IICAPI.h
 */
#pragma once
#ifndef IRITECH_IRIS_CAMERA_API_H_
#define IRITECH_IRIS_CAMERA_API_H_
#include "CapturingEventCallback.h"
#include "IrisDef.h"
#include "IndicatingLED.h"
#include "DeviceAttribute.h"

#ifdef __ANDROID__
#include <android/native_window.h>
#endif

// The following ifdef block is the standard way of creating macros which make
// exporting from a DLL simpler. All files within this DLL are compiled with
// the IICAPI_EXPORT symbol defined on the command line.
// This symbol should not be defined on any project that uses this DLL.
// This way any other project whose source files include this file see
// IICAPI functions as being imported from a DLL, whereas this DLL
// sees symbols defined with this macro as being exported.
#ifndef DOXYGEN_SHOULD_SKIP_THIS
#if defined(_WIN32) || defined(WIN32)
#   ifdef IICAPI_EXPORT
#       define IICAPI __declspec(dllexport)
#   else
#       define IICAPI __declspec(dllimport)
#   endif
#else //Unix/Linux
#   define IICAPI __attribute__ ((visibility ("default")))
#endif

#ifdef __cplusplus
extern "C" {
#endif
#endif /* DOXYGEN_SHOULD_SKIP_THIS */


//General rule for all APIs returning integer as error code:
//  0: if method succeeded
//  non-zero: method failed, returned value is the error code
//    defined in BaseError.h

/**
 * Get library version which is encoded following way: <br>
 * 1 highest order byte for major version, next byte for minor version and the 
 * two lowest order bytes for revision.<br>
 * (major << 24) | (minor << 16) | (revision)
 *
 * @return The return value includes the major and minor version numbers of the 
 *   SDK in the higher-order word, and information about build number in the 
 *   lower-order word. The lower-order byte of the higher-order word specifies the 
 *   major version number, in decimal notation. The lower-order byte of this word 
 *   specifies the minor version number, in decimal notation.
 *
 * @see IIC_GetLibDescription()
 */
IICAPI int IIC_GetLibVersion();

/**
 * Get library description string.
 *
 * @return Return a constant NULL-terminated string contain library description.
 *
 * @see IIC_GetLibVersion()
 */
IICAPI const char* IIC_GetLibDescription();

/**
 * Init all pre-conditions for working with library.
 *
 * @return Returns BERR_OK value indicates success. All other values indicate failure.
 *
 * @see BaseError, IIC_Deinit()
 */
IICAPI int IIC_Init();

/**
 * Finalize all resources prepared by IIC_Init().<br>
 * This API should be call last when all works with library finish.
 *
 * @see BaseError, IIC_Init()
 */
IICAPI void IIC_Deinit();

/**
* Returns a constant NULL-terminated string with the ASCII name of a 
* library error code. The caller must treat returned string as
* read only data. Do not modify or free it!
*
* @param [in] errorCode One of error code value defined in BaseError.h
*
* @return Returns the error name, or the string "UNDEFINED ERROR" if the value of
*    errorCode is not a known error.
*
* @see BaseError, IIC_GetLibVersion()
*/
IICAPI const char* IIC_GetErrorName(int errorCode);

/**
* Scan list of available iris cameras connected to host via the given 
* communication channel type.
*
* @param [in] channel One of the value enumerated in the 
*    CommunicationChannel enum.
* @param [out] deviceUri Array of string to be filled with uri(s) of devices.
* @param [in] uriMaxCount The maximum items allowed in the "deviceUri" array.
* @param [out] uriCount The number of uri(s) filled in the "deviceUri" array.
*
* @return Returns BERR_OK value indicates success. All other values indicate failure.
*
* @see BaseError, CommunicationChannel, IIC_OpenDevice()
*/
IICAPI int IIC_ScanDevices(
    iic::CommunicationChannel channel,
    char deviceUri[][256],
    int uriMaxCount,
    int* uriCount);

/**
* Open a handle to device to control it later.
*
* @param [in] deviceUri The uri representing device location.
* @param [in] options (optional, reserved for future use): user should pass NULL.
*    NULL terminated list of (option name, option value) pairs that
*    specify optional configuration parameters for the opened device.
* @param [out] hDevice The device handle value received.
*
* @return Returns BERR_OK value indicates success. All other values indicate failure.
*
* @see BaseError, IIC_CloseDevice()
*/
#ifdef __ANDROID__
IICAPI int IIC_OpenDevice(
    int vid,
    int pid,
    int fd,
    int busNum,
    int devAddr,
    const char *usbfs,
    const char* options[],
    ANativeWindow *previewWindow,
    iic::IICHandle* hDevice);
#else
IICAPI int IIC_OpenDevice(
    const char* deviceUri,
    const char* options[],
    iic::IICHandle* hDevice);
#endif
/**
* Close existing device handle to finish working with it.<br>
*    Caller shall make sure ongoing capturing is stopped via IIC_StopCapture()
*    before calling this method.
*
* @param [in] hDevice A handle to the device on which the operation is to be performed.
*
* @return Returns BERR_OK value indicates success. All other values indicate failure.
*
* @see BaseError, IIC_OpenDevice()
*/
IICAPI void IIC_CloseDevice(iic::IICHandle hDevice);

/**
* Send new firmware to device to do firmware update later.
*
* @param [in] hDevice A handle to the device on which the operation is to be performed.
* @param [in] firmwareData A pointer to the input buffer that contains firmware data.
* @param [in] firmwareLen Firmware data length in bytes.
*
* @return Returns BERR_OK value indicates success. All other values indicate failure.
*
* @see BaseError, IIC_ControlPower()
*/
IICAPI int IIC_UploadFirmware(
    iic::IICHandle hDevice,
    const void* firmwareData,
    int firmwareLen);

/**
* Control power option of the opened device.
*
* @param [in] hDevice A handle to the device on which the operation is to be performed.
* @param [in] powerOption The operation code to be performed.
* @param [in] optionalDelayTime The delay time (if being implemented, in mili-seconds).
*
* @return Returns BERR_OK value indicates success. All other values indicate failure.
*
* @see BaseError, DevicePowerOption, IIC_UploadFirmware()
*/
IICAPI int IIC_ControlPower(
    iic::IICHandle hDevice,
    iic::DevicePowerOption powerOption,
    int optionalDelayTime);

/**
* Method to recover device connection from errors. It may or may not
* work depending on the type of error happened to connection.
*
* @param [in] hDevice A handle to the device on which the operation is to be performed.
* @param [in] recoveryOption The recovery code to be performed.
*
* @return Returns BERR_OK value indicates success. All other values indicate failure.
*
* @see BaseError, ConnectionRecoveryOption, IIC_UploadFirmware()
*/
IICAPI int IIC_RecoverConnection(
    iic::IICHandle hDevice,
    iic::ConnectionRecoveryOption recoveryOption);

/**
* Get, set or generate a device attribute based on attribute ID.
*
* @param [in] hDevice A handle to the device on which the operation is to be performed.
* @param [in] controlCode The control code for the operation to be performed.<br>
*    The documentation for each control code provides usage details for the
*    inputBuffer, inputBufferSize, outputBuffer, and outputBufferSize parameters.
* @param [in] attID The attribute to be controlled by this operation.
* @param [in] inputBuffer (optional)A pointer to the input buffer that contains the data 
*    required to perform the operation. The format of this data depends on the 
*   .value of the controlCode parameter.<br>
*    This parameter can be NULL if controlCode specifies an operation that does not 
*    require input data.
* @param [in] inputBufferSize The size of the input buffer, in bytes.
* @param [out] outputBuffer (optional)A pointer to the output buffer that is to receive the data 
*    returned by the operation. The format of this data depends on the value of the
*    controlCode parameter.<br>
*    This parameter can be NULL if controlCode specifies an operation that does not return data.
* @param [in] outputBufferSize The size of the output buffer, in bytes.
* @param [out] outputLen (optional)A pointer to a variable that receives the size of the data stored 
*    in the output buffer, in bytes.<br>
*    If the output buffer is not enough to receive all of the data, the call fails with 
*    error BERR_MEM_SIZE, and outputLen contains the needed buffer size.
*
* @return Returns BERR_OK value indicates success. All other values indicate failure.
*
* @see BaseError, DeviceAttributeControlCode, IIC_StartCapturing()
*/
IICAPI int IIC_ControlAttribute(
    iic::IICHandle hDevice,
    iic::DeviceAttributeControlCode controlCode,
    iic::AttributeID attID,
    const void* inputBuffer,
    int inputBufferSize,
#ifdef __ANDROID__
    ANativeWindow *previewWindow,
#endif
    void* outputBuffer,
    int outputBufferSize,
    int* outputLen);

/**
* Start a capturing process inside iris camera.
*
* @param [in] hDevice A handle to the device on which the operation is to be performed.
* @param [in] eyeSelection The eye subtypes to be captured.<br>
*    For monocular iris captured device, it must be EYE_SUBTYPE_UNDEF.<br>
*    For binocular iris captured device, it shall be either:<br>
*    + (EYE_SUBTYPE_UNDEF) to capture both eyes.<br>
*    + (EYE_SUBTYPE_RIGHT) to capture right iris.<br>
*    + (EYE_SUBTYPE_LEFT) to capture left iris.
* @param [in] timeoutMode The time-out mode for the capturing.
* @param [in] timeoutParam The time-out value in seconds or frame count, depending on time-out mode.
* @param [in] autoLEDControl The device will control LED indicators in its default scheme.<br>
*    Non zero values for true - auto LED control.<br>
*    Zero value for false - non auto LED control.
* @param [in] autoCapture Whether device will automatically start image evaluation & selection.<br>
*    Zero value: device waits for capture control code (CAPTURE_CONTROL_START_IMAGE_SELECTION)
*    being sent through IIC_ControlCapture() to start that process.<br>
*    Non zero values: device automatically starts that process.
* @param [in] callbackOption (optional)The callback to receive capturing events (error, status, streaming image...)
*
* @return Returns BERR_OK value indicates success. All other values indicate failure.
*
* @see BaseError, EyeSubtype, CaptureTimeoutMode, CaptureCallbackOption, IIC_ControlCapture()
*/
IICAPI int IIC_StartCapturing(
    iic::IICHandle hDevice,
    iic::EyeSubtype eyeSelection,
    iic::CaptureTimeoutMode timeoutMode,
    int timeoutParam,
    int autoLEDControl,
    int autoCapture,
    const struct iic::CaptureCallbackOption* callbackOption
#ifdef __ANDROID__
    , ANativeWindow *previewWindow = NULL
#endif
    );

/**
* Control the ongoing capturing process.
*
* @param [in] hDevice A handle to the device on which the operation is to be performed.
* @param [in] option One of the values of the CaptureControlCode enum.
*
* @return Returns BERR_OK value indicates success. All other values indicate failure.
*
* @see BaseError, CaptureControlCode, IIC_GetCapturingStatus()
*/
IICAPI int IIC_ControlCapture(
    iic::IICHandle hDevice,
    iic::CaptureControlCode option);

/**
* Query the capturing status.
*
* @param [in] hDevice A handle to the device on which the operation is to be performed.
* @param [out] captureStatus A pointer to a variable which holds current status of capturing process.
*
* @return Returns BERR_OK value indicates success. All other values indicate failure.
*
* @see BaseError, CaptureStatus, IIC_GetStreamingImages()
*/
IICAPI int IIC_GetCapturingStatus(
    iic::IICHandle hDevice,
    iic::CaptureStatus* captureStatus);

/**
* Query the streaming images (e.g for display purpose).
*
* @param [in] hDevice A handle to the device on which the operation is to be performed.
* @param [in] imageDownscaleFactor Each dimension (width, height) reduced by factor times (1,2,4,8,16,32).
* @param [in] requestStreamingImageFormat Either RAW | JPEG.
* @param [in] requestStreamingImageCompressionQuality Value in range [1, 100]. Higher 
*    values mean higher image size, higher image quality.
* @param [out] captureStatus A pointer to a variable which holds current status of capturing process.
* @param [out] imageCount A pointer to a variable which holds the number of streaming images received.
* @param [out] imageFormat A pointer to a variable which holds the format of streaming image received.
* @param [out] eyeSubtypes An array of eye subtype value for the streaming image(s) received.
* @param [out] imageData An array of streaming image(s)'s content.
* @param [out] imageLength An array of image(s)'s size information.
* @param [out] imageWidth An array of image(s)'s width information.
* @param [out] imageHeight An array of image(s)'s height information.
*
* @return Returns BERR_OK value indicates success. All other values indicate failure.
*
* @see BaseError, ImageFormat, CaptureStatus, ImageFormat, EyeSubtype, IIC_GetResultImage()
*/
IICAPI int IIC_GetStreamingImages(
    iic::IICHandle hDevice,
    int imageDownscaleFactor,
    iic::ImageFormat requestStreamingImageFormat,
    int requestStreamingImageCompressionQuality,
    iic::CaptureStatus* captureStatus,
    int* imageCount,
    iic::ImageFormat* imageFormat,
    iic::EyeSubtype eyeSubtypes[2],
    const unsigned char* imageData[2],
    int imageLength[2],
    int imageWidth[2],
    int imageHeight[2]);

/**
* Query the image selected by capturing process.
*
* @param [in] hDevice A handle to the device on which the operation is to be performed.
* @param [in] subtype Get the result image of the corresponding eye subtype input.
* @param [in] imageHeader Requested additional header of the result image.
* @param [in] fillImageQualityScore Whether iris image quality score will be computed
*    and filled to the requested image header type. This option when turned on
*    take extra times (300 - 800ms) so please use with consideration.
* @param [in] imageFormat Requested format of the result image.
* @param [in] imageKind Requested kind of the result image.
* @param [in] imageCompressionCriteria Compressed by SIZE|QUALITY.
* @param [in] imageCompressionValue If image is compressed by quality criteria, 
*    input value in range [1-100].<br>
*    Higher values mean higher image quality and size, lower compression level.<br>
*    If image is compressed by size criteria, input the desired image size in bytes.<br>
*    Zero or negative values are meant for maximum image size.
* @param [out] imageData A pointer to a variable which holds the content of the result image.
* @param [out] imageLength A pointer to a variable which holds image size.
* @param [out] imageWidth A pointer to a variable which holds image width.
* @param [out] imageHeight A pointer to a variable which holds image height.
*
* @return Returns BERR_OK value indicates success. All other values indicate failure.
*
* @see BaseError, EyeSubtype, AdditionalImageHeader, ImageFormat, IrisImageKind, 
*    ImageCompressionCriteria, IIC_GetResultImageQuality()
*/
IICAPI int IIC_GetResultImage(
    iic::IICHandle hDevice,
    iic::EyeSubtype subtype,
    iic::AdditionalImageHeader imageHeader,
    int fillImageQualityScore,
    iic::ImageFormat imageFormat,
    iic::IrisImageKind imageKind,
    iic::ImageCompressionCriteria imageCompressionCriteria,
    int imageCompressionValue,
    const unsigned char** imageData,
    int* imageLength,
    int* imageWidth,
    int* imageHeight
#ifdef __ANDROID__
    , ANativeWindow *previewWindow = NULL
#endif
    );

/**
* Get quality metrics from the image selected by capturing process.
*
* @param [in] hDevice A handle to the device on which the operation is to be performed.
* @param [in] eyeSubtype Get the image quality of the corresponding eye subtype input.
* @param [out] qualityMetrics The byte array to receive quality metrics, at least 3 elements.<br>
*    Refer to ImageQualityMetricIndex enumeration to see position of each metric
*    filled in this array.
* @param [in] maxMetricCount Size of qualityMetrics metric array.
* @param [out] metricCount The number of metrics get filled in the qualityMetrics array.
*
* @return Returns BERR_OK value indicates success. All other values indicate failure.
*
* @see BaseError, EyeSubtype, IIC_GetResultImage()
*/
IICAPI int IIC_GetResultImageQuality(
    iic::IICHandle hDevice,
    iic::EyeSubtype eyeSubtype,
    unsigned char qualityMetrics[3],
    int maxMetricCount,
    int* metricCount);

/**
* Control on/off and blinking of the iris camera LED.
*
* @param [in] hDevice A handle to the device on which the operation is to be performed.
* @param [in] ledID ID of the LED to be controlled.
* @param [in] lightingOn Whether turn on/off LED.<br>
*    zero: turn on LED.<br>
*    non-zero: turn off LED.
* @param [in] duration The time period in millisecond of this LED controlling operation if
*    'lightingOn' is non-zero.
* @param [in] blinkingOn Whether the LED is blinking or constantly lighting.<br>
*    zero: constantly lighting.<br>
*....non-zero: blinking.
* @param [in] blinkingHalfCycle If 'blinkingOn' is non-zero, the LED will be on/off
*    alternatively in time period decided by this parameter.
*
* @return Returns BERR_OK value indicates success. All other values indicate failure.
*
* @see BaseError, IndicatingLedID, LEDStatus, IIC_GetResultImage()
*/
IICAPI int IIC_ControlLED(
    iic::IICHandle hDevice,
    iic::IndicatingLedID ledID,
    iic::LEDStatus lightingOn,
    int duration,
    int blinkingOn,
    int blinkingHalfCycle);

#ifdef __cplusplus
}
#endif

#endif //IRITECH_IRIS_CAMERA_API_H_
