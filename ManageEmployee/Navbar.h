#pragma once

#include <QWidget>
#include <QMessageBox>
#include "ui_Navbar.h"
#include "DialogFormLoginAdmin.h"

class Navbar : public QWidget
{
	Q_OBJECT

public:
	Navbar(QWidget *parent = nullptr);
	~Navbar();

	Ui::Navbar* getUi();

private:
	Ui::Navbar* ui;
	QMessageBox msgBox;
};
