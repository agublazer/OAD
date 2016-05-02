#include "pila.h"

Pila::Pila()
{
    back = nullptr;
}

Pila::~Pila()
{
    while (!empty())
    {
        Nodo *tmp;
        tmp = back->prev;
        delete back;
        back = tmp;
    }
}

bool Pila::empty()
{
    if (back == nullptr)
        return true;
    return false;
}

void Pila::push(int v)
{
    back = new Nodo(v, back);
}

void Pila::pop()
{
    if (back->prev == nullptr)
    {
        delete back;
        back = nullptr;
    }
    else
    {
        Nodo *tmp = back->prev;
        delete back;
        back = tmp;
    }
}

int Pila::getBack()
{

    return back->val;

}
