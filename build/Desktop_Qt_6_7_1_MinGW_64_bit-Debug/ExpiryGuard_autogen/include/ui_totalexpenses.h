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
#include <QtWidgets/QDialog>

QT_BEGIN_NAMESPACE

class Ui_totalexpenses
{
public:

    void setupUi(QDialog *totalexpenses)
    {
        if (totalexpenses->objectName().isEmpty())
            totalexpenses->setObjectName("totalexpenses");
        totalexpenses->setWindowModality(Qt::ApplicationModal);
        totalexpenses->resize(391, 321);

        retranslateUi(totalexpenses);

        QMetaObject::connectSlotsByName(totalexpenses);
    } // setupUi

    void retranslateUi(QDialog *totalexpenses)
    {
        totalexpenses->setWindowTitle(QCoreApplication::translate("totalexpenses", "Expenses", nullptr));
    } // retranslateUi

};

namespace Ui {
    class totalexpenses: public Ui_totalexpenses {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TOTALEXPENSES_H
