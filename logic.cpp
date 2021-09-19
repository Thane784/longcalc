#include "logic.h"
#include "binary_tree.h"
#include <QMap>

typedef QVector<QPair<EQString,EQChar>> Tokens;

Tokens lex(const EQString& text){
    Tokens tokens;
    for (int i{0};i<text.size();++i){
        EQChar symbol{text[i]};
           if(symbol.is_operator()){
           }
           if(symbol.is_number()){

           }
    }
    return(tokens);
}

binary_tree<EQString> build_tree(Tokens & tokens){
    binary_tree<EQString> tree;
    return(tree);
}

EQString calculate(const binary_tree<EQString>& tree){
    EQString result{"100500"};
    return(result);
}

EQString calculate(const EQString& text){
    Tokens tokens = lex(text);
    try {
        binary_tree<EQString> tree = build_tree(tokens);
        EQString result = calculate(tree);
        return(result);
    }
    catch (int error_code) {
        if(error_code == -1)
            return(text);/* to throw an exception */
    }
    return(text);
}


