/********************************************************************************
** Form generated from reading UI file 'expirydashboard.ui'
**
** Created by: Qt User Interface Compiler version 6.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_EXPIRYDASHBOARD_H
#define UI_EXPIRYDASHBOARD_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListView>

QT_BEGIN_NAMESPACE

class Ui_ExpiryDashboard
{
public:
    QComboBox *daySelectionBT;
    QLabel *label;
    QListView *showResult;

    void setupUi(QDialog *ExpiryDashboard)
    {
        if (ExpiryDashboard->objectName().isEmpty())
            ExpiryDashboard->setObjectName("ExpiryDashboard");
        ExpiryDashboard->setWindowModality(Qt::ApplicationModal);
        ExpiryDashboard->resize(640, 480);
        daySelectionBT = new QComboBox(ExpiryDashboard);
        daySelectionBT->addItem(QString());
        daySelectionBT->addItem(QString());
        daySelectionBT->setObjectName("daySelectionBT");
        daySelectionBT->setGeometry(QRect(330, 60, 51, 28));
        QFont font;
        font.setPointSize(10);
        font.setBold(true);
        daySelectionBT->setFont(font);
        daySelectionBT->setMouseTracking(true);
        label = new QLabel(ExpiryDashboard);
        label->setObjectName("label");
        label->setGeometry(QRect(210, 60, 111, 20));
        label->setFont(font);
        showResult = new QListView(ExpiryDashboard);
        showResult->setObjectName("showResult");
        showResult->setGeometry(QRect(50, 120, 551, 281));
        QFont font1;
        font1.setPointSize(14);
        font1.setBold(true);
        showResult->setFont(font1);
        showResult->setMovement(QListView::Free);
        showResult->setSpacing(3);
        showResult->setWordWrap(true);
        showResult->setItemAlignment(Qt::AlignCenter);

        retranslateUi(ExpiryDashboard);

        QMetaObject::connectSlotsByName(ExpiryDashboard);
    } // setupUi

    void retranslateUi(QDialog *ExpiryDashboard)
    {
        ExpiryDashboard->setWindowTitle(QCoreApplication::translate("ExpiryDashboard", "ExpiryDashboard ", nullptr));
        daySelectionBT->setItemText(0, QCoreApplication::translate("ExpiryDashboard", "7", nullptr));
        daySelectionBT->setItemText(1, QCoreApplication::translate("ExpiryDashboard", "15", nullptr));

        daySelectionBT->setCurrentText(QCoreApplication::translate("ExpiryDashboard", "7", nullptr));
        daySelectionBT->setPlaceholderText(QCoreApplication::translate("ExpiryDashboard", "Select Days", nullptr));
        label->setText(QCoreApplication::translate("ExpiryDashboard", "Select Days :", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ExpiryDashboard: public Ui_ExpiryDashboard {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EXPIRYDASHBOARD_H
