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
        pushButton = new QPushButton(expiredBox);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(150, 160, 83, 29));
        QFont font;
        font.setPointSize(10);
        font.setBold(true);
        pushButton->setFont(font);
        label = new QLabel(expiredBox);
        label->setObjectName("label");
        label->setGeometry(QRect(60, 90, 111, 31));
        QFont font1;
        font1.setPointSize(11);
        font1.setBold(true);
        label->setFont(font1);
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
