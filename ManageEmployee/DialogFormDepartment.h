#pragma once

#include <QDialog>
#include "ui_DialogFormDepartment.h"
#include "DatabaseManager.h"

class DialogFormDepartment : public QDialog
{
	Q_OBJECT

public:
	DialogFormDepartment(QWidget *parent = nullptr);
	~DialogFormDepartment();

signals:
	void excuteDBSuccessful();

public slots:
	void handleSubmit();

private:
	Ui::DialogFormDepartmentClass ui;
	DatabaseManager db;
	QMessageBox msgBox;
};
