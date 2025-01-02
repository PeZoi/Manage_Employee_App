#include "DialogFormBulletin.h"
#include "DatabaseSingleton.h"
#include "Constant.h"
#include "ErrorLabel.h"
#include <QDate>
#include <QTableWidgetItem>
#include <QAbstractItemView>
#include <QLayout>
#include <QVBoxLayout>
#include <QCheckBox>
#include <QDebug>

DialogFormBulletin::DialogFormBulletin(QWidget* parent)
	: QDialog(parent)
	, ui(new Ui::DialogFormBulletinClass())
{
	ui->setupUi(this);

	this->setWindowTitle(tr("Form Bulletin"));

	QLinearGradient gradient(0, 0, 0, this->height());
	gradient.setColorAt(0.0, Qt::white);
	gradient.setColorAt(1.0, QColor("#87A8D2"));

	QPalette palette;
	palette.setBrush(QPalette::Window, gradient);
	this->setPalette(palette);
	this->setAutoFillBackground(true);

	ui->start_date->setDisplayFormat("dd/MM/yyyy");
	ui->start_date->setDate(QDate::currentDate());
	ui->end_date->setDisplayFormat("dd/MM/yyyy");
	ui->end_date->setDate(QDate::currentDate());

	ui->radio_all->setChecked(true);
	ui->checkBox_actived->setChecked(true);

	setDisabledEmployee(false);
	setDisabledDepartment(false);

	DatabaseSingleton::getInstance()->getDB()->connectToDatabase();

	departments = DatabaseSingleton::getInstance()->getDB()->getDepartmentRepository()->getAll();
	employees = DatabaseSingleton::getInstance()->getDB()->getEmployeeRepository()->getAll();

	DatabaseSingleton::getInstance()->getDB()->closeDatabase();

	renderDepartments(departments);
	renderEmployees(employees);

	connect(ui->radio_deparment, &QRadioButton::toggled, this, &DialogFormBulletin::setDisabledDepartment);
	connect(ui->radio_selection, &QRadioButton::toggled, this, &DialogFormBulletin::setDisabledEmployee);
	connect(ui->radio_all, &QRadioButton::toggled, this, [this](bool checked) {
		if (checked) {
			setDisabledEmployee(false);
			setDisabledDepartment(false);
		}
		});
	connect(ui->btn_no, &QPushButton::clicked, this, &DialogFormBulletin::onClickCancel);
	connect(ui->filter_employee, &QLineEdit::textChanged, this, &DialogFormBulletin::filterEmployee);
	connect(ui->btn_yes, &QPushButton::clicked, this, &DialogFormBulletin::handleSubmit); 
}

DialogFormBulletin::~DialogFormBulletin()
{
	delete ui;
}

void DialogFormBulletin::renderDepartments(QList<DepartmentModel> _departments) {
	for (int i = 0; i < _departments.size(); i++) {
		ui->department_list->addItem(_departments.at(i).getName());
	}
}
void DialogFormBulletin::renderEmployees(QList<EmployeeModel> employees) {
	QLayout* currentLayout = ui->employee_widget->layout();
	if (currentLayout != nullptr) {
		QLayoutItem* item;
		while ((item = currentLayout->takeAt(0)) != nullptr) {
			delete item->widget();
			delete item;
		}
		delete currentLayout;
	}

	QVBoxLayout* layout1 = new QVBoxLayout();

	for (const EmployeeModel& employee : employees) {
		QString fullname = employee.getFirstName() + " " + employee.getLastName();
		QString displayName = QString("%1 (%2)").arg(fullname).arg(employee.getId());
		QCheckBox* checkBox = new QCheckBox(displayName, this);
		layout1->addWidget(checkBox);
	}

	ui->employee_widget->setLayout(layout1);
}

void DialogFormBulletin::setDisabledEmployee(bool check) {
	ui->filter_employee->setDisabled(!check); // vì check lấy isChecked của radio nên hơi ngược
	ui->employee_widget->setDisabled(!check);
}
void DialogFormBulletin::setDisabledDepartment(bool check) {
	ui->department_list->setDisabled(!check);
}

void DialogFormBulletin::filterEmployee(const QString& name) {
	QList<EmployeeModel> filteredEmployees;
	for (const EmployeeModel& employee : employees) {
		QString fullname = employee.getFirstName() + " " + employee.getLastName();
		QString displayName = QString("%1 (%2)").arg(fullname).arg(employee.getId());
		if (displayName.contains(name, Qt::CaseInsensitive)) {
			filteredEmployees.append(employee);
		}
	}

	renderEmployees(filteredEmployees);
}

void DialogFormBulletin::onClickCancel() {
	this->accept();
}
void DialogFormBulletin::handleSubmit() {
	QString title = ui->title->text();
	QString content = ui->content->toPlainText();
	QString startDate = ui->start_date->date().toString("dd/MM/yyyy");
	QString endDate = ui->end_date->date().toString("dd/MM/yyyy");
	bool isActive = ui->checkBox_actived->isChecked();
	bool isPriority = ui->checkBox_priority->isChecked();
	bool radio_all = ui->radio_all->isChecked();
	bool radio_department = ui->radio_deparment->isChecked();
	bool radio_employee = ui->radio_selection->isChecked();
	QString department = ui->department_list->currentText();
	QString type = radio_all ? Constant::B_TYPE_ALL : radio_department ? Constant::B_TYPE_DEPARTMENT : Constant::B_TYPE_EMPLOYEE;

	if (title.isEmpty() || content.isEmpty()) {
		ErrorLabel* error = new ErrorLabel("  Please fill in the name field");
		error->showTemporary(ui->verticalLayout, 3000);
		return;
	}

	BulletinModel bulletin = BulletinModel(0, title, content, startDate, endDate, isActive, isPriority, type);
	bulletin.setDepartment(department);

	// Handle get employee id list checked
	QLayout* currentLayout = ui->employee_widget->layout();
	QLayoutItem* item;
	while ((item = currentLayout->takeAt(0)) != nullptr) {
		QCheckBox* checkBox = qobject_cast<QCheckBox*>(item->widget());
		if (checkBox != nullptr && checkBox->isChecked()) {
			QRegularExpression re("\\(([^)]+)\\)");
			QRegularExpressionMatch match = re.match(checkBox->text());
			bulletin.addEmployee(match.captured(1));
		}
		delete item;
	}

	if (bulletin.getType() == Constant::B_TYPE_EMPLOYEE && bulletin.getEmployeeIds().isEmpty()) {
		ErrorLabel* error = new ErrorLabel("  Please select employee");
		error->showTemporary(ui->verticalLayout, 3000);
		return;
	}

	emit submit(bulletin, isEditMode, this);
}
void DialogFormBulletin::setMode(bool _isEditMode) {
	isEditMode = _isEditMode;
}
void DialogFormBulletin::setValue(BulletinModel bulletin) {
	ui->title->setText(bulletin.getTitle());
	ui->content->setPlainText(bulletin.getContent());
	ui->start_date->setDate(QDate::fromString(bulletin.getStartDate(), "dd/MM/yyyy"));
	ui->end_date->setDate(QDate::fromString(bulletin.getEndDate(), "dd/MM/yyyy"));
	ui->checkBox_actived->setChecked(bulletin.getIsActive());
	ui->checkBox_priority->setChecked(bulletin.getIsPriority());
	ui->radio_all->setChecked(bulletin.getType() == Constant::B_TYPE_ALL);
	ui->radio_deparment->setChecked(bulletin.getType() == Constant::B_TYPE_DEPARTMENT);
	ui->radio_selection->setChecked(bulletin.getType() == Constant::B_TYPE_EMPLOYEE);

	if (bulletin.getType() == Constant::B_TYPE_DEPARTMENT) {
		ui->department_list->setCurrentText(bulletin.getDepartment());
	}
	else if (bulletin.getType() == Constant::B_TYPE_EMPLOYEE) {
		// Handle init checkbox if checked
		QLayout* currentLayout = ui->employee_widget->layout();

		for (int i = 0; i < currentLayout->count(); ++i) {
			QLayoutItem* item = currentLayout->itemAt(i);
			QCheckBox* checkBox = qobject_cast<QCheckBox*>(item->widget());

			if (checkBox) {
				QRegularExpression re("\\(([^)]+)\\)"); 
				QRegularExpressionMatch match = re.match(checkBox->text());
				if (match.hasMatch()) {
					QString employeeId = match.captured(1); 

					if (bulletin.getEmployeeIds().contains(employeeId)) {
						checkBox->setChecked(true);
					}
					else {
						checkBox->setChecked(false);
					}
				}
			}
		}
	}
}

Ui::DialogFormBulletinClass* DialogFormBulletin::getUi() {
	return ui;
}
