#include "mainwindow.h"
#include "longcalc.h"

#include <QApplication>

int main(int argc, char *argv[]){
    QApplication a(argc, argv);
    LongCalc w;
    w.resize(800,700);
    w.show();
    return a.exec();
}
