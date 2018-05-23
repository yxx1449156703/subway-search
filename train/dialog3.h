#ifndef DIALOG3_H
#define DIALOG3_H

#include <QDialog>

namespace Ui {
class Dialog3;
}

class Dialog3 : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog3(QWidget *parent = 0);
    ~Dialog3();
    void paintEvent(QPaintEvent *event);
    QList<int> x,y;

private slots:
    void receiveData(QString max,QString pay,QString min);
    void on_pushButton_2_clicked();
    void on_pushButton_clicked();

private:
    Ui::Dialog3 *ui;

};

#endif // DIALOG3_H
