/********************************************************************************
** Form generated from reading UI file 'ManageEmployee.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MANAGEEMPLOYEE_H
#define UI_MANAGEEMPLOYEE_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ManageEmployeeClass
{
public:
    QTableWidget *table;
    QLabel *employeesLabel;
    QPushButton *edit;
    QPushButton *add;
    QPushButton *delete_2;

    void setupUi(QWidget *ManageEmployeeClass)
    {
        if (ManageEmployeeClass->objectName().isEmpty())
            ManageEmployeeClass->setObjectName(QString::fromUtf8("ManageEmployeeClass"));
        ManageEmployeeClass->resize(760, 387);
        table = new QTableWidget(ManageEmployeeClass);
        if (table->columnCount() < 7)
            table->setColumnCount(7);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        table->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        table->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        table->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        table->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        table->setHorizontalHeaderItem(4, __qtablewidgetitem4);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        table->setHorizontalHeaderItem(5, __qtablewidgetitem5);
        QTableWidgetItem *__qtablewidgetitem6 = new QTableWidgetItem();
        table->setHorizontalHeaderItem(6, __qtablewidgetitem6);
        table->setObjectName(QString::fromUtf8("table"));
        table->setGeometry(QRect(10, 60, 741, 261));
        table->setStyleSheet(QString::fromUtf8("QTableWidget {\n"
"	background: transparent;\n"
"}\n"
"\n"
"QHeaderView::section {	\n"
"	color: white; \n"
"	background-color: rgba(70, 133, 210, 1);\n"
"}\n"
"\n"
"QTableWidget::item:selected {\n"
"    background-color: #0e6c96;\n"
"	color: #fff;\n"
"}"));
        table->setAlternatingRowColors(false);
        table->setColumnCount(7);
        table->horizontalHeader()->setHighlightSections(false);
        table->horizontalHeader()->setStretchLastSection(true);
        employeesLabel = new QLabel(ManageEmployeeClass);
        employeesLabel->setObjectName(QString::fromUtf8("employeesLabel"));
        employeesLabel->setGeometry(QRect(260, 10, 161, 41));
        QFont font;
        font.setPointSize(20);
        employeesLabel->setFont(font);
        employeesLabel->setStyleSheet(QString::fromUtf8("QLabel {\n"
"	color: #e56f68;\n"
"}"));
        edit = new QPushButton(ManageEmployeeClass);
        edit->setObjectName(QString::fromUtf8("edit"));
        edit->setGeometry(QRect(580, 340, 81, 31));
        edit->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	text-align: center;\n"
"	color: #fff;\n"
"	background-color: rgba(70, 133, 210, 1);\n"
"	border-radius: 4px;\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"	background-color: rgba(70, 133, 210, 0.7);\n"
"}"));
        QIcon icon;
        icon.addFile(QString::fromUtf8("../icon/edit.png"), QSize(), QIcon::Normal, QIcon::Off);
        edit->setIcon(icon);
        edit->setIconSize(QSize(14, 14));
        add = new QPushButton(ManageEmployeeClass);
        add->setObjectName(QString::fromUtf8("add"));
        add->setGeometry(QRect(490, 340, 81, 31));
        add->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	text-align: center;\n"
"	color: #fff;\n"
"	background-color: rgba(70, 133, 210, 1);\n"
"	border-radius: 4px;\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"	background-color: rgba(70, 133, 210, 0.7);\n"
"}"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8("../icon/add.png"), QSize(), QIcon::Normal, QIcon::Off);
        add->setIcon(icon1);
        add->setIconSize(QSize(14, 14));
        delete_2 = new QPushButton(ManageEmployeeClass);
        delete_2->setObjectName(QString::fromUtf8("delete_2"));
        delete_2->setGeometry(QRect(670, 340, 81, 31));
        delete_2->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	text-align: center;\n"
"	color: #fff;\n"
"	background-color: rgba(70, 133, 210, 1);\n"
"	border-radius: 4px;\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"	background-color: rgba(70, 133, 210, 0.7);\n"
"}"));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8("../icon/close.png"), QSize(), QIcon::Normal, QIcon::Off);
        delete_2->setIcon(icon2);
        delete_2->setIconSize(QSize(12, 12));

        retranslateUi(ManageEmployeeClass);

        QMetaObject::connectSlotsByName(ManageEmployeeClass);
    } // setupUi

    void retranslateUi(QWidget *ManageEmployeeClass)
    {
        ManageEmployeeClass->setWindowTitle(QCoreApplication::translate("ManageEmployeeClass", "ManageEmployee", nullptr));
        QTableWidgetItem *___qtablewidgetitem = table->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("ManageEmployeeClass", "ID", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = table->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QCoreApplication::translate("ManageEmployeeClass", "Full Name", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = table->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QCoreApplication::translate("ManageEmployeeClass", "BirthDay", nullptr));
        QTableWidgetItem *___qtablewidgetitem3 = table->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QCoreApplication::translate("ManageEmployeeClass", "StartDay", nullptr));
        QTableWidgetItem *___qtablewidgetitem4 = table->horizontalHeaderItem(4);
        ___qtablewidgetitem4->setText(QCoreApplication::translate("ManageEmployeeClass", "Status", nullptr));
        QTableWidgetItem *___qtablewidgetitem5 = table->horizontalHeaderItem(5);
        ___qtablewidgetitem5->setText(QCoreApplication::translate("ManageEmployeeClass", "Department", nullptr));
        QTableWidgetItem *___qtablewidgetitem6 = table->horizontalHeaderItem(6);
        ___qtablewidgetitem6->setText(QCoreApplication::translate("ManageEmployeeClass", "Active", nullptr));
        employeesLabel->setText(QCoreApplication::translate("ManageEmployeeClass", "Employees", nullptr));
        edit->setText(QCoreApplication::translate("ManageEmployeeClass", "Edit", nullptr));
        add->setText(QCoreApplication::translate("ManageEmployeeClass", "Add", nullptr));
        delete_2->setText(QCoreApplication::translate("ManageEmployeeClass", "Delete", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ManageEmployeeClass: public Ui_ManageEmployeeClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MANAGEEMPLOYEE_H
