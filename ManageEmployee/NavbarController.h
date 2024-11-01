#pragma once
#include <QObject>
#include "Navbar.h"
#include <QMessageBox>

class NavbarController : public QObject {
	Q_OBJECT
public:
	explicit NavbarController(QObject* parent = nullptr);
	NavbarController(Navbar* view, QObject* parent = nullptr);
	Navbar* getUi();

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

	void handleSignInAdmin(QString pass, DialogFormLoginAdmin* dialog);

private:
	Navbar* navbarView;
	QMessageBox msgBox;
};

