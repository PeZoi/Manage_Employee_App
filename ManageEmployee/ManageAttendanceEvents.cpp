#include "ManageAttendanceEvents.h"

ManageAttendanceEvents::ManageAttendanceEvents(QWidget *parent)
	: QWidget(parent)
	, ui(new Ui::ManageAttendanceEventsClass())
{
	ui->setupUi(this);

	QLinearGradient gradient(0, 0, 0, this->height());
	gradient.setColorAt(0.0, Qt::white);
	gradient.setColorAt(1.0, QColor("#87A8D2"));

	QPalette palette;
	palette.setBrush(QPalette::Window, gradient);
	this->setPalette(palette);
	this->setAutoFillBackground(true);

	ui->table->setSelectionBehavior(QAbstractItemView::SelectRows);
	ui->table->setEditTriggers(QAbstractItemView::NoEditTriggers);
}

ManageAttendanceEvents::~ManageAttendanceEvents()
{
	delete ui;
}

Ui::ManageAttendanceEventsClass* ManageAttendanceEvents::getUi() {
	return ui;
}