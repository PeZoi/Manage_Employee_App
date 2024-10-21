#include "MainWindow.h"

#include <QHBoxLayout>

MainWindow::MainWindow(QWidget* parent)
    : QMainWindow(parent), navbar(new Navbar(this)),
    menu(new MenuList(this))
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

    if (isLoggedIn) {
        handleShowMenu();
    }
    else {
        handleHidenMenu();
    }
    
    connect(navbar, &Navbar::loginSuccessful, this, &MainWindow::handleShowMenu);
    connect(navbar, &Navbar::logoutSuccessful, this, &MainWindow::handleHidenMenu);
}


MainWindow::~MainWindow()
{}

void MainWindow::handleHidenMenu() {
    ui.content->layout()->removeWidget(menu);
    menu->hide();
}

void MainWindow::handleShowMenu() {
    ui.content->layout()->addWidget(menu);
    menu->show();
}