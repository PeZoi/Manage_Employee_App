#include "MainWindowController.h"

MainWindowController::MainWindowController(MainWindow* view, QObject* parent)
	: QObject(parent), mainWindowView(view)
{
	// Khởi tạo manage department controller
	ManageDepartment* md = new ManageDepartment(nullptr);
	mdController = new ManageDepartmentController(md, this);

	handleHiddenManageDepartment();
	handleHiddenManageEmployee();

	QSettings settings("Iritech", "Manage_Employee_App");
	bool isLoggedIn = settings.value("isLoggedIn", false).toBool();

	if (isLoggedIn) {
		handleShowMenu();
	}
	else {
		handleHiddenMenu();
	}

	// Xử lý khi đăng nhập thành công
	connect(mainWindowView->getNavbar(), &Navbar::loginSuccessful, this, &MainWindowController::handleShowMenu);
	// Xử lý khi đăng xuất thành công
	connect(mainWindowView->getNavbar(), &Navbar::logoutSuccessful, this, &MainWindowController::handleHiddenMenu);

	// Xử lý khi nhấn vào menu
	connect(mainWindowView->getMenu(), &MenuList::onClickDepartment, this, &MainWindowController::handleShowManageDepartment);
	connect(mainWindowView->getMenu(), &MenuList::onClickDepartment, mainWindowView->getNavbar(), &Navbar::handleShowBack);

	connect(mainWindowView->getMenu(), &MenuList::onClickEmployee, this, &MainWindowController::handleShowManageEmployee);
	connect(mainWindowView->getMenu(), &MenuList::onClickEmployee, mainWindowView->getNavbar(), &Navbar::handleShowBack);

	// Xử lý khi nhấn nút back
	connect(mainWindowView->getNavbar(), &Navbar::back, this, &MainWindowController::handleShowMenu);
}

void MainWindowController::handleHiddenMenu() {
	handleHiddenManageDepartment();
	handleHiddenManageEmployee();

	mainWindowView->getUi()->content->layout()->removeWidget(mainWindowView->getMenu());
	mainWindowView->getMenu()->hide();
}

void MainWindowController::handleShowMenu() {
	handleHiddenManageDepartment();
	handleHiddenManageEmployee();

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
}

void MainWindowController::handleHiddenManageEmployee() {
	//mainWindowView->getUi()->content->layout()->removeWidget(mainWindowView->getManageEmployee());
	//mainWindowView->getManageEmployee()->hide();
}

void MainWindowController::handleShowManageEmployee() {
	handleHiddenMenu();

	//mainWindowView->getUi()->content->layout()->addWidget(mainWindowView->getManageEmployee());
	//mainWindowView->getManageEmployee()->show();
}

MainWindow* MainWindowController::getMainWindowView() { return this->mainWindowView; }