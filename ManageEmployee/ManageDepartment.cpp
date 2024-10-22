#include "ManageDepartment.h"
#include <QAbstractItemView>
#include <QStandardItem>

QString departmentSelected = "";

ManageDepartment::ManageDepartment(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
	df_department = new DialogFormDepartment(this);

	ui.table->setEditTriggers(QAbstractItemView::NoEditTriggers);

	handleRenderTable();
	ui.edit->setDisabled(true);
	ui.delete_2->setDisabled(true);

	connect(ui.add, SIGNAL(clicked()), this, SLOT(handleClickAdd()));
	connect(ui.edit, SIGNAL(clicked()), this, SLOT(handleEdit()));
	connect(ui.delete_2, SIGNAL(clicked()), this, SLOT(handleDelete()));

	connect(df_department, &DialogFormDepartment::excuteDBSuccessful, this, &ManageDepartment::handleRenderTable);

	connect(ui.table, &QTableView::clicked, this, &ManageDepartment::handleRowClicked);
}

ManageDepartment::~ManageDepartment()
{}

void ManageDepartment::handleClickAdd() {
	df_department->exec();
}

void ManageDepartment::handleRenderTable() {
	db.connectToDatabase();

	QString query = "SELECT name, description FROM department";
	QSqlQuery result = db.executeQuery(query);

	// Đếm số hàng
	int rowCount = 0;
	while (result.next()) {
		rowCount++;
	}

	result.clear();
	result = db.executeQuery(query);

	QStandardItemModel* model = new QStandardItemModel(rowCount, 2, this);
	model->setHorizontalHeaderLabels({ "Tên", "Mô tả" });

	ui.table->setModel(model);

	int row = 0;
	while (result.next()) {
		model->setItem(row, 0, new QStandardItem(result.value("name").toString()));
		model->setItem(row, 1, new QStandardItem(result.value("description").toString()));
		row++;
	}

	
	ui.table->resizeColumnsToContents();


	db.closeDatabase();
}

void ManageDepartment::handleRowClicked(const QModelIndex& index) {
	if (!index.isValid()) {
		return; // Kiểm tra xem chỉ mục có hợp lệ không
	}

	ui.edit->setDisabled(false);
	ui.delete_2->setDisabled(false);

	departmentSelected = index.sibling(index.row(), 0).data().toString();
}

void ManageDepartment::handleEdit() {
	qDebug() << departmentSelected;
}

void ManageDepartment::handleDelete() {
	db.connectToDatabase();

	QString query = "DELETE FROM department WHERE name = " + departmentSelected + " ;";
	if (!db.executeCreate(query)) {
		msgBox.setText("Xoá thất bại");
		msgBox.exec();
	}

	handleRenderTable();

	msgBox.setText("Xoá thành công");
	msgBox.exec();


	db.closeDatabase();
}