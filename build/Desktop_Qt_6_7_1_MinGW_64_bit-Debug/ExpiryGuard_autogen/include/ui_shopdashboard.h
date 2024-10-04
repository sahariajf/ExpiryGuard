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
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
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
    QPushButton *pushButton;
    QLabel *label;
    QLabel *label_2;

    void setupUi(QDialog *ShopDashboard)
    {
        if (ShopDashboard->objectName().isEmpty())
            ShopDashboard->setObjectName("ShopDashboard");
        ShopDashboard->setWindowModality(Qt::ApplicationModal);
        ShopDashboard->resize(793, 530);
        selectMonth = new QComboBox(ShopDashboard);
        selectMonth->setObjectName("selectMonth");
        selectMonth->setGeometry(QRect(310, 20, 151, 28));
        monthDetails = new QLineEdit(ShopDashboard);
        monthDetails->setObjectName("monthDetails");
        monthDetails->setGeometry(QRect(40, 60, 701, 41));
        centralWidget = new QWidget(ShopDashboard);
        centralWidget->setObjectName("centralWidget");
        centralWidget->setGeometry(QRect(40, 140, 701, 321));
        tableView = new QTableView(centralWidget);
        tableView->setObjectName("tableView");
        tableView->setGeometry(QRect(0, 10, 691, 301));
        pushButton = new QPushButton(ShopDashboard);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(590, 470, 131, 29));
        label = new QLabel(ShopDashboard);
        label->setObjectName("label");
        label->setGeometry(QRect(180, 20, 121, 20));
        QFont font;
        font.setPointSize(10);
        font.setBold(true);
        label->setFont(font);
        label->setLayoutDirection(Qt::LeftToRight);
        label_2 = new QLabel(ShopDashboard);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(312, 110, 111, 20));
        QFont font1;
        font1.setPointSize(12);
        font1.setBold(true);
        label_2->setFont(font1);

        retranslateUi(ShopDashboard);

        QMetaObject::connectSlotsByName(ShopDashboard);
    } // setupUi

    void retranslateUi(QDialog *ShopDashboard)
    {
        ShopDashboard->setWindowTitle(QCoreApplication::translate("ShopDashboard", "Shop Dashboard", nullptr));
        pushButton->setText(QCoreApplication::translate("ShopDashboard", "Refresh data", nullptr));
        label->setText(QCoreApplication::translate("ShopDashboard", "Select month :", nullptr));
        label_2->setText(QCoreApplication::translate("ShopDashboard", "OverView :", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ShopDashboard: public Ui_ShopDashboard {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SHOPDASHBOARD_H
