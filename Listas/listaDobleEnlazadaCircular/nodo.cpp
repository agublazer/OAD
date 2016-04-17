#include "nodo.h"

Nodo::Nodo()
{
    next = nullptr;
    prev = nullptr;
}

Nodo::Nodo(int i, Nodo *p , Nodo *n )
{
    val = i;
    prev = p;
    next = n;
}
