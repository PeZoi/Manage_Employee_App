#include "ManageException.h"
#include <QAbstractItemView>

ManageException::ManageException(QWidget *parent)
	: QWidget(parent)
	, ui(new Ui::ManageExceptionClass())
{
	ui->setupUi(this);

	ui->table->setEditTriggers(QAbstractItemView::NoEditTriggers);
	ui->table->setSelectionBehavior(QAbstractItemView::SelectRows);
	ui->edit->setDisabled(true);
	ui->delete_2->setDisabled(true);
	
}

ManageException::~ManageException()
{
	delete ui;
}

Ui::ManageExceptionClass* ManageException::getUi() { return ui; };