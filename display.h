#ifndef DISPLAY_H
#define DISPLAY_H

#include <QWidget>
#include <QLabel>
#include <QTextEdit>
#include <iostream>

class Display : public QTextEdit{
    Q_OBJECT
private:
    QMap<int,QChar> symbols;
    QLabel* text;
    bool is_valid(int key);
public slots:
    void add();
    void add(QChar symbol);
public:
    explicit Display(QWidget *parent = nullptr);
    virtual void keyPressEvent(QKeyEvent *event);
signals:
};

#endif // DISPLAY_H
