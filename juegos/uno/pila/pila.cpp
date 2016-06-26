//#include "pila.h"

template<typename T>
Pila<T>::Pila()
{
    back = nullptr;
}

template<typename T>
Pila<T>::~Pila()
{
    while (!empty())
    {
        Nodo<T> *tmp;
        tmp = back->prev;
        delete back;
        back = tmp;
    }
}

template<typename T>
bool Pila<T>::empty()
{
    if (back == nullptr)
        return true;
    return false;
}

template<typename T>
void Pila<T>::push(T v)
{
    back = new Nodo<T>(v, back);
}

template<typename T>
void Pila<T>::pop()
{
    if (back->prev == nullptr)
    {
        delete back;
        back = nullptr;
    }
    else
    {
        Nodo<T> *tmp = back->prev;
        delete back;
        back = tmp;
    }
}

template<typename T>
T Pila<T>::getBack()
{

    return back->val;

}
