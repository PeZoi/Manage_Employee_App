/********************************************************************************
** Form generated from reading UI file 'DialogFormDepartment.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOGFORMDEPARTMENT_H
#define UI_DIALOGFORMDEPARTMENT_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_DialogFormDepartmentClass
{
public:
    QLineEdit *name;
    QLineEdit *description;
    QLabel *label;
    QLabel *label_4;
    QPushButton *submit;
    QPushButton *cancelButton;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;

    void setupUi(QDialog *DialogFormDepartmentClass)
    {
        if (DialogFormDepartmentClass->objectName().isEmpty())
            DialogFormDepartmentClass->setObjectName(QString::fromUtf8("DialogFormDepartmentClass"));
        DialogFormDepartmentClass->resize(311, 302);
        DialogFormDepartmentClass->setStyleSheet(QString::fromUtf8(""));
        name = new QLineEdit(DialogFormDepartmentClass);
        name->setObjectName(QString::fromUtf8("name"));
        name->setGeometry(QRect(90, 22, 211, 31));
        name->setStyleSheet(QString::fromUtf8("height: 25px;"));
        description = new QLineEdit(DialogFormDepartmentClass);
        description->setObjectName(QString::fromUtf8("description"));
        description->setGeometry(QRect(90, 60, 211, 171));
        description->setStyleSheet(QString::fromUtf8(""));
        label = new QLabel(DialogFormDepartmentClass);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(10, 60, 63, 28));
        label_4 = new QLabel(DialogFormDepartmentClass);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(10, 22, 55, 28));
        submit = new QPushButton(DialogFormDepartmentClass);
        submit->setObjectName(QString::fromUtf8("submit"));
        submit->setGeometry(QRect(130, 250, 81, 25));
        submit->setStyleSheet(QString::fromUtf8("QPushButton {\n"
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
        icon.addFile(QString::fromUtf8("C:/Users/MY PC/Documents/Zalo Received Files/icons/check.png"), QSize(), QIcon::Normal, QIcon::Off);
        submit->setIcon(icon);
        submit->setIconSize(QSize(14, 14));
        cancelButton = new QPushButton(DialogFormDepartmentClass);
        cancelButton->setObjectName(QString::fromUtf8("cancelButton"));
        cancelButton->setGeometry(QRect(220, 250, 81, 25));
        cancelButton->setStyleSheet(QString::fromUtf8("QPushButton {\n"
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
        icon1.addFile(QString::fromUtf8("C:/Users/MY PC/Documents/Zalo Received Files/icons/close.png"), QSize(), QIcon::Normal, QIcon::Off);
        cancelButton->setIcon(icon1);
        cancelButton->setIconSize(QSize(12, 12));
        verticalLayoutWidget = new QWidget(DialogFormDepartmentClass);
        verticalLayoutWidget->setObjectName(QString::fromUtf8("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(0, 280, 311, 20));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);

        retranslateUi(DialogFormDepartmentClass);

        QMetaObject::connectSlotsByName(DialogFormDepartmentClass);
    } // setupUi

    void retranslateUi(QDialog *DialogFormDepartmentClass)
    {
        DialogFormDepartmentClass->setWindowTitle(QCoreApplication::translate("DialogFormDepartmentClass", "DialogFormDepartment", nullptr));
        label->setText(QCoreApplication::translate("DialogFormDepartmentClass", "Description", nullptr));
        label_4->setText(QCoreApplication::translate("DialogFormDepartmentClass", "Name (*)", nullptr));
        submit->setText(QCoreApplication::translate("DialogFormDepartmentClass", "OK", nullptr));
        cancelButton->setText(QCoreApplication::translate("DialogFormDepartmentClass", "Cancel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class DialogFormDepartmentClass: public Ui_DialogFormDepartmentClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOGFORMDEPARTMENT_H
