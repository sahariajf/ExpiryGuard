#ifndef SHOPDASHBOARD_H
#define SHOPDASHBOARD_H

#include <QDialog>
#include "databaseheader.h"

namespace Ui {
class ShopDashboard;
}

class ShopDashboard : public QDialog
{
    Q_OBJECT

public:
    explicit ShopDashboard(QWidget *parent = nullptr);
    ~ShopDashboard();
    void ComboBoxWithFormattedDates();
    void setupTableView();

private slots:
    void on_selectMonth_currentIndexChanged(int index);

    void on_pushButton_clicked();

private:
    Ui::ShopDashboard *ui;
};

#endif // SHOPDASHBOARD_H
