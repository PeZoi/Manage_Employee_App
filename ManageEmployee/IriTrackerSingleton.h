#pragma once
#include "IriTracker.h"
#include <QThread>
class IriTrackerSingleton {
private:
	static IriTrackerSingleton* instance;
	static IriTracker* iriTracker;
	static QThread* streamThread;
	static QThread* getDeviceThread;

	IriTrackerSingleton() = default;

public:
	IriTrackerSingleton(const IriTrackerSingleton&) = delete;
	IriTrackerSingleton& operator=(const IriTrackerSingleton&) = delete;

	static IriTrackerSingleton* getInstance() {
		if (instance == nullptr) {
			instance = new IriTrackerSingleton();
		}
		return instance;
	}

	static void destroyInstance() {
		if (instance != nullptr) {
			delete instance;
		}
		instance = nullptr;
	}

    static IriTracker* getIriTracker() {
        return iriTracker;
    }

    static void setIriTracker(IriTracker* tracker) {
        iriTracker = tracker;
    }

    static QThread* getStreamThread() {
        return streamThread;
    }

    static void setStreamThread(QThread* thread) {
        streamThread = thread;
    }

    static QThread* getGetDeviceThread() {
        return getDeviceThread;
    }

    static void setGetDeviceThread(QThread* thread) {
        getDeviceThread = thread;
    }
};