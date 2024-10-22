#pragma once

#include <QWidget>
#include "ui_ManageEmployee.h"
#include "DatabaseManager.h"

class ManageEmployee : public QWidget
{
	Q_OBJECT

public:
	ManageEmployee(QWidget *parent = nullptr);
	~ManageEmployee();

private:
	Ui::ManageEmployeeClass ui;
	DatabaseManager db;
};
