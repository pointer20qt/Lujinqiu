#include "widget.h"
#include "ui_widget.h"
#include <QSqlDatabase>
#include <QDebug>
#include <QSqlQuery>
#include <QString>
#include <QTableWidget>
#include <QTableWidgetItem>
#include <QCheckBox>
#include<QDateTime>
#include<QPushButton>
#include<QComboBox>
#include"person.h"
Widget::Widget(QWidget *parent,QString sname) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    this->setWindowTitle("主界面");
    this->sname=sname;//虽然起名叫name但是我传的其实是id
    ui->l3->setText("当前登录："+this->sname);
    showhas("select *from student");
    showcombox();
    sele();
    connect(ui->tableWidget,QTableWidget::cellDoubleClicked,[=](int r,int c)
    {
        person *p=new person();
        p->init(ui->tableWidget->item(r,0)->text(),ui->tableWidget->item(r,1)->text());
        p->show();
    });

}
 Widget::showhas(QString s)
 {
    QSqlQuery sql;
    qDebug()<<this->sname;
     if(sql.exec(s))
     {
         ui->tableWidget->setRowCount(sql.size());
         int i=0;
         while(sql.next())
         {
          QCheckBox *x=new QCheckBox("未签到");
          QString sno=sql.value(0).toString();
          QSqlQuery newsql;
          newsql.exec(QString("select qtime from qd where id=%1 and date(qtime)=curdate() order by qtime desc").arg(sno));
          newsql.next();
          if(this->sname!=sno)
          {
              x->setDisabled(true);
          }
          if(newsql.size()>0)
          {
              x->setText("已签到");
              x->setChecked(true);
              x->setDisabled(true);
              ui->tableWidget->setItem(i,4,new QTableWidgetItem(newsql.value(0).toString()));
          }
          ui->tableWidget->setItem(i,0,new QTableWidgetItem(sql.value(0).toString()));
          ui->tableWidget->setItem(i,1,new QTableWidgetItem(sql.value(1).toString()));
          ui->tableWidget->setItem(i,2,new QTableWidgetItem(sql.value(2).toString()));
          ui->tableWidget->setCellWidget(i,3,x);
          QSqlQuery k;

          connect(x,QCheckBox::clicked,[=]()
          {
             x->setText("已签到");
             //将控件变为不可选定
             x->setDisabled(true);
             //将最后一列的时间添加上
             ui->tableWidget->setItem(i,4,new QTableWidgetItem(QDateTime::currentDateTime().toString()));
             //直接插入数据库中
                 QSqlQuery s;
                 qDebug()<<s.exec(QString("insert into qd values(%1,now())").arg(sno));
          });
          i++;
         }

     }
 }
  void Widget::showcombox()
  {
      QSqlQuery u;
      if(u.exec("select distinct ssex from student"))
      {  ui->comboBox->addItem("全部学生");
          while(u.next())
          {
               ui->comboBox->addItem(u.value(0).toString());
          }
      }
      connect(ui->comboBox,QComboBox::currentTextChanged,[=](QString text)
      {
          QSqlQuery n;
          if(text=="全部学生")
          {
              showhas("select *from student");
          }
          else
          {
              qDebug()<<showhas(QString("select *from student where ssex='%1'").arg(text));
          }

      });
  }
  void Widget::sele()
  {
      connect(ui->pushButton,QPushButton::clicked,[=]()
      {
          showhas(QString("select *from student where id=%1").arg(ui->le->text()));
      });
  }
Widget::~Widget()
{
    delete ui;
}


