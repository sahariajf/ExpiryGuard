#include "totalexpenses.h"
#include "ui_totalexpenses.h"

totalexpenses::totalexpenses(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::totalexpenses)
{
    ui->setupUi(this);
}

totalexpenses::~totalexpenses()
{
    delete ui;
}
