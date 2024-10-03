/********************************************************************************
** Form generated from reading UI file 'detailaleart.ui'
**
** Created by: Qt User Interface Compiler version 6.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DETAILALEART_H
#define UI_DETAILALEART_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListView>

QT_BEGIN_NAMESPACE

class Ui_detailAleart
{
public:
    QListView *ExpiredView;
    QListView *ExpiringView;
    QLabel *label;
    QLabel *label_2;

    void setupUi(QDialog *detailAleart)
    {
        if (detailAleart->objectName().isEmpty())
            detailAleart->setObjectName("detailAleart");
        detailAleart->setWindowModality(Qt::ApplicationModal);
        detailAleart->resize(446, 493);
        ExpiredView = new QListView(detailAleart);
        ExpiredView->setObjectName("ExpiredView");
        ExpiredView->setGeometry(QRect(10, 70, 421, 141));
        ExpiredView->setStyleSheet(QString::fromUtf8("QListView {\n"
"    text-align: center;  \n"
"}"));
        ExpiredView->setSpacing(2);
        ExpiringView = new QListView(detailAleart);
        ExpiringView->setObjectName("ExpiringView");
        ExpiringView->setGeometry(QRect(10, 280, 421, 141));
        ExpiringView->setStyleSheet(QString::fromUtf8("QListView {\n"
"    text-align: center;  \n"
"}"));
        ExpiringView->setSpacing(2);
        ExpiringView->setWordWrap(true);
        ExpiringView->setItemAlignment(Qt::AlignCenter);
        label = new QLabel(detailAleart);
        label->setObjectName("label");
        label->setGeometry(QRect(120, 20, 211, 41));
        QFont font;
        font.setPointSize(16);
        font.setBold(true);
        label->setFont(font);
        label_2 = new QLabel(detailAleart);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(120, 220, 211, 41));
        label_2->setFont(font);

        retranslateUi(detailAleart);

        QMetaObject::connectSlotsByName(detailAleart);
    } // setupUi

    void retranslateUi(QDialog *detailAleart)
    {
        detailAleart->setWindowTitle(QCoreApplication::translate("detailAleart", "Dialog", nullptr));
        label->setText(QCoreApplication::translate("detailAleart", "Already Expired", nullptr));
        label_2->setText(QCoreApplication::translate("detailAleart", "Going to Expire", nullptr));
    } // retranslateUi

};

namespace Ui {
    class detailAleart: public Ui_detailAleart {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DETAILALEART_H
