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

int main() {
    vector<int> v;
    int personas;
    int salto;

    cout << "# Personas: ";
    cin >> personas;
    cout << "Salto: ";
    cin >> salto;

    for (int i = 1; i <= personas; i++)
        v.push_back(i);

    josefo(salto, 2, v);
    
    for (int i = 0; i < v.size(); i++) {
        cout << v[i] << " ";
    }
    cout << endl;
}