/**
 * \file IndicatingLED.h
 */
#pragma once
#ifndef IRIS_CAMERA_INDICATING_LEDS_H_
#define IRIS_CAMERA_INDICATING_LEDS_H_

namespace iic
{
/** Indication led ID */
enum IndicatingLedID
{
    /**Red*/
    ILED_RED    = 1 << 0,
    /**Green*/
    ILED_GREEN  = 1 << 1,
    /**Blue*/
    ILED_BLUE   = 1 << 2,
    /**Orange*/
    ILED_ORANGE = 1 << 3
};

/** Led Status */
enum LEDStatus
{
    /**Off*/
    LED_OFF = 0,
    /**On*/
    LED_ON  = 1
};
} //namespace

#endif //IRIS_CAMERA_INDICATING_LEDS_H_
