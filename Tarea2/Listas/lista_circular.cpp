#include<iostream>
#include"lista_circular.h"

CList::~CList()
{
    for(IntNode *p;!isEmpty();)
    {
        p = head->next;
        delete head;
        head = p;
    }
}

void CList::addToHead(int el)
{
    head =  new IntNode(el,head);
    if (tail == nullptr)
        tail = head;
}

void CList::addToTail(int el)
{
    if (isEmpty())
    {
        tail = new IntNode(el);
        tail->next =  tail;
    }
    else
    {
        tail->next = new IntNode(el,tail->next);
        tail->next = head;
    }
}

int CList::deleteFromHead()
{
    int el = head->info;
    IntNode *tmp = head;
    if (head == tail)
        head = tail = nullptr;
    else head = head->next;
    delete tmp;

    return el;
}

int CList::deleteFromTail()
{
    int el =  tail -> info;
    if (head == tail)
    {
        delete head;
        head = tail = nullptr;
    }
    else
    {
        IntNode *tmp;
        for(tmp = head; tmp->next != tail; tmp = tmp->next);
        delete tail;
        tail = tmp;
        tail->next = nullptr;
    }
    return el;
}

void CList::deleteNode(int el)
{
    if (head != nullptr)
        if (head == tail and el == head ->info)
        {
            delete head;
            head = tail = nullptr;
        }
        else if (el == head->info)
        {
            IntNode *tmp = head->next;
            head = head->next;
            delete tmp;
        }
        else
        {
           IntNode *pred, *tmp;
           for (pred = head, tmp =  head->next; tmp != nullptr and !(tmp->info == el); pred =  pred->next,tmp = tmp->next );
           if (tmp != nullptr)
           {
               pred->next  = tmp->next;
               if (tmp == tail)
                    tail = pred;
               delete tmp;
           }

        }
}

bool CList::isInList(int el) const
{
    IntNode *tmp;
    for (tmp = head; tmp !=  nullptr and !(tmp->info == el); tmp = tmp->next);
    return tmp != nullptr;
}


