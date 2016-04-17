#ifndef LISTADEC_H
#define LISTADEC_H
#include "nodo.h"

class ListaDEC
{
private:
public:
    Nodo *front;
    Nodo *back;
    ListaDEC();
    ~ListaDEC();
    bool isEmpty();
    void pushFront(int v);
    void pushBack(int v);
    int popFront();
    int popBack();
    int deleteNode (int n);
    bool isInList (int n);
};

#endif // LISTADE_H
