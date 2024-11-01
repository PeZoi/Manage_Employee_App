/********************************************************************************
** Form generated from reading UI file 'DialogConfirm.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOGCONFIRM_H
#define UI_DIALOGCONFIRM_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_DialogConfirmClass
{
public:
    QLabel *label;
    QLabel *content;
    QPushButton *btn_no;
    QPushButton *btn_yes;

    void setupUi(QDialog *DialogConfirmClass)
    {
        if (DialogConfirmClass->objectName().isEmpty())
            DialogConfirmClass->setObjectName(QString::fromUtf8("DialogConfirmClass"));
        DialogConfirmClass->resize(362, 121);
        label = new QLabel(DialogConfirmClass);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(20, 20, 41, 41));
        label->setPixmap(QPixmap(QString::fromUtf8("../icon/question.png")));
        label->setScaledContents(true);
        label->setWordWrap(false);
        content = new QLabel(DialogConfirmClass);
        content->setObjectName(QString::fromUtf8("content"));
        content->setGeometry(QRect(80, 20, 271, 41));
        content->setWordWrap(true);
        btn_no = new QPushButton(DialogConfirmClass);
        btn_no->setObjectName(QString::fromUtf8("btn_no"));
        btn_no->setGeometry(QRect(260, 80, 91, 27));
        btn_no->setStyleSheet(QString::fromUtf8("QPushButton {\n"
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
        icon.addFile(QString::fromUtf8("../icon/close.png"), QSize(), QIcon::Normal, QIcon::Off);
        btn_no->setIcon(icon);
        btn_no->setIconSize(QSize(12, 12));
        btn_yes = new QPushButton(DialogConfirmClass);
        btn_yes->setObjectName(QString::fromUtf8("btn_yes"));
        btn_yes->setGeometry(QRect(160, 80, 91, 27));
        btn_yes->setStyleSheet(QString::fromUtf8("QPushButton {\n"
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
        icon1.addFile(QString::fromUtf8("../icon/check.png"), QSize(), QIcon::Normal, QIcon::Off);
        btn_yes->setIcon(icon1);
        btn_yes->setIconSize(QSize(14, 14));

        retranslateUi(DialogConfirmClass);

        QMetaObject::connectSlotsByName(DialogConfirmClass);
    } // setupUi

    void retranslateUi(QDialog *DialogConfirmClass)
    {
        DialogConfirmClass->setWindowTitle(QCoreApplication::translate("DialogConfirmClass", "DialogConfirm", nullptr));
        label->setText(QString());
        content->setText(QString());
        btn_no->setText(QCoreApplication::translate("DialogConfirmClass", "No", nullptr));
        btn_yes->setText(QCoreApplication::translate("DialogConfirmClass", "Yes", nullptr));
    } // retranslateUi

};

namespace Ui {
    class DialogConfirmClass: public Ui_DialogConfirmClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOGCONFIRM_H
