#ifndef DISPLAY_H
#define DISPLAY_H

#include <QWidget>
#include <QLabel>
#include <QTextEdit>
#include <iostream>

#include "eqchar.h"

class Display : public QTextEdit{
    Q_OBJECT
private:
    QVector<QChar> symbols = {'+','(','^',')','=','-','*','/','.'};
    void add(EQChar symbol);
    //QLabel* text;
    //bool is_valid(int key);
public:
    explicit Display(QWidget *parent = nullptr);
    virtual void keyPressEvent(QKeyEvent *event);
public slots:
    void add();
signals:
};

#endif // DISPLAY_H
