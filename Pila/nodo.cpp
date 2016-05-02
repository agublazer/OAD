#include "nodo.h"

Nodo::Nodo()
{
    prev = nullptr;
}

Nodo::Nodo(int i, Nodo *p)
{
    val = i;
    prev = p;
}

