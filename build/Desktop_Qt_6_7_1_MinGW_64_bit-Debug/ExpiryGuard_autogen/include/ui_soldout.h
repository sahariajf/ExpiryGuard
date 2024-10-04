/********************************************************************************
** Form generated from reading UI file 'soldout.ui'
**
** Created by: Qt User Interface Compiler version 6.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SOLDOUT_H
#define UI_SOLDOUT_H

#include <QtCore/QDate>
#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextEdit>

QT_BEGIN_NAMESPACE

class Ui_soldout
{
public:
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLineEdit *boxNumberIn;
    QLineEdit *sellAmountIn;
    QDateEdit *sellDateIn;
    QPushButton *soldOutBt;
    QPushButton *ResetBt;
    QTextEdit *showResult;
    QLabel *label_4;

    void setupUi(QDialog *soldout)
    {
        if (soldout->objectName().isEmpty())
            soldout->setObjectName("soldout");
        soldout->setWindowModality(Qt::ApplicationModal);
        soldout->resize(465, 534);
        soldout->setStyleSheet(QString::fromUtf8("\n"
"QWidget {\n"
"    background-color: rgb(130, 163, 255);  \n"
"}\n"
"\n"
"QDateEdit {\n"
"    border: 2px solid #27ae60;\n"
"    border-radius: 5px;\n"
"    padding: 5px;\n"
"    background-color: rgb(130, 255, 228);\n"
"    color: #333;\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-color: #c0392b; \n"
"}\n"
"\n"
"QLineEdit {\n"
"    border: 2px solid #27ae60;\n"
"    border-radius: 5px;\n"
"    padding: 5px;\n"
"    background-color: rgb(130, 255, 228);\n"
"    color: rgb(0, 0, 0);\n"
"}\n"
"\n"
"QLabel {\n"
"  color:rgb(0, 0, 0);\n"
" font-size: 18px;\n"
"	\n"
"}"));
        label = new QLabel(soldout);
        label->setObjectName("label");
        label->setGeometry(QRect(100, 60, 141, 20));
        QFont font;
        font.setBold(true);
        label->setFont(font);
        label_2 = new QLabel(soldout);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(100, 100, 131, 20));
        label_2->setFont(font);
        label_3 = new QLabel(soldout);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(80, 140, 141, 20));
        label_3->setFont(font);
        boxNumberIn = new QLineEdit(soldout);
        boxNumberIn->setObjectName("boxNumberIn");
        boxNumberIn->setGeometry(QRect(240, 60, 161, 26));
        QFont font1;
        font1.setPointSize(10);
        boxNumberIn->setFont(font1);
        sellAmountIn = new QLineEdit(soldout);
        sellAmountIn->setObjectName("sellAmountIn");
        sellAmountIn->setGeometry(QRect(240, 140, 161, 26));
        sellAmountIn->setFont(font1);
        sellDateIn = new QDateEdit(soldout);
        sellDateIn->setObjectName("sellDateIn");
        sellDateIn->setGeometry(QRect(240, 100, 161, 26));
        sellDateIn->setFont(font1);
        sellDateIn->setCalendarPopup(true);
        sellDateIn->setDate(QDate(2024, 10, 10));
        soldOutBt = new QPushButton(soldout);
        soldOutBt->setObjectName("soldOutBt");
        soldOutBt->setGeometry(QRect(130, 210, 101, 31));
        QFont font2;
        font2.setPointSize(12);
        font2.setBold(true);
        soldOutBt->setFont(font2);
        soldOutBt->setStyleSheet(QString::fromUtf8("QPushButton\n"
"{\n"
"border:none;\n"
"color:white;\n"
"background-color:rgb(0, 108, 0);\n"
"border-radius: 7px;\n"
"\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-color: rgb(0, 34, 0); \n"
"}"));
        ResetBt = new QPushButton(soldout);
        ResetBt->setObjectName("ResetBt");
        ResetBt->setGeometry(QRect(270, 210, 81, 31));
        ResetBt->setFont(font2);
        ResetBt->setStyleSheet(QString::fromUtf8("QPushButton\n"
"{\n"
"border:none;\n"
"color:white;\n"
"background-color:red;\n"
"border-radius: 7px;\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-color: rgb(85, 0, 0); \n"
"}"));
        showResult = new QTextEdit(soldout);
        showResult->setObjectName("showResult");
        showResult->setGeometry(QRect(90, 310, 301, 101));
        QFont font3;
        font3.setFamilies({QString::fromUtf8("Lima Bosonto Unicode")});
        showResult->setFont(font3);
        showResult->setStyleSheet(QString::fromUtf8("QTextEdit {\n"
"    border: 4px solid #ccc; \n"
"    border-radius: 10px; \n"
"    padding: 5px; \n"
"    font-size: 14px; \n"
"    color: rgb(165, 0, 0);\n"
"    background-color: rgb(129, 200, 255);\n"
"}"));
        label_4 = new QLabel(soldout);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(130, 270, 331, 261));
        label_4->setStyleSheet(QString::fromUtf8("image: url(:/main1/Picture3.png);"));
        label_4->raise();
        label->raise();
        label_2->raise();
        label_3->raise();
        boxNumberIn->raise();
        sellAmountIn->raise();
        sellDateIn->raise();
        soldOutBt->raise();
        ResetBt->raise();
        showResult->raise();

        retranslateUi(soldout);

        QMetaObject::connectSlotsByName(soldout);
    } // setupUi

    void retranslateUi(QDialog *soldout)
    {
        soldout->setWindowTitle(QCoreApplication::translate("soldout", "Sold out Box", nullptr));
        label->setText(QCoreApplication::translate("soldout", "Box Number :", nullptr));
        label_2->setText(QCoreApplication::translate("soldout", "Selling date :", nullptr));
        label_3->setText(QCoreApplication::translate("soldout", "Selling amount :", nullptr));
        sellDateIn->setDisplayFormat(QCoreApplication::translate("soldout", "yyyy-MM-dd", nullptr));
        soldOutBt->setText(QCoreApplication::translate("soldout", "Sold Out", nullptr));
        ResetBt->setText(QCoreApplication::translate("soldout", "Reset", nullptr));
        label_4->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class soldout: public Ui_soldout {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SOLDOUT_H
