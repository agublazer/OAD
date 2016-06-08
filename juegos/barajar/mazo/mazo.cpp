#include <iostream>
#include <cstdlib>
#include <time.h>
using namespace std;

template<typename T>
void Mazo<T>::agregar(T carta) {
    cartas.push(carta);
}

template<typename T>
T Mazo<T>::quitar() {
    T tmp = cartas.getBack();
    cartas.pop();
    return tmp;
}

template<typename T>
void Mazo<T>::barajar(T *arr,int ncartas){
    srand(time(NULL));
    T tmp;
    int r;
    for(int i = 0; i < ncartas; i++) {
        r = rand()%ncartas;
        tmp = arr[i];
        arr[i] = arr[r];
        arr[r] = tmp;
    }
    for (int i = 0; i < ncartas; i++) {
        agregar(arr[i]);
    }
}

template<typename T>
bool Mazo<T>::vacio() {
    return cartas.empty();
}



// void Barajar::swap(int &a, int &b){
//     int tmp = a;
//     a = b;
//     b = tmp;
// }

// Pila<int> Barajar::operator()(int *arr, int cantidad,int veces ){
//     srand (time(NULL));
//     int r;
//     Pila<int> pila;

//     for(int i =0; i< veces; i++) {
//         for (int j = 0; j < cantidad; j++) {
//             r = rand()%cantidad;
//             swap(arr[j], arr[r]);
//         }
//     }
//     for (int i =0 ;i < cantidad; i++) {
//          cout << arr[i]<< endl;;
//     }
//     cout << "*******" << endl;
//     for (int i =0 ;i < cantidad; i++) {
//          pila.push(arr[i]);
//     }
//     return pila;
// }

