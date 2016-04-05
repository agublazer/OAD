#include <iostream>
#include <stdlib.h>
using namespace std;

void swap(int *a, int *b)
{
    int tmp;
    tmp = *a;
    *a = *b;
    *b = tmp;

}

void bubbleSort(int *arr, int size)
{
    bool isSorted = false;
    for (int i = 1; i < size and !isSorted; i++)
    {
        isSorted = true;
        for (int j = 0; j < size -i ; j++)
        {
            if(arr[j] > arr[j+1])
            {
                isSorted = false;
                swap(arr[j], arr[j+1]);
            }
        
        }

        
    }
}

void cocktailSort(int *arr, int size)
{
    bool isSorted = false;
    for (int i = 1; i < size and !isSorted; i++)
    {
        isSorted = true;
        for (int j = i-1; j < size -i ; j++)
        {
            if(arr[j] > arr[j+1])
            {
                isSorted = false;
                swap(arr[j], arr[j+1]);
            }
        }
        isSorted = true;
        for (int j = size-i-1; j >i-1 ; j--)
        {
            if(arr[j] < arr[j-1])
            {
                isSorted = false;
                swap(arr[j], arr[j-1]);
            }
        }
    }
}
void selectionSort(int *arr, int size)
{
    int min;
    for (int i = 0; i < size ; i++)
    {
        min = i;
        for (int j = i+1; j < size; j++)
        {
            if (arr[j] < arr[min])
                min = j;
        }
        swap(arr[i], arr[min]);
    }
}

void insertionSort()
{

}

void quickSort()
{

}

void printArr(int *arr, int size)
{
    for (int i = 0; i < size; i++)
        cout << arr[i] << " ";
    cout << endl;
}

int main()
{
    int size = 10;
    int *array;
    array = new int[size];
    for(int i = 0; i < size; i++)
        array[i]=  rand() % 100;

    printArr(array, size);
    //bubbleSort(array, size);
    //cocktailSort(array, size);
    selectionSort(array, size);
    printArr(array, size);
}