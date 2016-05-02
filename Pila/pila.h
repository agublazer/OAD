#ifndef PILA_H
#define PILA_H

#include "nodo.h"

class Pila
{
private:
    Nodo *back;
public:
    Pila();
    ~Pila();
    bool empty();
    void push(int v);
    void pop();
    int getBack();
};

#endif // PILA_H
