#include "addbox.h"
#include "ui_addbox.h"

addbox::addbox(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::addbox)
{
    ui->setupUi(this);
}


addbox::~addbox()
{
    delete ui;
}

void addbox::on_SaveBt_clicked()
{
    QString boxNumber = ui->BoxNumberIn->text();
    QString name = ui->nameIn->text();
    QString purDate = ui->PurDatein->text();
    QString expiryDate = ui->ExpiryDatein->text();
    QString purAmount = ui->purAmountin->text();



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

    // Convert purchase date and expiry date to QDate
    QDate purchaseDate = QDate::fromString(purDate, "yyyy-MM-dd");
    QDate expiryDateObj = QDate::fromString(expiryDate, "yyyy-MM-dd");

    // Validate date comparison
    if (!purchaseDate.isValid() || !expiryDateObj.isValid()) {
        QMessageBox::warning(this, "Invalid Date", "Please enter valid purchase and expiry dates.");
        database.close();
        return;
    }

    if (expiryDateObj <= purchaseDate) {
        QMessageBox::warning(this, "Date Error", "Expiry date must be greater than purchase date.");
        database.close();
        return;
    }

    // Check if the box number already exists
    QSqlQuery checkQuery(database);
    checkQuery.prepare("SELECT COUNT(*) FROM AddBox WHERE number = :boxNumber");
    checkQuery.bindValue(":boxNumber", boxNumber);

    if (!checkQuery.exec()) {
        qDebug() << "Error: Unable to execute check query -" << checkQuery.lastError().text();
        database.close();
        return;
    }

    checkQuery.next();
    int count = checkQuery.value(0).toInt();

    if (count > 0) {
        // Show a notification that the box number already exists
        QMessageBox::warning(this, "Duplicate Entry", "This box number already exists.");
        database.close();
        return;
    }

    // Prepare the SQL query for inserting data
    QSqlQuery insertQuery(database);
    insertQuery.prepare("INSERT INTO AddBox (number, name, PurDate, ExpiryDate, PurAmount) "
                        "VALUES (:boxNumber, :name, :purDate, :expiryDate, :purAmount)");

    // Bind values to placeholders
    insertQuery.bindValue(":boxNumber", boxNumber);
    insertQuery.bindValue(":name", name);
    insertQuery.bindValue(":purDate", purDate);
    insertQuery.bindValue(":expiryDate", expiryDate);
    insertQuery.bindValue(":purAmount", purAmount);

    // Execute the query and check for errors
    if (!insertQuery.exec()) {
        qDebug() << "Error: Unable to execute query -" << insertQuery.lastError().text();
    } else {
        qDebug() << "Data saved successfully.";
    }

    // Close the database connection
    database.close();

    // Clear input fields
    ui->BoxNumberIn->clear();
    ui->nameIn->clear();
    ui->PurDatein->clear();
    ui->ExpiryDatein->clear();
    ui->purAmountin->clear();
}




void addbox::on_ResetBt_clicked()
{
    // Clear all the input fields
    ui->BoxNumberIn->clear();
    ui->nameIn->clear();
    ui->PurDatein->clear();
    ui->ExpiryDatein->clear();
    ui->purAmountin->clear();

    qDebug() << "All data cleared.";
}
