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
        bool Vacia();
        Nodo *getcabeza(){ return cabeza; }
        Nodo *getcola(){ return cola; }

    private:
        Nodo *cabeza, *cola;
};

void FusionaryOrdenar(ListaEnlazada lista1, ListaEnlazada lista2);

#endif // LISTAENLAZADA_H
