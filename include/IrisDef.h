/**
 * \file IrisDef.h
 */
#pragma once
#ifndef IRIS_DEFINITION_H__
#define IRIS_DEFINITION_H__

namespace iic
{
    /**Handle to abstract object/structure created by library.*/
    typedef void* IICHandle;

    /**
    * Enumerates all communication channel a device can support.
    */
    enum CommunicationChannel
    {
        COMM_CHANNEL_DEFAULT = 1,
        /**Control device through USB channel.*/
        COMM_CHANNEL_USB     = 1,
        /**Control device through UART channel.*/
        COMM_CHANNEL_UART    = 2,
        /**Control device through TCP_IP channel.*/
        COMM_CHANNEL_TCP_IP  = 4
    };

    /**
    * Enumerates all device attribute code a device can control.
    */
    enum DeviceAttributeControlCode
    {
        /**Read attribute value.*/
        ATTRIBUTE_CONTROL_GET        = 1,
        /**Write attribute value.*/
        ATTRIBUTE_CONTROL_SET        = 2,
        /**Generate/Regenerate attribute value.*/
        ATTRIBUTE_CONTROL_GENERATE   = 4
    };

    /**
    * Enumerates all device power option a device can support.
    */
    enum DevicePowerOption
    {
        /**Reboot device's operating system.
        Device connection will be dropped.
        It takes several seconds (about 5s) to have the rebooting device ready.
        User should use IIC_CloseDevice() to close the current device handle.
        To use device, user should scan and open it again to get new handle.*/
        DPO_REBOOT,

        /**Device sleep mode.
        Device connection will be dropped.
        Device's feature will not be accessible until it's is waked up.
        It takes several seconds (about 2s) to have complete this operation.
        User should use IIC_ControlPower() with option DPO_WAKEUP to the same
        device handle to wake up device and make it functions accessible.

        Calling IIC_CloseDevice() on slept device handle will make device
        impossible to access until it is restarted by replugging.*/
        DPO_SLEEP,

        /**Device wakeup after it has been put in standby mode.
        This operation must be done on the same device handle that was called
        with option DPO_SLEEP.
        */
        DPO_WAKEUP
    };

    /**
    * Enumerates all connection recovery option.
    */
    enum ConnectionRecoveryOption
    {
        /**Perform a USB port reset to reinitialize a device. The system will attempt
        * to restore the previous configuration and alternate settings after the
        * reset has completed.<br>
        *
        * If the reset fails, the descriptors change, or the previous state cannot be
        * restored, the device will appear to be disconnected and reconnected. This
        * means that the device handle is no longer valid (you should close it) and
        * rediscover the device. A return code of BERR_NOT_FOUND indicates
        * when this is the case.<br>
        *
        * This is a blocking operation which usually incurs a noticeable delay.
        */
        CONN_RO_RESET            = 0
    };

    /** 
     * Enumerates possible states of a capturing process.
     */
    enum CaptureStatus
    {
        /** No capturing process is active. */
        CAPTURE_STATUS_IDLE                 = 0,
        /** Images are streamed and evaluated on the fly, yet no qualified eye image is detected.*/
        CAPTURE_STATUS_READY                = 1,
        /** First eye image is detected, capturing  starts.*/
        CAPTURE_STATUS_CAPTURING            = 2,
        /** Capturing process completed successfully. */
        CAPTURE_STATUS_COMPLETE             = 3,
        /** Capturing process failed.*/
        CAPTURE_STATUS_FAILED_TO_CAPTURE    = 4,
        /** Capturing process has been canceled.*/
        CAPTURE_STATUS_ABORT                = 5
    };

    /** 
     * Timeout is starting to be counted when first qualified image is detected.
     * Depending on timeout mode, the moment of timeout is decided based on
     * either time passing or good frame count detected.
     */
    enum CaptureTimeoutMode
    {
        /**Time based mode*/
        CAPTURE_TIMEOUT_MODE_TIMEBASED  = 1,
        /**Frame based mode*/
        CAPTURE_TIMEOUT_MODE_FRAMEBASED = 2
    };

    /** 
     * Enumerates all control code of a capturing process.
     */
    enum CaptureControlCode
    {
        /**Stop ongoing capturing and discard captured images.*/
        CAPTURE_CONTROL_CANCEL                    = 0,
        /**Stop ongoing capturing but keep the captured images if any.*/
        CAPTURE_CONTROL_FORCE_FINISH              = 1,
        /**Discard current captured images and clear them from device memory.*/
        CAPTURE_CONTROL_CLEAR_SAMPLE              = 2,
        /**Start image evaluation & selection if capture mode is not
         *  auto capture that needs trigger action from operator to start
         *  image selection process.*/
        CAPTURE_CONTROL_START_IMAGE_SELECTION     = 3
    };

    /**
     * Enumerates all eye sides.
     */
    enum EyeSubtype
    {
        /**Unrecognized eye side.*/
        EYE_SUBTYPE_UNDEF = 0,
        /**Right eye side.*/
        EYE_SUBTYPE_RIGHT = 1,
        /**Left eye side.*/
        EYE_SUBTYPE_LEFT  = 2
    };

    /**
     * Enumerates all image formats.
     */
    enum ImageFormat
    {
        /**Unknown format*/
        IMAGE_FORMAT_UNKNOWN       = 0,
        /**Raw image format*/
        IMAGE_FORMAT_MONO_RAW      = 0x02,
        /**Mono JPEG image format*/
        IMAGE_FORMAT_MONO_JPEG     = 0x06,
        /**Mono JPEG2000 image format*/
        IMAGE_FORMAT_MONO_JPEG2000 = 0x0A,
        /**Mono PNG format*/
        IMAGE_FORMAT_MONO_PNG      = 0x0E
    };

    /**
     * Enumerates all additional image header.
     */
    enum AdditionalImageHeader
    {
        /**None*/
        ADDITIONAL_IMAGE_HEADER_NONE    = 0,
        /**IriTech proprietary format*/
        ADDITIONAL_IMAGE_HEADER_IRITECH = 1,
        /**ISO/IEC 19794-6:2005(E)*/
        ADDITIONAL_IMAGE_HEADER_ISO2005 = 2,
        /**ISO/IEC 19794-6:2011(E)*/
        ADDITIONAL_IMAGE_HEADER_ISO2011 = 4
    };

    /**
     * Enumerates all image kinds.
     */
    enum IrisImageKind
    {
        /**K1*/
        IRIS_IMAGE_KIND_K1 = 0x01,
        /**K2*/
        IRIS_IMAGE_KIND_K2 = 0x02,
        /**K3*/
        IRIS_IMAGE_KIND_K3 = 0x03,
        /**K7*/
        IRIS_IMAGE_KIND_K7 = 0x07
    };

    /**
     * Enumerates all compression criteria.
     */
    enum ImageCompressionCriteria
    {
        /**When iris image is cropped to get K3 or K7, user may expect
         *  the cropped image to have size nearest to a threshold, such as:
         *  1.5KB, 2.5KB, 3.5KB, 5.0KB, 7.0KB, 10.0KB*/
        IMAGE_COMPRESSION_CRITERIA_BY_SIZE      = 0,
        /**Image quality in range of [1-100]*/
        IMAGE_COMPRESSION_CRITERIA_BY_QUALITY   = 1
    };

    /**
     * Enumerates all iris scanner capability.
     */
    enum IrisScannerCapability
    {
        /**Iris scanner monocular*/
        IRIS_SCANNER_MONOCULAR = (1 << 0),
        /**Iris scanner binocular*/
        IRIS_SCANNER_BINOCULAR = (1 << 1),
        /**Iris scanner face eyes*/
        IRIS_SCANNER_FACE_EYES = (1 << 2) | IRIS_SCANNER_BINOCULAR
    };

    /**
     * Index of iris quality metric in the corresponding metric array.
     */
    enum ImageQualityMetricIndex
    {
        /**Total score*/
        IRIS_QM_TOTAL_SCORE         = 0,
        /**Usable area*/
        IRIS_QM_USABLE_AREA         = 1,
        /**Lower usable area*/
        IRIS_QM_LOWER_USABLE_AREA   = 2
    };
} //namespace

#endif //IRIS_DEFINITION_H__
