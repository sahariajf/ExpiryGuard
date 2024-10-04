/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QPushButton *ADDBoxBt;
    QPushButton *SoldOutBt;
    QPushButton *searchBT;
    QLineEdit *searchtext;
    QListView *searchResult;
    QTextEdit *ExpirationAlert;
    QPushButton *refreshBt;
    QPushButton *DetailsBt;
    QPushButton *ExpiryDashBoardBT;
    QPushButton *ExpiredBoxBt;
    QPushButton *ADDBoxBt_2;
    QPushButton *expensesBT;
    QLabel *label_2;
    QLabel *label;
    QLabel *label_3;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(944, 655);
        MainWindow->setCursor(QCursor(Qt::ArrowCursor));
        MainWindow->setStyleSheet(QString::fromUtf8("\n"
"QWidget {\n"
"    background-color: #f4f4f4; \n"
"    color: #333; \n"
"}\n"
"\n"
"\n"
"QMainWindow {\n"
"    background-color: #ffffff;\n"
"}\n"
"\n"
"\n"
"QHeaderView {\n"
"    background-color: #009688; \n"
"    color: #ffffff; \n"
"}\n"
"\n"
"\n"
"QPushButton {\n"
"    background-color: #009688; \n"
"    color: #ffffff; \n"
"    border: none; \n"
"    border-radius: 10px; \n"
"    padding: 5px; \n"
"    font-size: 15px; \n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-color: #00796b; \n"
"}\n"
"\n"
"\n"
"\n"
"\n"
"\n"
"QLabel {\n"
"    font-size: 16px; \n"
"    margin-bottom: 5px; \n"
"}\n"
"\n"
"\n"
"QListView {\n"
"    background-color:rgb(193, 201, 255); \n"
"    border: 1px solid #ccc; \n"
"    border-radius: 7px;\n"
"	\n"
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
""
                        "QScrollBar::sub-line:vertical {\n"
"    background: none; \n"
"}\n"
"\n"
""));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        ADDBoxBt = new QPushButton(centralwidget);
        ADDBoxBt->setObjectName("ADDBoxBt");
        ADDBoxBt->setGeometry(QRect(20, 30, 141, 41));
        QFont font;
        font.setBold(true);
        ADDBoxBt->setFont(font);
        SoldOutBt = new QPushButton(centralwidget);
        SoldOutBt->setObjectName("SoldOutBt");
        SoldOutBt->setGeometry(QRect(20, 90, 141, 41));
        SoldOutBt->setFont(font);
        searchBT = new QPushButton(centralwidget);
        searchBT->setObjectName("searchBT");
        searchBT->setGeometry(QRect(810, 40, 101, 31));
        searchBT->setFont(font);
        searchBT->setCheckable(false);
        searchtext = new QLineEdit(centralwidget);
        searchtext->setObjectName("searchtext");
        searchtext->setGeometry(QRect(600, 30, 201, 41));
        QFont font1;
        font1.setPointSize(9);
        searchtext->setFont(font1);
        searchtext->setEchoMode(QLineEdit::Normal);
        searchtext->setReadOnly(false);
        searchtext->setClearButtonEnabled(true);
        searchResult = new QListView(centralwidget);
        searchResult->setObjectName("searchResult");
        searchResult->setEnabled(true);
        searchResult->setGeometry(QRect(600, 80, 321, 121));
        QFont font2;
        font2.setFamilies({QString::fromUtf8("Lima Bosonto Unicode")});
        font2.setPointSize(11);
        searchResult->setFont(font2);
        searchResult->setMouseTracking(true);
        searchResult->setFocusPolicy(Qt::NoFocus);
        searchResult->setLayoutDirection(Qt::LeftToRight);
        searchResult->setAutoFillBackground(false);
        searchResult->setAlternatingRowColors(true);
        searchResult->setSelectionMode(QAbstractItemView::NoSelection);
        searchResult->setMovement(QListView::Free);
        searchResult->setProperty("isWrapping", QVariant(false));
        searchResult->setSpacing(2);
        searchResult->setWordWrap(true);
        searchResult->setSelectionRectVisible(false);
        searchResult->setItemAlignment(Qt::AlignAbsolute|Qt::AlignCenter|Qt::AlignHCenter|Qt::AlignJustify|Qt::AlignTop|Qt::AlignVCenter);
        ExpirationAlert = new QTextEdit(centralwidget);
        ExpirationAlert->setObjectName("ExpirationAlert");
        ExpirationAlert->setEnabled(true);
        ExpirationAlert->setGeometry(QRect(690, 470, 241, 81));
        ExpirationAlert->setFont(font);
        ExpirationAlert->setStyleSheet(QString::fromUtf8("QLineEdit, QTextEdit {\n"
"    border: 3px solid #ccc; \n"
"    border-radius: 10px; \n"
"    padding: 5px; \n"
"    font-size: 14px; \n"
"	color : rgb(165, 0, 0)\n"
"}"));
        refreshBt = new QPushButton(centralwidget);
        refreshBt->setObjectName("refreshBt");
        refreshBt->setGeometry(QRect(810, 570, 91, 31));
        refreshBt->setFont(font);
        DetailsBt = new QPushButton(centralwidget);
        DetailsBt->setObjectName("DetailsBt");
        DetailsBt->setGeometry(QRect(700, 570, 91, 31));
        DetailsBt->setFont(font);
        ExpiryDashBoardBT = new QPushButton(centralwidget);
        ExpiryDashBoardBT->setObjectName("ExpiryDashBoardBT");
        ExpiryDashBoardBT->setGeometry(QRect(20, 150, 141, 41));
        ExpiryDashBoardBT->setFont(font);
        ExpiredBoxBt = new QPushButton(centralwidget);
        ExpiredBoxBt->setObjectName("ExpiredBoxBt");
        ExpiredBoxBt->setGeometry(QRect(20, 210, 141, 41));
        ExpiredBoxBt->setFont(font);
        ADDBoxBt_2 = new QPushButton(centralwidget);
        ADDBoxBt_2->setObjectName("ADDBoxBt_2");
        ADDBoxBt_2->setGeometry(QRect(320, 30, 181, 41));
        QFont font3;
        font3.setFamilies({QString::fromUtf8("Lima Bosonto Unicode")});
        font3.setBold(false);
        ADDBoxBt_2->setFont(font3);
        expensesBT = new QPushButton(centralwidget);
        expensesBT->setObjectName("expensesBT");
        expensesBT->setGeometry(QRect(20, 270, 141, 41));
        expensesBT->setFont(font);
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(0, 470, 221, 211));
        label_2->setStyleSheet(QString::fromUtf8("image: url(:/main1/Picture2.png);"));
        label = new QLabel(centralwidget);
        label->setObjectName("label");
        label->setGeometry(QRect(50, 500, 1081, 141));
        label->setStyleSheet(QString::fromUtf8("image: url(:/main1/footer.png);"));
        label_3 = new QLabel(centralwidget);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(560, 220, 481, 241));
        label_3->setStyleSheet(QString::fromUtf8("image: url(:/main1/mid.png);"));
        MainWindow->setCentralWidget(centralwidget);
        label->raise();
        label_2->raise();
        ADDBoxBt->raise();
        SoldOutBt->raise();
        searchBT->raise();
        searchtext->raise();
        searchResult->raise();
        ExpirationAlert->raise();
        refreshBt->raise();
        DetailsBt->raise();
        ExpiryDashBoardBT->raise();
        ExpiredBoxBt->raise();
        ADDBoxBt_2->raise();
        expensesBT->raise();
        label_3->raise();
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName("statusBar");
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "ExpiryGuard", nullptr));
        ADDBoxBt->setText(QCoreApplication::translate("MainWindow", "ADD Box", nullptr));
        SoldOutBt->setText(QCoreApplication::translate("MainWindow", "Sold Out", nullptr));
        searchBT->setText(QCoreApplication::translate("MainWindow", "Search", nullptr));
        searchtext->setText(QCoreApplication::translate("MainWindow", "Input medicine name", nullptr));
        refreshBt->setText(QCoreApplication::translate("MainWindow", "Refresh", nullptr));
        DetailsBt->setText(QCoreApplication::translate("MainWindow", "Details", nullptr));
        ExpiryDashBoardBT->setText(QCoreApplication::translate("MainWindow", "Expiry DashBoard", nullptr));
        ExpiredBoxBt->setText(QCoreApplication::translate("MainWindow", "Expired Box", nullptr));
        ADDBoxBt_2->setText(QCoreApplication::translate("MainWindow", "Shop Dashboard", nullptr));
        expensesBT->setText(QCoreApplication::translate("MainWindow", "Expenses", nullptr));
        label_2->setText(QString());
        label->setText(QString());
        label_3->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
