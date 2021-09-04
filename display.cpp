#include <QPushButton>
#include <QKeyEvent>
#include <iostream>

#include "display.h"
#include "eqstring.h"
#include "logic.h"

Display::Display(QWidget *parent) : QTextEdit(parent){
}

EQChar Display::get_symbol(int key){
    for(auto symbol : required_symbols){
        if(symbol.unicode() == key){
            return(symbol);
        }
    }
    return(QChar{0});
}

void Display::add(){
    EQChar symbol = qobject_cast<QPushButton*>(sender())->text()[0];
    if(required_symbols.indexOf(symbol) != -1)
        add(symbol);
    if(symbol == '=')
        calculate(this->toPlainText());
    if(symbol == '<')
        this->textCursor().deletePreviousChar();
}

void Display::keyPressEvent(QKeyEvent *event){
    int key = event->key();
    if(key == Qt::Key_Equal)
        calculate(this->toPlainText());
    if(key == Qt::Key_Backspace)
        this->textCursor().deletePreviousChar();
    if(key == Qt::Key_Left)
        this->textCursor().movePosition(QTextCursor::PreviousCharacter);
    if(key == Qt::Key_Right)
        this->textCursor().movePosition( this->textCursor().Right);
    if(key == Qt::Key_Up)
        this->textCursor().movePosition( this->textCursor().Up);
    if(key == Qt::Key_Down)
        this->textCursor().movePosition( this->textCursor().Down);
    QChar symbol{get_symbol(key)};
    if(symbol != 0){
        add(symbol);
    }
}

void Display::add(EQChar symbol){
    EQString text = this->toPlainText();
    int cursor_position = this->textCursor().position();
    if(symbol.is_operator()&& text.size()>=1){
        if(text[cursor_position-1].is_operator())
            this->textCursor().deletePreviousChar();
    }
    this->insertPlainText(symbol);
}

/*

bool is_valid(QString text){
    return(true);
}

bool Display::is_valid(int key){
    for(auto& value : symbols){
        if(value.unicode() == key)
            return(true);
    }
    return(false);
}

bool is_valid(QString text,QChar symbol,int pos){
    int usymbol = symbol.unicode();
    if(!is_number(symbol)){
    if(pos>=1){
        if(usymbol == '^'){
            for(int i{pos-1};i>=0;--i){
                if(is_operator(text[i]))
                    return(false);
                else{
                    if(is_number(text[i]))
                        break;
                }
            }
        }
        if(usymbol == '.'){
            if(!is_number(text[pos-1]))
                return(false);
            for(int i{pos-1};i>=0;--i){
                if(text[i].unicode() == '.')
                    return(false);
                else{
                    if(!is_number(text[i]))
                        break;
                }
            }
            for(int i{pos};i<text.size();++i){
                if(text[i].unicode() == '.')
                    return(false);
                else{
                    if(!is_number(text[i]))
                        break;
                }
            }
        }
    }
    else{
        if(usymbol == '.' || usymbol == '*' || usymbol == '/' || usymbol == '^')
            return(false);
    }
    }
    return(true);
}





*/
