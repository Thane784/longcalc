#include "eqchar.h"

#include <QVector>

bool EQChar::is_number() const{
    return((*this).unicode() >='0' && (*this).unicode()<='9');
}

bool EQChar::is_operator() const{
    const QVector<QChar> values{'+','-','/','*','^'};
    return(values.indexOf((*this)) != -1);
}

bool EQChar::is_parenthesis() const{
    return((*this).unicode() == '(' || (*this).unicode() == ')');
}
