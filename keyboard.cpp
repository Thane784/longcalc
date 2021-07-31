#include <QGridLayout>
#include <QPushButton>
#include <QApplication>

#include "keyboard.h"
#include "display.h"

Keyboard::Keyboard(Display* display,QWidget *parent) : QWidget(parent){
    QGridLayout *grid = new QGridLayout(this);
    grid->setSpacing(2);
    QList<QString> values({"(", "1", "2", "3", "<-",
      ")", "4", "5", "6", "-",
      "^","7", "8", "9", "+",
      ".","/", "*", "0", "="
    });
    int count{0};
    for (int i{0}; i<4; ++i) {
        for (int j{0}; j<5; ++j) {
            QPushButton *btn = new QPushButton(values[count], this);
            btn->setFixedSize(110, 110);
            QFont font = btn->font();
            font.setPointSize(24);
            btn->setFont(font);
            grid->addWidget(btn, i, j);
            connect(btn, SIGNAL(clicked()), display, SLOT(add()));
            ++count;
        }
    }

    setLayout(grid);
}
