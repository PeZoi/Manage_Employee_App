#include "MenuList.h"

MenuList::MenuList(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);

	connect(ui.department_2, &QToolButton::clicked, this, [this]() {emit onClickDepartment(); });
	connect(ui.employee_2, &QToolButton::clicked, this, [this]() {emit onClickEmployee(); });
    connect(ui.event_2, &QToolButton::clicked, this, [this]() {emit onClickAttendanceEvents(); });
    connect(ui.tools_2, &QToolButton::clicked, this, [this]() {emit onClickTools(); });
    connect(ui.exception_2, &QToolButton::clicked, this, [this]() {emit onClickException(); });
    connect(ui.notification_2, &QToolButton::clicked, this, [this]() {emit onClickBulletin(); });

    ui.department_2->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
    ui.employee_2->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
    ui.event_2->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
    ui.notification_2->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
    ui.exception_2->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
    ui.report_2->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
    ui.tools_2->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
}

MenuList::~MenuList()
{}

Ui::MenuListClass MenuList::getUi() {
	return ui;
}