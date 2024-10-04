/********************************************************************************
** Form generated from reading UI file 'shopdashboard.ui'
**
** Created by: Qt User Interface Compiler version 6.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SHOPDASHBOARD_H
#define UI_SHOPDASHBOARD_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableView>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ShopDashboard
{
public:
    QComboBox *selectMonth;
    QWidget *centralWidget;
    QTableView *tableView;
    QPushButton *pushButton;
    QLabel *label;
    QLabel *label_2;
    QTextEdit *monthDetails;

    void setupUi(QDialog *ShopDashboard)
    {
        if (ShopDashboard->objectName().isEmpty())
            ShopDashboard->setObjectName("ShopDashboard");
        ShopDashboard->setWindowModality(Qt::ApplicationModal);
        ShopDashboard->resize(793, 530);
        ShopDashboard->setStyleSheet(QString::fromUtf8("QWidget {\n"
"    background-color: rgb(235, 235, 235); \n"
"    color: #333; \n"
"}\n"
"\n"
"\n"
"QHeaderView {\n"
"    background-color: #009688; \n"
"    color: #ffffff; \n"
"}\n"
"\n"
"QListView {\n"
"    background-color:rgb(193, 201, 255); \n"
"    border: 1px solid #ccc; \n"
"    border-radius: 7px;	\n"
"}\n"
"\n"
"\n"
"QScrollBar:vertical {\n"
"    border: 1px solid #ccc; \n"
"    background: #f4f4f4;\n"
"    width: 12px; \n"
"}\n"
"\n"
"QScrollBar::handle:vertical {\n"
"    background: #009688; \n"
"    min-height: 20px;\n"
"}\n"
"\n"
"QScrollBar::add-line:vertical, \n"
"QScrollBar::sub-line:vertical {\n"
"    background: none; \n"
"}"));
        selectMonth = new QComboBox(ShopDashboard);
        selectMonth->setObjectName("selectMonth");
        selectMonth->setGeometry(QRect(370, 20, 151, 28));
        selectMonth->setStyleSheet(QString::fromUtf8("QComboBox {\n"
"    background-color: #009688; \n"
"    color: #ffffff; \n"
"    border: none; \n"
"    border-radius: 3px; \n"
"    padding: 5px; \n"
"    font-size: 15px; \n"
"}\n"
"\n"
""));
        centralWidget = new QWidget(ShopDashboard);
        centralWidget->setObjectName("centralWidget");
        centralWidget->setGeometry(QRect(40, 170, 701, 301));
        tableView = new QTableView(centralWidget);
        tableView->setObjectName("tableView");
        tableView->setGeometry(QRect(20, 10, 661, 271));
        tableView->setStyleSheet(QString::fromUtf8("QTableView {\n"
"    background-color: #f5f5f5;   /* Light gray background */\n"
"    gridline-color: #cccccc;      /* Soft gray gridlines */\n"
"    border: 1px solid #c3c3c3;    /* Table border */\n"
"    selection-background-color: #87cefa;  /* Light blue for selected rows */\n"
"    selection-color: white;       /* Text color for selected rows */\n"
"    text-align: center;           /* Center align the text */\n"
"}\n"
"\n"
"QHeaderView::section {\n"
"    background-color: #333333;    /* Dark header background */\n"
"    color: white;                 /* White text in header */\n"
"    font-weight: bold;            /* Bold header text */\n"
"    padding: 5px;                 /* Add some padding to header */\n"
"    border: none;                 /* No border for header */\n"
"    text-align: center;           /* Center align header text */\n"
"}\n"
"\n"
"QTableView QTableCornerButton::section {\n"
"    background-color: #333333;    /* Dark corner button (matches header) */\n"
"}"));
        tableView->setEditTriggers(QAbstractItemView::NoEditTriggers);
        tableView->setGridStyle(Qt::DashDotLine);
        tableView->horizontalHeader()->setMinimumSectionSize(43);
        pushButton = new QPushButton(ShopDashboard);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(590, 480, 131, 31));
        QFont font;
        font.setBold(true);
        pushButton->setFont(font);
        pushButton->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: #009688; \n"
"    color: #ffffff; \n"
"    border: none; \n"
"    border-radius: 10px; \n"
"    padding: 5px; \n"
"    font-size: 18px; \n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-color: #00796b; \n"
"}"));
        label = new QLabel(ShopDashboard);
        label->setObjectName("label");
        label->setGeometry(QRect(220, 20, 141, 20));
        label->setFont(font);
        label->setLayoutDirection(Qt::LeftToRight);
        label->setStyleSheet(QString::fromUtf8("QLabel{\n"
" 	color:rgb(0, 104, 94);\n"
"	font-size:20px;\n"
"}"));
        label_2 = new QLabel(ShopDashboard);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(320, 130, 131, 31));
        QFont font1;
        font1.setPointSize(14);
        font1.setBold(true);
        font1.setUnderline(true);
        label_2->setFont(font1);
        label_2->setStyleSheet(QString::fromUtf8("QLabel {\n"
"\n"
"	color: rgb(170, 0, 0);\n"
"}"));
        monthDetails = new QTextEdit(ShopDashboard);
        monthDetails->setObjectName("monthDetails");
        monthDetails->setGeometry(QRect(40, 60, 701, 61));
        monthDetails->setStyleSheet(QString::fromUtf8("QTextEdit:focus {\n"
"    border: 2px solid #87cefa;      /* Blue border on focus */\n"
"    background-color: #ffffff;      /* White background on focus */\n"
"}\n"
"\n"
"QScrollBar:vertical {\n"
"    border: 1px solid #ccc; \n"
"    background: #f4f4f4;\n"
"    width: 8px; \n"
"}\n"
"\n"
"QTextEdit {\n"
"    background-color: #f0f0f0;      /* Light gray background */\n"
"    border: 2px solid #c3c3c3;      /* Soft gray border */\n"
"    border-radius: 7px;             /* Rounded corners */\n"
"    padding: 5px 10px;              /* Padding inside the line edit */\n"
"    font-size: 16px;                /* Font size */\n"
"    color: #333333;                 /* Text color */\n"
" font-weight: bold; \n"
"}"));

        retranslateUi(ShopDashboard);

        QMetaObject::connectSlotsByName(ShopDashboard);
    } // setupUi

    void retranslateUi(QDialog *ShopDashboard)
    {
        ShopDashboard->setWindowTitle(QCoreApplication::translate("ShopDashboard", "Shop Dashboard", nullptr));
        pushButton->setText(QCoreApplication::translate("ShopDashboard", "Refresh data", nullptr));
        label->setText(QCoreApplication::translate("ShopDashboard", "Select month :", nullptr));
        label_2->setText(QCoreApplication::translate("ShopDashboard", "OverView :", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ShopDashboard: public Ui_ShopDashboard {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SHOPDASHBOARD_H
