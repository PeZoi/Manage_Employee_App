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
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_DialogFormLoginAdminClass
{
public:
    QLabel *label;
    QLineEdit *password;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QPushButton *forgotButton;
    QPushButton *login_2;
    QPushButton *cancelButton;

    void setupUi(QDialog *DialogFormLoginAdminClass)
    {
        if (DialogFormLoginAdminClass->objectName().isEmpty())
            DialogFormLoginAdminClass->setObjectName(QString::fromUtf8("DialogFormLoginAdminClass"));
        DialogFormLoginAdminClass->resize(439, 108);
        label = new QLabel(DialogFormLoginAdminClass);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(10, 10, 55, 49));
        password = new QLineEdit(DialogFormLoginAdminClass);
        password->setObjectName(QString::fromUtf8("password"));
        password->setGeometry(QRect(80, 20, 351, 31));
        verticalLayoutWidget = new QWidget(DialogFormLoginAdminClass);
        verticalLayoutWidget->setObjectName(QString::fromUtf8("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(10, 60, 421, 51));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        forgotButton = new QPushButton(verticalLayoutWidget);
        forgotButton->setObjectName(QString::fromUtf8("forgotButton"));
        forgotButton->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	text-align: center;\n"
"	color: #fff;\n"
"	border-radius: 4px;\n"
"	background-color: rgba(70, 133, 210, 1);\n"
"	height: 25px\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"	background-color: rgba(70, 133, 210, 0.7);\n"
"}"));
        QIcon icon;
        icon.addFile(QString::fromUtf8("C:/Users/MY PC/Documents/Zalo Received Files/icons/forgot-password.png"), QSize(), QIcon::Normal, QIcon::Off);
        forgotButton->setIcon(icon);
        forgotButton->setIconSize(QSize(14, 14));

        horizontalLayout->addWidget(forgotButton);

        login_2 = new QPushButton(verticalLayoutWidget);
        login_2->setObjectName(QString::fromUtf8("login_2"));
        login_2->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	text-align: center;\n"
"	color: #fff;\n"
"	border-radius: 4px;\n"
"	background-color: rgba(70, 133, 210, 1);\n"
"	height: 25px\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"	background-color: rgba(70, 133, 210, 0.7);\n"
"}"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8("C:/Users/MY PC/Documents/Zalo Received Files/icons/check.png"), QSize(), QIcon::Normal, QIcon::Off);
        login_2->setIcon(icon1);
        login_2->setIconSize(QSize(14, 14));

        horizontalLayout->addWidget(login_2);

        cancelButton = new QPushButton(verticalLayoutWidget);
        cancelButton->setObjectName(QString::fromUtf8("cancelButton"));
        cancelButton->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	text-align: center;\n"
"	color: #fff;\n"
"	border-radius: 4px;\n"
"	background-color: rgba(70, 133, 210, 1);\n"
"	height: 25px\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"	background-color: rgba(70, 133, 210, 0.7);\n"
"}"));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8("C:/Users/MY PC/Documents/Zalo Received Files/icons/close.png"), QSize(), QIcon::Normal, QIcon::Off);
        cancelButton->setIcon(icon2);
        cancelButton->setIconSize(QSize(12, 12));

        horizontalLayout->addWidget(cancelButton);


        verticalLayout->addLayout(horizontalLayout);


        retranslateUi(DialogFormLoginAdminClass);

        QMetaObject::connectSlotsByName(DialogFormLoginAdminClass);
    } // setupUi

    void retranslateUi(QDialog *DialogFormLoginAdminClass)
    {
        DialogFormLoginAdminClass->setWindowTitle(QCoreApplication::translate("DialogFormLoginAdminClass", "DialogFormLoginAdmin", nullptr));
        label->setText(QCoreApplication::translate("DialogFormLoginAdminClass", "Password", nullptr));
        forgotButton->setText(QCoreApplication::translate("DialogFormLoginAdminClass", "Forgot Pasword", nullptr));
        login_2->setText(QCoreApplication::translate("DialogFormLoginAdminClass", "OK", nullptr));
        cancelButton->setText(QCoreApplication::translate("DialogFormLoginAdminClass", "Cancel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class DialogFormLoginAdminClass: public Ui_DialogFormLoginAdminClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOGFORMLOGINADMIN_H
