#ifndef SOLDOUT_H
#define SOLDOUT_H

#include <QDialog>
#include "databaseheader.h"

namespace Ui {
class soldout;
}

class soldout : public QDialog
{
    Q_OBJECT

public:
    explicit soldout(QWidget *parent = nullptr);
    ~soldout();

private slots:
    void on_soldOutBt_clicked();

    void on_ResetBt_clicked();

private:
    Ui::soldout *ui;
};

#endif // SOLDOUT_H
