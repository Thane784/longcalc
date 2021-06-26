#ifndef DISPLAY_H
#define DISPLAY_H

#include <QWidget>
#include <QLabel>
#include <QTextEdit>
#include <iostream>

class Display : public QTextEdit{
    Q_OBJECT
private:
    QMap<int,QString> symbols;
    QLabel* text;
public slots:
    void add();
    void add(QString symbol);
public:
    explicit Display(QWidget *parent = nullptr);
    virtual void keyPressEvent(QKeyEvent *event);
signals:
};

#endif // DISPLAY_H
