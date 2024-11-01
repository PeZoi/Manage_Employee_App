#pragma once

#include <QWidget>
#include "ui_MenuList.h"

class MenuList : public QWidget
{
	Q_OBJECT

public:
	MenuList(QWidget *parent = nullptr);
	~MenuList();

	Ui::MenuListClass getUi();

signals:
	void onClickDepartment();
	void onClickEmployee();
	void onClickAttendanceEvents();

private:
	Ui::MenuListClass ui;
};
