#include "logic.h"
#include "binary_tree.h"
#include <QMap>
#include <iostream>

typedef QVector<QPair<QString,QString>> Tokens;

Tokens lex(const QString& text){
    Tokens tokens;
    QString current_number;
    for (int i{0};i<text.size();++i){
        QChar symbol{text[i]};
           if(symbol.isNumber()){
               current_number += symbol;
           }
           else{
               if(current_number.size() != 0){
                   tokens.push_back(QPair<QString,QString>{"num",current_number});
               }
               current_number = "";
           }
           if(symbol.isSymbol()){
               tokens.push_back(QPair<QString,QString>{"operator",symbol});
           }
    }
    return(tokens);
}

binary_tree<QString> parse(Tokens & tokens){
    binary_tree<QString> tree;
    return(tree);
}

QString calculate(const binary_tree<QString>& tree){
    QString result{"100500"};
    return(result);
}

QString calculate(const QString& text){
    Tokens tokens = lex(text);
    /*for(auto& pair: tokens)
        std::cout << pair.first << " " << pair.second << "\n";
    */
    try {
        binary_tree<QString> tree = parse(tokens);
        QString result = calculate(tree);
        return(result);
    }
    catch (int error_code) {
        if(error_code == -1)
            return(text);/* to throw an exception */
    }
    return(text);
}


