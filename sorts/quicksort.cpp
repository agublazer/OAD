#include <iostream>
#include <stdlib.h>

using namespace std;

int divide(int *array, int inicio, int fin) {
    int izquierda;
    int derecha;
    int pivot;
    int temp;

    pivot = array[inicio];
    izquierda = inicio;
    derecha = fin;

    while (izquierda < derecha) {
        while (array[derecha] > pivot) {
            derecha--;
        }

        while ((izquierda < derecha) and (array[izquierda] <= pivot)) {
            izquierda++;
        }

        if (izquierda < derecha) {
            temp = array[izquierda];
            array[izquierda] = array[derecha];
            array[derecha] = temp;
        }
    }

    temp = array[derecha];
    array[derecha] = array[inicio];
    array[inicio] = temp;
    return derecha;

}

void quicksort(int *array, int inicio, int fin)
{
    int pivot;
    if (inicio < fin) {
        pivot = divide(array, inicio, fin);
        quicksort(array, inicio, pivot - 1);
        quicksort(array, pivot + 1, fin);
    }
}
int main()
{
    int t= 10;
    int *lista;
    lista=new int[t];
    for(int i=0;i<t;i++)
        lista[i]=rand()%100+1;

    quicksort(lista,0, t-1);
    for(int i=0;i<t;i++)
        cout<<lista[i]<<" ";
    return 0;
}
