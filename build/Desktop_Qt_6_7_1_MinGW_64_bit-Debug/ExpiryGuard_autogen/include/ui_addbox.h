/********************************************************************************
** Form generated from reading UI file 'addbox.ui'
**
** Created by: Qt User Interface Compiler version 6.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADDBOX_H
#define UI_ADDBOX_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_addbox
{
public:
    QLabel *label;
    QLineEdit *BoxNumberIn;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLineEdit *purAmountin;
    QPushButton *SaveBt;
    QPushButton *ResetBt;
    QDateEdit *PurDatein;
    QDateEdit *ExpiryDatein;
    QLabel *label_5;
    QLineEdit *nameIn;

    void setupUi(QDialog *addbox)
    {
        if (addbox->objectName().isEmpty())
            addbox->setObjectName("addbox");
        addbox->setWindowModality(Qt::ApplicationModal);
        addbox->resize(480, 500);
        addbox->setTabletTracking(false);
        label = new QLabel(addbox);
        label->setObjectName("label");
        label->setGeometry(QRect(110, 90, 121, 20));
        QFont font;
        font.setPointSize(10);
        font.setBold(true);
        label->setFont(font);
        BoxNumberIn = new QLineEdit(addbox);
        BoxNumberIn->setObjectName("BoxNumberIn");
        BoxNumberIn->setGeometry(QRect(250, 90, 161, 26));
        label_2 = new QLabel(addbox);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(110, 170, 131, 20));
        label_2->setFont(font);
        label_3 = new QLabel(addbox);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(110, 210, 121, 20));
        label_3->setFont(font);
        label_4 = new QLabel(addbox);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(110, 250, 141, 20));
        QFont font1;
        font1.setBold(true);
        label_4->setFont(font1);
        purAmountin = new QLineEdit(addbox);
        purAmountin->setObjectName("purAmountin");
        purAmountin->setGeometry(QRect(250, 250, 161, 26));
        SaveBt = new QPushButton(addbox);
        SaveBt->setObjectName("SaveBt");
        SaveBt->setGeometry(QRect(160, 310, 91, 31));
        QFont font2;
        font2.setPointSize(12);
        font2.setBold(true);
        SaveBt->setFont(font2);
        SaveBt->setStyleSheet(QString::fromUtf8("QPushButton\n"
"{\n"
"border:none;\n"
"color:white;\n"
"background-color:rgb(0, 108, 0);\n"
"border-radius:50px;\n"
"}"));
        ResetBt = new QPushButton(addbox);
        ResetBt->setObjectName("ResetBt");
        ResetBt->setGeometry(QRect(270, 310, 81, 31));
        ResetBt->setFont(font2);
        ResetBt->setStyleSheet(QString::fromUtf8("QPushButton\n"
"{\n"
"border:none;\n"
"color:white;\n"
"background-color:red;\n"
"border-radius:30px;\n"
"}"));
        PurDatein = new QDateEdit(addbox);
        PurDatein->setObjectName("PurDatein");
        PurDatein->setGeometry(QRect(250, 170, 161, 26));
        PurDatein->setFrame(true);
        PurDatein->setKeyboardTracking(true);
        PurDatein->setMinimumDateTime(QDateTime(QDate(2024, 9, 12), QTime(0, 0, 0)));
        PurDatein->setCalendarPopup(true);
        PurDatein->setCurrentSectionIndex(0);
        ExpiryDatein = new QDateEdit(addbox);
        ExpiryDatein->setObjectName("ExpiryDatein");
        ExpiryDatein->setEnabled(true);
        ExpiryDatein->setGeometry(QRect(250, 210, 161, 26));
        ExpiryDatein->setFrame(true);
        ExpiryDatein->setMinimumDateTime(QDateTime(QDate(2024, 9, 11), QTime(0, 0, 0)));
        ExpiryDatein->setCalendarPopup(true);
        label_5 = new QLabel(addbox);
        label_5->setObjectName("label_5");
        label_5->setGeometry(QRect(110, 130, 131, 20));
        label_5->setFont(font);
        nameIn = new QLineEdit(addbox);
        nameIn->setObjectName("nameIn");
        nameIn->setGeometry(QRect(250, 130, 161, 26));

        retranslateUi(addbox);

        QMetaObject::connectSlotsByName(addbox);
    } // setupUi

    void retranslateUi(QDialog *addbox)
    {
        addbox->setWindowTitle(QCoreApplication::translate("addbox", "Add new Box", nullptr));
        label->setText(QCoreApplication::translate("addbox", "Box Number :", nullptr));
        label_2->setText(QCoreApplication::translate("addbox", "Purchase Date :", nullptr));
        label_3->setText(QCoreApplication::translate("addbox", "Expiry Date  :", nullptr));
        label_4->setText(QCoreApplication::translate("addbox", "Purchase Amount:", nullptr));
        SaveBt->setText(QCoreApplication::translate("addbox", "Save", nullptr));
        ResetBt->setText(QCoreApplication::translate("addbox", "Reset", nullptr));
        PurDatein->setDisplayFormat(QCoreApplication::translate("addbox", "yyyy-MM-dd", nullptr));
        ExpiryDatein->setDisplayFormat(QCoreApplication::translate("addbox", "yyyy-MM-dd", nullptr));
        label_5->setText(QCoreApplication::translate("addbox", "Name of Med :", nullptr));
    } // retranslateUi

};

namespace Ui {
    class addbox: public Ui_addbox {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADDBOX_H
