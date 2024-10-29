#include "DialogFormDepartment.h"
#include "DepartmentModel.h"
#include "DepartmentRepository.h"


DialogFormDepartment::DialogFormDepartment(QWidget* parent)
	: QDialog(parent)
{
	ui.setupUi(this);

	connect(ui.submit, SIGNAL(clicked()), this, SLOT(handleSubmit()));
}

DialogFormDepartment::~DialogFormDepartment()
{}

// Kiểm tra xem tên có trùng không
bool DialogFormDepartment::checkNameDepartment(const QString& name) {
	DepartmentModel department = DepartmentRepository::getByName(name);
	if (department.getName() != "") {
		msgBox.setText("Tên phòng ban đã tồn tại");
		msgBox.exec();
		return true;
	}
	return false;
}

void DialogFormDepartment::handleSubmit() {
	QString name = ui.name->text();
	QString description = ui.description->text();

	if (name.trimmed().isEmpty()) {
		msgBox.setText("Trường tên không được để trống");
		msgBox.exec();
		return;
	}

	DepartmentModel department = DepartmentModel(name, description);

	emit submit(department, isEditMode_department);

	this->accept();
}

void DialogFormDepartment::setName(const QString& name) {
	ui.name->setText(name);
}

void DialogFormDepartment::setDescription(const QString& description) {
	ui.description->setText(description);
}

void DialogFormDepartment::setMode(bool _isEditMode) {
	ui.name->setDisabled(_isEditMode);
	isEditMode_department = _isEditMode;
}