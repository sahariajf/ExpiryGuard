#include "expirydashboard.h"
#include "ui_expirydashboard.h"
#include "databaseheader.h"

ExpiryDashboard::ExpiryDashboard(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::ExpiryDashboard)
{
    ui->setupUi(this);

    ui->showResult->setVisible(false);
}

ExpiryDashboard::~ExpiryDashboard()
{
    delete ui;
}

void ExpiryDashboard::on_daySelectionBT_activated(int index)
{
    QSqlDatabase database = QSqlDatabase::addDatabase("QSQLITE");
    database.setDatabaseName("E:/1Y2S/project/ExpiryGuard/database/ExpiryGurard.db");

    if (!database.open()) {
        qDebug() << "Error: Unable to open database.";
        return;
    }


    QDate today = QDate::currentDate();

    if(index == 0)
    {
        ui->showResult->setVisible(true);
        // Query for medicines expiring in the next 7 days
        QDate today = QDate::currentDate();
        QString todayStr = today.toString("yyyy-MM-dd");
        QString nextWeekStr = today.addDays(7).toString("yyyy-MM-dd");

        QSqlQuery expiryQuery;
        expiryQuery.prepare("SELECT name, number, ExpiryDate FROM addbox WHERE ExpiryDate BETWEEN :today AND :nextWeek");
        expiryQuery.bindValue(":today", todayStr);
        expiryQuery.bindValue(":nextWeek", nextWeekStr);

        if (!expiryQuery.exec()) {
            qDebug() << "Error: Unable to execute expiry query.";
            return;
        }

        QStringList expiringMessages;

        while (expiryQuery.next()) {
            QString name = expiryQuery.value(0).toString();
            QString boxNumber = expiryQuery.value(1).toString();
            QString expiryDate = expiryQuery.value(2).toString();

            QString message = QString(" • %1 which Box number %2 is going to expire on %3.")
                                  .arg(name)
                                  .arg(boxNumber)
                                  .arg(expiryDate);

            expiringMessages << message;
        }


        QStringListModel* model = new QStringListModel(this);
        model->setStringList(expiringMessages);
        ui->showResult->setModel(model);

    }

    if(index == 1)
    {
        ui->showResult->setVisible(true);
        // Query for medicines expiring in the next 7 days
        QDate today = QDate::currentDate();
        QString todayStr = today.toString("yyyy-MM-dd");
        QString next15Str = today.addDays(15).toString("yyyy-MM-dd");

        QSqlQuery expiryQuery;
        expiryQuery.prepare("SELECT name, number, ExpiryDate FROM addbox WHERE ExpiryDate BETWEEN :today AND :next15Str");
        expiryQuery.bindValue(":today", todayStr);
        expiryQuery.bindValue(":next15Str", next15Str);

        if (!expiryQuery.exec()) {
            qDebug() << "Error: Unable to execute expiry query.";
            return;
        }

        QStringList expiringMessages;

        while (expiryQuery.next()) {
            QString name = expiryQuery.value(0).toString();
            QString boxNumber = expiryQuery.value(1).toString();
            QString expiryDate = expiryQuery.value(2).toString();

            QString message = QString(" • %1 which Box number %2 is going to expire on %3.")
                                  .arg(name)
                                  .arg(boxNumber)
                                  .arg(expiryDate);

            expiringMessages << message;
        }


        QStringListModel* model = new QStringListModel(this);
        model->setStringList(expiringMessages);
        ui->showResult->setModel(model);

    }
}

