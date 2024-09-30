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

    void setupUi(QDialog *soldout)
    {
        if (soldout->objectName().isEmpty())
            soldout->setObjectName("soldout");
        soldout->setWindowModality(Qt::ApplicationModal);
        soldout->resize(465, 534);
        label = new QLabel(soldout);
        label->setObjectName("label");
        label->setGeometry(QRect(60, 60, 141, 20));
        QFont font;
        font.setPointSize(10);
        font.setBold(true);
        label->setFont(font);
        label_2 = new QLabel(soldout);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(60, 100, 131, 20));
        label_2->setFont(font);
        label_3 = new QLabel(soldout);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(40, 140, 141, 20));
        label_3->setFont(font);
        boxNumberIn = new QLineEdit(soldout);
        boxNumberIn->setObjectName("boxNumberIn");
        boxNumberIn->setGeometry(QRect(200, 60, 161, 26));
        QFont font1;
        font1.setPointSize(10);
        boxNumberIn->setFont(font1);
        sellAmountIn = new QLineEdit(soldout);
        sellAmountIn->setObjectName("sellAmountIn");
        sellAmountIn->setGeometry(QRect(200, 140, 161, 26));
        sellAmountIn->setFont(font1);
        sellDateIn = new QDateEdit(soldout);
        sellDateIn->setObjectName("sellDateIn");
        sellDateIn->setGeometry(QRect(200, 100, 161, 26));
        sellDateIn->setFont(font1);
        sellDateIn->setCalendarPopup(true);
        sellDateIn->setDate(QDate(2024, 10, 10));
        soldOutBt = new QPushButton(soldout);
        soldOutBt->setObjectName("soldOutBt");
        soldOutBt->setGeometry(QRect(100, 210, 101, 31));
        QFont font2;
        font2.setPointSize(12);
        font2.setBold(true);
        soldOutBt->setFont(font2);
        soldOutBt->setStyleSheet(QString::fromUtf8("QPushButton\n"
"{\n"
"border:none;\n"
"color:white;\n"
"background-color:rgb(0, 108, 0);\n"
"border-radius:50px;\n"
"}"));
        ResetBt = new QPushButton(soldout);
        ResetBt->setObjectName("ResetBt");
        ResetBt->setGeometry(QRect(240, 210, 81, 31));
        ResetBt->setFont(font2);
        ResetBt->setStyleSheet(QString::fromUtf8("QPushButton\n"
"{\n"
"border:none;\n"
"color:white;\n"
"background-color:red;\n"
"border-radius:30px;\n"
"}"));

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
    } // retranslateUi

};

namespace Ui {
    class soldout: public Ui_soldout {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SOLDOUT_H
