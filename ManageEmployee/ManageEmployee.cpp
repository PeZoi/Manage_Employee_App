#include "ManageEmployee.h"
#include "Navbar.h"
#include <QHBoxLayout>

ManageEmployee::ManageEmployee(QWidget* parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);

    QHBoxLayout* headerLayout = new QHBoxLayout(ui.header);
    ui.header->setLayout(headerLayout);
    // Tạo và thêm Navbar vào header
    Navbar* navbar = new Navbar(this);
    navbar->setFixedHeight(50);
    ui.header->layout()->addWidget(navbar);
}

ManageEmployee::~ManageEmployee()
{}
