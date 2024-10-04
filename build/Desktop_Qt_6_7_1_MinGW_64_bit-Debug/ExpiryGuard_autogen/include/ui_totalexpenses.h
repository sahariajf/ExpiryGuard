/********************************************************************************
** Form generated from reading UI file 'totalexpenses.ui'
**
** Created by: Qt User Interface Compiler version 6.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TOTALEXPENSES_H
#define UI_TOTALEXPENSES_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_totalexpenses
{
public:
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QDateEdit *dateEdit;
    QLineEdit *DiscriptionIn;
    QLineEdit *AmountIN;
    QPushButton *soldOutBt;
    QPushButton *ResetBt;

    void setupUi(QDialog *totalexpenses)
    {
        if (totalexpenses->objectName().isEmpty())
            totalexpenses->setObjectName("totalexpenses");
        totalexpenses->setWindowModality(Qt::ApplicationModal);
        totalexpenses->resize(415, 283);
        label = new QLabel(totalexpenses);
        label->setObjectName("label");
        label->setGeometry(QRect(110, 60, 63, 20));
        QFont font;
        font.setPointSize(10);
        font.setBold(true);
        label->setFont(font);
        label_2 = new QLabel(totalexpenses);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(70, 100, 121, 20));
        label_2->setFont(font);
        label_3 = new QLabel(totalexpenses);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(90, 140, 91, 20));
        label_3->setFont(font);
        dateEdit = new QDateEdit(totalexpenses);
        dateEdit->setObjectName("dateEdit");
        dateEdit->setGeometry(QRect(180, 60, 151, 29));
        DiscriptionIn = new QLineEdit(totalexpenses);
        DiscriptionIn->setObjectName("DiscriptionIn");
        DiscriptionIn->setGeometry(QRect(180, 100, 151, 28));
        AmountIN = new QLineEdit(totalexpenses);
        AmountIN->setObjectName("AmountIN");
        AmountIN->setGeometry(QRect(180, 140, 151, 28));
        soldOutBt = new QPushButton(totalexpenses);
        soldOutBt->setObjectName("soldOutBt");
        soldOutBt->setGeometry(QRect(100, 190, 101, 31));
        QFont font1;
        font1.setPointSize(12);
        font1.setBold(true);
        soldOutBt->setFont(font1);
        soldOutBt->setStyleSheet(QString::fromUtf8("QPushButton\n"
"{\n"
"border:none;\n"
"color:white;\n"
"background-color:rgb(0, 108, 0);\n"
"border-radius:50px;\n"
"}"));
        ResetBt = new QPushButton(totalexpenses);
        ResetBt->setObjectName("ResetBt");
        ResetBt->setGeometry(QRect(240, 190, 81, 31));
        ResetBt->setFont(font1);
        ResetBt->setStyleSheet(QString::fromUtf8("QPushButton\n"
"{\n"
"border:none;\n"
"color:white;\n"
"background-color:red;\n"
"border-radius:30px;\n"
"}"));

        retranslateUi(totalexpenses);

        QMetaObject::connectSlotsByName(totalexpenses);
    } // setupUi

    void retranslateUi(QDialog *totalexpenses)
    {
        totalexpenses->setWindowTitle(QCoreApplication::translate("totalexpenses", "Expenses", nullptr));
        label->setText(QCoreApplication::translate("totalexpenses", "Date :", nullptr));
        label_2->setText(QCoreApplication::translate("totalexpenses", "Discription :", nullptr));
        label_3->setText(QCoreApplication::translate("totalexpenses", "Amount :", nullptr));
        soldOutBt->setText(QCoreApplication::translate("totalexpenses", "Save", nullptr));
        ResetBt->setText(QCoreApplication::translate("totalexpenses", "Reset", nullptr));
    } // retranslateUi

};

namespace Ui {
    class totalexpenses: public Ui_totalexpenses {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TOTALEXPENSES_H
