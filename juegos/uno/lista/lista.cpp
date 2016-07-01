#include "lista.h"

template<typename T>
Lista<T>::Lista() {
    front = nullptr;
    back = nullptr;
}

template<typename T>
void Lista<T>::pushFront(T val) {
    front = new NodoL<T>( val , front );
    if (back == nullptr)
        back = front;
}

template<typename T>
void Lista<T>::pushBack(T val) {
    if (back != nullptr) {
        back -> next = new NodoL<T>(val);
        back = back -> next;
    }
    else {
        back = new NodoL<T>(val);
        front = back;
    }
}

template<typename T>
void Lista<T>::popFront() {
    if (front == nullptr and back == nullptr)
        return;

    NodoL<T> *tmp = front; //para borrar la front
    if (front == back) {
        front = nullptr;
        back = nullptr;
    }
    else
        front = front -> next;

    delete tmp;

}

template<typename T>
void Lista<T>::popBack() {
    if (front == nullptr and back == nullptr)
        return;

    if (front == back) {
        front = nullptr;
        back = nullptr;
    }
    else {
        NodoL<T> *tmp;
        tmp = front;
        while (tmp->next != back)
            tmp = tmp->next;
        delete back;
        back = tmp;
        back->next = nullptr;
    }
}

template<typename T>
void Lista<T>::popN(int n) {
    if (front == nullptr)
        return;

    if (n == 0) {
        NodoL<T> *tmp = front->next;
        front = front->next;
        delete tmp;
    }

    else {
        NodoL<T> *prev = front;
        NodoL<T> *tmp = front -> next;
        while (tmp != nullptr and n > 1) {
            prev = prev->next;
            tmp = tmp->next;
            n--;
        }
        if (tmp != nullptr) {
            prev->next = tmp->next;
            if (tmp == back)
                back = prev;
            delete tmp;
        }
    }

}

template<typename T>
T Lista<T>::getN(int n) {
    if (front == nullptr)
        throw;// como hacer que no retorne nada ??

    if (n == 0)
        return front->val;


    else {
        NodoL<T> *tmp = front -> next;
        while (tmp != nullptr and n > 1) {
            tmp = tmp->next;
            n--;
        }
        if (tmp != nullptr)
            return tmp->val;
        else
            throw; // cómo hacer para me retorne nada:'(
    }

}

template<typename T>
bool Lista<T>::empty() {
    if (front == nullptr)
        return true;
    return false;
}


template<typename T>
int Lista<T>::size() {
    if (front == nullptr)
        return 0;

    else {
        int size = 1;
        NodoL<T> *tmp = front -> next;
        while (tmp != nullptr) {
            tmp = tmp->next;
            size++;
        }

        return size;

    }

}


template<typename T>
Lista<T>::~Lista() {

    if (front != nullptr and back != nullptr){
        NodoL<T> *tmp;
        while (!empty()) {
            tmp = front->next;
            delete front;
            front = tmp;
        }

        delete tmp;
    }

}

template<typename T>
T Lista<T>::getback() {
    return back->val;
}


template<typename T>
T Lista<T>::getfront() {
    return front->val;
}
