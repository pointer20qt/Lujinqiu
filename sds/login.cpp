#include "login.h"
#include "ui_login.h"
#include<QPushButton>
#include<QSqlQuery>
#include<QString>
#include"widget.h"
#include<QDebug>
#include"zc.h"
login::login(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::login)
{
    ui->setupUi(this);
    this->setWindowTitle("登录");
    QSqlDatabase db=QSqlDatabase::addDatabase("QMYSQL");
    db.setDatabaseName("qiandao");
    db.setUserName("root");
    db.setPassword("123456");
    if(db.open())
    {
        qDebug()<<"打开数据库成功";
    }
    else
    {
        qDebug()<<"打开数据库失败";
    }
    /*QPixmap pixmap;
    pixmap.load("://QQ图片20200207205651.png");
    ui->rb->setPixmap(pixmap);*/
    connect(ui->btninto,QPushButton::clicked,[=]()
    {
        QSqlQuery sql;
        sql.exec(QString("select *from student where sname='%1' and pwd='%2'").arg(ui->line1->text()).arg(ui->line2->text()));
        sql.next();
        QString snsname=sql.value(0).toString();
        if(sql.size()>0)
        {
            Widget *w=new Widget(NULL,snsname);
            w->show();
            this->hide();
        }
        else
        {

            qDebug()<<"登录失败";
        }

    });
}

login::~login()
{
    delete ui;
}

void login::on_pzc_clicked()
{
    zc *z=new zc();
    z->show();
}
