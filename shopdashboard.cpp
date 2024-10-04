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

void ShopDashboard::setupTableView() {
    // Create database connection
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("E:/1Y2S/project/ExpiryGuard/database/ExpiryGurard.db");
    if (!db.open()) {
        QMessageBox::critical(this, "Database Error", "Unable to open database");
        return;
    }

    // Set up the model
    QSqlQueryModel* model = new QSqlQueryModel(this);

    // SQL query to retrieve data
    QSqlQuery query;
    query.prepare(R"(
        WITH unique_months AS (
            SELECT strftime('%Y-%m', PurDate) AS month_year, strftime('%m', PurDate) AS month_num
            FROM AddBox
            UNION
            SELECT strftime('%Y-%m', SellDate) AS month_year, strftime('%m', SellDate) AS month_num
            FROM SoldOut
        ),
        monthly_totals AS (
            SELECT
                um.month_year,
                um.month_num,
                COALESCE(SUM(ab.PurAmount), 0) AS total_purchase,
                COALESCE(SUM(so.SellAmount), 0) AS total_sale
            FROM unique_months um
            LEFT JOIN AddBox ab ON strftime('%Y-%m', ab.PurDate) = um.month_year
            LEFT JOIN SoldOut so ON strftime('%Y-%m', so.SellDate) = um.month_year
            GROUP BY um.month_year, um.month_num
            ORDER BY um.month_year
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
            total_sale,
            (total_sale - total_purchase) AS profit
        FROM monthly_totals;
    )");

    // Execute the query and check for errors
    if (!query.exec()) {
        QMessageBox::critical(this, "Query Error", query.lastError().text());
        return;
    }

    model->setQuery(query);

    // Check if the model has rows
    if (model->rowCount() == 0) {
        QMessageBox::information(this, "No Data", "No data available for the selected period.");
        return;
    }

    // Set header data
    model->setHeaderData(0, Qt::Horizontal, "Month");
    model->setHeaderData(1, Qt::Horizontal, "Total Purchase Amount");
    model->setHeaderData(2, Qt::Horizontal, "Total Sale Amount");
    model->setHeaderData(3, Qt::Horizontal, "Profit"); // Set header for profit

    // Set up the table view
    QTableView* tableView = new QTableView(this);
    tableView->setModel(model);
    tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);

    // Create a layout and add the table view
    QVBoxLayout* layout = new QVBoxLayout(ui->centralWidget); // Assuming you have a central widget
    layout->addWidget(tableView);
}


void ShopDashboard::on_pushButton_clicked()
{
    ComboBoxWithFormattedDates();
    setupTableView();
}

