#pragma once

#include <QMainWindow>
#include <QMessageBox>

#include "ui_SignUpAdmin.h"
#include "MainWindow.h"
#include "DatabaseManager.h"

class SignUpAdmin : public QMainWindow
{
	Q_OBJECT

public:
	SignUpAdmin(QWidget *parent = nullptr);
	~SignUpAdmin();

	Ui::SignUpAdminClass* getUi();

signals:
	void submit(EmployeeModel employee);

private:
	Ui::SignUpAdminClass* ui;
	QMessageBox msgBox;
};
