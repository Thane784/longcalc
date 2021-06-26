#include <QVBoxLayout>
#include <QTextEdit>

#include "longcalc.h"
#include "keyboard.h"
#include "display.h"

LongCalc::LongCalc(QWidget *parent) : QWidget(parent){
    QVBoxLayout *vbox = new QVBoxLayout(this);
    vbox->setSpacing(1);
    Display* display = new Display;
    display->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    QFont font = display->font();
    font.setPointSize(24);
    display->setFont(font);
    Keyboard* keyboard = new Keyboard{display};
    keyboard->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    vbox->addWidget(display);
    vbox->addWidget(keyboard);
}
