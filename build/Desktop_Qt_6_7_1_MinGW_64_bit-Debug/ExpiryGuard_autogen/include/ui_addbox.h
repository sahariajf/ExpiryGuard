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
    QLabel *label_6;

    void setupUi(QDialog *addbox)
    {
        if (addbox->objectName().isEmpty())
            addbox->setObjectName("addbox");
        addbox->setWindowModality(Qt::ApplicationModal);
        addbox->resize(480, 471);
        addbox->setTabletTracking(false);
        addbox->setStyleSheet(QString::fromUtf8("\n"
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
"  color:rgb(0, 0, 0)\n"
"	\n"
"}"));
        label = new QLabel(addbox);
        label->setObjectName("label");
        label->setGeometry(QRect(110, 90, 121, 20));
        QFont font;
        font.setPointSize(12);
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
        label_4->setGeometry(QRect(80, 250, 151, 20));
        label_4->setFont(font);
        purAmountin = new QLineEdit(addbox);
        purAmountin->setObjectName("purAmountin");
        purAmountin->setGeometry(QRect(250, 250, 161, 26));
        SaveBt = new QPushButton(addbox);
        SaveBt->setObjectName("SaveBt");
        SaveBt->setGeometry(QRect(160, 310, 91, 31));
        SaveBt->setFont(font);
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
        ResetBt->setFont(font);
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
        PurDatein->setMinimumDateTime(QDateTime(QDate(2024, 9, 11), QTime(0, 0, 0)));
        PurDatein->setCalendarPopup(true);
        PurDatein->setCurrentSectionIndex(0);
        ExpiryDatein = new QDateEdit(addbox);
        ExpiryDatein->setObjectName("ExpiryDatein");
        ExpiryDatein->setEnabled(true);
        ExpiryDatein->setGeometry(QRect(250, 210, 161, 26));
        ExpiryDatein->setFrame(true);
        ExpiryDatein->setMinimumDateTime(QDateTime(QDate(2024, 9, 10), QTime(0, 0, 0)));
        ExpiryDatein->setCalendarPopup(true);
        label_5 = new QLabel(addbox);
        label_5->setObjectName("label_5");
        label_5->setGeometry(QRect(110, 130, 131, 20));
        label_5->setFont(font);
        nameIn = new QLineEdit(addbox);
        nameIn->setObjectName("nameIn");
        nameIn->setGeometry(QRect(250, 130, 161, 26));
        label_6 = new QLabel(addbox);
        label_6->setObjectName("label_6");
        label_6->setGeometry(QRect(-10, 310, 221, 161));
        label_6->setStyleSheet(QString::fromUtf8("image: url(:/main1/pngwing.com (1).png);"));
        label_6->raise();
        label->raise();
        BoxNumberIn->raise();
        label_2->raise();
        label_3->raise();
        label_4->raise();
        purAmountin->raise();
        SaveBt->raise();
        ResetBt->raise();
        PurDatein->raise();
        ExpiryDatein->raise();
        label_5->raise();
        nameIn->raise();

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
        label_6->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class addbox: public Ui_addbox {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADDBOX_H
