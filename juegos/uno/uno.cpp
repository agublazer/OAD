#include "uno.h"
#include <iostream>
using namespace std;

Uno::Uno(int nJug) {
    jug = nJug;
    turno = 0;
    direccion = 1;
    int mazos = 2;

    if (nJug > 4) // Dos mazos si juegan 4 o menos jugadores
        mazos += (nJug - 4) / 2; // cada 2 jugadores aumento un mazo

    int nCartas = 52 * mazos;
    CartaUno *cartas = new CartaUno[nCartas]; // un mazo tiene 52 cartas

    char color[5] = {'g', 'r', 'y', 'b', 'n'};// Green, Red, Yellow, Blue, Ninguno
    char tipo[6] = {'n', 'r', 'b', '2', 'c', '4'}; // Numero, Reversa, Bloqueo, 2: +2, Cambiar-color, 4 +4
    int nc = 0;

    // Quiero 52 cartas , no uso 4 ceros
    // primero hacer los sets de 12 cartas por color 48
    // luego aumentarle las 4 cartas sin color : 2 de cambiar color y 2 de +4

    for (int v = 0; v < mazos; v++) {
        for (int c = 0; c < 4; c++) {// cuatro colores
            for (int i = 0; i < 9; i++) {
                cartas[nc].num = i + 1;
                cartas[nc].color = color[c];
                cartas[nc].tipo = tipo[0]; //tipo 0 = número
                nc++;
            }

            for (int t = 1; t < 4; t++) { //Genero: Reversa, Bloqueo y +2
                cartas[nc].num = 0;
                cartas[nc].color = color[c];
                cartas[nc].tipo = tipo[t];
                nc++;
            }

        }

        for (int v = 0; v < 2; v++) {
            for (int t = 4; t < 6; t++) { //aqúi genero los 2 últimos tipos, 2 cartas por tipo
                cartas[nc].num = 0;
                cartas[nc].color = color[4];
                cartas[nc].tipo = tipo[t];
                nc++;
            }
        }
    }

    mazo.barajar(cartas, nCartas);
    delete[] cartas;

    manos = new Lista<CartaUno>[nJug];
}


//     void pushFront(T num);
//     void pushBack(T num);
//     void popFront();
//     void popBack();
//     void popN(int n);
//     bool empty();
//     T getfront();
//     T getback();
//     T getN(int n);
//     int size();

void Uno::repartirCartas() {
    for (int j = 0; j < 7; j++) {
        for (int i = 0 ; i < jug; i++) {
            manos[i].pushBack(mazo.quitar());
        }
    }

}

void Uno::sgtTurno() {
    if (direccion) {
        turno++;
        if (turno >= jug)
            turno -= jug;
    }
    else {
        turno--;
        if (turno < 0)
            turno += jug;
    }

}

void Uno::partida() {
    repartirCartas();

}

int main() {
    Uno juego(4);
    cout << "holi" << endl;

    // CartaUno p;
    // CartaUno q;
    // p.color = 'c';
    // p.num = 1;
    // p.tipo = 't';

    // q.color = 'r';
    // q.num = 2;
    // q.tipo = 'w';

    // cout << p.color << p.num <<p.tipo << endl;
    // cout << q.color << q.num <<q.tipo << endl;
    // p = q;
    // cout << p.color << p.num <<p.tipo << endl;



}






