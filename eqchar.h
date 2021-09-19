#ifndef EQCHAR_H
#define EQCHAR_H

#include <QChar>

class EQChar : public QChar{
public:
    EQChar(QChar number):QChar(number){};
    bool is_number() const;
    bool is_operator() const;
    bool is_parenthesis() const;
};

#endif // EQCHAR_H
