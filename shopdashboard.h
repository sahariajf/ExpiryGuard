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

private:
    Ui::ShopDashboard *ui;
};

#endif // SHOPDASHBOARD_H
