#include "Tools.h"
#include <QLinearGradient>
#include <QPalette>

Tools::Tools(QWidget *parent)
	: QWidget(parent)
	, ui(new Ui::ToolsClass())
{
	ui->setupUi(this);

	QLinearGradient gradient(0, 0, 0, this->height());
	gradient.setColorAt(0.0, Qt::white);
	gradient.setColorAt(1.0, QColor("#87A8D2"));

	QPalette palette;
	palette.setBrush(QPalette::Window, gradient);
	this->setPalette(palette);
	this->setAutoFillBackground(true);

	ui->backup_data->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
	ui->restore_data->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
	ui->change_db->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
	ui->change_password->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
	ui->settings->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);

}

Tools::~Tools()
{
	delete ui;
}


Ui::ToolsClass* Tools::getUi() {
	return ui;
}