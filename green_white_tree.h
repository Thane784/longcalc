#ifndef GREEN_WHITE_TREE_H
#define GREEN_WHITE_TREE_H

#include <QString>
#include <QSharedPointer>

enum sides{
    ROOT,
    LEFT,
    RIGHT
};

template <class T>
class tree{
private:
    T m_data;
    QString m_colour;
    QSharedPointer<tree> m_parent = nullptr;
    QSharedPointer<tree> m_left = nullptr;
    QSharedPointer<tree> m_right = nullptr;
    int m_row = sides::ROOT;
public:
    explicit tree(QString colour,T data,int row=sides::ROOT,
                  QSharedPointer<tree> parent = nullptr);
    void add_child(const tree<T>& child,int side);
    // getters
    T get_data(){return(m_data);}
    QString get_colour(){return(m_colour);}
    QSharedPointer<tree> get_parent(){return(m_parent);}
    QSharedPointer<tree> get_left(){return(m_left);}
    QSharedPointer<tree> get_right(){return(m_right);}
};

template <class T>
tree<T>::tree(QString colour,T data,int row,
              QSharedPointer<tree> parent){
    if(parent == nullptr)
        assert(row==sides::ROOT && "the row must be root this case!");
    else{
        assert((row==sides::ROOT or row==sides::LEFT or row==sides::RIGHT)
               && "the row must be an value from 0 to 2!");
        parent->add_child(*this,row);
    }
    m_data = data;
    m_colour = colour;
    m_parent = parent;
    m_row = row;
}

#endif // GREEN_WHITE_TREE_H
