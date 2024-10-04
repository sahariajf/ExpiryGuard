/********************************************************************************
** Form generated from reading UI file 'expirydashboard.ui'
**
** Created by: Qt User Interface Compiler version 6.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_EXPIRYDASHBOARD_H
#define UI_EXPIRYDASHBOARD_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListView>

QT_BEGIN_NAMESPACE

class Ui_ExpiryDashboard
{
public:
    QComboBox *daySelectionBT;
    QLabel *label;
    QListView *showResult;

    void setupUi(QDialog *ExpiryDashboard)
    {
        if (ExpiryDashboard->objectName().isEmpty())
            ExpiryDashboard->setObjectName("ExpiryDashboard");
        ExpiryDashboard->setWindowModality(Qt::ApplicationModal);
        ExpiryDashboard->resize(559, 405);
        ExpiryDashboard->setStyleSheet(QString::fromUtf8("\n"
"\n"
"QWidget {\n"
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
""));
        daySelectionBT = new QComboBox(ExpiryDashboard);
        daySelectionBT->addItem(QString());
        daySelectionBT->addItem(QString());
        daySelectionBT->setObjectName("daySelectionBT");
        daySelectionBT->setGeometry(QRect(280, 50, 131, 28));
        QFont font;
        font.setBold(true);
        daySelectionBT->setFont(font);
        daySelectionBT->setMouseTracking(true);
        daySelectionBT->setStyleSheet(QString::fromUtf8("\n"
"QComboBox {\n"
"    background-color: #009688; \n"
"    color: #ffffff; \n"
"    border: none; \n"
"    border-radius: 3px; \n"
"    padding: 5px; \n"
"    font-size: 16px; \n"
"}"));
        label = new QLabel(ExpiryDashboard);
        label->setObjectName("label");
        label->setGeometry(QRect(170, 50, 101, 31));
        label->setFont(font);
        label->setStyleSheet(QString::fromUtf8("QLabel{\n"
" 	color:rgb(0, 104, 94);\n"
"	font-size:16px;\n"
"}"));
        showResult = new QListView(ExpiryDashboard);
        showResult->setObjectName("showResult");
        showResult->setGeometry(QRect(70, 100, 431, 281));
        showResult->setFont(font);
        showResult->setStyleSheet(QString::fromUtf8("QListView {\n"
"    background-color:rgb(193, 201, 255); \n"
"    border: 1px solid #ccc; \n"
"    border-radius: 7px;	\n"
" font-size: 14px;                /* Font size */\n"
"    color: #333333; \n"
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
"}\n"
"\n"
""));
        showResult->setMovement(QListView::Free);
        showResult->setSpacing(3);
        showResult->setWordWrap(true);
        showResult->setItemAlignment(Qt::AlignCenter);

        retranslateUi(ExpiryDashboard);

        QMetaObject::connectSlotsByName(ExpiryDashboard);
    } // setupUi

    void retranslateUi(QDialog *ExpiryDashboard)
    {
        ExpiryDashboard->setWindowTitle(QCoreApplication::translate("ExpiryDashboard", "ExpiryDashboard ", nullptr));
        daySelectionBT->setItemText(0, QCoreApplication::translate("ExpiryDashboard", "7", nullptr));
        daySelectionBT->setItemText(1, QCoreApplication::translate("ExpiryDashboard", "15", nullptr));

        daySelectionBT->setCurrentText(QString());
        daySelectionBT->setPlaceholderText(QCoreApplication::translate("ExpiryDashboard", "Select Days", nullptr));
        label->setText(QCoreApplication::translate("ExpiryDashboard", "Select Days :", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ExpiryDashboard: public Ui_ExpiryDashboard {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EXPIRYDASHBOARD_H
