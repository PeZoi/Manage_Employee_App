#include "ManageBulletinController.h"
#include "DatabaseSingleton.h"
#include "ErrorLabel.h"
#include "DialogConfirm.h"
#include "DialogFormBulletin.h"
#include <QDebug>
#include <QCheckBox>
#include <QHBoxLayout>

ManageBulletinController::ManageBulletinController(ManageBulletin* view, QObject* parent)
	: QObject(parent), mbView(view)
{
	handleRenderTable();

	connect(mbView->getUi()->add, SIGNAL(clicked()), this, SLOT(onClickAdd()));
	connect(mbView->getUi()->edit, SIGNAL(clicked()), this, SLOT(onClickEdit()));
	connect(mbView->getUi()->delete_2, SIGNAL(clicked()), this, SLOT(onClickDelete()));

	connect(mbView->getUi()->table, &QTableView::clicked, this, &ManageBulletinController::handleRowClicked);
	connect(mbView->getUi()->table, &QTableView::doubleClicked, this, [this](const QModelIndex& index) {
		handleRowClicked(index);
		onClickEdit();
		});
}

ManageBulletinController::~ManageBulletinController()
{}


void ManageBulletinController::onClickAdd() {
	DialogFormBulletin* dialog = new DialogFormBulletin(mbView);
	dialog->setMode(false);

	connect(dialog, &DialogFormBulletin::submit, this, &ManageBulletinController::submit);

	dialog->exec();
}

void ManageBulletinController::handleRenderTable() {
	DatabaseSingleton::getInstance()->getDB()->connectToDatabase();

	QList<BulletinModel> list = DatabaseSingleton::getInstance()->getDB()->getBulletinRepository()->getAll();

	mbView->getUi()->table->setRowCount(list.size());

	for (int i = 0; i < list.size(); i++) {
		mbView->getUi()->table->setItem(i, 0, new QTableWidgetItem(QString::number(list.at(i).getId())));
		mbView->getUi()->table->hideColumn(0);
		mbView->getUi()->table->setItem(i, 1, new QTableWidgetItem(list.at(i).getTitle()));
		mbView->getUi()->table->setItem(i, 2, new QTableWidgetItem(list.at(i).getType()));
		mbView->getUi()->table->setItem(i, 3, new QTableWidgetItem(list.at(i).getStartDate()));
		mbView->getUi()->table->setItem(i, 4, new QTableWidgetItem(list.at(i).getEndDate()));

		QCheckBox* checkBox = new QCheckBox();
		checkBox->setChecked(list.at(i).getIsActive());

		// Tạo QWidget để chứa checkbox
		QWidget* widget = new QWidget();
		QHBoxLayout* layout = new QHBoxLayout(widget);
		layout->addWidget(checkBox);
		layout->setAlignment(Qt::AlignCenter);  // Căn giữa checkbox
		layout->setContentsMargins(0, 0, 0, 0); // Loại bỏ khoảng cách thừa
		widget->setLayout(layout);

		mbView->getUi()->table->setCellWidget(i, 5, widget);

		// Kết nối sự kiện
		connect(checkBox, &QCheckBox::toggled, this, [this, list, i](bool checked) {
			handleToggleActive(list.at(i).getId(), checked);
			});

	}



	mbView->getUi()->table->verticalHeader()->setVisible(false);

	for (int i = 0; i < list.size(); ++i) {
		if (i % 2 == 0) { // Dòng chẵn
			for (int j = 0; j < mbView->getUi()->table->columnCount(); ++j) {
				QTableWidgetItem* item = mbView->getUi()->table->item(i, j);
				if (item) {
					item->setBackground(QColor(232, 235, 237)); // Màu xám nhạt
				}
			}
		}
	}
	DatabaseSingleton::getInstance()->getDB()->closeDatabase();
}

void ManageBulletinController::handleRowClicked(const QModelIndex& index) {
	if (!index.isValid()) {
		return;
	}

	mbView->getUi()->edit->setDisabled(false);
	mbView->getUi()->delete_2->setDisabled(false);

	int id = index.sibling(index.row(), 0).data().toInt();


	DatabaseSingleton::getInstance()->getDB()->connectToDatabase();
	bulletinSelected = DatabaseSingleton::getInstance()->getDB()->getBulletinRepository()->getById(id);
	DatabaseSingleton::getInstance()->getDB()->closeDatabase();
}

void ManageBulletinController::onClickEdit() {
	DatabaseSingleton::getInstance()->getDB()->connectToDatabase();

	DialogFormBulletin* dialog = new DialogFormBulletin(mbView);
	dialog->setMode(true);
	dialog->setValue(bulletinSelected);

	connect(dialog, &DialogFormBulletin::submit, this, &ManageBulletinController::submit);

	dialog->exec();
	DatabaseSingleton::getInstance()->getDB()->closeDatabase();
}

void ManageBulletinController::onClickDelete() {
	DatabaseSingleton::getInstance()->getDB()->connectToDatabase();
	DialogConfirm* confirm = new DialogConfirm(tr("Do you really want to delete bulletin ?"), nullptr);
	if (confirm->exec() == QDialog::Accepted) {
		if (DatabaseSingleton::getInstance()->getDB()->getBulletinRepository()->_delete(bulletinSelected.getId())) {
			bulletinSelected = BulletinModel();
			mbView->getUi()->edit->setDisabled(true);
			mbView->getUi()->delete_2->setDisabled(true);
			handleRenderTable();
		}
		else {
			qDebug() << "Xoá thất bại";
		};
	}
	DatabaseSingleton::getInstance()->getDB()->closeDatabase();
}

void ManageBulletinController::submit(const BulletinModel& bulletin, bool isEditMode, DialogFormBulletin* dialog) {
	DatabaseSingleton::getInstance()->getDB()->connectToDatabase();
	// Nếu không phải là mode edit
	if (!isEditMode) {
		if (DatabaseSingleton::getInstance()->getDB()->getBulletinRepository()->add(bulletin)) {
			handleRenderTable();
		};
	}
	else {
		BulletinModel bulletinFormat = bulletin;
		bulletinFormat.setId(bulletinSelected.getId());
		if (DatabaseSingleton::getInstance()->getDB()->getBulletinRepository()->update(bulletinFormat)) {
			handleRenderTable();
		};
	}
	dialog->accept();
	DatabaseSingleton::getInstance()->getDB()->closeDatabase();

}

void  ManageBulletinController::handleToggleActive(int id, bool checked) {
	DatabaseSingleton::getInstance()->getDB()->connectToDatabase();
	DatabaseSingleton::getInstance()->getDB()->getBulletinRepository()->updateActived(id, checked);
	DatabaseSingleton::getInstance()->getDB()->closeDatabase();
}

ManageBulletin* ManageBulletinController::getMbView() {
	return mbView;
}