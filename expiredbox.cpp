#include "expiredbox.h"
#include "ui_expiredbox.h"
#include "databaseheader.h"

expiredBox::expiredBox(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::expiredBox)
{
    ui->setupUi(this);
}

expiredBox::~expiredBox()
{
    delete ui;
}

#include <QMessageBox>

void expiredBox::on_pushButton_clicked()
{
    QString boxNumber = ui->ExpiredBoxIn->text();


    QSqlDatabase database = QSqlDatabase::addDatabase("QSQLITE");
    database.setDatabaseName("E:/1Y2S/project/ExpiryGuard/database/ExpiryGurard.db");

    if (!QFile::exists("E:/1Y2S/project/ExpiryGuard/database/ExpiryGurard.db")) {
        QMessageBox::warning(this, "Error", "Database file doesn't exist.");
        return;
    }

    if (!database.open()) {
        QMessageBox::warning(this, "Error", "Unable to open database.");
        return;
    }

    QSqlQuery query;
    QString currentDate = QDate::currentDate().toString("yyyy-MM-dd");

    // Check if the box is expired
    query.prepare("SELECT ExpiryDate FROM AddBox WHERE number = :boxNumber");
    query.bindValue(":boxNumber", boxNumber);

    if (query.exec()) {
        if (query.next()) {
            QString expireDate = query.value(0).toString();

            if (expireDate < currentDate) {
                QSqlQuery deleteQuery;
                deleteQuery.prepare("DELETE FROM addbox WHERE number = :boxNumber");
                deleteQuery.bindValue(":boxNumber", boxNumber);

                if (deleteQuery.exec()) {
                    QMessageBox::information(this, "Box Deleted", "Box number " + boxNumber + " has been removed.");
                } else {
                    QMessageBox::warning(this, "Error", "Try again");
                }
            }
            else
            {
                QMessageBox::information(this, "Box Not Expired", "Box number " + boxNumber + " is not expired.");
            }
        }
        else
        {
            QMessageBox::warning(this, "Error", "Box number " + boxNumber + " not found.");
        }
    }


    database.close();

    ui->ExpiredBoxIn->clear();
}

