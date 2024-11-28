/********************************************************************************
** Form generated from reading UI file 'EmployeeCheckInOut.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_EMPLOYEECHECKINOUT_H
#define UI_EMPLOYEECHECKINOUT_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QTreeView>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_EmployeeCheckInOutClass
{
public:
    QStackedWidget *stackedWidget;
    QWidget *hasEmployee;
    QLabel *dateLabel;
    QLabel *timeLabel;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QLineEdit *searchLineEdit;
    QTreeView *companyTreeView;
    QStackedWidget *stack_checkin_out;
    QWidget *use_device;
    QLabel *device;
    QWidget *use_password;
    QWidget *widget;
    QLabel *label_2;
    QComboBox *name_list;
    QLabel *label_3;
    QPushButton *show_all;
    QPushButton *submit_checkin_out;
    QLineEdit *password;
    QPushButton *back;
    QWidget *page;
    QWidget *widget_2;
    QLabel *label_4;
    QLabel *full_name;
    QLabel *label_6;
    QLabel *id;
    QLabel *label_8;
    QLabel *label_9;
    QLabel *label_10;
    QLabel *label_11;
    QLabel *notice;
    QLabel *avatar;
    QLabel *label_14;
    QLabel *this_month;
    QLabel *this_week;
    QLabel *today;
    QLabel *label_18;
    QLabel *label_19;
    QLabel *label_20;
    QPushButton *back_2;
    QWidget *noEmployee;
    QLabel *noEmployeeLabel_3;
    QLabel *noEmployeeLabel_1;
    QLabel *noEmployeeLabel_2;

    void setupUi(QWidget *EmployeeCheckInOutClass)
    {
        if (EmployeeCheckInOutClass->objectName().isEmpty())
            EmployeeCheckInOutClass->setObjectName(QString::fromUtf8("EmployeeCheckInOutClass"));
        EmployeeCheckInOutClass->resize(760, 409);
        stackedWidget = new QStackedWidget(EmployeeCheckInOutClass);
        stackedWidget->setObjectName(QString::fromUtf8("stackedWidget"));
        stackedWidget->setGeometry(QRect(0, 0, 751, 401));
        hasEmployee = new QWidget();
        hasEmployee->setObjectName(QString::fromUtf8("hasEmployee"));
        dateLabel = new QLabel(hasEmployee);
        dateLabel->setObjectName(QString::fromUtf8("dateLabel"));
        dateLabel->setGeometry(QRect(300, 90, 401, 41));
        QFont font;
        font.setPointSize(18);
        dateLabel->setFont(font);
        dateLabel->setStyleSheet(QString::fromUtf8("QLabel {\n"
"	color: #3883d9;\n"
"}"));
        timeLabel = new QLabel(hasEmployee);
        timeLabel->setObjectName(QString::fromUtf8("timeLabel"));
        timeLabel->setGeometry(QRect(330, 20, 381, 61));
        QFont font1;
        font1.setPointSize(36);
        timeLabel->setFont(font1);
        timeLabel->setStyleSheet(QString::fromUtf8("QLabel {\n"
"	color: #3883d9;\n"
"}"));
        verticalLayoutWidget = new QWidget(hasEmployee);
        verticalLayoutWidget->setObjectName(QString::fromUtf8("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(0, 0, 260, 391));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setSpacing(0);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        searchLineEdit = new QLineEdit(verticalLayoutWidget);
        searchLineEdit->setObjectName(QString::fromUtf8("searchLineEdit"));
        searchLineEdit->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"	color: #fff;\n"
"	background: #3883d9;\n"
"}"));

        verticalLayout->addWidget(searchLineEdit);

        companyTreeView = new QTreeView(verticalLayoutWidget);
        companyTreeView->setObjectName(QString::fromUtf8("companyTreeView"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(companyTreeView->sizePolicy().hasHeightForWidth());
        companyTreeView->setSizePolicy(sizePolicy);
        companyTreeView->setMinimumSize(QSize(258, 258));
        companyTreeView->setStyleSheet(QString::fromUtf8("QTreeView {\n"
"	border: 0.5px solid #ccc; \n"
"	background: transparent;\n"
"}"));

        verticalLayout->addWidget(companyTreeView);

        stack_checkin_out = new QStackedWidget(hasEmployee);
        stack_checkin_out->setObjectName(QString::fromUtf8("stack_checkin_out"));
        stack_checkin_out->setGeometry(QRect(260, 130, 491, 271));
        use_device = new QWidget();
        use_device->setObjectName(QString::fromUtf8("use_device"));
        device = new QLabel(use_device);
        device->setObjectName(QString::fromUtf8("device"));
        device->setGeometry(QRect(140, 30, 221, 181));
        device->setPixmap(QPixmap(QString::fromUtf8("../icon/no-device.jpg")));
        stack_checkin_out->addWidget(use_device);
        use_password = new QWidget();
        use_password->setObjectName(QString::fromUtf8("use_password"));
        widget = new QWidget(use_password);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(10, 20, 471, 171));
        widget->setStyleSheet(QString::fromUtf8("background-color: #fafbff; \n"
"border-radius: 10px;"));
        label_2 = new QLabel(widget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(10, 19, 91, 31));
        label_2->setStyleSheet(QString::fromUtf8("font: 18px;"));
        name_list = new QComboBox(widget);
        name_list->setObjectName(QString::fromUtf8("name_list"));
        name_list->setGeometry(QRect(110, 20, 201, 31));
        name_list->setStyleSheet(QString::fromUtf8("border: 1px solid black;\n"
"border-radius: 0px;"));
        label_3 = new QLabel(widget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(10, 70, 81, 31));
        label_3->setStyleSheet(QString::fromUtf8("font: 18px;"));
        show_all = new QPushButton(widget);
        show_all->setObjectName(QString::fromUtf8("show_all"));
        show_all->setGeometry(QRect(330, 20, 101, 31));
        show_all->setCursor(QCursor(Qt::PointingHandCursor));
        show_all->setStyleSheet(QString::fromUtf8("font: 18px;\n"
"color: white;\n"
"background: #3883d9;\n"
"border-radius: 4px;"));
        submit_checkin_out = new QPushButton(widget);
        submit_checkin_out->setObjectName(QString::fromUtf8("submit_checkin_out"));
        submit_checkin_out->setGeometry(QRect(190, 120, 111, 31));
        submit_checkin_out->setCursor(QCursor(Qt::PointingHandCursor));
        submit_checkin_out->setStyleSheet(QString::fromUtf8("font: 18px;\n"
"color: white;\n"
"background: #3883d9;\n"
"border-radius: 4px;"));
        QIcon icon;
        icon.addFile(QString::fromUtf8("../icon/check-white.webp"), QSize(), QIcon::Normal, QIcon::Off);
        submit_checkin_out->setIcon(icon);
        password = new QLineEdit(widget);
        password->setObjectName(QString::fromUtf8("password"));
        password->setGeometry(QRect(110, 70, 321, 31));
        password->setStyleSheet(QString::fromUtf8("border: 1px solid black;\n"
"border-radius: 0px;"));
        back = new QPushButton(use_password);
        back->setObjectName(QString::fromUtf8("back"));
        back->setGeometry(QRect(20, 220, 51, 41));
        back->setCursor(QCursor(Qt::PointingHandCursor));
        back->setStyleSheet(QString::fromUtf8("background: transparent;"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8("../icon/back.png"), QSize(), QIcon::Normal, QIcon::Off);
        back->setIcon(icon1);
        back->setIconSize(QSize(30, 30));
        stack_checkin_out->addWidget(use_password);
        page = new QWidget();
        page->setObjectName(QString::fromUtf8("page"));
        widget_2 = new QWidget(page);
        widget_2->setObjectName(QString::fromUtf8("widget_2"));
        widget_2->setGeometry(QRect(10, 10, 471, 211));
        widget_2->setStyleSheet(QString::fromUtf8("background-color: #fafbff; \n"
"border-radius: 10px;"));
        label_4 = new QLabel(widget_2);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(230, 10, 71, 21));
        label_4->setStyleSheet(QString::fromUtf8("font-weight: bold;\n"
"font: 18px;"));
        full_name = new QLabel(widget_2);
        full_name->setObjectName(QString::fromUtf8("full_name"));
        full_name->setGeometry(QRect(310, 10, 151, 21));
        full_name->setStyleSheet(QString::fromUtf8("font-weight: bold;\n"
"font: 18px;"));
        label_6 = new QLabel(widget_2);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(270, 40, 31, 16));
        label_6->setStyleSheet(QString::fromUtf8("font-weight: bold;\n"
"font: 18px;"));
        id = new QLabel(widget_2);
        id->setObjectName(QString::fromUtf8("id"));
        id->setGeometry(QRect(310, 40, 151, 16));
        id->setStyleSheet(QString::fromUtf8("font-weight: bold;\n"
"font: 18px;"));
        label_8 = new QLabel(widget_2);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setGeometry(QRect(200, 60, 131, 21));
        label_8->setStyleSheet(QString::fromUtf8("font-weight: bold;\n"
"font: 18px;"));
        label_9 = new QLabel(widget_2);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        label_9->setGeometry(QRect(200, 90, 91, 21));
        label_9->setStyleSheet(QString::fromUtf8("font-weight: bold;\n"
"font: 18px;"));
        label_10 = new QLabel(widget_2);
        label_10->setObjectName(QString::fromUtf8("label_10"));
        label_10->setGeometry(QRect(200, 120, 101, 21));
        label_10->setStyleSheet(QString::fromUtf8("font-weight: bold;\n"
"font: 18px;"));
        label_11 = new QLabel(widget_2);
        label_11->setObjectName(QString::fromUtf8("label_11"));
        label_11->setGeometry(QRect(200, 150, 111, 21));
        label_11->setStyleSheet(QString::fromUtf8("font-weight: bold;\n"
"font: 18px;"));
        notice = new QLabel(widget_2);
        notice->setObjectName(QString::fromUtf8("notice"));
        notice->setGeometry(QRect(110, 180, 281, 31));
        notice->setStyleSheet(QString::fromUtf8("background-color: #a32a2a;\n"
"color: white;\n"
"font-weight: bold;\n"
"border-radius: 0px;\n"
"font-size: 18px;\n"
"text-transform: uppercase;\n"
"padding: 0px 5px;"));
        avatar = new QLabel(widget_2);
        avatar->setObjectName(QString::fromUtf8("avatar"));
        avatar->setGeometry(QRect(40, 40, 101, 101));
        avatar->setTextFormat(Qt::AutoText);
        avatar->setPixmap(QPixmap(QString::fromUtf8("../icon/no-image.png")));
        avatar->setScaledContents(true);
        label_14 = new QLabel(widget_2);
        label_14->setObjectName(QString::fromUtf8("label_14"));
        label_14->setGeometry(QRect(340, 220, 111, 21));
        label_14->setStyleSheet(QString::fromUtf8("font-weight: bold;\n"
"font: 18px;"));
        this_month = new QLabel(widget_2);
        this_month->setObjectName(QString::fromUtf8("this_month"));
        this_month->setGeometry(QRect(310, 150, 51, 21));
        this_month->setStyleSheet(QString::fromUtf8("font-weight: bold;\n"
"font: 18px;"));
        this_week = new QLabel(widget_2);
        this_week->setObjectName(QString::fromUtf8("this_week"));
        this_week->setGeometry(QRect(310, 120, 51, 21));
        this_week->setStyleSheet(QString::fromUtf8("font-weight: bold;\n"
"font: 18px;"));
        today = new QLabel(widget_2);
        today->setObjectName(QString::fromUtf8("today"));
        today->setGeometry(QRect(310, 90, 51, 21));
        today->setStyleSheet(QString::fromUtf8("font-weight: bold;\n"
"font: 18px;"));
        label_18 = new QLabel(widget_2);
        label_18->setObjectName(QString::fromUtf8("label_18"));
        label_18->setGeometry(QRect(370, 90, 51, 21));
        label_18->setStyleSheet(QString::fromUtf8("font-weight: bold;\n"
"font: 18px;"));
        label_19 = new QLabel(widget_2);
        label_19->setObjectName(QString::fromUtf8("label_19"));
        label_19->setGeometry(QRect(370, 120, 51, 21));
        label_19->setStyleSheet(QString::fromUtf8("font-weight: bold;\n"
"font: 18px;"));
        label_20 = new QLabel(widget_2);
        label_20->setObjectName(QString::fromUtf8("label_20"));
        label_20->setGeometry(QRect(370, 150, 51, 21));
        label_20->setStyleSheet(QString::fromUtf8("font-weight: bold;\n"
"font: 18px;"));
        label_4->raise();
        full_name->raise();
        label_6->raise();
        id->raise();
        label_8->raise();
        label_9->raise();
        label_10->raise();
        notice->raise();
        avatar->raise();
        label_14->raise();
        label_11->raise();
        this_month->raise();
        this_week->raise();
        today->raise();
        label_18->raise();
        label_19->raise();
        label_20->raise();
        back_2 = new QPushButton(page);
        back_2->setObjectName(QString::fromUtf8("back_2"));
        back_2->setGeometry(QRect(20, 220, 51, 41));
        back_2->setCursor(QCursor(Qt::PointingHandCursor));
        back_2->setStyleSheet(QString::fromUtf8("background: transparent;"));
        back_2->setIcon(icon1);
        back_2->setIconSize(QSize(30, 30));
        stack_checkin_out->addWidget(page);
        stackedWidget->addWidget(hasEmployee);
        noEmployee = new QWidget();
        noEmployee->setObjectName(QString::fromUtf8("noEmployee"));
        noEmployeeLabel_3 = new QLabel(noEmployee);
        noEmployeeLabel_3->setObjectName(QString::fromUtf8("noEmployeeLabel_3"));
        noEmployeeLabel_3->setGeometry(QRect(150, 210, 411, 61));
        QFont font2;
        font2.setPointSize(9);
        font2.setBold(true);
        font2.setWeight(75);
        noEmployeeLabel_3->setFont(font2);
        noEmployeeLabel_3->setStyleSheet(QString::fromUtf8("QLabel {\n"
"	color: red;\n"
"}"));
        noEmployeeLabel_1 = new QLabel(noEmployee);
        noEmployeeLabel_1->setObjectName(QString::fromUtf8("noEmployeeLabel_1"));
        noEmployeeLabel_1->setGeometry(QRect(230, 50, 211, 131));
        noEmployeeLabel_1->setPixmap(QPixmap(QString::fromUtf8("C:/Users/MY PC/Documents/Zalo Received Files/icons/no-employee.png")));
        noEmployeeLabel_2 = new QLabel(noEmployee);
        noEmployeeLabel_2->setObjectName(QString::fromUtf8("noEmployeeLabel_2"));
        noEmployeeLabel_2->setGeometry(QRect(200, 170, 291, 61));
        noEmployeeLabel_2->setFont(font2);
        noEmployeeLabel_2->setStyleSheet(QString::fromUtf8("QLabel {\n"
"	color: red;\n"
"}"));
        stackedWidget->addWidget(noEmployee);

        retranslateUi(EmployeeCheckInOutClass);

        stackedWidget->setCurrentIndex(0);
        stack_checkin_out->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(EmployeeCheckInOutClass);
    } // setupUi

    void retranslateUi(QWidget *EmployeeCheckInOutClass)
    {
        EmployeeCheckInOutClass->setWindowTitle(QCoreApplication::translate("EmployeeCheckInOutClass", "EmployeeCheckInOut", nullptr));
        dateLabel->setText(QCoreApplication::translate("EmployeeCheckInOutClass", "Wednesday, October 23, 2024", nullptr));
        timeLabel->setText(QCoreApplication::translate("EmployeeCheckInOutClass", "03:27:30 PM", nullptr));
        device->setText(QString());
        label_2->setText(QCoreApplication::translate("EmployeeCheckInOutClass", "Your Name", nullptr));
        label_3->setText(QCoreApplication::translate("EmployeeCheckInOutClass", "Password", nullptr));
        show_all->setText(QCoreApplication::translate("EmployeeCheckInOutClass", "Show All", nullptr));
        submit_checkin_out->setText(QCoreApplication::translate("EmployeeCheckInOutClass", "Check In", nullptr));
        back->setText(QString());
        label_4->setText(QCoreApplication::translate("EmployeeCheckInOutClass", "Goodbye", nullptr));
        full_name->setText(QCoreApplication::translate("EmployeeCheckInOutClass", "\304\220\303\264ng", nullptr));
        label_6->setText(QCoreApplication::translate("EmployeeCheckInOutClass", "ID:", nullptr));
        id->setText(QCoreApplication::translate("EmployeeCheckInOutClass", "1", nullptr));
        label_8->setText(QCoreApplication::translate("EmployeeCheckInOutClass", "Working hours:", nullptr));
        label_9->setText(QCoreApplication::translate("EmployeeCheckInOutClass", "Today:", nullptr));
        label_10->setText(QCoreApplication::translate("EmployeeCheckInOutClass", "This week:", nullptr));
        label_11->setText(QCoreApplication::translate("EmployeeCheckInOutClass", "This month:", nullptr));
        notice->setText(QCoreApplication::translate("EmployeeCheckInOutClass", "check in susscessfully!", nullptr));
        avatar->setText(QString());
        label_14->setText(QCoreApplication::translate("EmployeeCheckInOutClass", "This month:", nullptr));
        this_month->setText(QCoreApplication::translate("EmployeeCheckInOutClass", "0.00", nullptr));
        this_week->setText(QCoreApplication::translate("EmployeeCheckInOutClass", "0.00", nullptr));
        today->setText(QCoreApplication::translate("EmployeeCheckInOutClass", "0.00", nullptr));
        label_18->setText(QCoreApplication::translate("EmployeeCheckInOutClass", "hours", nullptr));
        label_19->setText(QCoreApplication::translate("EmployeeCheckInOutClass", "hours", nullptr));
        label_20->setText(QCoreApplication::translate("EmployeeCheckInOutClass", "hours", nullptr));
        back_2->setText(QString());
        noEmployeeLabel_3->setText(QCoreApplication::translate("EmployeeCheckInOutClass", "Please log in as Administrator to add employees first!", nullptr));
        noEmployeeLabel_1->setText(QString());
        noEmployeeLabel_2->setText(QCoreApplication::translate("EmployeeCheckInOutClass", "There is no employee in the system. ", nullptr));
    } // retranslateUi

};

namespace Ui {
    class EmployeeCheckInOutClass: public Ui_EmployeeCheckInOutClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EMPLOYEECHECKINOUT_H
