#include "IriTrackerSingleton.h"

IriTrackerSingleton* IriTrackerSingleton::instance = nullptr;
IriTracker* IriTrackerSingleton::iriTracker = new IriTracker();
QThread* IriTrackerSingleton::streamThread = new QThread();
QThread* IriTrackerSingleton::streamThreadCheckInOut = new QThread();
QThread* IriTrackerSingleton::getDeviceThread = new QThread();