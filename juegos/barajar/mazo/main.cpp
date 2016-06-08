#include "mazo.h"
#include "../pila/pila.h"
#include <iostream>
using namespace std;

class Naipes {
public:
    char palo;
    int num;
};


int main() {
    Mazo<int> cartas;
    int c[] = {1, 2, 3, 4, 5, 6};
    cartas.barajar(c, 6);
    while (!cartas.vacio()) {
        cout << cartas.quitar() << endl;
    }
     cout << "-----" << endl;
    Mazo<Naipes> barajaNaipes;
    Naipes cc[52];

    char palo[] = {'E','C','T', 'D'};
    for (int j = 0; j < 4; j++) {
        for (int i = 0; i < 13; i++) {
            cc[j*13+i].palo = palo[j];
            cc[j*13+i].num = i+1;
        }
    }
    barajaNaipes.barajar(cc, 52);
    while (!barajaNaipes.vacio()) {
        Naipes tmp = barajaNaipes.quitar();
        cout << tmp.palo<< " " << tmp.num<< endl;
    }

}