#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "addbox.h"
#include "soldout.h"
#include "detailaleart.h"
#include "expiredbox.h"
#include "expirydashboard.h"

class AddBox;

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();


private slots:
    void on_ADDBoxBt_clicked();

    void on_SoldOutBt_clicked();

    void on_searchBT_clicked();

    void checkExpiryDates();

    void showNotification(const QString &message);

    void on_refreshBt_clicked();

    void on_DetailsBt_clicked();

    void on_ExpiredBoxBt_clicked();

    void on_ExpiryDashBoardBT_clicked();

private:
    Ui::MainWindow *ui;
    addbox *ptrAddbox;
    soldout *ptrsoldout;
    detailAleart *ptrdetailAleart;
    expiredBox *ptrExpiredBox;
    ExpiryDashboard *ptrExpirydashboard;
};
#endif // MAINWINDOW_H
