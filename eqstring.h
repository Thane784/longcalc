#ifndef EQSTRING_H
#define EQSTRING_H

#include <QString>

#include "eqchar.h"

class EQString : public QString{
public:
    EQString(QString str):QString(str){}
    EQChar operator[](int n) const{return(QString::operator[](n));}
};

#endif // EQSTRING_H
