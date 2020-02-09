#include "person.h"
#include "ui_person.h"
#include<QSqlQuery>
#include<QString>
#include<QTextCharFormat>
person::person(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::person)
{
    ui->setupUi(this);
    this->setWindowTitle("双击");
}
void person::init(QString id,QString sname)
{
    ui->label->setText(id);
    ui->label_2->setText(sname);
    QSqlQuery sql;
    sql.exec(QString("select qtime from qd where id=%1 and date_format(date(qtime),'%Y-%m')=date_format(curdate(),'%Y-%m')").arg(id));

    ui->label_3->setText(QString::number(sql.size()));
    QTextCharFormat f;
    f.setForeground(Qt::blue);
    f.setBackground(Qt::red);
    while(sql.next())
    {
        ui->calendarWidget->setDateTextFormat(sql.value(0).toDate(),f);
    }

}
person::~person()
{
    delete ui;
}
