/**
 * \file DeviceAttribute.h
 */
#pragma once
#ifndef IRIS_CAMERA_ATTRIBUTES_H_
#ifndef DOXYGEN_SHOULD_SKIP_THIS
#define IRIS_CAMERA_ATTRIBUTES_H_
#endif /* DOXYGEN_SHOULD_SKIP_THIS */

/** Input and output buffer containing integer value must be encoded in
    big-endian byte order.*/
#define ATTRIBUTE_TYPE_INT         0

/**BLOB is used for storing binary data.*/
#define ATTRIBUTE_TYPE_BLOB        10000

/** String is used for storing text data.*/
#define ATTRIBUTE_TYPE_STRING      10000

/**Attribute ID value = type value + input number*/
#define DECLARE_ATTRIBUTE_ID(name, type, number) \
    ATTRIBUTE_ID_##name = ATTRIBUTE_TYPE_##type + number

namespace iic
{
/**
* Enumerates all attribute ID of the device.
*/
enum
{
    /**
    - Name: ATTRIBUTE_ID_PRODUCT_NAME.
    - Type: string.
    - Description: product name of the device being used.
    - Access permission: read-only.
    */
    DECLARE_ATTRIBUTE_ID(PRODUCT_NAME, STRING, 1),

    /**
    - Name: ATTRIBUTE_ID_MANUFACTURER_NAME.
    - Type: string.
    - Description: manufacturer name of the device being used.
    - Access permission: read-only.
    */
    DECLARE_ATTRIBUTE_ID(MANUFACTURER_NAME, STRING, 2),

    /**
    - Name: ATTRIBUTE_ID_DEVICE_SERIAL.
    - Type: string.
    - Description: serial number of the device being used. Serial length is
    normally 16 characters.
    - Access permission: read-only; only manufacturer can write.
    */
    DECLARE_ATTRIBUTE_ID(DEVICE_SERIAL, STRING, 3),

    /**
    - Name: ATTRIBUTE_ID_MFG_DATE.
    - Type: string.
    - Description: manufacturing date of the device being used.
    Format: "YYYY-MM-DD".
    - Access permission: read-only; only manufacturer can write.
    */
    DECLARE_ATTRIBUTE_ID(MFG_DATE, STRING, 4),

    /**
    - Name: ATTRIBUTE_ID_FIRMWARE_VERSION_NUMBER
    - Type: integer.
    - Description: firmware version encoded in number of the device being used.
    An integer having 1 higher order byte for major version, 1 lower byte for minor version, last 2 lower order 
    bytes for revision number: i.e 0x01010001 means version 1.1.1
    - Access permission: read-only.
    */
    DECLARE_ATTRIBUTE_ID(FIRMWARE_VERSION_NUMBER, INT, 5),

    /**
    - Name: ATTRIBUTE_ID_FIRMWARE_VERSION.
    - Type: string.
    - Description: firmware version of the device being used.
    - Access permission: read-only.
    */
    DECLARE_ATTRIBUTE_ID(FIRMWARE_VERSION, STRING, 6),

    /**
    - Name: ATTRIBUTE_ID_DEVICE_CAPABILITY.
    - Type: integer.
    - Description: integer value of corresponding IrisScannerCapability
    enumeration representing capability of device being used.
    - Access permission: read-only.
    */
    DECLARE_ATTRIBUTE_ID(DEVICE_CAPABILITY, INT, 7),

    /**
    - Name: ATTRIBUTE_ID_IRIS_EXTRACTOR_ALG_PROVIDER.
    - Type: string.
    - Description: name of iris extractor algorithm's provider.
    - Access permission: read-only.
    */
    DECLARE_ATTRIBUTE_ID(IRIS_EXTRACTOR_ALG_PROVIDER, STRING, 8),

    /**
    - Name: ATTRIBUTE_ID_IRIS_EXTRACTOR_ALG_VERSION.
    - Type: string.
    - Description: version of iris extractor algorithm.
    - Access permission: read-only.
    */
    DECLARE_ATTRIBUTE_ID(IRIS_EXTRACTOR_ALG_VERSION, STRING, 9),

    /**
    - Name: ATTRIBUTE_ID_MFG_SITE.
    - Type: string.
    - Description: country code of manufacturing site, i.e: 001 - US, 082 - Korea
    - Access permission: read-only; only manufacturer can write.
    */
    DECLARE_ATTRIBUTE_ID(MFG_SITE, STRING, 10),

    /**
    - Name: ATTRIBUTE_ID_PCB_VERSION.
    - Type: string.
    - Description: PCB version.
    Format XX.xx: major & minor number
    - Access permission: read-only; only manufacturer can write.
    */
    DECLARE_ATTRIBUTE_ID(PCB_VERSION, STRING, 11),

    /**
    - Name: ATTRIBUTE_ID_PBA_VERSION.
    - Type: string.
    - Description: PBA version.
    Format XX.xx: major & minor number
    - Access permission: read-only; only manufacturer can write.
    */
    DECLARE_ATTRIBUTE_ID(PBA_VERSION, STRING, 12),

    /**
    - Name: ATTRIBUTE_ID_CAMERA_MODULE_VERSION.
    - Type: string.
    - Description: device's camera hardware module version.
    Format XX.xx: major & minor number
    - Access permission: read-only; only manufacturer can write.
    */
    DECLARE_ATTRIBUTE_ID(CAMERA_MODULE_VERSION, STRING, 13),

    /**
    - Name: ATTRIBUTE_ID_KERNEL_VERSION_NUMBER
    - Type: integer.
    - Description: kernel version encoded in number of the device being used.
    An integer having 1 higher order bytes for major version, 1 lower order 
    bytes for minor version, last 2 bytes for revision: i.e 0x05040007 means version 5.4.7.
    - Access permission: read-only.
    */
    DECLARE_ATTRIBUTE_ID(KERNEL_VERSION_NUMBER, INT, 14),

    /**
    - Name: ATTRIBUTE_ID_KERNEL_VERSION_STRING.
    - Type: string.
    - Description: kernel version string of the device being used.
    - Access permission: read-only.
    */
    DECLARE_ATTRIBUTE_ID(KERNEL_VERSION_STRING, STRING, 15),

    /**
    - Name: ATTRIBUTE_ID_TOTAL_SENSOR_IMAGE.
    - Type: integer.
    - Description: total images from device's image sensor to its internal image capture program in a capturing session.
    - Access permission: read-only.
    */
    DECLARE_ATTRIBUTE_ID(TOTAL_SENSOR_IMAGE, INT, 16),

    /**
    - Name: ATTRIBUTE_ID_TOTAL_EVALUATED_IMAGE.
    - Type: integer.
    - Description: total images being evaluated in a capturing session.
    - Access permission: read-only.
    */
    DECLARE_ATTRIBUTE_ID(TOTAL_EVALUATED_IMAGE, INT, 17),

    /**
    - Name: ATTRIBUTE_ID_TOTAL_BASIC_QUALIFIED_IMAGE.
    - Type: integer.
    - Description: device's image evaluation and selection speed (frames per second).
    - Access permission: read-only.
    */
    DECLARE_ATTRIBUTE_ID(TOTAL_BASIC_QUALIFIED_IMAGE, INT, 18),

    /**
    - Name: ATTRIBUTE_ID_IMAGE_SENSOR_SPEED.
    - Type: integer.
    - Description: speed (frames per second) of images streaming from device's sensor to its internal image capture program.
    - Access permission: read-only.
    */
    DECLARE_ATTRIBUTE_ID(IMAGE_SENSOR_SPEED, INT, 19),

    /**
    - Name: ATTRIBUTE_ID_IMAGE_EVALUATION_SPEED.
    - Type: integer.
    - Description: device's image evaluation and selection speed (frames per second).
    - Access permission: read-only.
    */
    DECLARE_ATTRIBUTE_ID(IMAGE_EVALUATION_SPEED, INT, 20),

    /**
    - Name: ATTRIBUTE_ID_IMAGE_PREVIEW_SPEED.
    - Type: integer.
    - Description: preview speed (frames per second) of images streaming from device to host.
    - Access permission: read-only.
    */
    DECLARE_ATTRIBUTE_ID(IMAGE_PREVIEW_SPEED, INT, 21),

    /**
    - Name: ATTRIBUTE_ID_TOTAL_CAPTURE_PROCESS_TIME.
    - Type: integer.
    - Description: time (in millisecond) in device from receiving start capture command to finish selecting best image for the capture session.
    - Access permission: read-only.
    */
    DECLARE_ATTRIBUTE_ID(TOTAL_CAPTURE_PROCESS_TIME, INT, 22),

    /**
    - Name: ATTRIBUTE_ID_DEVICE_CONFIG_VERSION.
    - Type: integer.
    - Description: 4 lowest bits is config layout version, next 4 higher bits is config data version.
    - Access permission: read-only.
    */
    DECLARE_ATTRIBUTE_ID(DEVICE_CONFIG_VERSION, INT, 23)
};

/**Attribute ID of device to control.*/
typedef int AttributeID;

} //namespace
#endif //IRIS_CAMERA_ATTRIBUTES_H_
