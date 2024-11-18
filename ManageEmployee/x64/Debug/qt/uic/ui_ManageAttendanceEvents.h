/********************************************************************************
** Form generated from reading UI file 'ManageAttendanceEvents.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MANAGEATTENDANCEEVENTS_H
#define UI_MANAGEATTENDANCEEVENTS_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QTreeView>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ManageAttendanceEventsClass
{
public:
    QLabel *departmentsLabel;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QLineEdit *searchLineEdit;
    QTreeView *companyTreeView;
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *horizontalLayout;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label;
    QSpinBox *page_size;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_2;
    QComboBox *filter_range;
    QTableWidget *table;
    QPushButton *delete_2;
    QPushButton *edit;
    QPushButton *add;
    QPushButton *check_out;
    QWidget *verticalLayoutWidget_2;
    QVBoxLayout *verticalLayout_2;

    void setupUi(QWidget *ManageAttendanceEventsClass)
    {
        if (ManageAttendanceEventsClass->objectName().isEmpty())
            ManageAttendanceEventsClass->setObjectName(QString::fromUtf8("ManageAttendanceEventsClass"));
        ManageAttendanceEventsClass->resize(775, 421);
        departmentsLabel = new QLabel(ManageAttendanceEventsClass);
        departmentsLabel->setObjectName(QString::fromUtf8("departmentsLabel"));
        departmentsLabel->setGeometry(QRect(260, 10, 281, 41));
        QFont font;
        font.setPointSize(20);
        departmentsLabel->setFont(font);
        departmentsLabel->setStyleSheet(QString::fromUtf8("QLabel {\n"
"	color: #e56f68;\n"
"}"));
        verticalLayoutWidget = new QWidget(ManageAttendanceEventsClass);
        verticalLayoutWidget->setObjectName(QString::fromUtf8("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(0, 60, 260, 286));
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

        horizontalLayoutWidget = new QWidget(ManageAttendanceEventsClass);
        horizontalLayoutWidget->setObjectName(QString::fromUtf8("horizontalLayoutWidget"));
        horizontalLayoutWidget->setGeometry(QRect(260, 60, 511, 31));
        horizontalLayout = new QHBoxLayout(horizontalLayoutWidget);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label = new QLabel(horizontalLayoutWidget);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout_2->addWidget(label);

        page_size = new QSpinBox(horizontalLayoutWidget);
        page_size->setObjectName(QString::fromUtf8("page_size"));

        horizontalLayout_2->addWidget(page_size);


        horizontalLayout->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        label_2 = new QLabel(horizontalLayoutWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        horizontalLayout_3->addWidget(label_2);

        filter_range = new QComboBox(horizontalLayoutWidget);
        filter_range->addItem(QString());
        filter_range->addItem(QString());
        filter_range->addItem(QString());
        filter_range->addItem(QString());
        filter_range->addItem(QString());
        filter_range->addItem(QString());
        filter_range->setObjectName(QString::fromUtf8("filter_range"));

        horizontalLayout_3->addWidget(filter_range);


        horizontalLayout->addLayout(horizontalLayout_3);

        table = new QTableWidget(ManageAttendanceEventsClass);
        if (table->columnCount() < 4)
            table->setColumnCount(4);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        table->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        table->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        table->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        table->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        table->setObjectName(QString::fromUtf8("table"));
        table->setGeometry(QRect(260, 90, 511, 241));
        QFont font1;
        font1.setPointSize(8);
        table->setFont(font1);
        table->setStyleSheet(QString::fromUtf8("QTableWidget {\n"
"	background: transparent;\n"
"}\n"
"\n"
"QHeaderView::section {	\n"
"	color: white; \n"
"	background-color: rgba(70, 133, 210, 1);\n"
"}\n"
"\n"
"QTableWidget::item:selected {\n"
"    background-color: #0e6c96;\n"
"	color: #fff;\n"
"}"));
        table->horizontalHeader()->setCascadingSectionResizes(false);
        table->horizontalHeader()->setHighlightSections(false);
        table->horizontalHeader()->setProperty("showSortIndicator", QVariant(false));
        table->horizontalHeader()->setStretchLastSection(true);
        delete_2 = new QPushButton(ManageAttendanceEventsClass);
        delete_2->setObjectName(QString::fromUtf8("delete_2"));
        delete_2->setGeometry(QRect(690, 360, 81, 31));
        delete_2->setStyleSheet(QString::fromUtf8("QPushButton {\n"
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
        delete_2->setIcon(icon);
        delete_2->setIconSize(QSize(12, 12));
        edit = new QPushButton(ManageAttendanceEventsClass);
        edit->setObjectName(QString::fromUtf8("edit"));
        edit->setGeometry(QRect(490, 360, 81, 31));
        edit->setStyleSheet(QString::fromUtf8("QPushButton {\n"
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
        icon1.addFile(QString::fromUtf8("../icon/edit.png"), QSize(), QIcon::Normal, QIcon::Off);
        edit->setIcon(icon1);
        edit->setIconSize(QSize(14, 14));
        add = new QPushButton(ManageAttendanceEventsClass);
        add->setObjectName(QString::fromUtf8("add"));
        add->setGeometry(QRect(400, 360, 81, 31));
        add->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	text-align: center;\n"
"	color: #fff;\n"
"	background-color: rgba(70, 133, 210, 1);\n"
"	border-radius: 4px;\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"	background-color: rgba(70, 133, 210, 0.7);\n"
"}"));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8("../icon/check.png"), QSize(), QIcon::Normal, QIcon::Off);
        add->setIcon(icon2);
        add->setIconSize(QSize(14, 14));
        check_out = new QPushButton(ManageAttendanceEventsClass);
        check_out->setObjectName(QString::fromUtf8("check_out"));
        check_out->setGeometry(QRect(580, 360, 101, 31));
        check_out->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	text-align: center;\n"
"	color: #fff;\n"
"	background-color: rgba(70, 133, 210, 1);\n"
"	border-radius: 4px;\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"	background-color: rgba(70, 133, 210, 0.7);\n"
"}"));
        QIcon icon3;
        icon3.addFile(QString::fromUtf8("../icon/check-red.png"), QSize(), QIcon::Normal, QIcon::Off);
        check_out->setIcon(icon3);
        check_out->setIconSize(QSize(24, 24));
        verticalLayoutWidget_2 = new QWidget(ManageAttendanceEventsClass);
        verticalLayoutWidget_2->setObjectName(QString::fromUtf8("verticalLayoutWidget_2"));
        verticalLayoutWidget_2->setGeometry(QRect(0, 400, 771, 21));
        verticalLayout_2 = new QVBoxLayout(verticalLayoutWidget_2);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);

        retranslateUi(ManageAttendanceEventsClass);

        QMetaObject::connectSlotsByName(ManageAttendanceEventsClass);
    } // setupUi

    void retranslateUi(QWidget *ManageAttendanceEventsClass)
    {
        ManageAttendanceEventsClass->setWindowTitle(QCoreApplication::translate("ManageAttendanceEventsClass", "ManageAttendanceEvents", nullptr));
        departmentsLabel->setText(QCoreApplication::translate("ManageAttendanceEventsClass", "Attendance Events", nullptr));
        label->setText(QCoreApplication::translate("ManageAttendanceEventsClass", "Events per page", nullptr));
        label_2->setText(QCoreApplication::translate("ManageAttendanceEventsClass", "View events from", nullptr));
        filter_range->setItemText(0, QCoreApplication::translate("ManageAttendanceEventsClass", "This week", nullptr));
        filter_range->setItemText(1, QCoreApplication::translate("ManageAttendanceEventsClass", "Last week", nullptr));
        filter_range->setItemText(2, QCoreApplication::translate("ManageAttendanceEventsClass", "This month", nullptr));
        filter_range->setItemText(3, QCoreApplication::translate("ManageAttendanceEventsClass", "Last month", nullptr));
        filter_range->setItemText(4, QCoreApplication::translate("ManageAttendanceEventsClass", "This year", nullptr));
        filter_range->setItemText(5, QCoreApplication::translate("ManageAttendanceEventsClass", "All events", nullptr));

        QTableWidgetItem *___qtablewidgetitem = table->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("ManageAttendanceEventsClass", "Type", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = table->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QCoreApplication::translate("ManageAttendanceEventsClass", "Date", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = table->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QCoreApplication::translate("ManageAttendanceEventsClass", "Time", nullptr));
        QTableWidgetItem *___qtablewidgetitem3 = table->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QCoreApplication::translate("ManageAttendanceEventsClass", "Exception", nullptr));
        delete_2->setText(QCoreApplication::translate("ManageAttendanceEventsClass", "Delete", nullptr));
        edit->setText(QCoreApplication::translate("ManageAttendanceEventsClass", "Edit", nullptr));
        add->setText(QCoreApplication::translate("ManageAttendanceEventsClass", "Add", nullptr));
        check_out->setText(QCoreApplication::translate("ManageAttendanceEventsClass", "Check out", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ManageAttendanceEventsClass: public Ui_ManageAttendanceEventsClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MANAGEATTENDANCEEVENTS_H
