#ifndef EXPIRYDASHBOARD_H
#define EXPIRYDASHBOARD_H

#include <QDialog>

namespace Ui {
class ExpiryDashboard;
}

class ExpiryDashboard : public QDialog
{
    Q_OBJECT

public:
    explicit ExpiryDashboard(QWidget *parent = nullptr);
    ~ExpiryDashboard();

private slots:
    void on_daySelectionBT_activated(int index);

private:
    Ui::ExpiryDashboard *ui;
};

#endif // EXPIRYDASHBOARD_H
