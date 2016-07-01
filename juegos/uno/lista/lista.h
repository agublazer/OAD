#ifndef LISTAENLAZADA_H
#define LISTAENLAZADA_H

template<typename T>
class NodoL {
public:
    NodoL *next;
    T val;

    NodoL(T n, NodoL *ptr = nullptr) { val = n; next = ptr; }
};

template<typename T>
class Lista {
private:
    NodoL<T> *front;
    NodoL<T> *back;
public:
    Lista();
    ~Lista();
    void pushFront(T num);
    void pushBack(T num);
    void popFront();
    void popBack();
    void popN(int n);
    bool empty();
    T getfront();
    T getback();
    T getN(int n);
    int size();

};

#include "lista.cpp"
#endif // LISTAENLAZADA_H
