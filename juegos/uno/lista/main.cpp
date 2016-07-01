#include <iostream>
#include "lista.h"
using namespace std;

int main() {
    Lista<int> hola;
    for(int i =0; i<10; i++){
        hola.pushBack(i);
    }
    for(int i =0; i<10; i++){
        cout <<hola.getN(i) << endl;
    }
    cout << "size:" << hola.size() << endl;

    hola.popN(5);
    for(int i =0; i<9; i++){
        cout <<hola.getN(i) << endl;
    }
    cout << "size:" << hola.size() << endl;
    hola.popN(5);
    cout << "size:" << hola.size() << endl;

        hola.popN(5);
    cout << "size:" << hola.size() << endl;

        hola.popN(5);
    cout << "size:" << hola.size() << endl;

        hola.popN(5);
    cout << "size:" << hola.size() << endl;

        hola.popN(5);
    cout << "size:" << hola.size() << endl;

    hola.popBack();
    cout << "size:" << hola.size() << endl;

        hola.popBack();
    cout << "size:" << hola.size() << endl;
        hola.popBack();
    cout << "size:" << hola.size() << endl;
        hola.popBack();
    cout << "size:" << hola.size() << endl;
    hola.popBack();
    cout << "size:" << hola.size() << endl;
        hola.popBack();
    cout << "size:" << hola.size() << endl;

    hola.pushBack(1);
        cout << "size:" << hola.size() << endl;
}
