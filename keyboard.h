#ifndef Keyboard_H
#define Keyboard_H

#include <QWidget>

#include "display.h"

class Keyboard : public QWidget{
    Q_OBJECT
public:
    explicit Keyboard(Display* display,QWidget *parent = nullptr);
signals:
};

#endif // Keyboard_H
