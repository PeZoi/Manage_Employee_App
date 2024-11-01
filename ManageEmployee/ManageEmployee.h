#pragma once

#include <QWidget>
#include "ui_ManageEmployee.h"
#include "DatabaseManager.h"
#include "DialogFormEmployee.h"

class ManageEmployee : public QWidget
{
	Q_OBJECT

public:
	ManageEmployee(QWidget *parent = nullptr);
	~ManageEmployee();

	Ui::ManageEmployeeClass* getUi();


signals:
	void modeEdit();

private:
	Ui::ManageEmployeeClass* ui;
};
