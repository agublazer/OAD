#ifndef NODO_H
#define NODO_H

#include <iostream>

using namespace std;
class Nodo
{
    public:
        int num;
        Nodo *next;
        Nodo(int n, Nodo *ptr = nullptr)
        {
            num = n;
            next = ptr;
        }
};

#endif // NODO_H
