#pragma once

#include <QMainWindow>
#include <QMessageBox>

#include "ui_SignUpAdmin.h"
#include "ManageEmployee.h"
#include "DatabaseManager.h"

class SignUpAdmin : public QMainWindow
{
	Q_OBJECT

public:
	SignUpAdmin(QWidget *parent = nullptr);
	~SignUpAdmin();

private slots:
	void handleSignUp();

private:
	Ui::SignUpAdminClass ui;
	ManageEmployee me;
	DatabaseManager db;
	QMessageBox msgBox;
};
