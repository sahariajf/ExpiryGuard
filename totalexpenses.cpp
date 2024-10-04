#include "totalexpenses.h"
#include "ui_totalexpenses.h"

totalexpenses::totalexpenses(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::totalexpenses)
{
    ui->setupUi(this);
}

totalexpenses::~totalexpenses()
{
    delete ui;
}

void totalexpenses::on_soldOutBt_clicked()
{
    QString discription = ui->DiscriptionIn->text();
    QString Date = ui->dateEdit->text();
    QString Amount = ui->AmountIN->text();

    // Set up the database connection
    QSqlDatabase database = QSqlDatabase::addDatabase("QSQLITE");
    database.setDatabaseName("E:/1Y2S/project/ExpiryGuard/database/ExpiryGurard.db");

    if (!QFile::exists("E:/1Y2S/project/ExpiryGuard/database/ExpiryGurard.db")) {
        qDebug() << "Error: Database file doesn't exist.";
        return;
    }

    if (!database.open()) {
        qDebug() << "Error: Unable to open database.";
        return;
    } else {
        qDebug() << "Database opened successfully.";
    }

    QSqlQuery insertQuery(database);
    insertQuery.prepare("INSERT INTO totalexpenses (date, discription, Amount) "
                        "VALUES (:date, :discription, :Amount)");


    insertQuery.bindValue(":date", Date);
    insertQuery.bindValue(":discription", discription);
    insertQuery.bindValue(":Amount", Amount);



    if (!insertQuery.exec()) {
        qDebug() << "Error: Unable to execute query -" << insertQuery.lastError().text();
    } else {
        qDebug() << "Data saved successfully";
         QMessageBox::information(this, "Success", "Saved Successfully!");
    }

}

