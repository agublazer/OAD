#include "listadec.h"

ListaDEC::ListaDEC()
{
    front = nullptr;
    back = nullptr;

}
ListaDEC::~ListaDEC()
{
    while (!isEmpty())
    {
        Nodo *n;
        n = front->next;
        delete front;
        front  = n;
    }
}

bool ListaDEC::isEmpty()
{
    if (front == nullptr)
        return true;
    return false;
}

void ListaDEC::pushFront(int v)
{
    front = new Nodo(v, back, front);
    if (back == nullptr)
        back = front;
    else
    {
        front->next->prev = front;
        back->next = front;
    }

}

void ListaDEC::pushBack(int v)
{
    if (back != nullptr)
    {
        back->next = new Nodo(v, back, front);
        back = back->next;
        front->prev = back;
    }
    else
        front = back = new Nodo(v, nullptr, nullptr);
}

int ListaDEC::popFront()
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
        front->prev = back;
        back->next = front;
    }
    delete tmp;
    return val;
}

int ListaDEC::popBack()
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
        delete back; // no funciona
        back = tmp;
        back->next = front;
        front->prev = back;
    }
    return val;
}

int ListaDEC::deleteNode(int n)
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
            front->prev = back;
            back->next = front;

        }
        else
        {
            Nodo *pred = front;
            Nodo *tmp = front->next;
            while (tmp != front and !(tmp->val = n))
            {
                pred = pred->next;
                tmp = tmp->next;
            }
            if (tmp != front)
            {
                pred->next = tmp->next;
                if (tmp == back)
                    back = pred;
                delete tmp;/// ?
            }
        }
    }
}

bool ListaDEC::isInList(int n)
{
    Nodo *tmp = front;
    while (tmp != back and !(tmp->val == n ))
    {
        tmp = tmp->next;
    }
    if (tmp != back)
        if (tmp->val == n)
            return true;
    return false;
}
