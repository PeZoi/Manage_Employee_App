#pragma once

#include <QWidget>
#include "ui_ManageAttendanceEvents.h"

class ManageAttendanceEvents : public QWidget
{
	Q_OBJECT

public:
	ManageAttendanceEvents(QWidget *parent = nullptr);
	~ManageAttendanceEvents();

	Ui::ManageAttendanceEventsClass* getUi();

private:
	Ui::ManageAttendanceEventsClass *ui;
};
