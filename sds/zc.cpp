#include "zc.h"
#include "ui_zc.h"
#include "QSqlQuery"
zc::zc(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::zc)
{
    ui->setupUi(this);
    this->setWindowTitle("注册");
}

zc::~zc()
{
    delete ui;
}

void zc::on_pushButton_clicked()
{
    QSqlQuery sql;
    sql.exec(QString("insert into student values('%1','%2','%3','%4')").arg(ui->lid->text()).arg(ui->lname->text()).arg(ui->lsex->text()).arg(ui->lpwd->text()));

}
