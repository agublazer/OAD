#ifndef PILA_H
#define PILA_H

template<typename T>
class Nodo {
public:
    Nodo *prev;
    T val;

    Nodo(){ prev = nullptr;}
    Nodo(T i, Nodo *p) { val = i; prev = p;}
};

template<typename T>
class Pila {
private:
    Nodo<T> *back;
public:
    Pila();
    ~Pila();
    bool empty();
    void push(T v);
    void pop();
    T getBack();
};

#include "pila.cpp"
#endif // PILA_H
