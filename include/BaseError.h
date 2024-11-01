/**
 * \file BaseError.h
 */
#pragma once
#ifndef COMMON_BASE_ERROR_DEF_H__
#ifndef DOXYGEN_SHOULD_SKIP_THIS
#define COMMON_BASE_ERROR_DEF_H__
#endif /* DOXYGEN_SHOULD_SKIP_THIS */

namespace iic{
/*
Idea:
  - This error enumeration give name to as much errors as possible happening
  in all kind of modules.
  - Errors is divided to group of similar characteristic.
  - Base errors use 2 lower bytes of integer 4 bytes type for error code
  - Extended error information is encoded in 2 higher bytes.
  Designed & assigned by each module.
    http://www-numi.fnal.gov/offline_software/srt_public_context/WebDocs/Errors/unix_system_errors.html
*/
/**Enumeration all errors possible happening.*/
enum BaseError
{
    /**Success (no error) */
    BERR_OK                                 = 0,

    /**Other error */
    BERR_FAILED                             = 1,

    /**Invalid parameter */
    BERR_INVALID_PARAM                      = 2,

    /**Given memory size is insufficient */
    BERR_MEM_SIZE                           = 3,

    /**Failed to allocate memory */
    BERR_NO_MEM                             = 4,

    /**Resource busy */
    BERR_BUSY                               = 5,

    /**Operation timeout */
    BERR_TIMEOUT                            = 6,

    /**Overflow */
    BERR_OVERFLOW                           = 7,

    /**Pipe error */
    BERR_PIPE                               = 8,

    /**System call interrupted (perhaps due to signal) */
    BERR_INTERRUPTED                        = 9,

    /**Connection disconnected */
    BERR_DISCONNECTED                       = 10,

    /**Input/output error */
    BERR_IO                                 = 11,

    /**Error create/read/write file */
    BERR_FILE_IO                            = 12,

    /**Access denied (insufficient permissions) */
    BERR_ACCESS                             = 13,

    /**Can not access a needed library */
    BERR_LIB_ACCESS                         = 14,

    /**Cannot access a needed service */
    BERR_SERVICE_ACCESS                     = 15,

    /**Resource not exist */
    BERR_NO_DATA                            = 16,

    /**Resource already exists */
    BERR_ALREADY_EXISTS                     = 17,

    /**No such device (it may have been disconnected) */
    BERR_NO_DEVICE                          = 18,

    /**Entity not found */
    BERR_NOT_FOUND                          = 19,

    /**Operation not supported or unimplemented on this platform */
    BERR_NOT_SUPPORTED                      = 20,

    /**Data size is not suitable (may be too big/long) */
    BERR_DATA_SIZE                          = 21,

    /**Data format is not correct */
    BERR_DATA_FORMAT                        = 22,

    /**Error in data encryption */
    BERR_ENCRYPTION                         = 23,

    /**Error in data decryption */
    BERR_DECRYPTION                         = 24,

    /**Error in signature validation */
    BERR_SIGNATURE                          = 25,

    /**Version incompatible */
    BERR_UNSUPPORTED_VERSION                = 26,

    /**Command unsupported */
    BERR_UNSUPPORTED_COMMAND                = 27,

    /**Command data invalid */
    BERR_INVALID_COMMAND_DATA               = 28,

    /**Image format unsupported */
    BERR_UNSUPPORTED_IMAGE_FORMAT           = 29,

    /**Image encoding */
    BERR_IMAGE_ENCODING                     = 30,

    /**Image decoding */
    BERR_IMAGE_DECODING                     = 31,

    /**Sensor not found */
    BERR_SENSOR_NOT_FOUND                   = 32,

    /**Sensor not ready to work */
    BERR_SENSOR_NOT_READY                   = 33,

    /**Iris border detection error */
    BERR_BORDER_DETECTION                   = 34,

    /**Cryptographic keys not matched by requirements */
    BERR_KEY_NOT_MATCHED                    = 35,

    /**Cryptographic keys not available */
    BERR_KEY_NOT_FOUND                      = 36,

    /**Not properly initialized state of certain module/service, either from beginning or after runtime exception.*/
    BERR_NOT_INITIALIZED                    = 37
};
} //namespace
#ifndef DOXYGEN_SHOULD_SKIP_THIS
#define MODULE_ERROR(moduleID, errorID) ((moduleID) | (errorID))
#endif /* DOXYGEN_SHOULD_SKIP_THIS */
#endif //COMMON_BASE_ERROR_DEF_H__
