#ifndef LISTADE_H
#define LISTADE_H
#include "nodo.h"

class ListaDE
{
private:
public:
    Nodo *front;
    Nodo *back;
    ListaDE();
    ~ListaDE();
    bool isEmpty();
    void pushFront(int v);
    void pushBack(int v);
    int popFront();
    int popBack();
    int deleteNode (int n);
    bool isInList (int n);
};

#endif // LISTADE_H
