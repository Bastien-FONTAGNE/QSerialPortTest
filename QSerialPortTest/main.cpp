#include "QSerialPortTest.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QSerialPortTest w;
    w.show();
    return a.exec();
}
