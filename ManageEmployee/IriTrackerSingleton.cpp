#include "IriTrackerSingleton.h"

IriTrackerSingleton* IriTrackerSingleton::instance = nullptr;
IriTracker* IriTrackerSingleton::iriTracker = new IriTracker();
IriTracker* IriTrackerSingleton::iriTrackerGetDevice = new IriTracker();
IriTracker* IriTrackerSingleton::iriCaptureEyes = new IriTracker();
QThread* IriTrackerSingleton::streamThread = new QThread();
QThread* IriTrackerSingleton::streamThreadCheckInOut = new QThread();
QThread* IriTrackerSingleton::getDeviceThread = new QThread();

bool IriTrackerSingleton::isRunningGetDeviceThread = true;
bool IriTrackerSingleton::isRunningStreamThreadCheckInOut = true;
bool IriTrackerSingleton::isFoundDevice = false;
