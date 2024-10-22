#include "MenuList.h"

MenuList::MenuList(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);

	connect(ui.department, &QPushButton::clicked, this, [this]() {emit onClickDepartment(); });
	connect(ui.employee, &QPushButton::clicked, this, [this]() {emit onClickEmployee(); });
}

MenuList::~MenuList()
{}