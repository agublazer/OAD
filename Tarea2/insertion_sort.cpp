#include <iostream>
#include <stdlib.h>

using namespace std;

void printLista(int *lista,int n)
{
    for(int i=0;i<n;i++)
        cout<<lista[i]<<" ";

    cout<<endl;
}

void i_sort(int *lista,int n)
{
    int j, temp;
	for (int i=0;i<n; i++)
    {
		j = i;
		while (j > 0 and lista[j] < lista[j-1])
		{
            temp = lista[j];
            lista[j] = lista[j-1];
            lista[j-1] = temp;
            j--;
        }
    }
}

int main()
{
    int n=7;
    int *lista;
    lista = new int [n];
    for(int i=0;i<n;i++)
        lista[i]= rand()%20+1;

    printLista(lista,n);

    i_sort(lista,n);

    printLista(lista,n);

    delete lista;

}
