#include "totalexpenses.h"
#include "ui_totalexpenses.h"

totalexpenses::totalexpenses(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::totalexpenses)
{
    ui->setupUi(this);
    QDateEdit *dateEdit = ui->dateEdit;
    QDate todayDate = QDate::currentDate();

    dateEdit->setDate(todayDate);
    dateEdit->setDisplayFormat("yyyy-MM-dd");
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
        qDebug() << "Error: Unable to execute query to database totalExpanses-" << insertQuery.lastError().text();
    } else {
        qDebug() << "Data saved successfully";

    }

    QSqlQuery insertDashboardQuery(database);
    insertDashboardQuery.prepare("INSERT INTO dashboard (date, puramount, sellamount, expenses) "
                                 "VALUES (:date, 0, 0, :expenses)");


    insertDashboardQuery.bindValue(":date", Date);
    insertDashboardQuery.bindValue(":expenses", Amount);

    if (!insertDashboardQuery.exec()) {
        qDebug() << "Insert error:" << insertDashboardQuery.lastError();
    } else {
        qDebug() << "Data inserted successfully into dashboard!";
        QMessageBox::information(this, "Success", "Saved Successfully!");
    }


    ui->AmountIN->clear();
    ui->dateEdit->clear();
    ui->DiscriptionIn->clear();


}


void totalexpenses::on_ResetBt_clicked()
{
    ui->AmountIN->clear();
    ui->dateEdit->clear();
    ui->DiscriptionIn->clear();
}

