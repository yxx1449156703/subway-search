#include "ziz.h"
#include "ui_ziz.h"
#include<QMessageBox>

ziz::ziz(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::ziz)
{
    ui->setupUi(this);
}

ziz::~ziz()
{
    delete ui;
}

void ziz::on_pushButton_clicked()
{
    dialog=new Dialog(this);
    dialog->setModal(false);
    dialog->show();
}

void ziz::on_pushButton_2_clicked()
{
    dialog1=new Dialog1(this);
    dialog1->setModal(false);
    dialog1->show();
}

void ziz::on_pushButton_3_clicked()
{
    dialog2=new Dialog2(this);
    dialog2->setModal(false);
    dialog2->show();
}

void ziz::on_pushButton_4_clicked()
{
    QMessageBox::question(this, tr("联系我们"), tr("联系电话：110      微博：bjdt@sina.com      地址：我也不知道"),QMessageBox::Yes);
    return;
}

void ziz::on_pushButton_5_clicked()
{
    QApplication* app;
    app->exit(0);
}
