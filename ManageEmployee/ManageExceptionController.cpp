#include "ManageExceptionController.h"
#include "DatabaseSingleton.h"
#include "ErrorLabel.h"
#include "DialogConfirm.h"
#include "DialogAssignmentException.h"
#include <QDebug>

ManageExceptionController::ManageExceptionController(ManageException* view, QObject* parent)
	: QObject(parent), mexView(view)
{
	handleRenderTable();

	connect(mexView->getUi()->add, SIGNAL(clicked()), this, SLOT(onClickAdd()));
	connect(mexView->getUi()->edit, SIGNAL(clicked()), this, SLOT(onClickEdit()));
	connect(mexView->getUi()->delete_2, SIGNAL(clicked()), this, SLOT(onClickDelete()));
	connect(mexView->getUi()->assignment, SIGNAL(clicked()), this, SLOT(onClickAssignment()));

	connect(mexView->getUi()->table, &QTableView::clicked, this, &ManageExceptionController::handleRowClicked);
	connect(mexView->getUi()->table, &QTableView::doubleClicked, this, [this](const QModelIndex& index) {
		handleRowClicked(index);
		onClickEdit();
		});

}

ManageExceptionController::~ManageExceptionController()
{}

void ManageExceptionController::onClickAssignment() {
	DialogAssignmentException* dialog = new DialogAssignmentException(mexView);

	dialog->exec();
}

void ManageExceptionController::onClickAdd() {
	DialogFormException* dialog = new DialogFormException(mexView);
	dialog->setMode(false);

	connect(dialog, &DialogFormException::submit, this, &ManageExceptionController::submitException);

	dialog->exec();
}

void ManageExceptionController::handleRenderTable() {
	DatabaseSingleton::getInstance()->getDB()->connectToDatabase();

	QList<ExceptionModel> exceptionList = DatabaseSingleton::getInstance()->getDB()->getExceptionRepository()->getAll();

	mexView->getUi()->table->setRowCount(exceptionList.size());

	for (int i = 0; i < exceptionList.size(); i++) {
		mexView->getUi()->table->setItem(i, 0, new QTableWidgetItem(exceptionList.at(i).getName()));
		mexView->getUi()->table->setItem(i, 1, new QTableWidgetItem(exceptionList.at(i).getPaidHours()));
		mexView->getUi()->table->setItem(i, 2, new QTableWidgetItem(QString::number(exceptionList.at(i).getPaidCoefficient(), 'f', 2)));
		mexView->getUi()->table->setItem(i, 3, new QTableWidgetItem(QString::number(exceptionList.at(i).getWorkCoefficient(), 'f', 2)));
	}

	mexView->getUi()->table->verticalHeader()->setVisible(false);

	for (int i = 0; i < exceptionList.size(); ++i) {
		if (i % 2 == 0) { // Dòng chẵn
			for (int j = 0; j < mexView->getUi()->table->columnCount(); ++j) {
				QTableWidgetItem* item = mexView->getUi()->table->item(i, j);
				if (item) {
					item->setBackground(QColor(232, 235, 237)); // Màu xám nhạt
				}
			}
		}
	}
	DatabaseSingleton::getInstance()->getDB()->closeDatabase();
}

void ManageExceptionController::handleRowClicked(const QModelIndex& index) {
	if (!index.isValid()) {
		return;
	}

	mexView->getUi()->edit->setDisabled(false);
	mexView->getUi()->delete_2->setDisabled(false);

	QString exceptionName = index.sibling(index.row(), 0).data().toString();

	DatabaseSingleton::getInstance()->getDB()->connectToDatabase();

	exceptionSelected = DatabaseSingleton::getInstance()->getDB()->getExceptionRepository()->getByName(exceptionName);

	DatabaseSingleton::getInstance()->getDB()->closeDatabase();
}

void ManageExceptionController::onClickEdit() {
	DatabaseSingleton::getInstance()->getDB()->connectToDatabase();

	DialogFormException* dialog = new DialogFormException(mexView);
	dialog->setMode(true);
	dialog->setValue(exceptionSelected);

	connect(dialog, &DialogFormException::submit, this, &ManageExceptionController::submitException);

	dialog->exec();
	DatabaseSingleton::getInstance()->getDB()->closeDatabase();
}

void ManageExceptionController::onClickDelete() {
	DatabaseSingleton::getInstance()->getDB()->connectToDatabase();
	DialogConfirm* confirm = new DialogConfirm("Do you really want to delete exception ?", nullptr);
	if (confirm->exec() == QDialog::Accepted) {
		if (DatabaseSingleton::getInstance()->getDB()->getExceptionRepository()->_delete(exceptionSelected.getId())) {
			exceptionSelected = ExceptionModel();
			mexView->getUi()->edit->setDisabled(true);
			mexView->getUi()->delete_2->setDisabled(true);
			handleRenderTable();
		}
		else {
			qDebug() << "Xoá thất bại";

		};
	}
	DatabaseSingleton::getInstance()->getDB()->closeDatabase();
}

void ManageExceptionController::submitException(const ExceptionModel& exception, bool isEditMode, DialogFormException* exceptionView) {
	DatabaseSingleton::getInstance()->getDB()->connectToDatabase();
	// Nếu không phải là mode edit
	if (!isEditMode) {
		// Kiểm tra xem name có tồn tại không
		if (DatabaseSingleton::getInstance()->getDB()->getExceptionRepository()->getByName(exception.getName()).getName() != "") {
			ErrorLabel* error = new ErrorLabel("  The name already exists");
			error->showTemporary(exceptionView->getUi()->verticalLayout, 3000);
			return;
		}
		if (DatabaseSingleton::getInstance()->getDB()->getExceptionRepository()->add(exception)) {
			handleRenderTable();
		};
	}
	else {
		ExceptionModel exceptionFormat = exception;
		exceptionFormat.setId(exceptionSelected.getId());

		// Kiểm tra xem name có giống tên hiện tại ko thì bỏ qua check
		bool checkExistName = exception.getName() == exceptionSelected.getName();
		if (!checkExistName && DatabaseSingleton::getInstance()->getDB()->getExceptionRepository()->getByName(exception.getName()).getName() != "") {
			ErrorLabel* error = new ErrorLabel("  The name already exists");
			error->showTemporary(exceptionView->getUi()->verticalLayout, 3000);
			return;
		}
		if (DatabaseSingleton::getInstance()->getDB()->getExceptionRepository()->update(exceptionFormat)) {
			handleRenderTable();
		};
	}
	exceptionView->accept();

	DatabaseSingleton::getInstance()->getDB()->closeDatabase();

}

ManageException* ManageExceptionController::getMexView() {
	return mexView;
}