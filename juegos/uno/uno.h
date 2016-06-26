#ifndef UNO_H
#define UNO_H

#include "pila/pila.h"
#include "mazo/mazo.h"

struct CartaUno {
    char color; // G-R-B-Y-B
    int num; //1-9
    char tipo; //Numero-Cancelar-Voltear-+2 .... SIN COLOR, +4 cambiar color 1
};


class Uno{
private:
    Mazo<CartaUno> mazo;
    void cancelarTurno();
    void aumentarCartas(int n);
    void cambiarSentido();
public:
    Uno(int nJug);



};

#endif //UNO_H


// Lunes  20: Josefo, Reversi, Arbol, Ordenamiento
// Martes 21: 4 en raya, 3 en raya 3D, Dado, Bingo
// Martes 28: Baraja, Uno, Areas PF, Areas Functor

//-----------
//l  COLOR  l 
//l    #    l
//l         l
//l   T+4   l
//l         l
//l         l
//----------