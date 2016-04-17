#ifndef NODO_H
#define NODO_H


class Nodo
{
public:
    Nodo *next;
    Nodo *prev;
    int val;

    Nodo();
    Nodo(int i, Nodo *prev , Nodo *next);
    Nodo(const Nodo &n) : val(n.val), prev(n.prev), next(n.next){}
    Nodo operator =(const Nodo n)
    {
        val = n.val;
        prev = n.prev;
        next = n.next;
        return n;
    }

};

#endif // NODO_H
