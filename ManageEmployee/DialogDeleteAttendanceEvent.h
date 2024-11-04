#pragma once

#include <QDialog>
#include "ui_DialogDeleteAttendanceEvent.h"

QT_BEGIN_NAMESPACE
namespace Ui { class DialogDeleteAttendanceEventClass; };
QT_END_NAMESPACE

class DialogDeleteAttendanceEvent : public QDialog
{
	Q_OBJECT

public:
	DialogDeleteAttendanceEvent(QWidget *parent = nullptr);
	~DialogDeleteAttendanceEvent();

	Ui::DialogDeleteAttendanceEventClass* getUi();

private:
	Ui::DialogDeleteAttendanceEventClass *ui;
};
