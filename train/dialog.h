#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <QString>
#include <string>
#include "Dialog3.h"

namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = 0);
    ~Dialog();

signals:
    void  sendData(QString,QString,QString);

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::Dialog *ui;
    QString start1,des1;
    Dialog3 *dialog3;

};

#endif // DIALOG_H
