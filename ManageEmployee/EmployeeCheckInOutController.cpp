#include "EmployeeCheckInOutController.h"
#include "CustomFilterProxyModel.h"
#include "Utils.h"
#include "IDatabaseManager.h"
#include "EmployeeModel.h"
#include "IriTrackerSingleton.h"
#include "DialogNotification.h"
#include "Constant.h"
#include "AudioUtils.h"
#include <QStandardItemModel>
#include <QTimer>
#include <QDate>
#include <QTime>
#include <QSortFilterProxyModel>
#include <QDebug>
#include <QWidget>

bool checkConnectSignal_IN_OUT = false;
bool _flagFoundDevice = false;

EmployeeCheckInOutController::EmployeeCheckInOutController(EmployeeCheckInOut* view, IDatabaseManager*& _db, QObject* parent)
	: QObject(parent), view(view), db(_db)
{
	iriTracker = new IriTracker();

	view->getUi()->stack_checkin_out->setCurrentIndex(0);
	view->getUi()->password->setEchoMode(QLineEdit::Password);

	loadEmployee();
	setupRealTimeClock();

	connect(view->getUi()->companyTreeView, &QTreeView::clicked, this, &EmployeeCheckInOutController::handleSelectEmployee);
	connect(view->getUi()->name_list, &QComboBox::currentTextChanged, this, &EmployeeCheckInOutController::handleSelectEmployeeByCombo);
	connect(view->getUi()->back, &QPushButton::clicked, this, [this]() {
		this->getView()->getUi()->stack_checkin_out->setCurrentIndex(0);
		});
	connect(view->getUi()->back_2, &QPushButton::clicked, this, [this]() {
		this->getView()->getUi()->stack_checkin_out->setCurrentIndex(0);
		});


	connect(view->getUi()->submit_checkin_out, &QPushButton::clicked, this, &EmployeeCheckInOutController::handleSubmitForPassword);
	connect(view->getUi()->show_all, &QPushButton::clicked, this, &EmployeeCheckInOutController::onClickShowAll);

	//connect(view, &EmployeeCheckInOut::onClickDevice, this, &EmployeeCheckInOutController::processStreaming);
	connect(IriTrackerSingleton::getIriTrackerGetDevice(), &IriTracker::foundDevice, this, &EmployeeCheckInOutController::switchImage, Qt::QueuedConnection);
	processStreaming();
}

EmployeeCheckInOut* EmployeeCheckInOutController::getView() {
	return view;
}

void EmployeeCheckInOutController::setupRealTimeClock() {
	QTimer* timer = new QTimer(this);

	connect(timer, &QTimer::timeout, this, &EmployeeCheckInOutController::updateDateTime);
	timer->start(1000);

	updateDateTime();
}

void EmployeeCheckInOutController::updateDateTime() {
	QLocale::setDefault(QLocale(QLocale::English, QLocale::UnitedStates));

	QString timeString = QTime::currentTime().toString("hh:mm:ss AP");
	QString dateString = QDate::currentDate().toString("dddd, MMMM d, yyyy");

	view->getUi()->timeLabel->setText(timeString);
	view->getUi()->dateLabel->setText(dateString);
}

void EmployeeCheckInOutController::onClickShowAll() {
	db->connectToDatabase();
	QList<EmployeeModel> employeeList = db->getEmployeeRepository()->getAll();

	view->getUi()->name_list->clear();
	view->getUi()->show_all->setDisabled(true);

	for (int i = 0; i < employeeList.size(); i++) {
		QString fullname = employeeList.at(i).getFirstName() + " " + employeeList.at(i).getLastName();
		QString displayName = QString("%1 (%2)").arg(fullname).arg(employeeList.at(i).getId());
		view->getUi()->name_list->addItem(displayName);
	}

	db->closeDatabase();
}

void EmployeeCheckInOutController::loadEmployee() {
	db->connectToDatabase();

	bool checkHasEmployee = false;

	QStandardItemModel* model = new QStandardItemModel(this);
	view->getUi()->companyTreeView->header()->setVisible(false);

	QList<DepartmentModel> departmentList = db->getDepartmentRepository()->getAll();

	for (int i = 0; i < departmentList.size(); i++) {
		QList<EmployeeModel> employeeList = db->getEmployeeRepository()->getByDepartment(departmentList.at(i).getName());

		QString departmentDisplay = QString("%1 (%2)").arg(departmentList.at(i).getName()).arg(employeeList.size());
		QStandardItem* departmentItem = new QStandardItem(departmentDisplay);
		departmentItem->setFlags(departmentItem->flags() & ~Qt::ItemIsEditable);

		for (int j = 0; j < employeeList.size(); j++) {
			checkHasEmployee = true;

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

	if (!checkHasEmployee) {
		view->getUi()->stackedWidget->setCurrentIndex(1);
	}

	db->closeDatabase();
}

void EmployeeCheckInOutController::handleSelectEmployee(const QModelIndex& index) {
	db->connectToDatabase();

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

			view->getUi()->stack_checkin_out->setCurrentIndex(1);

			EmployeeModel employee = db->getEmployeeRepository()->getById(employeeSelected);
			QList<EmployeeModel> employeeList = db->getEmployeeRepository()->getByDepartment(employee.getDepartment().getName());

			view->getUi()->name_list->clear();

			for (int i = 0; i < employeeList.size(); i++) {
				QString fullname = employeeList.at(i).getFirstName() + " " + employeeList.at(i).getLastName();
				QString displayName = QString("%1 (%2)").arg(fullname).arg(employeeList.at(i).getId());
				view->getUi()->name_list->addItem(displayName);
			}

			if (employee.getStatus() == "IN") {
				view->getUi()->submit_checkin_out->setText(tr("Check Out"));
			}
			else {
				view->getUi()->submit_checkin_out->setText(tr("Check In"));
			}

			view->getUi()->name_list->setCurrentText(item->text());
			view->getUi()->show_all->setDisabled(false);
			view->getUi()->password->setText("");
		}
	}

	db->closeDatabase();
}


void EmployeeCheckInOutController::handleSelectEmployeeByCombo(const QString& name) {
	db->connectToDatabase();

	QRegularExpression re("\\(([^)]+)\\)");
	QRegularExpressionMatch match = re.match(name);
	employeeSelected = match.captured(1);

	EmployeeModel employee = db->getEmployeeRepository()->getById(employeeSelected);

	if (employee.getStatus() == "IN") {
		view->getUi()->submit_checkin_out->setText("Check Out");
	}
	else {
		view->getUi()->submit_checkin_out->setText("Check In");
	}
	view->getUi()->password->setText("");

	db->closeDatabase();
}

void EmployeeCheckInOutController::handleAttendanceEventForEmployee(QString id) {
	EmployeeModel employee = db->getEmployeeRepository()->getById(id);

	AttendanceEventModel attendanceEvent;
	attendanceEvent.setException(0);
	attendanceEvent.setEmployeeId(id);
	attendanceEvent.setDateEvent(QDate::currentDate().toString("dd/MM/yyyy"));
	attendanceEvent.setTime(QTime::currentTime().toString("HH:mm:ss"));

	if (employee.getStatus() == "OUT") {
		qint64 session = QDateTime::currentDateTime().toSecsSinceEpoch();
		attendanceEvent.setSession(session);
		attendanceEvent.setTypeEvent("IN");
	}
	else {
		QList<AttendanceEventModel> events = db->getAttendanceEventRepository()->getByEmployeeId(id);
		QList<int> sessionList;
		for (int i = 0; i < events.size(); i++) {
			sessionList.append(events.at(i).getSession());
		}

		int sessionSigle = Utils::getSigleNumber(sessionList);

		attendanceEvent.setSession(sessionSigle);
		attendanceEvent.setTypeEvent("OUT");
	}

	if (!db->getAttendanceEventRepository()->add(attendanceEvent)) {
		// Báo lỗi
		return;
	}

	qDebug() << "Điểm danh thành công";
	

	if (employee.getStatus() == "OUT") {
		AudioUtils::getInstance()->getAudioWelcome()->play();
		db->getEmployeeRepository()->updateStatus("IN", id);
	}
	else {
		AudioUtils::getInstance()->getAudioGoodbye()->play();
		db->getEmployeeRepository()->updateStatus("OUT", id);
	}

	QList<AttendanceEventModel> events = db->getAttendanceEventRepository()->getByEmployeeId(employee.getId());
	std::sort(events.begin(), events.end(), [](const AttendanceEventModel& a, const AttendanceEventModel& b) {
		return a.getSession() < b.getSession();
		});
	double totalToday = 0;
	double totalThisWeek = 0;
	double totalThisMonth = 0;
	QDateTime dateTimeNow = QDateTime::currentDateTime();
	for (int i = 0; i < events.size() - 1; i = i + 2) {
		if (events.at(i).getSession() != events.at(i + 1).getSession()) {
			continue;
		}
		QDateTime dateTimeCheckin = QDateTime::fromString(events.at(i).getDateEvent() + " " + events.at(i).getTime(), "dd/MM/yyyy HH:mm:ss");
		QDateTime dateTimeCheckout = QDateTime::fromString(events.at(i + 1).getDateEvent() + " " + events.at(i + 1).getTime(), "dd/MM/yyyy HH:mm:ss");

		qint64 seconds = dateTimeCheckin.secsTo(dateTimeCheckout);
		double hours = seconds / 3600.0;

		// Check today
		if (dateTimeCheckin.date() == dateTimeNow.date()) {
			totalToday += hours;
		}
		// check this week
		if (Utils::isInCurrentWeek(dateTimeCheckin.date())) {
			totalThisWeek += hours;
		}
		// check this month
		if (Utils::isInCurrentMonth(dateTimeCheckin.date())) {
			totalThisMonth += hours;
		}
	}

	view->getUi()->stack_checkin_out->setCurrentIndex(2);
	view->getUi()->full_name->setText(employee.getFirstName() + " " + employee.getLastName());
	view->getUi()->id->setText(employee.getId());
	view->getUi()->today->setText(QString::number(totalToday, 'f', 2));
	view->getUi()->this_week->setText(QString::number(totalThisWeek, 'f', 2));
	view->getUi()->this_month->setText(QString::number(totalThisMonth, 'f', 2));

	if (employee.getStatus() == "IN") {
		view->getUi()->notice->setText(tr("check out successfully !"));
	}
	else {
		view->getUi()->notice->setText(tr("check in successfully !"));
	}

	QTimer* timer = new QTimer(this);
	connect(timer, &QTimer::timeout, this, [this, timer]() {
		view->getUi()->stack_checkin_out->setCurrentIndex(0);
		timer->stop();
		timer->deleteLater();
		});

	timer->start(3000);


	// Handle show bulletin
	if (employee.getStatus() == "OUT") {
		QList<BulletinModel> bulletinList = db->getBulletinRepository()->getByCurrentDate();
		QList<BulletinModel> bulletinListFilter;
		for (BulletinModel bulletin : bulletinList) {
			if (bulletin.getType() == Constant::B_TYPE_ALL) {
				bulletinListFilter.append(bulletin);
				continue;
			}
			if (bulletin.getType() == Constant::B_TYPE_DEPARTMENT && bulletin.getDepartment() == employee.getDepartment().getName()) {
				bulletinListFilter.append(bulletin);
				continue;
			}
			if (bulletin.getType() == Constant::B_TYPE_EMPLOYEE && bulletin.getEmployeeIds().contains(employee.getId())) {
				bulletinListFilter.append(bulletin);
				continue;
			}
		}
		std::sort(bulletinListFilter.begin(), bulletinListFilter.end(), [](const BulletinModel& a, const BulletinModel& b) {
			return a.getIsPriority() > b.getIsPriority();  // Sắp xếp theo isPriority, true sẽ lên trước
			});
		DialogNotification* dialogNotification = new DialogNotification(bulletinListFilter, nullptr);
		dialogNotification->exec();
	}
}

void EmployeeCheckInOutController::handleSubmitForPassword() {
	db->connectToDatabase();
	QString displayNameSelected = view->getUi()->name_list->currentText();
	QString password = view->getUi()->password->text().trimmed();

	if (password.isEmpty()) {
		qDebug() << "Mật khẩu không được để trống";
		return;
	}

	QRegularExpression re("\\(([^)]+)\\)");
	QRegularExpressionMatch match = re.match(displayNameSelected);
	QString id = match.captured(1);

	if (!db->getEmployeeRepository()->signInStaff(id, password)) {
		qDebug() << "Đăng nhập thất bại";
		return;
	}

	handleAttendanceEventForEmployee(id);

	db->closeDatabase();
}

void EmployeeCheckInOutController::handleCheckInOutByIries(QString employeeId) {
	qDebug() << "============= QUÉT THÀNH CÔNG: " << employeeId;
	db->connectToDatabase();

	handleAttendanceEventForEmployee(employeeId);


	db->closeDatabase();
}


void EmployeeCheckInOutController::processStreaming() {
	// Kiểm tra và kết nối tín hiệu nếu chưa kết nối
	if (!checkConnectSignal_IN_OUT) {
		connect(iriTracker, &IriTracker::imageProcessed, this, &EmployeeCheckInOutController::updateFrame);
		connect(iriTracker, &IriTracker::isCheckCompareSuccess, this, &EmployeeCheckInOutController::handleCheckInOutByIries);

		checkConnectSignal_IN_OUT = true;
	}

	// Dừng luồng hiện tại nếu nó đang chạy
	if (IriTrackerSingleton::getStreamThreadCheckInOut()->isRunning()) {
		IriTrackerSingleton::getStreamThreadCheckInOut()->quit();
	}

	// Di chuyển tracker sang thread và kết nối run()
	iriTracker->moveToThread(IriTrackerSingleton::getStreamThreadCheckInOut());
	connect(IriTrackerSingleton::getStreamThreadCheckInOut(), &QThread::started, iriTracker, &IriTracker::scan_iri);

	// Bắt đầu luồng
	IriTrackerSingleton::getStreamThreadCheckInOut()->start();
}

void EmployeeCheckInOutController::updateFrame(const unsigned char* imageData, int imageLen, int imageWidth, int imageHeight) {
	if (imageData && imageWidth > 0 && imageHeight > 0) {
		// Tạo QImage từ dữ liệu raw
		QImage image(imageData, imageWidth, imageHeight, QImage::Format_Grayscale8);
		QPixmap pixmap = QPixmap::fromImage(image);

		view->getUi()->device->setPixmap(pixmap.scaled(view->getUi()->device->size(), Qt::KeepAspectRatio));
	}
	else {
		qDebug() << "Dữ liệu hình ảnh không hợp lệ.";
	}
}

void EmployeeCheckInOutController::switchImage(bool isFoundDevice) {
	if (isFoundDevice != _flagFoundDevice) {
		if (isFoundDevice) {
			if (!_flagFoundDevice) {
				view->getUi()->device->setPixmap(QPixmap("D:/IriTech/Code/ManageEmployee/icon/found-device.png"));
				_flagFoundDevice = true;
			}
		}
		else {
			view->getUi()->device->setPixmap(QPixmap("D:/IriTech/Code/ManageEmployee/icon/no-device.jpg"));
			_flagFoundDevice = false;
		}
	}
}