#include "uno.h"
#include <iostream>
using namespace std;

Uno::Uno(int nJug) {
    CartaUno cartas[104];
    char color[5] = {'g', 'r', 'y', 'b', 'n'};// Green, Red, Yellow, Blue, Ninguno
    char tipo[6] = {'n', 'r','b', 'c', '2', '4'};// Numero, Reversa, Bloqueo, Cambiar-color, 2: +2, 4 +4
    int nc = 0;
    for (int c = 0; c < 4; c++) {
        for (int i = 0; i < 9; i++) {
            cartas[nc].num = i + 1;
            cartas[nc].color = color[c];
            cartas[nc].tipo = tipo[0];
            nc++;
        }
        cout << nc << endl;
        for (int t = 1; t < 6; t++) {
            for (int i = 0; i < 2; i++) {
                cartas[nc].num = 0;
                cartas[nc].color = color[c];
                cartas[nc].tipo = tipo[t];
                nc++;

            }
        }

    }

    for (int i = 0; i < 104; i++) {
        cout << "Numero: " <<cartas[i].num << endl;
        cout << "Color: " << cartas[i].color << endl;
        cout << "Tipo: " << cartas[i].tipo << endl;
        cout << "--------" << endl;

    }    
}

int main(){
    Uno juego(4);
    cout << "holi" << endl;
}






