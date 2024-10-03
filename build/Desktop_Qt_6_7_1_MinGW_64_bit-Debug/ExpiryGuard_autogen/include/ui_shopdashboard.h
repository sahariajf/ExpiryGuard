/********************************************************************************
** Form generated from reading UI file 'shopdashboard.ui'
**
** Created by: Qt User Interface Compiler version 6.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SHOPDASHBOARD_H
#define UI_SHOPDASHBOARD_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>

QT_BEGIN_NAMESPACE

class Ui_ShopDashboard
{
public:
    QComboBox *selectMonth;

    void setupUi(QDialog *ShopDashboard)
    {
        if (ShopDashboard->objectName().isEmpty())
            ShopDashboard->setObjectName("ShopDashboard");
        ShopDashboard->setWindowModality(Qt::ApplicationModal);
        ShopDashboard->resize(793, 480);
        selectMonth = new QComboBox(ShopDashboard);
        selectMonth->setObjectName("selectMonth");
        selectMonth->setGeometry(QRect(261, 50, 151, 28));

        retranslateUi(ShopDashboard);

        QMetaObject::connectSlotsByName(ShopDashboard);
    } // setupUi

    void retranslateUi(QDialog *ShopDashboard)
    {
        ShopDashboard->setWindowTitle(QCoreApplication::translate("ShopDashboard", "Shop Dashboard", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ShopDashboard: public Ui_ShopDashboard {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SHOPDASHBOARD_H
