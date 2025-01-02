#include "MainWindow.h"

MainWindow::MainWindow(IDatabaseManager*& _db, QWidget* parent)
    : QMainWindow(parent), ui(new Ui::MainWindowClass),
    menu(new MenuList(this)), db(_db)
{
    navbarController = new NavbarController(new Navbar(nullptr), _db, this);
    ui->setupUi(this);

    QLinearGradient gradient(0, 0, 0, this->height());
    gradient.setColorAt(0.0, Qt::white);
    gradient.setColorAt(1.0, QColor("#87A8D2"));

    QPalette palette;
    palette.setBrush(QPalette::Window, gradient);
    this->setPalette(palette);
    this->setAutoFillBackground(true);

    ui->header->layout()->addWidget(navbarController->getUi());

    this->setWindowTitle(tr("IriTracker - Time And Attendance Management System"));
}


MainWindow::~MainWindow()
{}

DialogFormLoginAdmin& MainWindow::getFormLogin() {
    return formLogin;
}


MenuList* MainWindow::getMenu() {
    return menu;
}

NavbarController* MainWindow::getNavbarController() {
    return navbarController;
}
