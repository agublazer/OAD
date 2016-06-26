#ifndef MAZO_H
#define MAZO_H


#include "../pila/pila.h"
#include <iostream>

template<typename T>
class Mazo{
private:
    Pila<T> cartas;
public:
    void agregar(T carta);
    T quitar();
    void barajar(T *arr, int ncartas);
    bool vacio();
    //void barajar(T *arr,int ncartas, void(*fnc)(T, T));
    //void barajar(T *arr, function<void(T, T)> &f);//recibir ptr a funcion; esa función va a ser el swap con random
    //recibe un array con las cartas

    
};

#include "mazo.cpp"
#endif // MAZO_H