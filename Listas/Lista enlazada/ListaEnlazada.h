#ifndef LISTAENLAZADA_H
#define LISTAENLAZADA_H
#include "Nodo.h"

class ListaEnlazada
{
    public:
        ListaEnlazada();
        ~ListaEnlazada();
        void agrCabeza(int num);
        void agrCola(int num);
        int boCabeza();
        int boCola();
        void boNodo(int n);
        bool estaenLista(int n) const;
        int Vacia();

    private:
        Nodo *cabeza, *cola;
};

#endif // LISTAENLAZADA_H
