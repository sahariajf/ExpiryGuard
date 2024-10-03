#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ptrAddbox= new addbox();
    ptrsoldout = new soldout();

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
    ptrsoldout->show();
}


void MainWindow::on_searchBT_clicked()
{
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

    QSqlQuery query;
    query.prepare(QString("SELECT name, number FROM addbox WHERE name LIKE '%%1%'").arg(searchTerm));


    if (!query.exec()) {
        qDebug() << "Error executing search query: " << query.lastError();
        return;
    }

    QStringList resultList; // List to hold the results

    // Iterate through the results and populate the QStringList
    while (query.next()) {
        QString name = query.value(0).toString();
        int boxNumber = query.value(1).toInt();

        QString message = QString("%1 is found in box number %2.")
                              .arg(name)
                              .arg(boxNumber);
        resultList << message;
    }

    if (resultList.isEmpty()) {
        resultList << "Oh No! The medicine is already sold out. Order more.";
    }

    // Create a QStringListModel and set it to QListView
    QStringListModel *model = new QStringListModel(this);
    model->setStringList(resultList);
    ui->searchResult->setModel(model); // Use setModel() for QListView

    database.close();

    ui->searchtext->clear();
}





