/********************************************************************************
** Form generated from reading UI file 'ManageDepartment.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MANAGEDEPARTMENT_H
#define UI_MANAGEDEPARTMENT_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ManageDepartmentClass
{
public:
    QLabel *departmentsLabel;
    QTableWidget *table;
    QPushButton *add;
    QPushButton *edit;
    QPushButton *delete_2;

    void setupUi(QWidget *ManageDepartmentClass)
    {
        if (ManageDepartmentClass->objectName().isEmpty())
            ManageDepartmentClass->setObjectName(QString::fromUtf8("ManageDepartmentClass"));
        ManageDepartmentClass->resize(761, 381);
        ManageDepartmentClass->setStyleSheet(QString::fromUtf8("height: fit-content;"));
        departmentsLabel = new QLabel(ManageDepartmentClass);
        departmentsLabel->setObjectName(QString::fromUtf8("departmentsLabel"));
        departmentsLabel->setGeometry(QRect(240, 10, 191, 41));
        QFont font;
        font.setPointSize(20);
        departmentsLabel->setFont(font);
        departmentsLabel->setStyleSheet(QString::fromUtf8("QLabel {\n"
"	color: #e56f68;\n"
"}"));
        table = new QTableWidget(ManageDepartmentClass);
        if (table->columnCount() < 2)
            table->setColumnCount(2);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        table->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        table->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        table->setObjectName(QString::fromUtf8("table"));
        table->setGeometry(QRect(10, 60, 741, 271));
        QFont font1;
        font1.setPointSize(8);
        table->setFont(font1);
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
        table->horizontalHeader()->setCascadingSectionResizes(false);
        table->horizontalHeader()->setHighlightSections(false);
        table->horizontalHeader()->setProperty("showSortIndicator", QVariant(false));
        table->horizontalHeader()->setStretchLastSection(true);
        add = new QPushButton(ManageDepartmentClass);
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
        QIcon icon;
        icon.addFile(QString::fromUtf8("C:/Users/MY PC/Documents/Zalo Received Files/icons/add.png"), QSize(), QIcon::Normal, QIcon::Off);
        add->setIcon(icon);
        add->setIconSize(QSize(14, 14));
        edit = new QPushButton(ManageDepartmentClass);
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
        QIcon icon1;
        icon1.addFile(QString::fromUtf8("C:/Users/MY PC/Documents/Zalo Received Files/icons/edit.png"), QSize(), QIcon::Normal, QIcon::Off);
        edit->setIcon(icon1);
        edit->setIconSize(QSize(14, 14));
        delete_2 = new QPushButton(ManageDepartmentClass);
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
        icon2.addFile(QString::fromUtf8("C:/Users/MY PC/Documents/Zalo Received Files/icons/close.png"), QSize(), QIcon::Normal, QIcon::Off);
        delete_2->setIcon(icon2);
        delete_2->setIconSize(QSize(12, 12));

        retranslateUi(ManageDepartmentClass);

        QMetaObject::connectSlotsByName(ManageDepartmentClass);
    } // setupUi

    void retranslateUi(QWidget *ManageDepartmentClass)
    {
        ManageDepartmentClass->setWindowTitle(QCoreApplication::translate("ManageDepartmentClass", "ManageDepartment", nullptr));
        departmentsLabel->setText(QCoreApplication::translate("ManageDepartmentClass", "Departments", nullptr));
        QTableWidgetItem *___qtablewidgetitem = table->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("ManageDepartmentClass", "Name", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = table->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QCoreApplication::translate("ManageDepartmentClass", "Description", nullptr));
        add->setText(QCoreApplication::translate("ManageDepartmentClass", "Add", nullptr));
        edit->setText(QCoreApplication::translate("ManageDepartmentClass", "Edit", nullptr));
        delete_2->setText(QCoreApplication::translate("ManageDepartmentClass", "Delete", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ManageDepartmentClass: public Ui_ManageDepartmentClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MANAGEDEPARTMENT_H
