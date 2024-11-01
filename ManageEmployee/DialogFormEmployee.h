#pragma once

#include <QDialog>
#include "ui_DialogFormEmployee.h"
#include "DatabaseManager.h"
#include "EmployeeModel.h"

class DialogFormEmployee : public QDialog
{
	Q_OBJECT

public:
	DialogFormEmployee(QWidget *parent = nullptr);
	~DialogFormEmployee();
	Ui::DialogFormEmployeeClass getUi();

	bool isEditMode_employee = false;
	QString idSelected = "";
	QString avatarPath = "";
	QString iri_rightPath = "";
	QString iri_leftPath = "";

signals:
	void submit(EmployeeModel employee, bool isEditMode, DialogFormEmployee* employeeView);
	void uploadAvatar(DialogFormEmployee* employeeForm, bool isEditMode_employee);

public slots:
	void handleSubmit();
	void setMode(bool _isEditMode);
	void setValue(EmployeeModel employee);

	

private:
	Ui::DialogFormEmployeeClass ui;
	QMessageBox msgBox;
};
