#include <iostream>
#include "tres.h"
using namespace std;

//http://www.cplusplus.com/articles/4z18T05o/

void fun::obtener(int &x, int &y, int &z) {
    x = cola.front().getI();
    y = cola.front().getJ();
    z = cola.front().getK();
    cola.pop();
}

int tres::lim(int a) {
    if (a < 0)
        return (a += 3);
    else if (a > 3)
        return (a -= 3);
}

tres::tres() {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            for (int k = 0; k < 3; k++) {
                tab[i][j][k] = '*';
            }
        }
    }

    jugadas = 0;
    turno = 0;
}


void tres::printTabl() {
    for (int i = 2; i >= 0; i--) {
        for (int j = 0; j < 3; j++) {
            cout << "  "; // para que se mire mejor
            if (j == 1)
                cout << i + 1 << " ";
            else
                cout << "  ";
            for (int n = 0; n < 2 - j; n++)
                cout << " ";
            for (int k = 0; k < 3; k++) {
                cout << "/" << tab[i][j][k] ;
            } cout << "/" << endl;
        } cout << endl;
    }
}

void tres::printPart() {
    cout << "   1 2 3" << endl;
    for (int j = 0; j < 3; j++) {
        cout << " " << j + 1 << " ";
        for (int k = 0; k < 3; k++) {
            cout << tab[_i][j][k] << " ";
        } cout << endl;
    } cout << endl;

}

bool tres::libre(char c) {
    if (c == '*')
        return true;
    return false;
}

char tres::simb() {
    if (turno)
        return 'O';
    else
        return 'X';
}

void tres::lados(int i, int j, int k) { //1; -1; 0
    if (0 <= _i + i and _i + i < 3 and 0 <= _j + j and _j + j < 3 and 0 <= _k + k and _k + k < 3) {
        if (tab[_i + i][_j + j][_k + k] == simb())
            validos(i, j, k);
    }

}

bool tres::verificar() {// +1 ,-1 o 0

    int m;
    int n;
    int p;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            for (int k = 0; k < 3; k++) {
                if (!(i == 0 and j == 0 and k == 0)) {
                    m = i; n = j; p = k;
                    if (m > 1)
                        m -= 3;
                    if (n > 1)
                        n -= 3;
                    if (p > 1)
                        p -= 3;
                    lados(m, n, p);
                }
            }
        }
    }

    int i;
    int j;
    int k;//PODRIA USAR LOS MISMOS DE ARRIBA

    while (!validos.empty()) {
        validos.obtener(i, j , k);
        i = lim(_i + i * 2);
        j = lim(_j + j * 2);
        k = lim(_k + k * 2);

        if (tab[i][j][k] == simb()) {
            tab[_i][_j][_k] = 'G';
            tab[i][j][k] = 'G';
            return true;
        }
    }

    return false;

}



void tres::jugar() {

    while (jugadas < 27) {//el tablero solo tiene 27 espacios, cuando se llenan, termina el juego en empate
inicio:
        system("clear");
        printTabl();
        cout << "Jugadas: " << jugadas << " Juega: " << simb() << endl << "Ingresa la capa: ";
        cin >> _i;
        if (0 < _i and _i <= 3) {
            _i--;

            do {
                system("clear");
                printPart();
                cout << "Ingresa la fila y columna: ";
                cin >> _k;
                cin >> _j;

                if (_k == 0 or _j == 0)
                    goto inicio; // AREGLAR ESTO

            } while (!(0 < _k and _k <= 3 and 0 < _j and _j <= 3) or !libre(tab[_i][--_j][--_k]));

            tab[_i][_j][_k] = simb();

            if (verificar()) {
                system("clear");
                cout << "GANA " << simb() << endl;
                printTabl();
                return;
            }

            turno = !turno;
            jugadas++;
        }
    }
    system("clear");
    cout << "EMPATE!" << endl;
    printTabl();
}
