#pragma once
#include <QObject>
#include "ManageAttendanceEvents.h"
class ManageAttendanceEventsController : public QObject {
	Q_OBJECT

public:
	ManageAttendanceEventsController(ManageAttendanceEvents* view, QObject* parent = nullptr);

	ManageAttendanceEvents* getView();

private:
	ManageAttendanceEvents* view;
};

