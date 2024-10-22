#include "MainWindow.h"

#include <QHBoxLayout>

MainWindow::MainWindow(QWidget* parent)
    : QMainWindow(parent), navbar(new Navbar(this)),
    menu(new MenuList(this)), md(new ManageDepartment(this)), me(new ManageEmployee(this))
{
    ui.setupUi(this);

    QHBoxLayout* headerLayout = new QHBoxLayout(ui.header);
    QHBoxLayout* contentLayout = new QHBoxLayout(ui.content);
    ui.header->setLayout(headerLayout);
    ui.content->setLayout(contentLayout);
    // Tạo và thêm Navbar vào header
    navbar->setFixedHeight(50);
    ui.header->layout()->addWidget(navbar);

    QSettings settings("Iritech", "Manage_Employee_App");
    bool isLoggedIn = settings.value("isLoggedIn", false).toBool();

    handleHiddenManageDepartment();
    handleHiddenManageEmployee();
    if (isLoggedIn) {
        handleShowMenu();

        qDebug() << "Đã đăng nhập";
    }
    else {
        handleHiddenMenu();
        
        qDebug() << "Chưa đăng nhập";
    }
    
    // Xử lý khi đăng nhập thành công
    connect(navbar, &Navbar::loginSuccessful, this, &MainWindow::handleShowMenu);
    // Xử lý khi đăng xuất thành công
    connect(navbar, &Navbar::logoutSuccessful, this, &MainWindow::handleHiddenMenu);

    // Xử lý khi nhấn vào menu
    connect(menu, &MenuList::onClickDepartment, this, &MainWindow::handleShowManageDepartment);
    connect(menu, &MenuList::onClickDepartment, navbar, &Navbar::handleShowBack);

    connect(menu, &MenuList::onClickEmployee, this, &MainWindow::handleShowManageEmployee);
    connect(menu, &MenuList::onClickEmployee, navbar, &Navbar::handleShowBack);

    // Xử lý khi nhấn nút back
    connect(navbar, &Navbar::back, this, &MainWindow::handleShowMenu);
}


MainWindow::~MainWindow()
{}

void MainWindow::handleHiddenMenu() {
    handleHiddenManageDepartment();
    handleHiddenManageEmployee();
    ui.content->layout()->removeWidget(menu);
    menu->hide();
}

void MainWindow::handleShowMenu() {
    handleHiddenManageDepartment();
    handleHiddenManageEmployee();
    ui.content->layout()->addWidget(menu);
    menu->show();
}

void MainWindow::handleHiddenManageDepartment() {
    ui.content->layout()->removeWidget(md);
    md->hide();
}

void MainWindow::handleShowManageDepartment() {
    handleHiddenMenu();
    ui.content->layout()->addWidget(md);
    md->show();
}

void MainWindow::handleHiddenManageEmployee() {
    ui.content->layout()->removeWidget(me);
    me->hide();
}

void MainWindow::handleShowManageEmployee() {
    handleHiddenMenu();
    ui.content->layout()->addWidget(me);
    me->show();
}

