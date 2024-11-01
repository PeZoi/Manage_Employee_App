#pragma once

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <QString>

#include "IICAPI.h"
#include "IrisDef.h"
#include "BaseError.h"
using namespace iic;

#ifndef SLEEP_MSEC_H
#define SLEEP_MSEC_H

#ifdef _WIN32
#include <Windows.h>
#else
#include <unistd.h>
#endif // _WIN32

inline void sleep_msec(int miliseconds)
{
#ifdef _WIN32
    ::Sleep(miliseconds);
#else
    ::usleep(miliseconds * 1000);
#endif // _WIN32
}

#endif // SLEEP_MSEC_H

class IriTracker
{
public:
    IriTracker();
    static QString run();
};

