/********************************************************************************
** Form generated from reading UI file 'SignUpAdmin.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SIGNUPADMIN_H
#define UI_SIGNUPADMIN_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SignUpAdminClass
{
public:
    QWidget *centralWidget;
    QLabel *infoLabel;
    QLineEdit *email_2;
    QLineEdit *password_2;
    QLabel *retypePasswordLabel;
    QLineEdit *password_confirm_2;
    QLabel *passwordLabel;
    QLabel *emailLabe;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *btn_signup_2;
    QPushButton *cancelButton;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *SignUpAdminClass)
    {
        if (SignUpAdminClass->objectName().isEmpty())
            SignUpAdminClass->setObjectName(QString::fromUtf8("SignUpAdminClass"));
        SignUpAdminClass->resize(489, 312);
        centralWidget = new QWidget(SignUpAdminClass);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        infoLabel = new QLabel(centralWidget);
        infoLabel->setObjectName(QString::fromUtf8("infoLabel"));
        infoLabel->setGeometry(QRect(20, 10, 441, 91));
        QFont font;
        font.setPointSize(10);
        infoLabel->setFont(font);
        email_2 = new QLineEdit(centralWidget);
        email_2->setObjectName(QString::fromUtf8("email_2"));
        email_2->setGeometry(QRect(210, 190, 251, 31));
        password_2 = new QLineEdit(centralWidget);
        password_2->setObjectName(QString::fromUtf8("password_2"));
        password_2->setGeometry(QRect(210, 110, 251, 31));
        retypePasswordLabel = new QLabel(centralWidget);
        retypePasswordLabel->setObjectName(QString::fromUtf8("retypePasswordLabel"));
        retypePasswordLabel->setGeometry(QRect(20, 150, 181, 31));
        retypePasswordLabel->setFont(font);
        password_confirm_2 = new QLineEdit(centralWidget);
        password_confirm_2->setObjectName(QString::fromUtf8("password_confirm_2"));
        password_confirm_2->setGeometry(QRect(210, 150, 251, 31));
        passwordLabel = new QLabel(centralWidget);
        passwordLabel->setObjectName(QString::fromUtf8("passwordLabel"));
        passwordLabel->setGeometry(QRect(20, 110, 181, 31));
        passwordLabel->setFont(font);
        emailLabe = new QLabel(centralWidget);
        emailLabe->setObjectName(QString::fromUtf8("emailLabe"));
        emailLabe->setGeometry(QRect(20, 190, 181, 31));
        emailLabe->setFont(font);
        verticalLayoutWidget = new QWidget(centralWidget);
        verticalLayoutWidget->setObjectName(QString::fromUtf8("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(20, 230, 441, 51));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        btn_signup_2 = new QPushButton(verticalLayoutWidget);
        btn_signup_2->setObjectName(QString::fromUtf8("btn_signup_2"));
        btn_signup_2->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	text-align: center;\n"
"	color: #fff;\n"
"	background-color: rgba(70, 133, 210, 1);\n"
"	border: 1px solid #2dd0f9;\n"
"	height: 25px;\n"
"	width: 100px;\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"	background-color: rgba(70, 133, 210, 0.7);\n"
"}"));
        QIcon icon;
        icon.addFile(QString::fromUtf8("../icon/check.png"), QSize(), QIcon::Normal, QIcon::Off);
        btn_signup_2->setIcon(icon);
        btn_signup_2->setIconSize(QSize(14, 14));

        horizontalLayout->addWidget(btn_signup_2);

        cancelButton = new QPushButton(verticalLayoutWidget);
        cancelButton->setObjectName(QString::fromUtf8("cancelButton"));
        cancelButton->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	text-align: center;\n"
"	color: #fff;\n"
"	background-color: rgba(70, 133, 210, 1);\n"
"	border: 1px solid #2dd0f9;\n"
"	height: 25px;\n"
"	width: 100px;\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"	background-color: rgba(70, 133, 210, 0.7);\n"
"}"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8("../icon/close.png"), QSize(), QIcon::Normal, QIcon::Off);
        cancelButton->setIcon(icon1);
        cancelButton->setIconSize(QSize(12, 12));

        horizontalLayout->addWidget(cancelButton);


        verticalLayout->addLayout(horizontalLayout);

        SignUpAdminClass->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(SignUpAdminClass);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        SignUpAdminClass->setStatusBar(statusBar);

        retranslateUi(SignUpAdminClass);

        QMetaObject::connectSlotsByName(SignUpAdminClass);
    } // setupUi

    void retranslateUi(QMainWindow *SignUpAdminClass)
    {
        SignUpAdminClass->setWindowTitle(QCoreApplication::translate("SignUpAdminClass", "SignUpAdmin", nullptr));
        infoLabel->setText(QCoreApplication::translate("SignUpAdminClass", "This is the first time you've run IriTracker on this computer. \n"
"Before continuing, you must enter an administrator \n"
"password and an email to remind password.  Password \n"
"must be at least 4 characters long.", nullptr));
        retypePasswordLabel->setText(QCoreApplication::translate("SignUpAdminClass", "Retype password", nullptr));
        passwordLabel->setText(QCoreApplication::translate("SignUpAdminClass", "Administrator password", nullptr));
        emailLabe->setText(QCoreApplication::translate("SignUpAdminClass", "Email", nullptr));
        btn_signup_2->setText(QCoreApplication::translate("SignUpAdminClass", "OK", nullptr));
        cancelButton->setText(QCoreApplication::translate("SignUpAdminClass", "Cancel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class SignUpAdminClass: public Ui_SignUpAdminClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SIGNUPADMIN_H
