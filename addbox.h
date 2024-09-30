#ifndef ADDBOX_H
#define ADDBOX_H

#include <QDialog>
#include "databaseheader.h"

namespace Ui {
class addbox;
}

class addbox : public QDialog
{
    Q_OBJECT

public:
    explicit addbox(QWidget *parent = nullptr);
    ~addbox();

private slots:
    void on_SaveBt_clicked();

    void on_ResetBt_clicked();

private:
    Ui::addbox *ui;
};

#endif // ADDBOX_H
