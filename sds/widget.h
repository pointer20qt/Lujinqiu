#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>

#include <QString>
namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0,QString sname=NULL);
    showhas(QString sql);//显示在表中函数
    void showcombox();//关于combox的函数
    void sele();
    QString sname;
    ~Widget();


private slots:


private:
    Ui::Widget *ui;
};

#endif // WIDGET_H
