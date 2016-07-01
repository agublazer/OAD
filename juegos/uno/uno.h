#ifndef UNO_H
#define UNO_H

#include "pila/pila.h"
#include "lista/lista.h"
#include "mazo/mazo.h"

struct CartaUno {
    char color; // G-R-B-Y-B
    int num; //1-9
    char tipo; //Numero-Cancelar-Voltear-+2 .... SIN COLOR, +4 cambiar color 1
};


class Uno{
private:
    int jug;
    int turno;
    bool direccion;
    Mazo<CartaUno> mazo;
    Mazo<CartaUno> mesa;
    Lista<CartaUno> *manos; 

    void cancelarTurno();
    void aumentarCartas(int n);
    void cambiarSentido();

    void repartirCartas();
    void sgtTurno();
public:
    Uno(int nJug);
    void partida();
};

#endif //UNO_H

//-----------
//l  COLOR  l 
//l    #    l
//l         l
//l   T+4   l
//l         l
//l         l
//----------