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

