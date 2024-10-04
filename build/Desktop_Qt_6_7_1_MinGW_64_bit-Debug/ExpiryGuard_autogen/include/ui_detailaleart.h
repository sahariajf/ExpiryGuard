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
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_detailAleart
{
public:
    QListView *ExpiredView;
    QListView *ExpiringView;
    QLabel *label;
    QLabel *label_2;
    QPushButton *pushButton;

    void setupUi(QDialog *detailAleart)
    {
        if (detailAleart->objectName().isEmpty())
            detailAleart->setObjectName("detailAleart");
        detailAleart->setWindowModality(Qt::ApplicationModal);
        detailAleart->resize(446, 493);
        detailAleart->setStyleSheet(QString::fromUtf8("QWidget {\n"
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
"QLabel{\n"
" 	color:rgb(0, 104, 94);\n"
"	font-size:25px;\n"
"}\n"
"\n"
"QListView {\n"
"    background-color:rgb(193, 201, 255); \n"
"    border: 1px solid #ccc; \n"
"    border-radius: 7px;	\n"
" font-size: 16px;                /* Font size */\n"
"    color: #333333; \n"
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
""
                        "QScrollBar::add-line:vertical, \n"
"QScrollBar::sub-line:vertical {\n"
"    background: none; \n"
"}\n"
"\n"
""));
        ExpiredView = new QListView(detailAleart);
        ExpiredView->setObjectName("ExpiredView");
        ExpiredView->setGeometry(QRect(10, 70, 421, 141));
        QFont font;
        font.setBold(true);
        ExpiredView->setFont(font);
        ExpiredView->setStyleSheet(QString::fromUtf8("QListView {\n"
"    text-align: center;  \n"
"}"));
        ExpiredView->setSpacing(2);
        ExpiringView = new QListView(detailAleart);
        ExpiringView->setObjectName("ExpiringView");
        ExpiringView->setGeometry(QRect(10, 280, 421, 141));
        ExpiringView->setFont(font);
        ExpiringView->setStyleSheet(QString::fromUtf8("QListView {\n"
"    text-align: center;  \n"
"}"));
        ExpiringView->setSpacing(2);
        ExpiringView->setWordWrap(true);
        ExpiringView->setItemAlignment(Qt::AlignCenter);
        label = new QLabel(detailAleart);
        label->setObjectName("label");
        label->setGeometry(QRect(120, 20, 211, 41));
        label->setFont(font);
        label_2 = new QLabel(detailAleart);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(120, 220, 211, 41));
        label_2->setFont(font);
        pushButton = new QPushButton(detailAleart);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(180, 440, 83, 29));
        pushButton->setFont(font);

        retranslateUi(detailAleart);

        QMetaObject::connectSlotsByName(detailAleart);
    } // setupUi

    void retranslateUi(QDialog *detailAleart)
    {
        detailAleart->setWindowTitle(QCoreApplication::translate("detailAleart", "Detail Aleart", nullptr));
        label->setText(QCoreApplication::translate("detailAleart", "Already Expired", nullptr));
        label_2->setText(QCoreApplication::translate("detailAleart", "Going to Expire", nullptr));
        pushButton->setText(QCoreApplication::translate("detailAleart", "Refresh", nullptr));
    } // retranslateUi

};

namespace Ui {
    class detailAleart: public Ui_detailAleart {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DETAILALEART_H
