#include <QPushButton>
#include <QKeyEvent>
#include <iostream>

#include "display.h"
#include "logic.h"

Display::Display(QWidget *parent) : QTextEdit(parent){
}

void Display::update_result(const QString& text){
    QString new_text = calculate(text);
    this->setText(new_text);
    if(this->toPlainText().size()>=1)
        this->moveCursor(QTextCursor::End);
}

QChar Display::get_symbol(int key) const{
    for(auto symbol : required_symbols){
        if(symbol.unicode() == key){
            return(symbol);
        }
    }
    return(QChar{0});
}

void Display::add(){
    QChar symbol = qobject_cast<QPushButton*>(sender())->text()[0];
    if(required_symbols.indexOf(symbol) != -1)
        add(symbol);
    if(symbol == '=')
        update_result(this->toPlainText());
    if(symbol == '<')
        this->textCursor().deletePreviousChar();
}

void Display::keyPressEvent(QKeyEvent *event){
    int key = event->key();
    if(key == Qt::Key_Equal)
        update_result(this->toPlainText());
    if(key == Qt::Key_Backspace)
        this->textCursor().deletePreviousChar();
    if(key == Qt::Key_Left)
        this->moveCursor(QTextCursor::Left);
    if(key == Qt::Key_Right)
        this->moveCursor(QTextCursor::Right);
    if(key == Qt::Key_Up)
        this->moveCursor(QTextCursor::Up);
    if(key == Qt::Key_Down)
        this->moveCursor(QTextCursor::Down);
    QChar symbol{get_symbol(key)};
    if(symbol != 0){
        add(symbol);
    }
}

void Display::add(const QChar& symbol){
    QString text = this->toPlainText();
    int cursor_position = this->textCursor().position();
    if(symbol.isSymbol()&& cursor_position>=1){
        if(text[cursor_position-1].isSymbol())
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
