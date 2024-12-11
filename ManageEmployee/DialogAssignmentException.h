#pragma once

#include <QDialog>
#include "ui_DialogAssignmentException.h"
#include "DepartmentModel.h"
#include "EmployeeModel.h"

QT_BEGIN_NAMESPACE
namespace Ui { class DialogAssignmentExceptionClass; };
QT_END_NAMESPACE

class DialogAssignmentException : public QDialog
{
	Q_OBJECT

public:
	DialogAssignmentException(QWidget *parent = nullptr);
	~DialogAssignmentException();

	void renderExceptions();
	void renderDepartments(QList<DepartmentModel> departments);
	void renderEmployees(QList<EmployeeModel> employees);

	void setDisabledEmployee(bool check);
	void setDisabledDepartment(bool check);

	void filterDepartment(const QString& name);
	void filterEmployee(const QString& name);

private:
	Ui::DialogAssignmentExceptionClass *ui;
	QList<DepartmentModel> departments;
	QList<EmployeeModel> employees;
};
