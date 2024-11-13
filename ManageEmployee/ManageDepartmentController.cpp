#include "ManageDepartmentController.h"
#include "DepartmentRepository.h"
#include "ErrorLabel.h"
#include "DialogConfirm.h"
#include <QStandardItemModel>
#include <QTableView>

ManageDepartmentController::ManageDepartmentController(ManageDepartment* view, QObject* parent)
	: QObject(parent), mdView(view)
{
	handleRenderTable();

	connect(mdView->getUi()->add, SIGNAL(clicked()), this, SLOT(onClickAdd()));
	connect(mdView->getUi()->edit, SIGNAL(clicked()), this, SLOT(onClickEdit()));
	connect(mdView->getUi()->delete_2, SIGNAL(clicked()), this, SLOT(onClickDelete()));

	connect(mdView->getUi()->table, &QTableView::clicked, this, &ManageDepartmentController::handleRowClicked);
	connect(mdView->getUi()->table, &QTableView::doubleClicked, this, [this](const QModelIndex& index) {
		handleRowClicked(index);
		onClickEdit();
		});
}

void ManageDepartmentController::onClickAdd() {
	DialogFormDepartment* dialog = new DialogFormDepartment(mdView);
	dialog->setMode(false);

	connect(dialog, &DialogFormDepartment::submit, this, &ManageDepartmentController::submitDepartment);

	dialog->exec();
}

void ManageDepartmentController::handleRenderTable() {
	QList<DepartmentModel> departmentList = DepartmentRepository::getAllIgnoreOthers();

	mdView->getUi()->table->setRowCount(departmentList.size());

	for (int i = 0; i < departmentList.size(); i++) {
		mdView->getUi()->table->setItem(i, 0, new QTableWidgetItem(departmentList.at(i).getName()));
		mdView->getUi()->table->setItem(i, 1, new QTableWidgetItem(departmentList.at(i).getDescription()));
	}

	mdView->getUi()->table->verticalHeader()->setVisible(false);

	for (int i = 0; i < departmentList.size(); ++i) {
		if (i % 2 == 0) { // Dòng chẵn
			for (int j = 0; j < mdView->getUi()->table->columnCount(); ++j) {
				QTableWidgetItem* item = mdView->getUi()->table->item(i, j);
				if (item) {
					item->setBackground(QColor(232, 235, 237)); // Màu xám nhạt
				}
			}
		}
	}
}

void ManageDepartmentController::handleRowClicked(const QModelIndex& index) {
	if (!index.isValid()) {
		return;
	}

	mdView->getUi()->edit->setDisabled(false);
	mdView->getUi()->delete_2->setDisabled(false);

	departmentSelected = index.sibling(index.row(), 0).data().toString();

}

void ManageDepartmentController::onClickEdit() {
	DepartmentModel department = DepartmentRepository::getByName(departmentSelected);

	DialogFormDepartment* dialog = new DialogFormDepartment(mdView);
	dialog->setMode(true);
	dialog->setName(department.getName());
	dialog->setDescription(department.getDescription());

	connect(dialog, &DialogFormDepartment::submit, this, &ManageDepartmentController::submitDepartment);

	dialog->exec();

}

void ManageDepartmentController::onClickDelete() {
	DialogConfirm* confirm = new DialogConfirm("Do you really want to delete department ?", nullptr);
	if (confirm->exec() == QDialog::Accepted) {
		if (DepartmentRepository::_delete(departmentSelected)) {
			departmentSelected = "";
			handleRenderTable();
		}
		else {
			qDebug() << "Xoá thất bại";

		};
	}
}

void ManageDepartmentController::submitDepartment(const DepartmentModel& department, bool isEditMode, DialogFormDepartment* departmentView) {
	DatabaseManager::connectToDatabase();

	// Nếu không phải là mode edit
	if (!isEditMode) {
		// Kiểm tra xem name có tồn tại không
		if (DepartmentRepository::getByName(department.getName()).getName() != "") {
			ErrorLabel* error = new ErrorLabel("  The name already exists");
			error->showTemporary(departmentView->getUi()->verticalLayout, 3000);
			return;
		}
		if (DepartmentRepository::add(department)) {
			handleRenderTable();
		};
	}
	else {
		if (DepartmentRepository::update(department)) {
			handleRenderTable();
		};
	}
	departmentView->accept();

	DatabaseManager::closeDatabase();
}

ManageDepartment* ManageDepartmentController::getMdView() {
	return mdView;
}