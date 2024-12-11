#include "ManageDepartment.h"

ManageDepartment::ManageDepartment(QWidget* parent)
	: QWidget(parent), ui(new Ui::ManageDepartmentClass)
{
	ui->setupUi(this);

	ui->table->setEditTriggers(QAbstractItemView::NoEditTriggers);
	ui->table->setSelectionBehavior(QAbstractItemView::SelectRows);

	ui->edit->setDisabled(true);
	ui->delete_2->setDisabled(true);
}

ManageDepartment::~ManageDepartment()
{}

Ui::ManageDepartmentClass* ManageDepartment::getUi() { return ui; };