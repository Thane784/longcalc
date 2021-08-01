#include <QPushButton>
#include <QKeyEvent>
#include <iostream>

#include "display.h"
#include "eqstring.h"

Display::Display(QWidget *parent) : QTextEdit(parent){}

void Display::add(){
    EQChar symbol = qobject_cast<QPushButton*>(sender())->text()[0];
    add(symbol);
}

void Display::keyPressEvent(QKeyEvent *event){
    /*
    EQChar symbol = event->key();
    if(symbol.is_valid()){
        add(symbols[symbol]);
    }
    */
}

void Display::add(EQChar symbol){
    EQString text = this->toPlainText();
    int cursor_position = this->textCursor().position();
    if(symbol.is_operator() && text[cursor_position-1].is_operator()){
        this->textCursor().deletePreviousChar();
        this->insertPlainText(symbol);
        return;
    }
    //if(is_valid(text,symbol,cursor_position))
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
