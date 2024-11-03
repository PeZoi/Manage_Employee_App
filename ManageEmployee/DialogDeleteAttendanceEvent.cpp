#include "DialogDeleteAttendanceEvent.h"

DialogDeleteAttendanceEvent::DialogDeleteAttendanceEvent(QWidget *parent)
	: QDialog(parent)
	, ui(new Ui::DialogDeleteAttendanceEventClass())
{
	ui->setupUi(this);

	QLinearGradient gradient(0, 0, 0, this->height());
	gradient.setColorAt(0.0, Qt::white);
	gradient.setColorAt(1.0, QColor("#87A8D2"));

	QPalette palette;
	palette.setBrush(QPalette::Window, gradient);
	this->setPalette(palette);
	this->setAutoFillBackground(true);

	connect(ui->btn_yes, &QPushButton::clicked, this, [this]() {accept(); });
	connect(ui->btn_no, &QPushButton::clicked, this, [this]() {reject(); });
}

DialogDeleteAttendanceEvent::~DialogDeleteAttendanceEvent()
{
	delete ui;
}

Ui::DialogDeleteAttendanceEventClass* DialogDeleteAttendanceEvent::getUi() {
	return ui;
}