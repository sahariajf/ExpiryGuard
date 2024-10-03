#include "mainwindow.h"
#include "./ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ptrAddbox= new addbox();
    ptrsoldout = new soldout();
    ptrdetailAleart = new detailAleart();

    ui->searchResult->setVisible(false);
    ui->ExpirationAlert->setVisible(false);

    checkExpiryDates();


}

MainWindow::~MainWindow()
{
    delete ptrsoldout;
    delete ptrAddbox;
    delete ptrdetailAleart;
    delete ui;
}

void MainWindow::on_ADDBoxBt_clicked()
{
    ptrAddbox->show();
}


void MainWindow::on_SoldOutBt_clicked()
{


    ptrAddbox->show(); // Show AddBox as a modal dialog
}


void MainWindow::on_searchBT_clicked()
{
    ui->searchResult->setVisible(true);

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

    QString searchTerm = ui->searchtext->text();

    if (searchTerm.isEmpty()) {
        QMessageBox::warning(this, "Input Required", "Please input a medicine name.");
        return;
    }

    QSqlQuery query;
    query.prepare(QString("SELECT name, number , PurAmount FROM addbox WHERE name LIKE '%%1%'").arg(searchTerm));


    if (!query.exec()) {
        qDebug() << "Error executing search query: " << query.lastError();
        return;
    }

    QStringList resultList;


    while (query.next()) {
        QString name = query.value(0).toString();
        int boxNumber = query.value(1).toInt();
        QString purPrice = query.value(2).toString();

        QString message = QString(" • %1 is found in box number %2 which purchge ammount is %3.")
                              .arg(name)
                              .arg(boxNumber)
                              .arg(purPrice);
        resultList << message;
    }

    if (resultList.isEmpty()) {
        resultList << "Oh No! The medicine is already sold out. Order more.";
    }


    QStringListModel *model = new QStringListModel(this);
    model->setStringList(resultList);
    ui->searchResult->setModel(model);

    database.close();

    ui->searchtext->clear();
}


void MainWindow::checkExpiryDates()
{
    QSqlDatabase database = QSqlDatabase::addDatabase("QSQLITE");
    database.setDatabaseName("E:/1Y2S/project/ExpiryGuard/database/ExpiryGurard.db");

    if (!database.open()) {
        qDebug() << "Error: Unable to open database.";
        return;
    }


    QDate today = QDate::currentDate();

    // Query for medicines expiring in the next 7 days
    QString todayStr = today.toString("yyyy-MM-dd");
    QString nextWeekStr = today.addDays(7).toString("yyyy-MM-dd");

    QSqlQuery expiryQuery;
    expiryQuery.prepare("SELECT COUNT(*) FROM addbox WHERE ExpiryDate BETWEEN :today AND :nextWeek");
    expiryQuery.bindValue(":today", todayStr);
    expiryQuery.bindValue(":nextWeek", nextWeekStr);

    int expiringCount = 0;
    if (expiryQuery.exec()) {
        if (expiryQuery.next()) {
            expiringCount = expiryQuery.value(0).toInt(); // Get the count result
        }
    } else {
        qDebug() << "Error executing expiry query: " << expiryQuery.lastError();
    }


    // Query for medicines that have already expired
    QSqlQuery expiredQuery;
    expiredQuery.prepare("SELECT COUNT(*) FROM addbox WHERE ExpiryDate < :today");
    expiredQuery.bindValue(":today", todayStr);

    int expiredCount = 0;
    if (expiredQuery.exec()) {
        if (expiredQuery.next()) {
            expiredCount = expiredQuery.value(0).toInt();
        }
    } else {
        qDebug() << "Error executing expired query: " << expiredQuery.lastError();
    }

    // Display results in the ExpirationAlert
    if(expiredCount > 0 || expiringCount > 0 )
    {
        ui->ExpirationAlert->setVisible(true);
        QString message1 = QString("%1 medicine(s) are going to expire in the next 7 days and %2 medicine(s) have already expired.")
                              .arg(expiringCount)
                              .arg(expiredCount);
        QString massage2 = QString("%1 medicine(s) are going to expire in the next 7 days")
                               .arg(expiringCount);

        QString massage3 = QString("Aleart!! %1 medicine(s) have already expired.")
                               .arg(expiredCount);
        if(expiredCount > 0 && expiringCount > 0)
            ui->ExpirationAlert->setText(message1);

        else if(expiredCount > 0)
            ui->ExpirationAlert->setText(massage3);

        else if(expiringCount > 0)
            ui->ExpirationAlert->setText(massage2);
    }

    database.close();
}


void MainWindow::on_refreshBt_clicked()
{
    checkExpiryDates();
}


void MainWindow::on_DetailsBt_clicked()
{
    ptrdetailAleart->show();
}

