#include <QPushButton>
#include <QKeyEvent>
#include <QMap>
#include <iostream>

#include "display.h"


Display::Display(QWidget *parent) : QTextEdit(parent){
    symbols = {{Qt::Key_Plus,"+"},{Qt::Key_ParenLeft,"("},{Qt::Key_AsciiCircum,"^"},{Qt::Key_ParenRight,")"},{Qt::Key_Equal ,"="},{Qt::Key_Minus,"-"},{Qt::Key_Asterisk,"*"},{Qt::Key_Slash,"/"},{Qt::Key_Period,"."}};
    for(int i{0};i<10;++i)
        symbols.insert(0x30+i,QString::number(i));
}

void Display::add(){
    QString symbol = qobject_cast<QPushButton*>(sender())->text();
    add(symbol);
}

void Display::add(QString symbol){
    this->insertPlainText(symbol);
}

void Display::keyPressEvent(QKeyEvent *event){
    add(symbols[event->key()]);
}
