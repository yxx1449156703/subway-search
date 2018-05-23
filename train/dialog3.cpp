#include "dialog3.h"
#include "ui_dialog3.h"
#include "stdio.h"
#include<fstream>
#include<QPainter>
#include<qline.h>
#include<vector>
#include <qstring.h>
#include <qlist.h>
#include <vector>
#include <iostream>
#include <string.h>
#include<QMessageBox>
using namespace std;

Dialog3::Dialog3(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog3)
{
    ui->setupUi(this);

}

Dialog3::~Dialog3()
{
    delete ui;
}

void Dialog3::receiveData(QString max,QString pay,QString min)
{
    ui->textEdit->setText(max);
    ui->lineEdit_2->setText(pay+"分钟");
    ui->textEdit_3->setText(min);
}

void Dialog3::on_pushButton_2_clicked()
{
    this->close();
}

#include <qfile.h>
#include<qtextstream.h>

void Dialog3::on_pushButton_clicked()
{
    x.clear();
    y.clear();
    QString max,min,test;
    max=ui->textEdit->toPlainText();
    min=ui->textEdit_3->toPlainText();
    QFile f("location.txt");
    f.open(QIODevice::ReadOnly|QIODevice::Text);
    QTextStream stream(&f);
    QStringList li=max.split(",");
    for(int i=0;i<li.length();i+=2){
        stream.seek(0);
        const char *bitch=li.at(i).toStdString().c_str();
        while(1){
            QString s=stream.readLine();
            if(0==s)break;
            char aaa[100];
            int aa,bb;
            sscanf(s.toStdString().c_str(),"%s %d %d",aaa,&aa,&bb);
            if(strcmp(aaa,bitch))continue;
            x.append(aa);
            y.append(bb);
            QString sss=QString::number(aa,10)+aaa+QString::number(bb,10);
        }
    }
    this->update();
}

void Dialog3::paintEvent(QPaintEvent *event)
{
      QPainter painter(this);
      painter.setRenderHint(QPainter::Antialiasing, true);
      QColor color(214,39,50);
      QPen prn;prn.setWidth(8);prn.setColor(color);
           painter.setRenderHint(QPainter::Antialiasing, true);
          painter.setPen(color);
          painter.setPen(prn);
          if(x.length()==2){
              QString sb=QString::number(x.at(0),10);
          }
           for(int i=0;i<x.length()-1;i++) painter.drawLine(QPointF(x.at(i), y.at(i)), QPointF(x.at(i+1), y.at(i+1)));

}
