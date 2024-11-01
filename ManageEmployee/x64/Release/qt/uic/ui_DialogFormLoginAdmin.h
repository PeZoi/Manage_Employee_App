/********************************************************************************
** Form generated from reading UI file 'DialogFormLoginAdmin.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOGFORMLOGINADMIN_H
#define UI_DIALOGFORMLOGINADMIN_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_DialogFormLoginAdminClass
{
public:
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLineEdit *password;
    QPushButton *login;

    void setupUi(QDialog *DialogFormLoginAdminClass)
    {
        if (DialogFormLoginAdminClass->objectName().isEmpty())
            DialogFormLoginAdminClass->setObjectName(QString::fromUtf8("DialogFormLoginAdminClass"));
        DialogFormLoginAdminClass->resize(600, 114);
        horizontalLayoutWidget = new QWidget(DialogFormLoginAdminClass);
        horizontalLayoutWidget->setObjectName(QString::fromUtf8("horizontalLayoutWidget"));
        horizontalLayoutWidget->setGeometry(QRect(20, 20, 561, 51));
        horizontalLayout = new QHBoxLayout(horizontalLayoutWidget);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(horizontalLayoutWidget);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout->addWidget(label);

        password = new QLineEdit(horizontalLayoutWidget);
        password->setObjectName(QString::fromUtf8("password"));

        horizontalLayout->addWidget(password);

        login = new QPushButton(DialogFormLoginAdminClass);
        login->setObjectName(QString::fromUtf8("login"));
        login->setGeometry(QRect(500, 80, 80, 25));

        retranslateUi(DialogFormLoginAdminClass);

        QMetaObject::connectSlotsByName(DialogFormLoginAdminClass);
    } // setupUi

    void retranslateUi(QDialog *DialogFormLoginAdminClass)
    {
        DialogFormLoginAdminClass->setWindowTitle(QCoreApplication::translate("DialogFormLoginAdminClass", "DialogFormLoginAdmin", nullptr));
        label->setText(QCoreApplication::translate("DialogFormLoginAdminClass", "M\341\272\255t kh\341\272\251u: ", nullptr));
        login->setText(QCoreApplication::translate("DialogFormLoginAdminClass", "\304\220\304\203ng nh\341\272\255p", nullptr));
    } // retranslateUi

};

namespace Ui {
    class DialogFormLoginAdminClass: public Ui_DialogFormLoginAdminClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOGFORMLOGINADMIN_H
