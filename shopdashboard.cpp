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
    setupTableView();
}

ShopDashboard::~ShopDashboard()
{
    delete ui;
}

void ShopDashboard::ComboBoxWithFormattedDates()
{
    QSqlDatabase database = QSqlDatabase::database("qt_sql_default_connection");
    if (!database.isValid()) {
        database = QSqlDatabase::addDatabase("QSQLITE");
        database.setDatabaseName("E:/1Y2S/project/ExpiryGuard/database/ExpiryGurard.db");
    }

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
        // QMessageBox::warning(this, "Error", "No valid dates found.");
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

void ShopDashboard::on_selectMonth_currentIndexChanged(int index)
{
    if (index < 0 || index >= ui->selectMonth->count()) {
        return;
    }

    QString selectedMonthYear = ui->selectMonth->currentText();
    QStringList parts = selectedMonthYear.split(" - ");

    QString monthStr = parts[0];
    QString yearStr = parts[1];

    qDebug() << selectedMonthYear;

    QDate date = QDate::fromString("01 " + monthStr + " " + yearStr, "dd MMMM yyyy");
    if (!date.isValid()) return;

    int monthNumber = date.month();
    int yearNumber = date.year();

    double totalPurAmount = 0.0;
    double totalSellAmount = 0.0;

    QSqlDatabase database = QSqlDatabase::database("qt_sql_default_connection");
    if (!database.isValid()) {
        database = QSqlDatabase::addDatabase("QSQLITE");
        database.setDatabaseName("E:/1Y2S/project/ExpiryGuard/database/ExpiryGurard.db");
    }

    if (!database.open()) {
        QMessageBox::warning(this, "Database Error", "Unable to open database.");
        return;
    }


    QString datePrefix = QString("%1-%2").arg(yearNumber).arg(QString::number(monthNumber).rightJustified(2, '0'));


    QSqlQuery purQuery;
    purQuery.prepare("SELECT COALESCE(SUM(purAmount + expenses), 0) FROM dashboard WHERE Date LIKE :datePrefix || '%'");
    purQuery.bindValue(":datePrefix", datePrefix);
    purQuery.exec();

    if (purQuery.next()) {
        totalPurAmount = purQuery.value(0).toDouble();
    }


    QSqlQuery sellQuery;
    sellQuery.prepare("SELECT COALESCE(SUM(sellAmount), 0) FROM dashboard WHERE Date LIKE :datePrefix || '%'");
    sellQuery.bindValue(":datePrefix", datePrefix);
    sellQuery.exec();

    if (sellQuery.next()) {
        totalSellAmount = sellQuery.value(0).toDouble();
    }

    database.close();


    double totalProfit = totalSellAmount - totalPurAmount;


    if(totalProfit > 0)
    {
        QString message = QString(" Great ! Your Total cost (medicine + expenses ) amount: %1, Total sell amount: %2, and profit of this month is: %3")
                              .arg(QString::number(totalPurAmount, 'f', 2))
                              .arg(QString::number(totalSellAmount, 'f', 2))
                              .arg(QString::number(totalProfit, 'f', 2));
        ui->monthDetails->setText(message);
    }


    else {
    QString message = QString("Oh no! Your Total cost (medicine + expenses ) amount: %1, Total sell amount: %2, and loss of this month is: %3")
                          .arg(QString::number(totalPurAmount, 'f', 2))
                          .arg(QString::number(totalSellAmount, 'f', 2))
                          .arg(QString::number(totalProfit, 'f', 2));
        ui->monthDetails->setText(message);
    }


}

 // Create table

void ShopDashboard::setupTableView() {

    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("E:/1Y2S/project/ExpiryGuard/database/ExpiryGurard.db");
    if (!db.open()) {
        QMessageBox::critical(this, "Database Error", "Unable to open database");
        return;
    }


    QSqlQueryModel* model = new QSqlQueryModel(this);


    QSqlQuery query;
    query.prepare(R"(
        WITH monthly_totals AS (
            SELECT
                strftime('%Y-%m', Date) AS month_year,
                strftime('%m', Date) AS month_num,
                COALESCE(SUM(purAmount), 0) AS total_purchase,
                COALESCE(SUM(expenses), 0) AS total_expenses,
                COALESCE(SUM(sellAmount), 0) AS total_sale
            FROM dashboard
            GROUP BY month_year, month_num
            ORDER BY month_year
        )
        SELECT
            CASE month_num
                WHEN '01' THEN 'January'
                WHEN '02' THEN 'February'
                WHEN '03' THEN 'March'
                WHEN '04' THEN 'April'
                WHEN '05' THEN 'May'
                WHEN '06' THEN 'June'
                WHEN '07' THEN 'July'
                WHEN '08' THEN 'August'
                WHEN '09' THEN 'September'
                WHEN '10' THEN 'October'
                WHEN '11' THEN 'November'
                WHEN '12' THEN 'December'
            END || ' - ' || substr(month_year, 1, 4) AS month_year,
            total_purchase,
            total_expenses,
            total_sale,
            (total_sale - (total_purchase + total_expenses)) AS profit
        FROM monthly_totals;
    )");

    // Execute the query and check for errors
    if (!query.exec()) {
        QMessageBox::critical(this, "Query Error", query.lastError().text());
        return;
    }

    model->setQuery(query);

    // Check if the model has rows
    if (model->rowCount() < 0) {
        QMessageBox::information(this, "No Data", "No data available for the selected period.");
        return;
    }

    // Set header data
    model->setHeaderData(0, Qt::Horizontal, "Month");
    model->setHeaderData(1, Qt::Horizontal, "Total Purchase Amount");
    model->setHeaderData(2, Qt::Horizontal, "Total Expenses");
    model->setHeaderData(3, Qt::Horizontal, "Total Sale Amount");
    model->setHeaderData(4, Qt::Horizontal, "Profit");

    QLayout* existingLayout = ui->centralWidget->layout();


    if (existingLayout) {
        QLayoutItem* item;
        while ((item = existingLayout->takeAt(0))) {
            delete item->widget();
        }
    } else {
        existingLayout = new QVBoxLayout(ui->centralWidget);
    }

    QTableView* tableView = new QTableView(this);
    tableView->setModel(model);
    tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);

    existingLayout->addWidget(tableView);

    db.close();
}


void ShopDashboard::on_pushButton_clicked()
{
    ComboBoxWithFormattedDates();
    setupTableView();
}

