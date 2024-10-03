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
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(798, 600);
        MainWindow->setCursor(QCursor(Qt::ArrowCursor));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        ADDBoxBt = new QPushButton(centralwidget);
        ADDBoxBt->setObjectName("ADDBoxBt");
        ADDBoxBt->setGeometry(QRect(20, 30, 111, 41));
        SoldOutBt = new QPushButton(centralwidget);
        SoldOutBt->setObjectName("SoldOutBt");
        SoldOutBt->setGeometry(QRect(20, 90, 111, 41));
        searchBT = new QPushButton(centralwidget);
        searchBT->setObjectName("searchBT");
        searchBT->setGeometry(QRect(652, 40, 101, 31));
        QFont font;
        font.setPointSize(11);
        font.setBold(true);
        searchBT->setFont(font);
        searchBT->setCheckable(false);
        searchtext = new QLineEdit(centralwidget);
        searchtext->setObjectName("searchtext");
        searchtext->setGeometry(QRect(440, 40, 191, 31));
        searchtext->setEchoMode(QLineEdit::Normal);
        searchtext->setReadOnly(false);
        searchtext->setClearButtonEnabled(true);
        searchResult = new QListView(centralwidget);
        searchResult->setObjectName("searchResult");
        searchResult->setEnabled(true);
        searchResult->setGeometry(QRect(440, 90, 311, 121));
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
        searchResult->setItemAlignment(Qt::AlignCenter);
        ExpirationAlert = new QTextEdit(centralwidget);
        ExpirationAlert->setObjectName("ExpirationAlert");
        ExpirationAlert->setEnabled(true);
        ExpirationAlert->setGeometry(QRect(573, 506, 211, 61));
        MainWindow->setCentralWidget(centralwidget);
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
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
