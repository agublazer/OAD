#include "listade.h"

ListaDE::ListaDE()
{
    front = nullptr;
    back = nullptr;

}
ListaDE::~ListaDE()
{
    while (!isEmpty())
    {
        Nodo *n;
        n = front->next;
        delete front;
        front  = n;
    }
}

bool ListaDE::isEmpty()
{
    if (front == nullptr)
        return true;
    return false;
}

void ListaDE::pushFront(int v)
{
    front = new Nodo(v, nullptr, front);
    if (back == nullptr)
        back = front;
    else
        front->next->prev = front;

}

void ListaDE::pushBack(int v)
{
    if (back != nullptr)
    {
        back->next = new Nodo(v, back, nullptr);
        back = back->next;
    }
    else
        front = back = new Nodo(v, nullptr, nullptr);
}

int ListaDE::popFront()
{
    int val = front->val;
    Nodo *tmp = front;
    if (front == back)
    {
        front = nullptr;
        back = nullptr;
    }
    else
    {
        front = front->next;
        front->prev = nullptr;
    }
    delete tmp;
    return val;
}

int ListaDE::popBack()
{
    int val = back->val;
    if (front == back)
    {
        delete front;
        front = nullptr;
        back = nullptr;

    }
    else
    {
        Nodo *tmp = back->prev;

        delete back;
        back = tmp;
        back->next = nullptr;
    }
    return val;
}

int ListaDE::deleteNode(int n)
{
    if (front != nullptr)
    {
        if (front == back and n == front->val)
        {
            delete front;
            front = back = nullptr;
        }
        else if (n == front->val)
        {
            Nodo *tmp = front;
            front = front->next;
            delete tmp;
        }
        else
        {
            Nodo *pred = front;
            Nodo *tmp = front->next;
            while(tmp != nullptr and !(tmp->val = n))
            {
               pred = pred->next;
               tmp =tmp->next;
            }
            if (tmp != nullptr)
            {
                pred->next = tmp->next;
                if (tmp == back)
                    back = pred;
                delete tmp;
            }
        }
    }
}

bool ListaDE::isInList(int n)
{
    Nodo *tmp= front;
    while(tmp != nullptr and !(tmp->val == n ))
    {
        tmp = tmp->next;
    }
    if (tmp != nullptr)
        return true;
    return false;
}
