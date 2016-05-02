#include "ListaEnlazada.h"

ListaEnlazada::ListaEnlazada()
{
    cabeza = nullptr;
    cola = nullptr;
}

void ListaEnlazada::agrCabeza(int num)
{
    cabeza = new Nodo( num , cabeza );
    if(cola == nullptr)
    {
        cola = cabeza;
    }
}

void ListaEnlazada::agrCola(int num)
{
    if(cola != 0)
    {
        cola -> next = new Nodo(num);
        cola = cola -> next;
    }
    else
    {
        cola = new Nodo(num);
        cabeza = cola;
    }
}

int ListaEnlazada::boCabeza()
{
    if(cabeza == nullptr and cola == nullptr)
    {
        cout << "lista vacia" << endl;
        return 0;
    }
    int cabezret = cabeza -> num;
    Nodo *tmp = cabeza; //para borrar la cabeza
    if(cabeza == cola)
    {
        cabeza = nullptr;
        cola = nullptr;
    }
    else
    {
        cabeza = cabeza -> next;
    }
    delete tmp;
    return cabezret;
}

int ListaEnlazada::boCola()
{
    if(cabeza == nullptr and cola == nullptr)
    {
        cout << "lista vacia" << endl;
        return 0;
    }
    int colaret = cola -> num;
    if(cabeza == cola)
    {
        cabeza = nullptr;
        cola = nullptr;
    }
    else
    {
        Nodo *tmp;
        tmp = cabeza;
        while(tmp->next != cola)
        {
            tmp = tmp->next;
        }
        delete cola;
        cola = tmp;
        cola->next = nullptr;
    }
    return colaret;
}

void ListaEnlazada::boNodo(int n)
{
    if(cabeza != nullptr)
    {
        if(cabeza == cola and n == cabeza->num)
        {
            delete cabeza;
            cabeza = nullptr;
            cola = nullptr;
        }
        else
        {
            if(n == cabeza->num)
            {
                Nodo *tmp = cabeza -> next;
                cabeza = cabeza -> next;
                delete tmp;
            }
            else
            {
                Nodo *prev, *tmp;
                prev = cabeza;
                tmp = cabeza -> next;
                while(tmp != 0 and !(tmp->num == n))
                {
                    prev = prev -> next;
                    tmp = tmp -> next;
                }
                if(tmp != nullptr)
                {
                    prev -> next = tmp -> next;
                    if(tmp == cola)
                        cola = prev;
                    delete tmp;
                }
            }
        }
    }
}

bool ListaEnlazada::Vacia()
{
    if(cabeza == nullptr)
        return true;
    return false;
}

bool ListaEnlazada::estaenLista(int n) const
{
    Nodo *tmp;
    tmp = cabeza;
    while(tmp != nullptr and !(tmp -> num == n))
    {
        tmp = tmp -> next;
    }
    if(tmp != nullptr)
    {
        return tmp;
    }


}

void FusionaryOrdenar(ListaEnlazada *lista1, ListaEnlazada *lista2)
{
    if( ( lista1->getcabeza() == nullptr and lista1->getcola() == nullptr ) or ( lista2->getcabeza() == nullptr and lista2->getcola() == nullptr ) )
    {
        cout << "una de tus listas esta vacia" << endl;
        return;
    }
    Nodo *tmp1, *tmp2;

}

ListaEnlazada::~ListaEnlazada()
{
    Nodo *tmp;
    while(!Vacia())
    {
        tmp = cabeza->next;
        delete cabeza;
        cabeza = tmp;
    }
    delete tmp;
}
