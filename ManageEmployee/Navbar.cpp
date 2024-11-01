#include "Navbar.h"
#include <QSettings>
#include <QFile>

Navbar::Navbar(QWidget* parent)
	: QWidget(parent), ui(new Ui::Navbar)
{
	ui->setupUi(this);

	ui->navbarLayout->setAlignment(Qt::AlignLeft);
}

Navbar::~Navbar()
{}

Ui::Navbar* Navbar::getUi() {
	return ui;
}