#pragma once

#include <QDialog>
#include "ui_DialogFormAttendanceEvents.h"
#include "AttendaceEventModel.h"

class DialogFormAttendanceEvents : public QDialog
{
	Q_OBJECT

public:
	DialogFormAttendanceEvents(QString employeeSelected ,QWidget *parent = nullptr);
	~DialogFormAttendanceEvents();

	Ui::DialogFormAttendanceEventsClass* getUi();
	bool isEditMode = false;
	QString employeeSelected;

signals:
	void submit(QString _employeeSelected, bool isEditMode, DialogFormAttendanceEvents* dialog);

public slots:
	void handleSubmit();
	void setMode(bool _isEditMode);
	void setValue(const QList<AttendanceEventModel>& events);

	QString handleCheckTimeCheckInOut();

private:
	Ui::DialogFormAttendanceEventsClass *ui;
};
