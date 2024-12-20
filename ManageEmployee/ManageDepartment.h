#pragma once

#include <QWidget>
#include "ui_ManageDepartment.h"

class ManageDepartment : public QWidget
{
	Q_OBJECT

public:
	ManageDepartment(QWidget *parent = nullptr);
	~ManageDepartment();

	Ui::ManageDepartmentClass* getUi();

signals:
	void modeEdit();

private:
	Ui::ManageDepartmentClass* ui;
};
