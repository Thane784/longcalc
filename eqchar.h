#ifndef EQCHAR_H
#define EQCHAR_H

#include <QChar>

class EQChar : public QChar{
public:
    EQChar(QChar number):QChar(number){};
    bool is_number();
    bool is_operator();
    bool is_parenthesis();
};

#endif // EQCHAR_H
