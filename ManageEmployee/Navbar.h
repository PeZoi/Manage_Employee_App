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

signals:
	void logoutSuccessful();
	void loginSuccessful();
	void back();

public slots:
	void handleClickLogout();
	void handleClickLogin();
	void handleClickCopyright();
	void handleClickMode();
	void handleClickExit();
	void handleHiddenBack();
	void handleShowBack();
	void onLoginSuccess();
	void onLogoutSuccess();

private:
	Ui::Navbar ui;
	QMessageBox msgBox;
	DialogFormLoginAdmin formLogin;
};
