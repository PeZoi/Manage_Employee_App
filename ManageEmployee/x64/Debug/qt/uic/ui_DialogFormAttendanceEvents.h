/********************************************************************************
** Form generated from reading UI file 'DialogFormAttendanceEvents.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOGFORMATTENDANCEEVENTS_H
#define UI_DIALOGFORMATTENDANCEEVENTS_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDateTimeEdit>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_DialogFormAttendanceEventsClass
{
public:
    QPushButton *cancelButton;
    QPushButton *submit;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *horizontalLayout;
    QRadioButton *radio_in_out;
    QRadioButton *radio_in;
    QRadioButton *radio_out;
    QLabel *label_2;
    QLabel *label_3;
    QDateTimeEdit *dateTime_checkin;
    QDateTimeEdit *dateTime_checkout;
    QLabel *label_4;
    QLabel *hours;

    void setupUi(QDialog *DialogFormAttendanceEventsClass)
    {
        if (DialogFormAttendanceEventsClass->objectName().isEmpty())
            DialogFormAttendanceEventsClass->setObjectName(QString::fromUtf8("DialogFormAttendanceEventsClass"));
        DialogFormAttendanceEventsClass->resize(467, 214);
        cancelButton = new QPushButton(DialogFormAttendanceEventsClass);
        cancelButton->setObjectName(QString::fromUtf8("cancelButton"));
        cancelButton->setGeometry(QRect(380, 180, 81, 25));
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
        QIcon icon;
        icon.addFile(QString::fromUtf8("C:/Users/MY PC/Documents/Zalo Received Files/icons/close.png"), QSize(), QIcon::Normal, QIcon::Off);
        cancelButton->setIcon(icon);
        cancelButton->setIconSize(QSize(12, 12));
        submit = new QPushButton(DialogFormAttendanceEventsClass);
        submit->setObjectName(QString::fromUtf8("submit"));
        submit->setGeometry(QRect(290, 180, 81, 25));
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
        QIcon icon1;
        icon1.addFile(QString::fromUtf8("C:/Users/MY PC/Documents/Zalo Received Files/icons/check.png"), QSize(), QIcon::Normal, QIcon::Off);
        submit->setIcon(icon1);
        submit->setIconSize(QSize(14, 14));
        verticalLayoutWidget = new QWidget(DialogFormAttendanceEventsClass);
        verticalLayoutWidget->setObjectName(QString::fromUtf8("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(0, 150, 461, 20));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(DialogFormAttendanceEventsClass);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(10, 10, 91, 21));
        horizontalLayoutWidget = new QWidget(DialogFormAttendanceEventsClass);
        horizontalLayoutWidget->setObjectName(QString::fromUtf8("horizontalLayoutWidget"));
        horizontalLayoutWidget->setGeometry(QRect(100, 10, 181, 24));
        horizontalLayout = new QHBoxLayout(horizontalLayoutWidget);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        radio_in_out = new QRadioButton(horizontalLayoutWidget);
        radio_in_out->setObjectName(QString::fromUtf8("radio_in_out"));

        horizontalLayout->addWidget(radio_in_out);

        radio_in = new QRadioButton(horizontalLayoutWidget);
        radio_in->setObjectName(QString::fromUtf8("radio_in"));

        horizontalLayout->addWidget(radio_in);

        radio_out = new QRadioButton(horizontalLayoutWidget);
        radio_out->setObjectName(QString::fromUtf8("radio_out"));

        horizontalLayout->addWidget(radio_out);

        label_2 = new QLabel(DialogFormAttendanceEventsClass);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(10, 50, 91, 21));
        label_3 = new QLabel(DialogFormAttendanceEventsClass);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(10, 90, 91, 21));
        dateTime_checkin = new QDateTimeEdit(DialogFormAttendanceEventsClass);
        dateTime_checkin->setObjectName(QString::fromUtf8("dateTime_checkin"));
        dateTime_checkin->setGeometry(QRect(100, 50, 361, 24));
        dateTime_checkout = new QDateTimeEdit(DialogFormAttendanceEventsClass);
        dateTime_checkout->setObjectName(QString::fromUtf8("dateTime_checkout"));
        dateTime_checkout->setGeometry(QRect(100, 90, 361, 24));
        label_4 = new QLabel(DialogFormAttendanceEventsClass);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(10, 130, 91, 21));
        hours = new QLabel(DialogFormAttendanceEventsClass);
        hours->setObjectName(QString::fromUtf8("hours"));
        hours->setGeometry(QRect(100, 130, 361, 21));
        hours->setStyleSheet(QString::fromUtf8("font-weight: bold;"));

        retranslateUi(DialogFormAttendanceEventsClass);

        QMetaObject::connectSlotsByName(DialogFormAttendanceEventsClass);
    } // setupUi

    void retranslateUi(QDialog *DialogFormAttendanceEventsClass)
    {
        DialogFormAttendanceEventsClass->setWindowTitle(QCoreApplication::translate("DialogFormAttendanceEventsClass", "DialogFormAttendanceEvents", nullptr));
        cancelButton->setText(QCoreApplication::translate("DialogFormAttendanceEventsClass", "Cancel", nullptr));
        submit->setText(QCoreApplication::translate("DialogFormAttendanceEventsClass", "OK", nullptr));
        label->setText(QCoreApplication::translate("DialogFormAttendanceEventsClass", "Event type", nullptr));
        radio_in_out->setText(QCoreApplication::translate("DialogFormAttendanceEventsClass", "In - Out", nullptr));
        radio_in->setText(QCoreApplication::translate("DialogFormAttendanceEventsClass", "In", nullptr));
        radio_out->setText(QCoreApplication::translate("DialogFormAttendanceEventsClass", "Out", nullptr));
        label_2->setText(QCoreApplication::translate("DialogFormAttendanceEventsClass", "Checkin", nullptr));
        label_3->setText(QCoreApplication::translate("DialogFormAttendanceEventsClass", "Checkout", nullptr));
        label_4->setText(QCoreApplication::translate("DialogFormAttendanceEventsClass", "Added hours", nullptr));
        hours->setText(QCoreApplication::translate("DialogFormAttendanceEventsClass", "0.00", nullptr));
    } // retranslateUi

};

namespace Ui {
    class DialogFormAttendanceEventsClass: public Ui_DialogFormAttendanceEventsClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOGFORMATTENDANCEEVENTS_H
