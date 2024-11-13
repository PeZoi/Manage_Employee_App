#pragma once

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <QString>
#include <functional>
#include <QObject>


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

class IriTracker : public QObject {
    Q_OBJECT

signals:
    void newImageCaptured(const unsigned char* imageData, int imageLen, int imageHeight, int imageWidth);
    void captureFinished();
public slots:
    int capture_without_callback(IICHandle hdev);
    QString run();
public:
    IriTracker();
    
    IICHandle hdev;
    
    
};

