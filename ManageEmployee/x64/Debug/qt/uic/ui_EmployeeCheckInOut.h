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
#include <QtWidgets/QApplication>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
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
        stackedWidget->setGeometry(QRect(0, 0, 751, 391));
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


        QMetaObject::connectSlotsByName(EmployeeCheckInOutClass);
    } // setupUi

    void retranslateUi(QWidget *EmployeeCheckInOutClass)
    {
        EmployeeCheckInOutClass->setWindowTitle(QCoreApplication::translate("EmployeeCheckInOutClass", "EmployeeCheckInOut", nullptr));
        dateLabel->setText(QCoreApplication::translate("EmployeeCheckInOutClass", "Wednesday, October 23, 2024", nullptr));
        timeLabel->setText(QCoreApplication::translate("EmployeeCheckInOutClass", "03:27:30 PM", nullptr));
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
