#ifndef EXPIREDBOX_H
#define EXPIREDBOX_H

#include <QDialog>

namespace Ui {
class expiredBox;
}

class expiredBox : public QDialog
{
    Q_OBJECT

public:
    explicit expiredBox(QWidget *parent = nullptr);
    ~expiredBox();

private slots:
    void on_pushButton_clicked();

private:
    Ui::expiredBox *ui;
};

#endif // EXPIREDBOX_H
