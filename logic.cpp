#include "logic.h"
#include "binary_tree.h"
#include <QMap>

QMap<EQString,EQChar> lex(EQString text){
    QMap<EQString,EQChar> tokens;
    return(tokens);
}

binary_tree<EQString> build_tree(QMap<EQString,EQChar> tokens){
    binary_tree<EQString> tree;
    return(tree);
}

EQString calculate(binary_tree<EQString> tree){
    EQString result{"100500"};
    return(result);
}

EQString calculate(EQString text){
    QMap<EQString,EQChar> tokens = lex(text);
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


