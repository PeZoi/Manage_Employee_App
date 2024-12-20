#pragma once

#include <QWidget>
#include "ui_EmployeeCheckInOut.h"

QT_BEGIN_NAMESPACE
namespace Ui { class EmployeeCheckInOutClass; };
QT_END_NAMESPACE

class EmployeeCheckInOut : public QWidget
{
	Q_OBJECT

signals:
	void onClickDevice();

public:
	EmployeeCheckInOut(QWidget *parent = nullptr);
	~EmployeeCheckInOut();

	Ui::EmployeeCheckInOutClass* getUi();

public slots:
	bool eventFilter(QObject* obj, QEvent* event);

private:
	Ui::EmployeeCheckInOutClass *ui;
};
