#include "EmployeeCheckInOut.h"
#include <QDebug>

EmployeeCheckInOut::EmployeeCheckInOut(QWidget *parent)
	: QWidget(parent)
	, ui(new Ui::EmployeeCheckInOutClass())
{
	ui->setupUi(this);

	ui->device->installEventFilter(this);
}

EmployeeCheckInOut::~EmployeeCheckInOut()
{
	delete ui;
}

Ui::EmployeeCheckInOutClass* EmployeeCheckInOut::getUi() {
	return ui;
}

bool EmployeeCheckInOut::eventFilter(QObject* obj, QEvent* event) {
	if (event->type() == QEvent::MouseButtonPress) {
		qDebug() << "Click";
		emit onClickDevice();
		return true;
	}
	return QWidget::eventFilter(obj, event);
}