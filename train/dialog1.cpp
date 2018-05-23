#include "dialog1.h"
#include "ui_dialog1.h"
#include "stdio.h"
#include<fstream>
#include<vector>
#include <qstring.h>
#include <vector>
#include <qfile.h>
#include<qtextstream.h>
#include <iostream>
#include <string.h>
#include<QMessageBox>
#include <qstringlist.h>
using namespace std;

QString str2qstr(const string str);
string qstr2str(const QString qstr);

Dialog1::Dialog1(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog1)
{
    ui->setupUi(this);
}

Dialog1::~Dialog1()
{
    delete ui;
}

void Dialog1::on_pushButton_2_clicked()
{
    this->close();
}

void Dialog1::on_pushButton_clicked()
{
    QString start;
    int number;
    if( ui->starting->text().isEmpty()|| ui->ending->text().isEmpty() )
            {
                QMessageBox::warning(this, tr("警告信息"), tr("站点或线路为空，不能添加！"));
                return;
            }
    start=ui->starting->text();
    number=ui->ending->text().toInt();
    int num=number;
    if(num==4) num=3;
    if(num==5) num=4;
    if(num==6) num=5;
    if(num==8) num=6;
    if(num==9) num=7;
    if(num==10) num=8;
    if(num==13) num=9;
    QFile f("BaseInfo.txt");
    if(!f.open(QIODevice::ReadWrite | QIODevice::Text))
     {
         QMessageBox::information(NULL, "Error","Can't open file!", QMessageBox::Yes | QMessageBox::No, QMessageBox::Yes);
         return ;
        }
     QList<QString> li;
     QTextStream in(&f);
     QString str;
     while((str=in.readLine())!=0)li.append(str);
     in.seek(0);
     li[num]=li[num]+",3,"+start;
     for(int i=0;i<li.length();i++) in<< li[i] << endl;
     f.close();
     QFile f1("Information.txt");
     if(!f1.open(QIODevice::ReadWrite | QIODevice::Text))
      {
          QMessageBox::information(NULL, "Error","Can't open file!", QMessageBox::Yes | QMessageBox::No, QMessageBox::Yes);
          return ;
         }
      QList<QString> l;
      QTextStream on(&f1);
      QString st;
      while((st=on.readLine())!=0)l.append(st);
      on.seek(0);
      l[num]=l[num]+",3,"+start;
      for(int i=0;i<l.length();i++) on<< l[i] << endl;
      f1.close();
      QMessageBox::information(NULL, "Attention","添加成功", QMessageBox::Yes | QMessageBox::No, QMessageBox::Yes);
}
