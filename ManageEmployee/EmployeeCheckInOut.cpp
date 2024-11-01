#include "EmployeeCheckInOut.h"

EmployeeCheckInOut::EmployeeCheckInOut(QWidget *parent)
	: QWidget(parent)
	, ui(new Ui::EmployeeCheckInOutClass())
{
	ui->setupUi(this);
}

EmployeeCheckInOut::~EmployeeCheckInOut()
{
	delete ui;
}

Ui::EmployeeCheckInOutClass* EmployeeCheckInOut::getUi() {
	return ui;
}
