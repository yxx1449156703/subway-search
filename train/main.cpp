#include "ziz.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    ziz w;
    w.show();

    return a.exec();
}
