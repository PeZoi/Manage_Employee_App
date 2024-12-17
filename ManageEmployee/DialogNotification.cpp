#include "DialogNotification.h"
#include <QAbstractItemView>
#include "DatabaseSingleton.h"
#include <QTableWidgetItem>
#include <QHeaderView>
#include <QPushButton>

DialogNotification::DialogNotification(QList<BulletinModel> list, QWidget *parent)
	: bulletinList(list), QDialog(parent)
	, ui(new Ui::DialogNotificationClass())
{
	ui->setupUi(this);

	QLinearGradient gradient(0, 0, 0, this->height());
	gradient.setColorAt(0.0, Qt::white);
	gradient.setColorAt(1.0, QColor("#87A8D2"));

	QPalette palette;
	palette.setBrush(QPalette::Window, gradient);
	this->setPalette(palette);
	this->setAutoFillBackground(true);

	connect(ui->table, &QTableView::clicked, this, &DialogNotification::handleRowClicked);
	connect(ui->ok, &QPushButton::clicked, this, [this]() {
		this->accept();
		});

	if (list.size() > 0) {
		bulletinSelected = list.at(0);
		ui->title->setText(bulletinSelected.getTitle());
		ui->content->setText(bulletinSelected.getContent());
	}

	ui->table->setEditTriggers(QAbstractItemView::NoEditTriggers);
	ui->table->setSelectionBehavior(QAbstractItemView::SelectRows);
	ui->table->horizontalHeader()->setSectionResizeMode(1, QHeaderView::Stretch);

	renderBulletin();
}

DialogNotification::~DialogNotification()
{
	delete ui;
}

Ui::DialogNotificationClass* DialogNotification::getUi() {
	return ui;
}

void DialogNotification::renderBulletin() {
	ui->table->setRowCount(bulletinList.size());

	for (int i = 0; i < bulletinList.size(); i++) {
		ui->table->setItem(i, 0, new QTableWidgetItem(QString::number(bulletinList.at(i).getId())));
		ui->table->hideColumn(0);
		ui->table->setItem(i, 1, new QTableWidgetItem(bulletinList.at(i).getTitle()));
		ui->table->setItem(i, 2, new QTableWidgetItem(bulletinList.at(i).getStartDate()));
		ui->table->setItem(i, 3, new QTableWidgetItem(bulletinList.at(i).getEndDate()));
	}

	ui->table->verticalHeader()->setVisible(false);

	for (int i = 0; i < bulletinList.size(); ++i) {
		if (i % 2 == 0) { // Dòng chẵn
			for (int j = 0; j < ui->table->columnCount(); ++j) {
				QTableWidgetItem* item = ui->table->item(i, j);
				if (item) {
					item->setBackground(QColor(232, 235, 237)); // Màu xám nhạt
				}
			}
		}
	}
	DatabaseSingleton::getInstance()->getDB()->closeDatabase();
}


void DialogNotification::handleRowClicked(const QModelIndex& index) {
	if (!index.isValid()) {
		return;
	}
	int row = index.row();
	BulletinModel bulletin = bulletinList.at(row);
	ui->title->setText(bulletin.getTitle());
	ui->content->setText(bulletin.getContent());
}