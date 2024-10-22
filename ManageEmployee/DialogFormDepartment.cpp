#include "DialogFormDepartment.h"

DialogFormDepartment::DialogFormDepartment(QWidget *parent)
	: QDialog(parent)
{
	ui.setupUi(this);

	connect(ui.submit, SIGNAL(clicked()), this, SLOT(handleSubmit()));
}

DialogFormDepartment::~DialogFormDepartment()
{}

void DialogFormDepartment::handleSubmit() {
	QString name = ui.name->text();
	QString description = ui.description->text();

	if (name.trimmed().isEmpty()) {
		msgBox.setText("Trường tên không được để trống");
		msgBox.exec();
		return;
	}

	db.connectToDatabase();

	// Kiểm tra xem tên có trùng không
	QString checkNameQuery = "SELECT COUNT(*) FROM department WHERE name = " + name + ";";
	QSqlQuery result = db.executeQuery(checkNameQuery);
	if (result.next() && result.value(0).toInt() > 0) {
		msgBox.setText("Tên phòng ban đã tồn tại");
		msgBox.exec();
		return;
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

	emit excuteDBSuccessful();

	db.closeDatabase();
	this->accept();
}