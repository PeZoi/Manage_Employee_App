#pragma once

#include <QWidget>
#include "ui_MenuList.h"

class MenuList : public QWidget
{
	Q_OBJECT

public:
	MenuList(QWidget *parent = nullptr);
	~MenuList();

signals:
	void onClickDepartment();
	void onClickEmployee();

private:
	Ui::MenuListClass ui;
};
