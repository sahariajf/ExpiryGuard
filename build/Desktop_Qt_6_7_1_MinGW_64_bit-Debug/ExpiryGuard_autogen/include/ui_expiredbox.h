/********************************************************************************
** Form generated from reading UI file 'expiredbox.ui'
**
** Created by: Qt User Interface Compiler version 6.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_EXPIREDBOX_H
#define UI_EXPIREDBOX_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_expiredBox
{
public:
    QPushButton *pushButton;
    QLabel *label;
    QLineEdit *ExpiredBoxIn;

    void setupUi(QDialog *expiredBox)
    {
        if (expiredBox->objectName().isEmpty())
            expiredBox->setObjectName("expiredBox");
        expiredBox->setWindowModality(Qt::ApplicationModal);
        expiredBox->resize(382, 320);
        expiredBox->setFocusPolicy(Qt::NoFocus);
        expiredBox->setStyleSheet(QString::fromUtf8("\n"
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
"QLineEdit{\n"
" border: 2px solid #ccc; \n"
"    border-radius: 3px; \n"
"    padding: 5px; \n"
"    font-size: 16px; \n"
"    color: rgb(165, 0, 0);\n"
"    background-color: rgb(129, 200, 255);\n"
"	font-weight : bold;\n"
"}\n"
""));
        pushButton = new QPushButton(expiredBox);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(150, 160, 83, 29));
        QFont font;
        font.setBold(true);
        pushButton->setFont(font);
        label = new QLabel(expiredBox);
        label->setObjectName("label");
        label->setGeometry(QRect(60, 90, 111, 31));
        label->setFont(font);
        ExpiredBoxIn = new QLineEdit(expiredBox);
        ExpiredBoxIn->setObjectName("ExpiredBoxIn");
        ExpiredBoxIn->setGeometry(QRect(180, 90, 111, 31));

        retranslateUi(expiredBox);

        QMetaObject::connectSlotsByName(expiredBox);
    } // setupUi

    void retranslateUi(QDialog *expiredBox)
    {
        expiredBox->setWindowTitle(QCoreApplication::translate("expiredBox", "Expired Box", nullptr));
        pushButton->setText(QCoreApplication::translate("expiredBox", "Expired", nullptr));
        label->setText(QCoreApplication::translate("expiredBox", "Box Number :", nullptr));
    } // retranslateUi

};

namespace Ui {
    class expiredBox: public Ui_expiredBox {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EXPIREDBOX_H
