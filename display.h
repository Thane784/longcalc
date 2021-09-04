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
    QVector<QChar> required_symbols = {'+','(','^',')','-','*','/','.','0',
                                       '1','2','3','4','5','6','7','8','9'};
    EQChar get_symbol(int key);
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
