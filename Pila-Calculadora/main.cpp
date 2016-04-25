#include <iostream>
#include "pila.h"
using namespace std;

int main(int argc, char *argv[])
{

    Pila pila;
    cout << pila.empty() << endl;
    for (int i=0; i<10;i++)
        pila.push(i);
    cout << pila.empty() << endl;
    for (int i=0; i <10;i++){
        cout <<pila.getBack() << endl;
        pila.pop();
    }
    cout << pila.empty() << endl;
    return 0;
}
