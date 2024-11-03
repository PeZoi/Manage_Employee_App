/********************************************************************************
** Form generated from reading UI file 'DialogDeleteAttendanceEvent.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOGDELETEATTENDANCEEVENT_H
#define UI_DIALOGDELETEATTENDANCEEVENT_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_DialogDeleteAttendanceEventClass
{
public:
    QPushButton *btn_yes;
    QPushButton *btn_no;
    QLabel *label;
    QLabel *label_2;
    QWidget *checkin;
    QLabel *label_3;
    QLabel *date_checkin;
    QLabel *time_checkin;
    QWidget *checkout;
    QLabel *label_6;
    QLabel *date_checkout;
    QLabel *time_checkout;

    void setupUi(QDialog *DialogDeleteAttendanceEventClass)
    {
        if (DialogDeleteAttendanceEventClass->objectName().isEmpty())
            DialogDeleteAttendanceEventClass->setObjectName(QString::fromUtf8("DialogDeleteAttendanceEventClass"));
        DialogDeleteAttendanceEventClass->resize(366, 147);
        btn_yes = new QPushButton(DialogDeleteAttendanceEventClass);
        btn_yes->setObjectName(QString::fromUtf8("btn_yes"));
        btn_yes->setGeometry(QRect(170, 110, 91, 27));
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
        QIcon icon;
        icon.addFile(QString::fromUtf8("../icon/check.png"), QSize(), QIcon::Normal, QIcon::Off);
        btn_yes->setIcon(icon);
        btn_yes->setIconSize(QSize(14, 14));
        btn_no = new QPushButton(DialogDeleteAttendanceEventClass);
        btn_no->setObjectName(QString::fromUtf8("btn_no"));
        btn_no->setGeometry(QRect(270, 110, 91, 27));
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
        QIcon icon1;
        icon1.addFile(QString::fromUtf8("../icon/close.png"), QSize(), QIcon::Normal, QIcon::Off);
        btn_no->setIcon(icon1);
        btn_no->setIconSize(QSize(12, 12));
        label = new QLabel(DialogDeleteAttendanceEventClass);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(170, 10, 55, 16));
        label->setStyleSheet(QString::fromUtf8("font-weight: bold;"));
        label_2 = new QLabel(DialogDeleteAttendanceEventClass);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(270, 10, 55, 16));
        label_2->setStyleSheet(QString::fromUtf8("font-weight: bold;"));
        checkin = new QWidget(DialogDeleteAttendanceEventClass);
        checkin->setObjectName(QString::fromUtf8("checkin"));
        checkin->setGeometry(QRect(10, 30, 351, 31));
        label_3 = new QLabel(checkin);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(10, 5, 55, 21));
        date_checkin = new QLabel(checkin);
        date_checkin->setObjectName(QString::fromUtf8("date_checkin"));
        date_checkin->setGeometry(QRect(140, 0, 81, 31));
        date_checkin->setStyleSheet(QString::fromUtf8("font-weight: bold;"));
        time_checkin = new QLabel(checkin);
        time_checkin->setObjectName(QString::fromUtf8("time_checkin"));
        time_checkin->setGeometry(QRect(250, 0, 71, 31));
        time_checkin->setStyleSheet(QString::fromUtf8("font-weight: bold;"));
        checkout = new QWidget(DialogDeleteAttendanceEventClass);
        checkout->setObjectName(QString::fromUtf8("checkout"));
        checkout->setGeometry(QRect(10, 70, 351, 31));
        label_6 = new QLabel(checkout);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(10, 5, 61, 21));
        date_checkout = new QLabel(checkout);
        date_checkout->setObjectName(QString::fromUtf8("date_checkout"));
        date_checkout->setGeometry(QRect(140, 0, 81, 31));
        date_checkout->setStyleSheet(QString::fromUtf8("font-weight: bold;"));
        time_checkout = new QLabel(checkout);
        time_checkout->setObjectName(QString::fromUtf8("time_checkout"));
        time_checkout->setGeometry(QRect(250, 0, 71, 31));
        time_checkout->setStyleSheet(QString::fromUtf8("font-weight: bold;"));

        retranslateUi(DialogDeleteAttendanceEventClass);

        QMetaObject::connectSlotsByName(DialogDeleteAttendanceEventClass);
    } // setupUi

    void retranslateUi(QDialog *DialogDeleteAttendanceEventClass)
    {
        DialogDeleteAttendanceEventClass->setWindowTitle(QCoreApplication::translate("DialogDeleteAttendanceEventClass", "DialogDeleteAttendanceEvent", nullptr));
        btn_yes->setText(QCoreApplication::translate("DialogDeleteAttendanceEventClass", "Ok", nullptr));
        btn_no->setText(QCoreApplication::translate("DialogDeleteAttendanceEventClass", "Cancel", nullptr));
        label->setText(QCoreApplication::translate("DialogDeleteAttendanceEventClass", "Date", nullptr));
        label_2->setText(QCoreApplication::translate("DialogDeleteAttendanceEventClass", "Time", nullptr));
        label_3->setText(QCoreApplication::translate("DialogDeleteAttendanceEventClass", "Checkin: ", nullptr));
        date_checkin->setText(QCoreApplication::translate("DialogDeleteAttendanceEventClass", "11/03/2024", nullptr));
        time_checkin->setText(QCoreApplication::translate("DialogDeleteAttendanceEventClass", "11:00:00", nullptr));
        label_6->setText(QCoreApplication::translate("DialogDeleteAttendanceEventClass", "Checkout:", nullptr));
        date_checkout->setText(QCoreApplication::translate("DialogDeleteAttendanceEventClass", "11/03/2024", nullptr));
        time_checkout->setText(QCoreApplication::translate("DialogDeleteAttendanceEventClass", "11:00:00", nullptr));
    } // retranslateUi

};

namespace Ui {
    class DialogDeleteAttendanceEventClass: public Ui_DialogDeleteAttendanceEventClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOGDELETEATTENDANCEEVENT_H
