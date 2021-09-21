#ifndef DISPLAY_H
#define DISPLAY_H

#include <QWidget>
#include <QLabel>
#include <QTextEdit>
#include <iostream>

#include <QChar>
#include <QString>

class Display : public QTextEdit{
    Q_OBJECT
private:
    QVector<QChar> required_symbols = {'+','-','*','/','0',
                                       '1','2','3','4','5','6','7','8','9'};
    /*
    QVector<QChar> required_symbols = {'+','(','^',')','-','*','/','.','0',
                                       '1','2','3','4','5','6','7','8','9'};*/
    QChar get_symbol(int key) const;
    void add(const QChar& symbol);
    void update_result(const QString& text);
    //QLabel* text;
    //bool is_valid(int key);
public:
    explicit Display(QWidget *parent = nullptr);
    virtual void keyPressEvent(QKeyEvent *event);
public slots:
    void add();
signals:
};

#endif // DISPLAY_H
