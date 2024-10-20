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

private slots:
	void handleClickLogout();
	void handleClickLogin();
	void handleClickCopyright();
	void handleClickMode();
	void handleClickExit();
	void onLoginSuccess();
	void onLogoutSuccess();

private:
	Ui::Navbar ui;
	QMessageBox msgBox;
	DialogFormLoginAdmin formLogin;
};
