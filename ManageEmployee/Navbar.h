#pragma once

#include <QWidget>
#include "ui_Navbar.h"

class Navbar : public QWidget
{
	Q_OBJECT

public:
	Navbar(QWidget *parent = nullptr);
	~Navbar();

	Ui::Navbar* getUi();

private:
	Ui::Navbar* ui;
};
