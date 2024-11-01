/********************************************************************************
** Form generated from reading UI file 'MenuList.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MENULIST_H
#define UI_MENULIST_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MenuListClass
{
public:
    QLabel *administrationLabel;
    QToolButton *tools_2;
    QToolButton *notification_2;
    QToolButton *report_2;
    QToolButton *employee_2;
    QToolButton *event_2;
    QToolButton *department_2;
    QToolButton *exception_2;

    void setupUi(QWidget *MenuListClass)
    {
        if (MenuListClass->objectName().isEmpty())
            MenuListClass->setObjectName(QString::fromUtf8("MenuListClass"));
        MenuListClass->resize(751, 373);
        administrationLabel = new QLabel(MenuListClass);
        administrationLabel->setObjectName(QString::fromUtf8("administrationLabel"));
        administrationLabel->setGeometry(QRect(280, 20, 211, 31));
        QFont font;
        font.setPointSize(20);
        administrationLabel->setFont(font);
        administrationLabel->setStyleSheet(QString::fromUtf8("QLabel {\n"
"	color: #e56f68;\n"
"}"));
        tools_2 = new QToolButton(MenuListClass);
        tools_2->setObjectName(QString::fromUtf8("tools_2"));
        tools_2->setGeometry(QRect(460, 220, 161, 131));
        QFont font1;
        font1.setPointSize(11);
        font1.setBold(true);
        font1.setWeight(75);
        tools_2->setFont(font1);
        tools_2->setStyleSheet(QString::fromUtf8("QToolButton {\n"
"	background: transparent;\n"
"	color: #3690ac;\n"
"}\n"
"\n"
"QToolButton:hover {\n"
"	border: 1px solid #aaa;\n"
"	border-radius: 10px;\n"
"	background: #bed0e6;\n"
"}"));
        QIcon icon;
        icon.addFile(QString::fromUtf8("../icon/tool.png"), QSize(), QIcon::Normal, QIcon::Off);
        tools_2->setIcon(icon);
        tools_2->setIconSize(QSize(70, 70));
        notification_2 = new QToolButton(MenuListClass);
        notification_2->setObjectName(QString::fromUtf8("notification_2"));
        notification_2->setGeometry(QRect(290, 220, 161, 131));
        notification_2->setFont(font1);
        notification_2->setStyleSheet(QString::fromUtf8("QToolButton {\n"
"	background: transparent;\n"
"	color: #3690ac;\n"
"}\n"
"\n"
"QToolButton:hover {\n"
"	border: 1px solid #aaa;\n"
"	border-radius: 10px;\n"
"	background: #bed0e6;\n"
"}"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8("../icon/bullentin.png"), QSize(), QIcon::Normal, QIcon::Off);
        notification_2->setIcon(icon1);
        notification_2->setIconSize(QSize(70, 70));
        report_2 = new QToolButton(MenuListClass);
        report_2->setObjectName(QString::fromUtf8("report_2"));
        report_2->setGeometry(QRect(120, 220, 161, 131));
        report_2->setFont(font1);
        report_2->setStyleSheet(QString::fromUtf8("QToolButton {\n"
"	background: transparent;\n"
"	color: #3690ac;\n"
"}\n"
"\n"
"QToolButton:hover {\n"
"	border: 1px solid #aaa;\n"
"	border-radius: 10px;\n"
"	background: #bed0e6;\n"
"}"));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8("../icon/report.png"), QSize(), QIcon::Normal, QIcon::Off);
        report_2->setIcon(icon2);
        report_2->setIconSize(QSize(70, 70));
        employee_2 = new QToolButton(MenuListClass);
        employee_2->setObjectName(QString::fromUtf8("employee_2"));
        employee_2->setGeometry(QRect(210, 80, 151, 131));
        employee_2->setFont(font1);
        employee_2->setStyleSheet(QString::fromUtf8("QToolButton {\n"
"	background: transparent;\n"
"	color: #3690ac;\n"
"}\n"
"\n"
"QToolButton:hover {\n"
"	border: 1px solid #aaa;\n"
"	border-radius: 10px;\n"
"	background: #bed0e6;\n"
"}"));
        QIcon icon3;
        icon3.addFile(QString::fromUtf8("../icon/employee.png"), QSize(), QIcon::Normal, QIcon::Off);
        employee_2->setIcon(icon3);
        employee_2->setIconSize(QSize(70, 70));
        event_2 = new QToolButton(MenuListClass);
        event_2->setObjectName(QString::fromUtf8("event_2"));
        event_2->setGeometry(QRect(370, 80, 181, 131));
        event_2->setFont(font1);
        event_2->setStyleSheet(QString::fromUtf8("QToolButton {\n"
"	background: transparent;\n"
"	color: #3690ac;\n"
"}\n"
"\n"
"QToolButton:hover {\n"
"	border: 1px solid #aaa;\n"
"	border-radius: 10px;\n"
"	background: #bed0e6;\n"
"}"));
        QIcon icon4;
        icon4.addFile(QString::fromUtf8("../icon/calendar.png"), QSize(), QIcon::Normal, QIcon::Off);
        event_2->setIcon(icon4);
        event_2->setIconSize(QSize(70, 70));
        department_2 = new QToolButton(MenuListClass);
        department_2->setObjectName(QString::fromUtf8("department_2"));
        department_2->setGeometry(QRect(50, 80, 151, 131));
        department_2->setFont(font1);
        department_2->setStyleSheet(QString::fromUtf8("QToolButton {\n"
"	background: transparent;\n"
"	color: #3690ac;\n"
"}\n"
"\n"
"QToolButton:hover {\n"
"	border: 1px solid #aaa;\n"
"	border-radius: 10px;\n"
"	background: #bed0e6;\n"
"}"));
        QIcon icon5;
        icon5.addFile(QString::fromUtf8("../icon/department.png"), QSize(), QIcon::Normal, QIcon::Off);
        department_2->setIcon(icon5);
        department_2->setIconSize(QSize(70, 70));
        exception_2 = new QToolButton(MenuListClass);
        exception_2->setObjectName(QString::fromUtf8("exception_2"));
        exception_2->setGeometry(QRect(560, 80, 151, 131));
        exception_2->setFont(font1);
        exception_2->setStyleSheet(QString::fromUtf8("QToolButton {\n"
"	background: transparent;\n"
"	color: #3690ac;\n"
"}\n"
"\n"
"QToolButton:hover {\n"
"	border: 1px solid #aaa;\n"
"	border-radius: 10px;\n"
"	background: #bed0e6;\n"
"}"));
        QIcon icon6;
        icon6.addFile(QString::fromUtf8("../icon/exception.png"), QSize(), QIcon::Normal, QIcon::Off);
        exception_2->setIcon(icon6);
        exception_2->setIconSize(QSize(70, 70));

        retranslateUi(MenuListClass);

        QMetaObject::connectSlotsByName(MenuListClass);
    } // setupUi

    void retranslateUi(QWidget *MenuListClass)
    {
        MenuListClass->setWindowTitle(QCoreApplication::translate("MenuListClass", "MenuList", nullptr));
        administrationLabel->setText(QCoreApplication::translate("MenuListClass", "Administration", nullptr));
        tools_2->setText(QCoreApplication::translate("MenuListClass", "Tools", nullptr));
        notification_2->setText(QCoreApplication::translate("MenuListClass", "Bulletin Board", nullptr));
        report_2->setText(QCoreApplication::translate("MenuListClass", "Reports", nullptr));
        employee_2->setText(QCoreApplication::translate("MenuListClass", "Employees", nullptr));
        event_2->setText(QCoreApplication::translate("MenuListClass", "Attendance Events", nullptr));
        department_2->setText(QCoreApplication::translate("MenuListClass", "Departments", nullptr));
        exception_2->setText(QCoreApplication::translate("MenuListClass", "Exceptions", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MenuListClass: public Ui_MenuListClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MENULIST_H
