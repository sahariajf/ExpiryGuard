#include "mainwindow.h"
#include "./ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ptrAddbox= new addbox();
    ptrsoldout = new soldout();

    ui->searchResult->setVisible(false);
    ui->ExpirationAlert->setVisible(false);

    checkExpiryDates();


}

MainWindow::~MainWindow()
{
    delete ptrsoldout;
    delete ptrAddbox;
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

    // Get today's date and the date 7 days from now
    QDate today = QDate::currentDate();
    QDate nextWeek = today.addDays(7);


    QString todayStr = today.toString("yyyy-MM-dd");
    QString nextWeekStr = nextWeek.toString("yyyy-MM-dd");


    QSqlQuery query;
    query.prepare("SELECT COUNT(*) FROM addbox WHERE ExpiryDate BETWEEN :today AND :nextWeek");
    query.bindValue(":today", todayStr);
    query.bindValue(":nextWeek", nextWeekStr);

    if (query.exec()) {
        if (query.next()) {
            int count = query.value(0).toInt(); // Get the count result

            if(count>0)

            {   ui->ExpirationAlert->setVisible(true);
                QString message = QString("%1 medicine(s) are going to expire in the next 7 days").arg(count);
                ui->ExpirationAlert->setText(message);
            }

        }
    }
    else
    {
        qDebug() << "Error executing query: " << query.lastError();
    }

    database.close();
}




