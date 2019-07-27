#include "widget.h"
#include "ui_widget.h"
#include <QMessageBox>
#include <QString>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    disablePb();
}
Widget::~Widget()
{
    delete ui;
}
void Widget::changeMoney(int n){
    money += n;
    ui->lcdNumber->display(money);
    enablePb();
}
void Widget::buy(int n){
    money -= n;
    ui->lcdNumber->display(money);
    disablePb();
}
void Widget::disablePb(){
    if(money<200){
        ui->pbCoke->setEnabled(false);
    }
    if(money<50){
        ui->pbTea->setEnabled(false);
        ui->pbCoke->setEnabled(false);
    }
    if(money<30){
        ui->pbTea->setEnabled(false);
        ui->pbCoffee->setEnabled(false);
        ui->pbCoke->setEnabled(false);
    }
}
void Widget::enablePb(){
    if(money>=200){
        ui->pbCoke->setEnabled(true);
        ui->pbCoffee->setEnabled(true);
        ui->pbTea->setEnabled(true);
    }
    if(money>=50){
        ui->pbCoffee->setEnabled(true);
        ui->pbTea->setEnabled(true);
    }
    if(money>=30){
        ui->pbCoffee->setEnabled(true);
    }
}
void Widget::on_pb10_clicked()
{
    changeMoney(10);

}
void Widget::on_pb50_clicked()
{
    changeMoney(50);

}
void Widget::on_pb100_clicked()
{
    changeMoney(100);
}
void Widget::on_pb500_clicked()
{
    changeMoney(500);
}
void Widget::on_pbCoffee_clicked()
{
    buy(30);
}
void Widget::on_pbTea_clicked()
{
     buy(50);
}
void Widget::on_pbCoke_clicked()
{
     buy(200);
}
void Widget::on_pbReset_clicked()
{
    QMessageBox msg;
    QString c500=QString::number(money/500);
    QString c100=QString::number((money%500)/100);
    QString c50=QString::number((money%100)/50);
    QString c10=QString::number((money%50)/10);

    msg.information(nullptr, "title", "500원: "+c500+"\n100원: "+c100+"\n50원: "+c50+"\n10원: "+c10);

    money=0;
    ui->lcdNumber->display(money);
}
