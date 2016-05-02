#ifndef NODO_H
#define NODO_H


class Nodo
{
public:
    Nodo *prev;
    int val;

    Nodo();
    Nodo(int i, Nodo *prev);
};
#endif // NODO_H
