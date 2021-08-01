#include <QPushButton>
#include <QKeyEvent>
#include <QMap>
#include <iostream>

#include "display.h"


Display::Display(QWidget *parent) : QTextEdit(parent){
    symbols = {{Qt::Key_Plus,'+'},{Qt::Key_ParenLeft,'('},{Qt::Key_AsciiCircum,'^'},{Qt::Key_ParenRight,')'},{Qt::Key_Equal ,'='},{Qt::Key_Minus,'-'},{Qt::Key_Asterisk,'*'},{Qt::Key_Slash,'/'},{Qt::Key_Period,'.'}};
    for(int i{0};i<10;++i){
        char temp{i+0x30};
        symbols.insert(0x30+i,temp);
    }
    //QChar::number(i)
}

void Display::add(){
    QChar symbol = qobject_cast<QPushButton*>(sender())->text()[0];
    add(symbol);
}

bool is_number(QChar symbol){
    return(symbol.unicode() >=0x30 && symbol.unicode()<=0x39);
}

bool is_operator(QChar symbol){
    const QList<QChar> values{'+','-','/','*','^'};
    return(values.indexOf(symbol) != -1);
}

bool is_parenthesis(QChar symbol){
    return(symbol.unicode() == '(' || symbol.unicode() == ')');
}

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

void Display::add(QChar symbol){
    QString text = this->toPlainText();
    int cursor_position = this->textCursor().position();
    if(is_operator(symbol) && is_operator(text[cursor_position-1])){
        this->textCursor().deletePreviousChar();
        this->insertPlainText(symbol);
        return;
    }
    if(is_valid(text,symbol,cursor_position))
        this->insertPlainText(symbol);

}

void Display::keyPressEvent(QKeyEvent *event){
    auto symbol = event->key();
    if(is_valid(symbol)){
        add(symbols[symbol]);
    }
}
