#include <iostream>
#include <vector>
using namespace std;

void josefo(int salto, int vivos, vector<int>& v) {
    int i = 0;
    salto -=1;
    while (v.size() > vivos) {
        i += salto;
        if (i >= v.size())
            i = i % v.size();

        v.erase(v.begin() + i);
    }
}

void josefo_SinSTL(int salto, int vivos, int *arr, int arrSize){
    int i = 0;
    int cont = arrSize;
    int check;

    while(cont > vivos) {
        check = salto;
        while(check > 0){
            if(i >= arrSize)
                i -= arrSize;
            if(arr[i] !=0)
                check--;
            i++;
        }
        arr[i-1] = 0;
        cont-- ;
    }
}

int main() {
    vector<int> v;
    int personas;
    int salto;

    cout << "# Personas: ";
    cin >> personas;
    cout << "Salto: ";
    cin >> salto;

    for (int i = 1; i <= personas; i++) {
        v.push_back(i);
    }

    josefo(salto, 2, v);
    
    for (int i = 0; i < v.size(); i++) {
        cout << v[i] << " ";
    }
    cout << endl;

    //-------------

    int *array = new int[personas];
    for (int i = 1; i <= personas; i++){
        array[i-1] = i;
    }

    josefo_SinSTL(salto, 2, array, personas);

    for (int i = 0; i < personas; ++i){
        if(array[i] != 0){
            cout << array[i]<< " ";
        }
    }
    cout << endl;

    delete[] array;


}