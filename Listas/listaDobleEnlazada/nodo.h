#ifndef NODO_H
#define NODO_H


class Nodo
{
public:
    Nodo *next;
    Nodo *prev;
    int val;

    Nodo();
    Nodo(int i, Nodo *prev = nullptr, Nodo *next = nullptr);

};

#endif // NODO_H
