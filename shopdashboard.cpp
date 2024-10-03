#include "shopdashboard.h"
#include "ui_shopdashboard.h"
#include "databaseheader.h"
#include <QSet>

ShopDashboard::ShopDashboard(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::ShopDashboard)
{
    ui->setupUi(this);
    ComboBoxWithFormattedDates();
}

ShopDashboard::~ShopDashboard()
{
    delete ui;
}

void ShopDashboard::ComboBoxWithFormattedDates()
{

    QSqlDatabase database = QSqlDatabase::addDatabase("QSQLITE");
    database.setDatabaseName("E:/1Y2S/project/ExpiryGuard/database/ExpiryGurard.db");

    if (!database.open()) {
        QMessageBox::warning(this, "Database Error", "Unable to open database.");
        return;
    }

    QSqlQuery purdateQuery("SELECT MIN(Purdate) FROM addbox");
    purdateQuery.next();
    QString minPurDateStr = purdateQuery.value(0).toString();


    QSqlQuery selldateQuery("SELECT MIN(selldate) FROM soldout");
    selldateQuery.next();
    QString minSellDateStr = selldateQuery.value(0).toString();


    QDate minPurDate = QDate::fromString(minPurDateStr, "yyyy-MM-dd");
    QDate minSellDate = QDate::fromString(minSellDateStr, "yyyy-MM-dd");


    QDate startDate = minPurDate.isValid() && minSellDate.isValid()
                          ? (minPurDate < minSellDate ? minPurDate : minSellDate)
                          : (minPurDate.isValid() ? minPurDate : minSellDate);

    if (!startDate.isValid()) {
        QMessageBox::warning(this, "Error", "No valid dates found.");
        return;
    }

    QDate currentDate = QDate::currentDate();
    ui->selectMonth->clear();

    QSet<QString> uniqueMonths;
    for (QDate date = startDate; date <= currentDate; date = date.addMonths(1)) {
        QString formattedDate = date.toString("MMMM - yyyy");
        uniqueMonths.insert(formattedDate);
    }

    for (const QString &month : uniqueMonths) {
        ui->selectMonth->addItem(month);
    }

    QString currentMonth = currentDate.toString("MMMM - yyyy");
    if (!uniqueMonths.contains(currentMonth)) {
        ui->selectMonth->addItem(currentMonth);
    }

    database.close();
}
