#include "MainWindow.h"

#include <QHBoxLayout>

MainWindow::MainWindow(QWidget* parent)
    : QMainWindow(parent), ui(new Ui::MainWindowClass), navbar(new Navbar(this)),
    menu(new MenuList(this))
{
    ui->setupUi(this);

    QHBoxLayout* headerLayout = new QHBoxLayout(ui->header);
    QHBoxLayout* contentLayout = new QHBoxLayout(ui->content);
    ui->header->setLayout(headerLayout);
    ui->content->setLayout(contentLayout);
    // Tạo và thêm Navbar vào header
    navbar->setFixedHeight(50);
    ui->header->layout()->addWidget(navbar);
    
}


MainWindow::~MainWindow()
{}

DialogFormLoginAdmin& MainWindow::getFormLogin() {
    return formLogin;
}


MenuList* MainWindow::getMenu() {
    return menu;
}

Navbar* MainWindow::getNavbar() {
    return navbar;
}

