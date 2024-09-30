#include "soldout.h"
#include "ui_soldout.h"

soldout::soldout(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::soldout)
{
    ui->setupUi(this);
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

    // Fetch details from addbox table
    QSqlQuery selectQuery(database);
    selectQuery.prepare("SELECT Name, purAmount FROM addbox WHERE number = :boxNumber");
    selectQuery.bindValue(":boxNumber", boxNumber);

    QString medicineName;
    double purAmount = 0.0; // Initialize purAmount

    if (selectQuery.exec() && selectQuery.next()) {
        medicineName = selectQuery.value(0).toString();
        purAmount = selectQuery.value(1).toDouble();
    } else {
        // Show a message box if the box number does not exist
        QMessageBox::warning(this, "Box Number Not Found", "The entered box number does not exist in the AddBox table.");
        database.close();
        return; // Exit if the box number is not found
    }

    // Calculate profit
    double sellAmountValue = sellAmount.toDouble();
    double profit = sellAmountValue- purAmount;

    // Show message in QListView
    QString message = QString("You sold %1 which box number is %2 with profit amount %3")
                          .arg(medicineName)
                          .arg(boxNumber)
                          .arg(profit);

    // Create a model and set the message
    QStringListModel *model = new QStringListModel();
    QStringList list;
    list << message;
    model->setStringList(list);
    ui->showdetails->setModel(model); // Assuming showdetails is your QListView

    // Prepare the SQL query for inserting data into the SoldOut table
    QSqlQuery insertQuery(database);
    insertQuery.prepare("INSERT INTO SoldOut (number, SellDate, SellAmount, profit) "
                        "VALUES (:boxNumber, :sellDate, :sellAmount, :profit)");

    // Bind values to placeholders
    insertQuery.bindValue(":boxNumber", boxNumber);
    insertQuery.bindValue(":sellDate", sellDate);
    insertQuery.bindValue(":sellAmount", sellAmount);
    insertQuery.bindValue(":profit", profit); // Bind profit value

    // Execute the query and check for errors
    if (!insertQuery.exec()) {
        qDebug() << "Error: Unable to execute query -" << insertQuery.lastError().text();
    } else {
        qDebug() << "Data saved successfully with profit calculated.";
    }

    // Close the database connection
    database.close();

    // Clear input fields
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

