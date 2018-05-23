#ifndef ZIZ_H
#define ZIZ_H

#include <QMainWindow>
#include "Dialog.h"
#include "Dialog1.h"
#include "Dialog2.h"

namespace Ui {
class ziz;
}

class ziz : public QMainWindow
{
    Q_OBJECT

public:
    explicit ziz(QWidget *parent = 0);
    ~ziz();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_5_clicked();

private:
    Ui::ziz *ui;
    Dialog *dialog;
    Dialog1 *dialog1;
    Dialog2 *dialog2;
};

#endif // ZIZ_H
