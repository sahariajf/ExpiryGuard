#include "soldout.h"
#include "ui_soldout.h"

soldout::soldout(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::soldout)
{
    ui->setupUi(this);
    QDateEdit *dateEdit = ui->sellDateIn;
    QDate todayDate = QDate::currentDate();

    dateEdit->setDate(todayDate);
    dateEdit->setDisplayFormat("yyyy-MM-dd");

}

soldout::~soldout()
{
    delete ui;
}

void soldout::on_soldOutBt_clicked()
{

    QString boxNumber = ui->boxNumberIn->text();
    QString sellDate = ui->sellDateIn->text();
    QString sellAmount = ui->sellAmountIn->text();

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


    QSqlQuery selectQuery(database);
    selectQuery.prepare("SELECT Name, purAmount FROM addbox WHERE number = :boxNumber");
    selectQuery.bindValue(":boxNumber", boxNumber);

    QString medicineName;
    double purAmount = 0.0;

    if (selectQuery.exec() && selectQuery.next()) {
        medicineName = selectQuery.value(0).toString();
        purAmount = selectQuery.value(1).toDouble();

    } else {

        QMessageBox::warning(this, "Box Number Not Found", "The entered box number does not exist in the AddBox table.");
        database.close();
        return;
    }


    double sellAmountValue = sellAmount.toDouble();
    double profit = sellAmountValue- purAmount;
    double loss = purAmount - sellAmountValue ;
    QString message;

    if (profit > 0) {
        message = QString("You sold %1 which box number is %2 with profit amount %3")
                      .arg(medicineName)
                      .arg(boxNumber)
                      .arg(profit);
    } else {
        message = QString("OH No ! You sold %1 which box number is %2 with loss of amount %3")
                      .arg(medicineName)
                      .arg(boxNumber)
                      .arg(loss);
    }


    QStringListModel *model = new QStringListModel();
    QStringList list;
    list << message;
    model->setStringList(list);
    ui->showdetails->setModel(model);


    QSqlQuery insertQuery(database);
    insertQuery.prepare("INSERT INTO SoldOut (number, SellDate, SellAmount, profit) "
                        "VALUES (:boxNumber, :sellDate, :sellAmount, :profit)");


    insertQuery.bindValue(":boxNumber", boxNumber);
    insertQuery.bindValue(":sellDate", sellDate);
    insertQuery.bindValue(":sellAmount", sellAmount);
    insertQuery.bindValue(":profit", profit);


    if (!insertQuery.exec()) {
        qDebug() << "Error: Unable to execute query -" << insertQuery.lastError().text();
    } else {
        QSqlQuery query;
        query.prepare("DELETE FROM AddBox WHERE number = :boxNumber");
        query.bindValue(":boxNumber", boxNumber);


        if (!query.exec()) {
             qDebug() << "removed  unsuccessfully.";
        } else {
            qDebug() << "removed  successfully.";
        }
        qDebug() << "Data saved successfully with profit calculated.";
    }

    QSqlQuery insertDashboardQuery(database);
    insertDashboardQuery.prepare("INSERT INTO dashboard (date, puramount, sellamount, expenses) "
                                 "VALUES (:date, 0, :sellamount, 0)");

    // Bind values to placeholders
    insertDashboardQuery.bindValue(":date", sellDate);
    insertDashboardQuery.bindValue(":sellamount", sellAmount);

    if (!insertDashboardQuery.exec()) {
        qDebug() << "Insert error:" << insertDashboardQuery.lastError();
    } else {
        qDebug() << "Data inserted successfully into dashboard!";
        QMessageBox::information(this, "Congratulations", "Sold out!");
    }


    database.close();


    ui->boxNumberIn->clear();
    ui->sellDateIn->clear();
    ui->sellAmountIn->clear();
}




void soldout::on_ResetBt_clicked()
{
    ui->boxNumberIn->clear();
    ui->sellDateIn->clear();
    ui->sellAmountIn->clear();
}

