#ifndef DETAILALEART_H
#define DETAILALEART_H

#include <QDialog>
#include "databaseheader.h"


namespace Ui {
class detailAleart;
}

class detailAleart : public QDialog
{
    Q_OBJECT

public:
    explicit detailAleart(QWidget *parent = nullptr);
    ~detailAleart();
    void populateExpiryLists();

private slots:
    void on_pushButton_clicked();

private:
    Ui::detailAleart *ui;
};

#endif // DETAILALEART_H
