#include "ManageEmployee.h"

ManageEmployee::ManageEmployee(QWidget* parent)
	: QWidget(parent), ui(new Ui::ManageEmployeeClass)
{
	ui->setupUi(this);

	ui->table->setEditTriggers(QAbstractItemView::NoEditTriggers);
	ui->table->setSelectionBehavior(QAbstractItemView::SelectRows);

	ui->edit->setDisabled(true);
	ui->delete_2->setDisabled(true);

}

ManageEmployee::~ManageEmployee()
{}

Ui::ManageEmployeeClass* ManageEmployee::getUi() { return ui; };