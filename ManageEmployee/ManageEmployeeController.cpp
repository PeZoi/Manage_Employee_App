#include "ManageEmployeeController.h"
#include "DepartmentModel.h"
#include "DepartmentRepository.h"
#include "EmployeeRepository.h"
#include "ErrorLabel.h"
#include "DialogConfirm.h"
#include <QAbstractItemView>
#include <QStandardItem>
#include <QSettings>
#include <QTableWidgetItem>
#include <QCheckBox>
#include <QDate>
#include <QFileDialog>
#include <QGraphicsScene>
#include <QPixmap>


ManageEmployeeController::ManageEmployeeController(ManageEmployee* view, QObject* parent)
	: QObject(parent), meView(view)
{
	handleRenderTable();

	connect(meView->getUi()->add, SIGNAL(clicked()), this, SLOT(onClickAdd()));
	connect(meView->getUi()->edit, SIGNAL(clicked()), this, SLOT(onClickEdit()));
	connect(meView->getUi()->delete_2, SIGNAL(clicked()), this, SLOT(onClickDelete()));

	connect(meView->getUi()->table, &QTableView::clicked, this, &ManageEmployeeController::handleRowClicked);
	connect(meView->getUi()->table, &QTableView::doubleClicked, this, [this](const QModelIndex& index) {
		handleRowClicked(index);
		onClickEdit();
		});
}

void ManageEmployeeController::onClickAdd() {
	DialogFormEmployee* dialog = new DialogFormEmployee(meView);

	dialog->setMode(false);
	renderDepartments(dialog->getUi());

	connect(dialog, &DialogFormEmployee::uploadAvatar, this, &ManageEmployeeController::handleUploadAvatar);
	connect(dialog, &DialogFormEmployee::submit, this, &ManageEmployeeController::submitEmployee);

	dialog->exec();
}

void ManageEmployeeController::handleRenderTable() {
	QList<EmployeeModel> employeeList = EmployeeRepository::getAll();

	meView->getUi()->table->setRowCount(employeeList.size());

	for (int i = 0; i < employeeList.size(); i++) {
		meView->getUi()->table->setItem(i, 0, new QTableWidgetItem(employeeList.at(i).getId()));
		meView->getUi()->table->setItem(i, 1, new QTableWidgetItem(employeeList.at(i).getFirstName() + " " + employeeList.at(i).getLastName()));
		meView->getUi()->table->setItem(i, 2, new QTableWidgetItem(employeeList.at(i).getDateOfBirth().toString("dd/MM/yyyy")));
		meView->getUi()->table->setItem(i, 3, new QTableWidgetItem(employeeList.at(i).getStartDateOfWork().toString("dd/MM/yyyy")));
		meView->getUi()->table->setItem(i, 4, new QTableWidgetItem(employeeList.at(i).getStatus()));
		meView->getUi()->table->setItem(i, 5, new QTableWidgetItem(employeeList.at(i).getDepartment().getName()));

		// Tạo QRadioButton cho cột "Hoạt Động"
		QCheckBox* checkBox = new QCheckBox();
		checkBox->setChecked(employeeList.at(i).getIsEnabled());
		meView->getUi()->table->setCellWidget(i, 6, checkBox);

		connect(checkBox, &QCheckBox::toggled, this, [this, i](bool checked) {
			QModelIndex index = meView->getUi()->table->model()->index(i, 0);
			QString id = meView->getUi()->table->model()->data(index).toString();

			handleToggleEnabled(id, checked);
			});


	}

	meView->getUi()->table->verticalHeader()->setVisible(false);

	for (int i = 0; i < employeeList.size(); ++i) {
		if (i % 2 == 0) { // Dòng chẵn
			for (int j = 0; j < meView->getUi()->table->columnCount(); ++j) {
				QTableWidgetItem* item = meView->getUi()->table->item(i, j);
				if (item) {
					item->setBackground(QColor(232, 235, 237)); // Màu xám nhạt
				}
			}
		}
	}
}

void ManageEmployeeController::handleRowClicked(const QModelIndex& index) {
	if (!index.isValid()) {
		return; // Kiểm tra xem chỉ mục có hợp lệ không
	}

	meView->getUi()->edit->setDisabled(false);
	meView->getUi()->delete_2->setDisabled(false);

	employeeSelected = index.sibling(index.row(), 0).data().toString();

}

void ManageEmployeeController::onClickEdit() {
	EmployeeModel employee = EmployeeRepository::getById(employeeSelected);

	DialogFormEmployee* dialog = new DialogFormEmployee(meView);
	dialog->setMode(true);
	renderDepartments(dialog->getUi());
	dialog->setValue(employee);

	connect(dialog, &DialogFormEmployee::uploadAvatar, this, &ManageEmployeeController::handleUploadAvatar);
	connect(dialog, &DialogFormEmployee::submit, this, &ManageEmployeeController::submitEmployee);

	dialog->exec();

}

void ManageEmployeeController::onClickDelete() {
	DialogConfirm* confirm = new DialogConfirm("Do you really want to delete employee ?", nullptr);
	if (confirm->exec() == QDialog::Accepted) {
		if (EmployeeRepository::_delete(employeeSelected)) {
			handleRenderTable();
		}
		else {
			qDebug() << "Xoá thất bại";
		};
	}
}

void ManageEmployeeController::submitEmployee(const EmployeeModel& employee, bool isEditMode, DialogFormEmployee* employeeView) {
	DatabaseManager::connectToDatabase();

	// Nếu không phải là mode edit
	if (!isEditMode) {
		// Kiểm tra xem id có tồn tại không
		if (!EmployeeRepository::getById(employee.getId()).getId().isEmpty()) {
			ErrorLabel* error = new ErrorLabel("  Employee ID exists.");
			error->showTemporary(employeeView->getUi().errorLayout, 3000);
			return;
		}
		if (EmployeeRepository::add(employee)) {
			handleRenderTable();
		}
		else {
			ErrorLabel* error = new ErrorLabel("  Addition failed.");
			error->showTemporary(employeeView->getUi().errorLayout, 3000);
			return;
		}
	}
	else {
		if (EmployeeRepository::update(employee)) {
			handleRenderTable();
		}
		else {
			ErrorLabel* error = new ErrorLabel("  Update failed.");
			error->showTemporary(employeeView->getUi().errorLayout, 3000);
			return;
		}
	}

	employeeView->accept();

	DatabaseManager::closeDatabase();
}

void ManageEmployeeController::handleToggleEnabled(QString id, bool checked) {
	DatabaseManager::connectToDatabase();
	EmployeeRepository::toggleEnabled(id, checked);
	DatabaseManager::closeDatabase();
}

void ManageEmployeeController::handleUploadAvatar(DialogFormEmployee* employeeForm, bool isEditMode_employee) {
	DatabaseManager::connectToDatabase();
	QString picpath = QFileDialog::getOpenFileName(nullptr, tr("Open file"), "C://Users//MY PC//OneDrive//Pictures", "JPG File(*.jpg);;PNG File(*.png)");
	QString savePath = "D://IriTech//Code//ManageEmployee//image//" + QFileInfo(picpath).baseName() + "_" + employeeSelected + "." + QFileInfo(picpath).suffix();
	QFile::copy(picpath, savePath);

	QPixmap avatar;
	avatar.load(savePath);

	QGraphicsScene* scene = new QGraphicsScene(this);
	scene->addPixmap(avatar);

	employeeForm->getUi().avatar->setScene(scene);
	employeeForm->getUi().avatar->fitInView(scene->itemsBoundingRect(), Qt::KeepAspectRatio);

	employeeForm->avatarPath = savePath;

	if (isEditMode_employee) {
		EmployeeRepository::changeAvatar(savePath, employeeSelected);
	}

	DatabaseManager::closeDatabase();
}

void ManageEmployeeController::renderDepartments(Ui::DialogFormEmployeeClass employeeForm) {
	QList<DepartmentModel> employeeList = DepartmentRepository::getAll();

	for (int i = 0; i < employeeList.size(); i++) {
		employeeForm.department->addItem(employeeList.at(i).getName());
	}
}

ManageEmployee* ManageEmployeeController::getMeView() {
	return meView;
}