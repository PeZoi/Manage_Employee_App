#include "ManageBulletin.h"
#include <QAbstractItemView>

ManageBulletin::ManageBulletin(QWidget *parent)
	: QWidget(parent)
	, ui(new Ui::ManageBulletinClass())
{
	ui->setupUi(this);

	ui->table->setEditTriggers(QAbstractItemView::NoEditTriggers);
	ui->table->setSelectionBehavior(QAbstractItemView::SelectRows);
	ui->edit->setDisabled(true);
	ui->delete_2->setDisabled(true);
}

ManageBulletin::~ManageBulletin()
{
	delete ui;
}

Ui::ManageBulletinClass* ManageBulletin::getUi() { return ui; };