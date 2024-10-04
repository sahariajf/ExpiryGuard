#ifndef TOTALEXPENSES_H
#define TOTALEXPENSES_H

#include <QDialog>
#include "databaseheader.h"

namespace Ui {
class totalexpenses;
}

class totalexpenses : public QDialog
{
    Q_OBJECT

public:
    explicit totalexpenses(QWidget *parent = nullptr);
    ~totalexpenses();

private slots:
    void on_soldOutBt_clicked();

private:
    Ui::totalexpenses *ui;
};

#endif // TOTALEXPENSES_H
