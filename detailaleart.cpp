#include "detailaleart.h"
#include "ui_detailaleart.h"

detailAleart::detailAleart(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::detailAleart)
{
    ui->setupUi(this);
    populateExpiryLists();
}

detailAleart::~detailAleart()
{
    delete ui;
}

void detailAleart::populateExpiryLists() {
    QSqlDatabase database = QSqlDatabase::addDatabase("QSQLITE");
    database.setDatabaseName("E:/1Y2S/project/ExpiryGuard/database/ExpiryGurard.db");

    if (!database.open()) {
        qDebug() << "Error: Unable to open database.";
        return;
    }

    QDate currentDate = QDate::currentDate();
    QDate sevenDaysFromNow = currentDate.addDays(7);

    // Query for medicines expiring in the next 7 days
    QSqlQuery expiringQuery;
    expiringQuery.prepare("SELECT name, number FROM AddBox WHERE ExpiryDate BETWEEN :currentDate AND :sevenDaysFromNow");
    expiringQuery.bindValue(":currentDate", currentDate);
    expiringQuery.bindValue(":sevenDaysFromNow", sevenDaysFromNow);

    QStringList expiringList;
    if (expiringQuery.exec()) {
        while (expiringQuery.next()) {
            QString name = expiringQuery.value(0).toString();
            int number = expiringQuery.value(1).toInt();  // Assuming BoxNumber is the second column

            QString message = QString(" • %1 is in box number %2 and going to expire.")
                                  .arg(name)
                                  .arg(number);

            expiringList << message;
        }
    } else {
        qDebug() << "Error fetching expiring medicines: " << expiringQuery.lastError().text();
    }

    if (expiringList.isEmpty()) {
        expiringList << "Great! No medicine is going to expire in the next 7 days.";
    }

    QStringListModel *expiringModel = new QStringListModel(this);
    expiringModel->setStringList(expiringList);
    ui->ExpiringView->setModel(expiringModel);

    // Query for medicines that have already expired
    QSqlQuery expiredQuery;
    expiredQuery.prepare("SELECT name, number FROM AddBox WHERE ExpiryDate < :currentDate");
    expiredQuery.bindValue(":currentDate", currentDate);

    QStringList expiredList;
    if (expiredQuery.exec()) {
        while (expiredQuery.next()) {
            QString name = expiredQuery.value(0).toString();
            int number = expiredQuery.value(1).toInt();

            QString message = QString(" • %1 is in box number %2 and already expired.")
                                  .arg(name)
                                  .arg(number);

            expiredList << message;
        }
    } else {
        qDebug() << "Error fetching expired medicines: " << expiredQuery.lastError().text();
    }

    if (expiredList.isEmpty()) {
        expiredList << "Great! No medicine has expired.";
    }

    QStringListModel *expiredModel = new QStringListModel(this);
    expiredModel->setStringList(expiredList);
    ui->ExpiredView->setModel(expiredModel);
}
