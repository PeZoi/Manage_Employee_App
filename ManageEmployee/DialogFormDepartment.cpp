#include "DialogFormDepartment.h"

bool isEditMode_department = false;

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
	QString checkNameQuery = "SELECT COUNT(*) FROM department WHERE name = '" + name + "';";
	QSqlQuery result = db.executeQuery(checkNameQuery);
	if (result.next() && result.value(0).toInt() > 0) {
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

	db.connectToDatabase();

	// Nếu không phải là mode edit
	if (!isEditMode_department) {
		// Kiểm tra xem name có tồn tại không
		if (checkNameDepartment(name)) {
			msgBox.setText("Tên phòng ban đã tồn tại");
			msgBox.exec();
		}
		QString insertEmployeeQuery = "INSERT INTO department (name, description) "
			"VALUES (:name, :description);";

		QMap<QString, QVariant> params;
		params[":name"] = name;
		params[":description"] = description;

		if (!db.executeCreate(insertEmployeeQuery, params)) {
			msgBox.setText("Tạo phòng ban thất bại");
			msgBox.exec();
		}
	}
	else {
		QString editEmployeeQuery = "UPDATE department SET description = :description "
			"WHERE name = :name";

		QMap<QString, QVariant> params;
		params[":name"] = name;
		params[":description"] = description;

		if (!db.executeCreate(editEmployeeQuery, params)) {
			msgBox.setText("Sửa phòng ban thất bại");
			msgBox.exec();
		}
	}

	emit excuteDBSuccessful();

	db.closeDatabase();
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