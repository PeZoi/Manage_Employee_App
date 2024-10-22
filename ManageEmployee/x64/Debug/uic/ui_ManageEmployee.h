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
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ManageEmployeeClass
{
public:
    QLabel *label;

    void setupUi(QWidget *ManageEmployeeClass)
    {
        if (ManageEmployeeClass->objectName().isEmpty())
            ManageEmployeeClass->setObjectName(QString::fromUtf8("ManageEmployeeClass"));
        ManageEmployeeClass->resize(600, 400);
        label = new QLabel(ManageEmployeeClass);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(210, 30, 371, 31));
        label->setStyleSheet(QString::fromUtf8("color: #f53e2d;\n"
"font-size: 28px"));

        retranslateUi(ManageEmployeeClass);

        QMetaObject::connectSlotsByName(ManageEmployeeClass);
    } // setupUi

    void retranslateUi(QWidget *ManageEmployeeClass)
    {
        ManageEmployeeClass->setWindowTitle(QCoreApplication::translate("ManageEmployeeClass", "ManageEmployee", nullptr));
        label->setText(QCoreApplication::translate("ManageEmployeeClass", "Nh\303\242n Vi\303\252n", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ManageEmployeeClass: public Ui_ManageEmployeeClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MANAGEEMPLOYEE_H
