#include "ListaEnlazada.h"

int main()
{
    ListaEnlazada Milista1;
    ListaEnlazada Milista2;
    for(int i = 0 ; i <= 8 ; i+=2)
    {
        Milista1.agrCola(i);
    }
    for(int i = 1 ; i <= 9 ; i+=2)
    {
        Milista2.agrCola(i);
    }

    cout << Milista1.estaenLista(4) << endl;
}
