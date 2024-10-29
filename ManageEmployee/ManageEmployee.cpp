#include "ManageEmployee.h"
#include <QAbstractItemView>
#include <QStandardItem>
#include <QSettings>
#include <QTableWidgetItem>
#include <QCheckBox>

QString employeeSelected = "";

ManageEmployee::ManageEmployee(QWidget* parent)
	: QWidget(parent)
{
	ui.setupUi(this);

	df_employee = new DialogFormEmployee(this);

	ui.table->setEditTriggers(QAbstractItemView::NoEditTriggers);

	handleRenderTable();
	ui.edit->setDisabled(true);
	ui.delete_2->setDisabled(true);

	connect(ui.add, SIGNAL(clicked()), this, SLOT(handleClickAdd()));
	connect(ui.edit, SIGNAL(clicked()), this, SLOT(handleEdit()));
	connect(ui.delete_2, SIGNAL(clicked()), this, SLOT(handleDelete()));

	connect(df_employee, &DialogFormEmployee::excuteDBSuccessful, this, &ManageEmployee::handleRenderTable);
	connect(ui.table, &QTableView::clicked, this, &ManageEmployee::handleRowClicked);
	connect(ui.table, &QTableView::doubleClicked, this, [this]() {
		&ManageEmployee::handleRowClicked;
		handleEdit();
		});
}

ManageEmployee::~ManageEmployee()
{}

void ManageEmployee::handleClickAdd() {
	df_employee->setMode(false);

	df_employee->exec();
}

void ManageEmployee::handleRenderTable() {
	db.connectToDatabase();

	QString query = "SELECT * FROM employee WHERE role = 'STAFF'";
	QSqlQuery result = db.executeQuery(query);

	// Đếm số hàng
	int rowCount = 0;
	while (result.next()) {
		rowCount++;
	}

	result.clear();
	result = db.executeQuery(query);

	ui.table->setRowCount(rowCount);
	ui.table->setColumnCount(7);
	ui.table->setHorizontalHeaderLabels({ "Mã Số", "Họ Tên", "Ngày Sinh", "Ngày Bắt Đầu", "Trạng thái", "Phòng Ban", "Hoạt Động" });

	int row = 0;
	while (result.next()) {
		ui.table->setItem(row, 0, new QTableWidgetItem(result.value(0).toString()));
		ui.table->setItem(row, 1, new QTableWidgetItem(result.value(1).toString() + " " + result.value(2).toString()));
		ui.table->setItem(row, 2, new QTableWidgetItem(result.value(5).toString()));
		ui.table->setItem(row, 3, new QTableWidgetItem(result.value(6).toString()));
		ui.table->setItem(row, 4, new QTableWidgetItem(result.value(7).toString()));
		ui.table->setItem(row, 5, new QTableWidgetItem(result.value(4).toString()));

		// Tạo QRadioButton cho cột "Hoạt Động"
		QCheckBox* checkBox = new QCheckBox();
		checkBox->setChecked(result.value(8).toBool());
		ui.table->setCellWidget(row, 6, checkBox);

		connect(checkBox, &QCheckBox::toggled, this, [this, row](bool checked) {
			QModelIndex index = ui.table->model()->index(row, 0); // Cột thứ nhất có chỉ số là 0
			QString id = ui.table->model()->data(index).toString();

			handleToggleEnabled(id, checked);
			});

		row++;
	}


	ui.table->resizeColumnsToContents();


	db.closeDatabase();
}

void ManageEmployee::handleRowClicked(const QModelIndex& index) {
	if (!index.isValid()) {
		return; // Kiểm tra xem chỉ mục có hợp lệ không
	}

	ui.edit->setDisabled(false);
	ui.delete_2->setDisabled(false);

	employeeSelected = index.sibling(index.row(), 0).data().toString();
}

void ManageEmployee::handleEdit() {

	QString query = "SELECT * FROM employee WHERE id = '" + employeeSelected + "'; ";
	QSqlQuery result = db.executeQuery(query);

	df_employee->setMode(true);
	df_employee->setValue(result);

	df_employee->exec();
}

void ManageEmployee::handleDelete() {
	db.connectToDatabase();

	qDebug() << employeeSelected;

	QString query = "DELETE FROM employee WHERE id = '" + employeeSelected + "';";
	if (!db.executeCreate(query)) {
		msgBox.setText("Xoá thất bại");
		msgBox.exec();
		return;
	}

	handleRenderTable();

	msgBox.setText("Xoá thành công");
	msgBox.exec();


	db.closeDatabase();
}

void ManageEmployee::handleToggleEnabled(QString id, bool checked) {
	QString query = "UPDATE employee SET is_enabled = :is_enabled WHERE id = :id;";

	QMap<QString, QVariant> params;
	params[":is_enabled"] = checked; 
	params[":id"] = id; 

	db.connectToDatabase();
	db.executeCreate(query, params);
	db.closeDatabase();
}