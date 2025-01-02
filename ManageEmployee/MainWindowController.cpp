#include "MainWindowController.h"
#include "DatabaseManagerMYSQL.h"
#include "DatabaseManagerSQLite.h"
#include "DatabaseManagerSQLServer.h"
#include <QSettings>

MainWindowController::MainWindowController(MainWindow* view, IDatabaseManager*& _db, QObject* parent)
	: QObject(parent), mainWindowView(view), db(_db)
{
	// Khởi tạo manage department controller
	ManageDepartment* md = new ManageDepartment(nullptr);
	mdController = new ManageDepartmentController(md, db, this);

	// Khởi tạo manage employee controller
	ManageEmployee* me = new ManageEmployee(nullptr);
	meController = new ManageEmployeeController(me, db, this);

	// Khởi tạo employee check in-out controller
	EmployeeCheckInOut* ecio = new EmployeeCheckInOut(nullptr);
	ecioController = new EmployeeCheckInOutController(ecio, db, this);

	// Khởi tạo manage attendance events controller
	ManageAttendanceEvents* mae = new ManageAttendanceEvents(nullptr);
	maeController = new ManageAttendanceEventsController(mae, db, this);

	// Khởi tạo manage exception controller
	ManageException* mex = new ManageException(nullptr);
	mexController = new ManageExceptionController(mex, this);

	// Khởi tạo manage bulletin controller
	ManageBulletin* mb = new ManageBulletin(nullptr);
	mbController = new ManageBulletinController(mb, this);

	// Khởi tạo tools controller
	Tools* tools = new Tools(nullptr);
	toolsController = new ToolsController(tools, db, this);

	handleHiddenManageDepartment();
	handleHiddenManageEmployee();
	handleHiddenManageEvents();
	handleHiddenManageException();
	handleHiddenManageBulletin();
	handleHiddenTools();
	handleHiddenMenu();

	handleShowCheckInOut();

	// Xử lý khi đăng nhập thành công
	connect(mainWindowView->getNavbarController(), &NavbarController::loginSuccessful, this, &MainWindowController::handleLogin);
	// Xử lý khi đăng xuất thành công
	connect(mainWindowView->getNavbarController(), &NavbarController::logoutSuccessful, this, &MainWindowController::handleLogout);

	// Xử lý khi nhấn vào menu
	connect(mainWindowView->getMenu(), &MenuList::onClickDepartment, this, &MainWindowController::handleShowManageDepartment);
	connect(mainWindowView->getMenu(), &MenuList::onClickDepartment, mainWindowView->getNavbarController(), &NavbarController::handleShowBack);

	connect(mainWindowView->getMenu(), &MenuList::onClickEmployee, this, &MainWindowController::handleShowManageEmployee);
	connect(mainWindowView->getMenu(), &MenuList::onClickEmployee, mainWindowView->getNavbarController(), &NavbarController::handleShowBack);

	connect(mainWindowView->getMenu(), &MenuList::onClickAttendanceEvents, this, &MainWindowController::handleShowManageEnvents);
	connect(mainWindowView->getMenu(), &MenuList::onClickAttendanceEvents, mainWindowView->getNavbarController(), &NavbarController::handleShowBack);

	connect(mainWindowView->getMenu(), &MenuList::onClickException, this, &MainWindowController::handleShowManageException);
	connect(mainWindowView->getMenu(), &MenuList::onClickException, mainWindowView->getNavbarController(), &NavbarController::handleShowBack);

	connect(mainWindowView->getMenu(), &MenuList::onClickBulletin, this, &MainWindowController::handleShowManageBulletin);
	connect(mainWindowView->getMenu(), &MenuList::onClickBulletin, mainWindowView->getNavbarController(), &NavbarController::handleShowBack);

	connect(mainWindowView->getMenu(), &MenuList::onClickTools, this, &MainWindowController::handleShowTools);
	connect(mainWindowView->getMenu(), &MenuList::onClickTools, mainWindowView->getNavbarController(), &NavbarController::handleShowBack);

	// Xử lý khi nhấn nút back
	connect(mainWindowView->getNavbarController(), &NavbarController::back, this, &MainWindowController::handleBack);
}

void MainWindowController::handleLogout() {
	db->connectToDatabase();

	handleHiddenManageDepartment();
	handleHiddenManageEmployee();
	handleHiddenManageEvents();
	handleHiddenTools();
	handleHiddenManageException();
	handleHiddenManageBulletin();
	handleHiddenMenu();

	QList<EmployeeModel> employeeList = db->getEmployeeRepository()->getAll();
	if (employeeList.isEmpty()) {
		ecioController->getView()->getUi()->stackedWidget->setCurrentIndex(1);
	}
	else {
		ecioController->getView()->getUi()->stackedWidget->setCurrentIndex(0);
	}

	ecioController->getView()->getUi()->stack_checkin_out->setCurrentIndex(0);
	ecioController->loadEmployee();

	handleShowCheckInOut();
	db->closeDatabase();
}

void MainWindowController::handleLogin() {
	handleHiddenManageDepartment();
	handleHiddenManageEmployee();
	handleHiddenManageEvents();
	handleHiddenManageException();
	handleHiddenCheckInOut();
	handleHiddenManageBulletin();
	handleHiddenTools();

	handleShowMenu();
}

void MainWindowController::handleBack() {
	handleHiddenManageDepartment();
	handleHiddenManageEmployee();
	handleHiddenManageEvents();
	handleHiddenManageException();
	handleHiddenManageBulletin();
	handleHiddenTools();

	handleShowMenu();
}

void MainWindowController::handleHiddenMenu() {
	mainWindowView->getUi()->content->layout()->removeWidget(mainWindowView->getMenu());
	mainWindowView->getMenu()->hide();
}

void MainWindowController::handleShowMenu() {
	mainWindowView->getUi()->content->layout()->addWidget(mainWindowView->getMenu());
	mainWindowView->getMenu()->show();
}

void MainWindowController::handleHiddenManageDepartment() {
	if (mdController && mdController->getMdView()) {
		mainWindowView->getUi()->content->layout()->removeWidget(mdController->getMdView());
		mdController->getMdView()->hide();
	}
}

void MainWindowController::handleShowManageDepartment() {
	handleHiddenMenu();
	mainWindowView->getUi()->content->layout()->addWidget(mdController->getMdView());
	mdController->getMdView()->show();

	mdController->getMdView()->getUi()->edit->setDisabled(true);
	mdController->getMdView()->getUi()->delete_2->setDisabled(true);

	mdController->departmentSelected = "";

	mdController->handleRenderTable();
}

void MainWindowController::handleHiddenManageEmployee() {
	mainWindowView->getUi()->content->layout()->removeWidget(meController->getMeView());
	meController->getMeView()->hide();
}

void MainWindowController::handleShowManageEmployee() {
	handleHiddenMenu();
	mainWindowView->getUi()->content->layout()->addWidget(meController->getMeView());
	meController->getMeView()->show();

	meController->getMeView()->getUi()->edit->setDisabled(true);
	meController->getMeView()->getUi()->delete_2->setDisabled(true);

	meController->employeeSelected = "";

	meController->handleRenderTable();
}

void MainWindowController::handleHiddenCheckInOut() {
	mainWindowView->getUi()->content->layout()->removeWidget(ecioController->getView());
	ecioController->getView()->hide();
}

void MainWindowController::handleShowCheckInOut() {
	mainWindowView->getUi()->content->layout()->addWidget(ecioController->getView());
	ecioController->getView()->show();
}

void MainWindowController::handleHiddenManageEvents() {
	mainWindowView->getUi()->content->layout()->removeWidget(maeController->getView());
	maeController->getView()->hide();
}
void MainWindowController::handleShowManageEnvents() {
	handleHiddenMenu();
	mainWindowView->getUi()->content->layout()->addWidget(maeController->getView());
	maeController->getView()->show();

	maeController->getView()->getUi()->add->setDisabled(true);
	maeController->getView()->getUi()->edit->setDisabled(true);
	maeController->getView()->getUi()->delete_2->setDisabled(true);
	maeController->getView()->getUi()->check_out->setDisabled(true);

	maeController->employeeSelected = "";

	maeController->handleRenderTable();
	maeController->loadEmployee();
}

void MainWindowController::handleHiddenManageException() {
	mainWindowView->getUi()->content->layout()->removeWidget(mexController->getMexView());
	mexController->getMexView()->hide();
};
void MainWindowController::handleShowManageException() {
	handleHiddenMenu();

	mainWindowView->getUi()->content->layout()->addWidget(mexController->getMexView());
	mexController->getMexView()->show();

	mexController->getMexView()->getUi()->edit->setDisabled(true);
	mexController->getMexView()->getUi()->delete_2->setDisabled(true);

	mexController->exceptionSelected = ExceptionModel();

	mexController->handleRenderTable();
};

void MainWindowController::handleHiddenManageBulletin() {
	mainWindowView->getUi()->content->layout()->removeWidget(mbController->getMbView());
	mbController->getMbView()->hide();
};
void MainWindowController::handleShowManageBulletin() {
	handleHiddenMenu();

	mainWindowView->getUi()->content->layout()->addWidget(mbController->getMbView());
	mbController->getMbView()->show();

	mbController->getMbView()->getUi()->edit->setDisabled(true);
	mbController->getMbView()->getUi()->delete_2->setDisabled(true);

	mbController->bulletinSelected = BulletinModel();

	mbController->handleRenderTable();
};

void MainWindowController::handleHiddenTools() {
	mainWindowView->getUi()->content->layout()->removeWidget(toolsController->getView());
	toolsController->getView()->hide();
}
void MainWindowController::handleShowTools() {
	handleHiddenMenu();
	mainWindowView->getUi()->content->layout()->addWidget(toolsController->getView());
	toolsController->getView()->show();
}

MainWindow* MainWindowController::getMainWindowView() { return this->mainWindowView; }