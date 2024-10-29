#include "ManageDepartmentController.h"
#include "DepartmentRepository.h"
#include <QStandardItemModel>
#include <QTableView>

ManageDepartmentController::ManageDepartmentController(ManageDepartment* view, QObject* parent)
	: QObject(parent), mdView(view)
{
	handleRenderTable();

	connect(mdView->getUi()->add, SIGNAL(clicked()), this, SLOT(onClickAdd()));
	connect(mdView->getUi()->edit, SIGNAL(clicked()), this, SLOT(onClickEdit()));
	connect(mdView->getUi()->delete_2, SIGNAL(clicked()), this, SLOT(onClickDelete()));

	//connect(df_department, &DialogFormDepartment::excuteDBSuccessful, this, &ManageDepartmentController::handleRenderTable);
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


	QList<DepartmentModel> departmentList = DepartmentRepository::getAll();

	QStandardItemModel* model = new QStandardItemModel(departmentList.size(), 2, this);
	model->setHorizontalHeaderLabels({ "Tên", "Mô tả" });

	mdView->getUi()->table->setModel(model);

	for (int i = 0; i < departmentList.size(); i++) {
		model->setItem(i, 0, new QStandardItem(departmentList.at(i).getName()));
		model->setItem(i, 1, new QStandardItem(departmentList.at(i).getDescription()));
	}

	mdView->getUi()->table->resizeColumnsToContents();
}

void ManageDepartmentController::handleRowClicked(const QModelIndex& index) {
	if (!index.isValid()) {
		return; // Kiểm tra xem chỉ mục có hợp lệ không
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
	if (DepartmentRepository::_delete(departmentSelected)) {
		handleRenderTable();
	}
	else {
		qDebug() << "Xoá thất bại";
	};
}

void ManageDepartmentController::submitDepartment(const DepartmentModel& department, bool isEditMode) {
	DatabaseManager::connectToDatabase();

	// Nếu không phải là mode edit
	if (!isEditMode) {
		// Kiểm tra xem name có tồn tại không
		if (DepartmentRepository::getByName(department.getName()).getName() != "") {
			/*msgBox.setText("Tên phòng ban đã tồn tại");
			msgBox.exec();*/
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

	DatabaseManager::closeDatabase();
}

ManageDepartment* ManageDepartmentController::getMdView() {
	return mdView;
}