#include "DialogFormDepartment.h"
#include "DepartmentModel.h"
#include "ErrorLabel.h"

DialogFormDepartment::DialogFormDepartment(QWidget* parent)
	: QDialog(parent), ui(new Ui::DialogFormDepartmentClass)
{
	ui->setupUi(this);

	this->setWindowTitle(tr("Form Department"));

	QLinearGradient gradient(0, 0, 0, this->height());
	gradient.setColorAt(0.0, Qt::white);
	gradient.setColorAt(1.0, QColor("#87A8D2"));

	QPalette palette;
	palette.setBrush(QPalette::Window, gradient);
	this->setPalette(palette);
	this->setAutoFillBackground(true);


	connect(ui->submit, SIGNAL(clicked()), this, SLOT(handleSubmit()));
	connect(ui->cancelButton, &QPushButton::clicked, this, [this]() {this->accept(); });
}

DialogFormDepartment::~DialogFormDepartment()
{}

void DialogFormDepartment::handleSubmit() {
	QString name = ui->name->text();
	QString description = ui->description->text();

	if (name.trimmed().isEmpty()) {
		ErrorLabel* error = new ErrorLabel(tr("  The name field cannot be left empty"));
		error->showTemporary(ui->verticalLayout, 3000);
		return;
	}

	DepartmentModel department = DepartmentModel(name, description);

	emit submit(department, isEditMode_department, this);

}

void DialogFormDepartment::setName(const QString& name) {
	ui->name->setText(name);
}

void DialogFormDepartment::setDescription(const QString& description) {
	ui->description->setText(description);
}

void DialogFormDepartment::setMode(bool _isEditMode) {
	ui->name->setDisabled(_isEditMode);
	isEditMode_department = _isEditMode;
}

Ui::DialogFormDepartmentClass* DialogFormDepartment::getUi() {
	return ui;
}