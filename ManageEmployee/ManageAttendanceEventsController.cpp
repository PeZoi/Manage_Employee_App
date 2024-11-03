#include "ManageAttendanceEventsController.h"
#include "CustomFilterProxyModel.h"
#include "DialogFormAttendanceEvents.h"
#include "EmployeeRepository.h"
#include "AttendanceEventRepository.h"
#include "DialogDeleteAttendanceEvent.h"
#include "ErrorLabel.h"
#include "Utils.h"
#include <QStandardItemModel>
#include <QSortFilterProxyModel>

ManageAttendanceEventsController::ManageAttendanceEventsController(ManageAttendanceEvents* view, QObject* parent)
	: QObject(parent), view(view)
{
	loadEmployee();

	connect(view->getUi()->add, &QPushButton::clicked, this, &ManageAttendanceEventsController::onClickAdd);
	connect(view->getUi()->delete_2, &QPushButton::clicked, this, &ManageAttendanceEventsController::onClickDelete);
	connect(view->getUi()->check_out, &QPushButton::clicked, this, &ManageAttendanceEventsController::handleCheckout);

	connect(view->getUi()->companyTreeView, &QTreeView::clicked, this, &ManageAttendanceEventsController::handleSelectEmployee);

	connect(view->getUi()->table, &QTableView::clicked, this, &ManageAttendanceEventsController::handleRowClicked);
	connect(view->getUi()->table, &QTableView::doubleClicked, this, [this](const QModelIndex& index) {
		handleRowClicked(index);
		onClickEdit();
		});

}

ManageAttendanceEvents* ManageAttendanceEventsController::getView() {
	return view;
}


void ManageAttendanceEventsController::loadEmployee() {
	QStandardItemModel* model = new QStandardItemModel(this);
	view->getUi()->companyTreeView->header()->setVisible(false);

	QList<DepartmentModel> departmentList = DepartmentRepository::getAll();

	for (int i = 0; i < departmentList.size(); i++) {
		QList<EmployeeModel> employeeList = EmployeeRepository::getByDepartment(departmentList.at(i).getName());

		QString departmentDisplay = QString("%1 (%2)").arg(departmentList.at(i).getName()).arg(employeeList.size());
		QStandardItem* departmentItem = new QStandardItem(departmentDisplay);
		departmentItem->setFlags(departmentItem->flags() & ~Qt::ItemIsEditable);

		for (int j = 0; j < employeeList.size(); j++) {
			QString id = employeeList.at(j).getId();
			QString fullname = employeeList.at(j).getFirstName() + " " + employeeList.at(j).getLastName();
			QString employeeDisplay = QString("%1 (%2)").arg(fullname).arg(id);

			QStandardItem* employeeItem = new QStandardItem(employeeDisplay);
			if (employeeList.at(j).getIsEnabled()) {
				employeeItem->setIcon(QIcon("D:\\IriTechCode\\ManageEmployee\\icon\\avatar.png"));
			}
			else {
				employeeItem->setIcon(QIcon("D:\\IriTechCode\\ManageEmployee\\icon\\ban.png"));
			}
			employeeItem->setFlags(employeeItem->flags() & ~Qt::ItemIsEditable);

			departmentItem->appendRow(employeeItem);
		}

		model->appendRow(departmentItem);
	}

	CustomFilterProxyModel* filterModel = new CustomFilterProxyModel(this);
	filterModel->setSourceModel(model);
	filterModel->setFilterCaseSensitivity(Qt::CaseInsensitive);
	filterModel->setFilterKeyColumn(0);

	view->getUi()->companyTreeView->setModel(filterModel);
	view->getUi()->companyTreeView->expandAll();

	connect(view->getUi()->searchLineEdit, &QLineEdit::textChanged, filterModel, &CustomFilterProxyModel::setFilterFixedString);
}

void ManageAttendanceEventsController::onClickAdd() {
	DialogFormAttendanceEvents* dialog = new DialogFormAttendanceEvents(employeeSelected, nullptr);
	dialog->setMode(false);

	connect(dialog, &DialogFormAttendanceEvents::submit, this, &ManageAttendanceEventsController::handleSubmit);

	dialog->exec();
}
void ManageAttendanceEventsController::onClickEdit() {
	DatabaseManager::connectToDatabase();
	QList<AttendanceEventModel> events = AttendanceEventRepository::getBySession(attendanceEventSelected.getSession());
	qDebug() << attendanceEventSelected.getSession();
	DialogFormAttendanceEvents* dialog = new DialogFormAttendanceEvents(employeeSelected, nullptr);
	dialog->setMode(true);
	dialog->setValue(events);

	connect(dialog, &DialogFormAttendanceEvents::submit, this, &ManageAttendanceEventsController::handleSubmit);

	dialog->exec();
	DatabaseManager::closeDatabase();
}
void ManageAttendanceEventsController::onClickDelete() {
	DatabaseManager::connectToDatabase();
	DialogDeleteAttendanceEvent* dialog = new DialogDeleteAttendanceEvent(nullptr);

	QList<AttendanceEventModel> events = AttendanceEventRepository::getBySession(attendanceEventSelected.getSession());
	dialog->getUi()->date_checkin->setText(events.at(0).getDateEvent());
	dialog->getUi()->time_checkin->setText(events.at(0).getTime());
	if (events.size() == 2) {
		dialog->getUi()->date_checkout->setText(events.at(1).getDateEvent());
		dialog->getUi()->time_checkout->setText(events.at(1).getTime());
	}
	else {
		dialog->getUi()->checkout->hide();
	}

	if (dialog->exec() == QDialog::Accepted) {
		if (!AttendanceEventRepository::deleteBySession(attendanceEventSelected.getSession())) {
			ErrorLabel* error = new ErrorLabel("  Delete failed.");
			error->showTemporary(view->getUi()->verticalLayout, 3000);
			return;
		}
	}

	handleRenderTable();

	DatabaseManager::closeDatabase();
	dialog->accept();
}
void ManageAttendanceEventsController::handleCheckout() {
	DatabaseManager::connectToDatabase();

	QList<AttendanceEventModel> events = AttendanceEventRepository::getByEmployeeId(employeeSelected);
	QDateTime checkinLastest = QDateTime::fromString("01/01/1990 00:00:00", "dd/MM/yyyy HH:mm:ss");
	int sessionEvent = 0;

	for (int i = 0; i < events.size(); i++) {
		if (events.at(i).getTypeEvent() == "OUT") {
			continue;
		}
		QDateTime checkint = QDateTime::fromString(events.at(i).getDateEvent() + " " + events.at(i).getTime(), "dd/MM/yyyy HH:mm:ss");
		if (checkint >= checkinLastest) {
			checkinLastest = checkint;
			sessionEvent = events.at(i).getSession();
		}
	}

	AttendanceEventModel attendanceEvent;
	attendanceEvent.setSession(sessionEvent);
	attendanceEvent.setEmployeeId(employeeSelected);
	attendanceEvent.setException(0);
	attendanceEvent.setTypeEvent("OUT");
	attendanceEvent.setDateEvent(QDate::currentDate().toString("dd/MM/yyyy"));
	attendanceEvent.setTime(QTime::currentTime().toString("HH:mm:ss"));

	if (!AttendanceEventRepository::add(attendanceEvent)) {
		ErrorLabel* error = new ErrorLabel("  Checkout failed");
		error->showTemporary(view->getUi()->verticalLayout, 3000);
		return;
	}

	EmployeeRepository::updateStatus("OUT", employeeSelected);
	view->getUi()->check_out->setDisabled(true);

	handleRenderTable();
	DatabaseManager::closeDatabase();
}

void ManageAttendanceEventsController::handleSelectEmployee(const QModelIndex& index) {
	DatabaseManager::connectToDatabase();

	CustomFilterProxyModel* filterModel = qobject_cast<CustomFilterProxyModel*>(view->getUi()->companyTreeView->model());
	QStandardItemModel* sourceModel = qobject_cast<QStandardItemModel*>(filterModel->sourceModel());

	// Chuyển đổi QModelIndex của CustomFilterProxyModel sang QModelIndex của QStandardItemModel
	QModelIndex sourceIndex = filterModel->mapToSource(index);

	// Lấy QStandardItem từ QModelIndex của QStandardItemModel
	QStandardItem* item = sourceModel->itemFromIndex(sourceIndex);

	if (item) {
		// Kiểm tra xem item có phải là nhân viên không
		if (item->parent() != nullptr) {
			QRegularExpression re("\\(([^)]+)\\)");
			QRegularExpressionMatch match = re.match(item->text());
			employeeSelected = match.captured(1);

			handleRenderTable();

			EmployeeModel employee = EmployeeRepository::getById(employeeSelected);

			view->getUi()->add->setDisabled(false);

			// Nếu nhân viên đang có trạng thái là In thì bỏ disable nút check out
			if (employee.getStatus() == "IN") {
				view->getUi()->check_out->setDisabled(false);
			}
		}
	}

	DatabaseManager::closeDatabase();
}

void ManageAttendanceEventsController::handleRenderTable() {
	DatabaseManager::connectToDatabase();

	QList<AttendanceEventModel> eventList = AttendanceEventRepository::getByEmployeeId(employeeSelected);
	view->getUi()->table->setRowCount(eventList.size());

	for (int i = 0; i < eventList.size(); i++) {
		view->getUi()->table->setItem(i, 0, new QTableWidgetItem(eventList.at(i).getTypeEvent()));
		view->getUi()->table->setItem(i, 1, new QTableWidgetItem(eventList.at(i).getDateEvent()));
		view->getUi()->table->setItem(i, 2, new QTableWidgetItem(eventList.at(i).getTime()));
		view->getUi()->table->setItem(i, 3, new QTableWidgetItem(eventList.at(i).getException() == 0 ? " " : " "));
	}

	view->getUi()->table->verticalHeader()->setVisible(false);

	for (int i = 0; i < eventList.size(); ++i) {
		if (i % 2 == 0) {
			for (int j = 0; j < view->getUi()->table->columnCount(); ++j) {
				QTableWidgetItem* item = view->getUi()->table->item(i, j);
				if (item) {
					item->setBackground(QColor(232, 235, 237));
				}
			}
		}
	}

	DatabaseManager::closeDatabase();
}

void ManageAttendanceEventsController::handleSubmit(QString _employeeSelected, bool isEditMode, DialogFormAttendanceEvents* dialog) {
	DatabaseManager::connectToDatabase();
	EmployeeModel employee = EmployeeRepository::getById(_employeeSelected);
	bool checkStatusIn = employee.getStatus() == "IN" ? true : false;


	QString dateCheckin = dialog->getUi()->dateTime_checkin->dateTime().toString("dd/MM/yyyy");
	QString timeCheckin = dialog->getUi()->dateTime_checkin->dateTime().toString("HH:mm:ss");
	QDateTime dateTimeCheckin = dialog->getUi()->dateTime_checkin->dateTime();

	QString dateCheckout = dialog->getUi()->dateTime_checkout->dateTime().toString("dd/MM/yyyy");
	QString timeCheckout = dialog->getUi()->dateTime_checkout->dateTime().toString("HH:mm:ss");
	QDateTime dateTimeCheckout = dialog->getUi()->dateTime_checkout->dateTime();

	AttendanceEventModel attendanceEvent;

	if (dialog->getUi()->radio_in_out->isChecked()) {

		if (checkStatusIn) {
			ErrorLabel* error = new ErrorLabel("  Cannot add this event. The 'IN' event exists.");
			error->showTemporary(dialog->getUi()->verticalLayout, 3000);
			return;
		}
		QList<AttendanceEventModel> events = AttendanceEventRepository::getByEmployeeId(employeeSelected);

		for (int i = 0; i < events.size(); i = i + 2) {
			QDateTime checkinDB = QDateTime::fromString(events.at(i).getDateEvent() + " " + events.at(i).getTime(), "dd/MM/yyyy HH:mm:ss");
			QDateTime checkoutDB = QDateTime::fromString(events.at(i + 1).getDateEvent() + " " + events.at(i + 1).getTime(), "dd/MM/yyyy HH:mm:ss");

			// check điều kiện cho edit
			if (dateTimeCheckin == checkinDB && dateTimeCheckout == checkoutDB && isEditMode) {
				break;
			}

			if (dateTimeCheckin == checkinDB && (checkinDB <= dateTimeCheckout && checkoutDB >= dateTimeCheckout) && attendanceEventSelected.getSession() != events.at(i).getSession()) {
				ErrorLabel* error = new ErrorLabel("  Time duplicates with other event.");
				error->showTemporary(dialog->getUi()->verticalLayout, 3000);
				return;
			}

			if (checkinDB <= dateTimeCheckout && checkoutDB >= dateTimeCheckout && attendanceEventSelected.getSession() != events.at(i).getSession()) {
				ErrorLabel* error = new ErrorLabel("  Event time is overlapped with other events.");
				error->showTemporary(dialog->getUi()->verticalLayout, 3000);
				return;
			}

			if (checkinDB <= dateTimeCheckin && checkoutDB >= dateTimeCheckin && attendanceEventSelected.getSession() != events.at(i).getSession()) {
				ErrorLabel* error = new ErrorLabel("  Event time is overlapped with other events.");
				error->showTemporary(dialog->getUi()->verticalLayout, 3000);
				return;
			}

			if (dateTimeCheckin <= checkinDB && dateTimeCheckout >= checkoutDB && attendanceEventSelected.getSession() != events.at(i).getSession()) {
				ErrorLabel* error = new ErrorLabel("  Event time is overlapped with other events.");
				error->showTemporary(dialog->getUi()->verticalLayout, 3000);
				return;
			}
		}

		QList<AttendanceEventModel> checkin_outList = AttendanceEventRepository::getBySession(attendanceEventSelected.getSession());

		if (!isEditMode) {
			qint64 session = QDateTime::currentDateTime().toSecsSinceEpoch();
			attendanceEvent.setSession(session);
		}
		attendanceEvent.setEmployeeId(_employeeSelected);
		attendanceEvent.setException(0);

		// IN
		attendanceEvent.setTypeEvent("IN");
		attendanceEvent.setDateEvent(dateCheckin);
		attendanceEvent.setTime(timeCheckin);
		if (isEditMode) {
			attendanceEvent.setId(checkin_outList.at(0).getId());
			attendanceEvent.setSession(checkin_outList.at(0).getSession());
		}

		if (!isEditMode) {
			if (!AttendanceEventRepository::add(attendanceEvent)) {
				ErrorLabel* error = new ErrorLabel("  Additon failed");
				error->showTemporary(dialog->getUi()->verticalLayout, 3000);
				return;
			}
		}
		else {
			if (!AttendanceEventRepository::update(attendanceEvent)) {
				ErrorLabel* error = new ErrorLabel("  Edit failed");
				error->showTemporary(dialog->getUi()->verticalLayout, 3000);
				return;
			}
		}


		// OUT
		attendanceEvent.setTypeEvent("OUT");
		attendanceEvent.setDateEvent(dateCheckout);
		attendanceEvent.setTime(timeCheckout);
		if (isEditMode) {
			attendanceEvent.setId(checkin_outList.at(1).getId());
			attendanceEvent.setSession(checkin_outList.at(1).getSession());
		}

		if (!isEditMode) {
			if (!AttendanceEventRepository::add(attendanceEvent)) {
				ErrorLabel* error = new ErrorLabel("  Additon failed");
				error->showTemporary(dialog->getUi()->verticalLayout, 3000);
				return;
			}
		}
		else {
			if (!AttendanceEventRepository::update(attendanceEvent)) {
				ErrorLabel* error = new ErrorLabel("  Edit failed");
				error->showTemporary(dialog->getUi()->verticalLayout, 3000);
				return;
			}
		}
	}

	if (dialog->getUi()->radio_in->isChecked()) {
		if (checkStatusIn && !isEditMode) {
			ErrorLabel* error = new ErrorLabel("  Cannot add this event. The 'IN' event exists.");
			error->showTemporary(dialog->getUi()->verticalLayout, 3000);
			return;
		}

		QList<AttendanceEventModel> events = AttendanceEventRepository::getByEmployeeId(_employeeSelected);
		QDateTime checkoutLast = QDateTime::fromString("01/01/1990 00:00:00", "dd/MM/yyyy HH:mm:ss");

		for (int i = 0; i < events.size(); i++) {
			if (events.at(i).getTypeEvent() == "IN") {
				continue;
			}
			QDateTime checkout = QDateTime::fromString(events.at(i).getDateEvent() + " " + events.at(i).getTime(), "dd/MM/yyyy HH:mm:ss");
			if (checkout >= checkoutLast) {
				checkoutLast = checkout;
			}
		}

		if (dateTimeCheckin <= checkoutLast) {
			ErrorLabel* error = new ErrorLabel("  The current event should be later than the previous normal event.");
			error->showTemporary(dialog->getUi()->verticalLayout, 3000);
			return;
		}

		QList<AttendanceEventModel> checkin_outList = AttendanceEventRepository::getBySession(attendanceEventSelected.getSession());

		if (!isEditMode) {
			qint64 session = QDateTime::currentDateTime().toSecsSinceEpoch();
			attendanceEvent.setSession(session);
		}
		else {
			attendanceEvent.setId(checkin_outList.at(0).getId());
			attendanceEvent.setSession(checkin_outList.at(0).getSession());
		}
		attendanceEvent.setEmployeeId(_employeeSelected);
		attendanceEvent.setException(0);
		attendanceEvent.setTypeEvent("IN");
		attendanceEvent.setDateEvent(dateCheckin);
		attendanceEvent.setTime(timeCheckin);

		if (!isEditMode) {
			if (!AttendanceEventRepository::add(attendanceEvent)) {
				ErrorLabel* error = new ErrorLabel("  Additon failed");
				error->showTemporary(dialog->getUi()->verticalLayout, 3000);
				return;
			}
		}
		else {
			if (!AttendanceEventRepository::update(attendanceEvent)) {
				ErrorLabel* error = new ErrorLabel("  Edit failed");
				error->showTemporary(dialog->getUi()->verticalLayout, 3000);
				return;
			}
		}

		view->getUi()->check_out->setDisabled(false);

		EmployeeRepository::updateStatus("IN", _employeeSelected);
	}

	if (dialog->getUi()->radio_out->isChecked()) {
		if (!checkStatusIn) {
			ErrorLabel* error = new ErrorLabel("  The current event should be later than the previous normal event.");
			error->showTemporary(dialog->getUi()->verticalLayout, 3000);
			return;
		}

		QList<AttendanceEventModel> events = AttendanceEventRepository::getByEmployeeId(employeeSelected);
		QList<int> sessionList;
		for (int i = 0; i < events.size(); i++) {
			sessionList.append(events.at(i).getSession());
		}

		int sessionSigle = Utils::getSigleNumber(sessionList);

		events = AttendanceEventRepository::getBySession(sessionSigle);
		QDateTime checkinDB = QDateTime::fromString(events.at(0).getDateEvent() + " " + events.at(0).getTime(), "dd/MM/yyyy HH:mm:ss");

		if (dateTimeCheckout <= checkinDB) {
			ErrorLabel* error = new ErrorLabel("  The current event should be later than the previous normal event.");
			error->showTemporary(dialog->getUi()->verticalLayout, 3000);
			return;
		}

		attendanceEvent.setSession(sessionSigle);
		attendanceEvent.setEmployeeId(_employeeSelected);
		attendanceEvent.setException(0);
		attendanceEvent.setTypeEvent("OUT");
		attendanceEvent.setDateEvent(dateCheckout);
		attendanceEvent.setTime(timeCheckout);

		if (!AttendanceEventRepository::add(attendanceEvent)) {
			ErrorLabel* error = new ErrorLabel("  Additon failed");
			error->showTemporary(dialog->getUi()->verticalLayout, 3000);
			return;
		}

		view->getUi()->check_out->setDisabled(true);

		EmployeeRepository::updateStatus("OUT", _employeeSelected);
	}

	dialog->accept();
	handleRenderTable();

	DatabaseManager::closeDatabase();
}

void ManageAttendanceEventsController::handleRowClicked(const QModelIndex& index) {
	DatabaseManager::connectToDatabase();
	if (!index.isValid()) {
		return; // Kiểm tra xem chỉ mục có hợp lệ không
	}
	QString dateEvent = index.sibling(index.row(), 1).data().toString();
	QString timeEvent = index.sibling(index.row(), 2).data().toString();

	attendanceEventSelected = AttendanceEventRepository::getByDateAndTime(dateEvent, timeEvent);

	view->getUi()->edit->setDisabled(false);
	view->getUi()->delete_2->setDisabled(false);
	DatabaseManager::closeDatabase();
}