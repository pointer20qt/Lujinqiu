#ifndef ZC_H
#define ZC_H

#include <QWidget>

namespace Ui {
class zc;
}

class zc : public QWidget
{
    Q_OBJECT

public:
    explicit zc(QWidget *parent = 0);
    ~zc();

private slots:
    void on_pushButton_clicked();

private:
    Ui::zc *ui;
};

#endif // ZC_H
