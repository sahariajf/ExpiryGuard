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
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QTableView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ShopDashboard
{
public:
    QComboBox *selectMonth;
    QLineEdit *monthDetails;
    QWidget *centralWidget;
    QTableView *tableView;

    void setupUi(QDialog *ShopDashboard)
    {
        if (ShopDashboard->objectName().isEmpty())
            ShopDashboard->setObjectName("ShopDashboard");
        ShopDashboard->setWindowModality(Qt::ApplicationModal);
        ShopDashboard->resize(793, 480);
        selectMonth = new QComboBox(ShopDashboard);
        selectMonth->setObjectName("selectMonth");
        selectMonth->setGeometry(QRect(310, 20, 151, 28));
        monthDetails = new QLineEdit(ShopDashboard);
        monthDetails->setObjectName("monthDetails");
        monthDetails->setGeometry(QRect(40, 60, 701, 41));
        centralWidget = new QWidget(ShopDashboard);
        centralWidget->setObjectName("centralWidget");
        centralWidget->setGeometry(QRect(40, 130, 701, 331));
        tableView = new QTableView(centralWidget);
        tableView->setObjectName("tableView");
        tableView->setGeometry(QRect(5, 0, 691, 331));

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
