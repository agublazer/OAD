#include <iostream>
#include "cifradoMod.h"
using namespace std;

int main() {
    int clavPri;
    int clavPub;
    int opcion;
    string input;
    string output;

    cout << "1.Cifrar \n2. Descifrar" << endl;
    cin >> opcion;


    if (opcion == 1) {
        cout << "Clave Privada: ";
        cin >> clavPri;
        cifradoMod cifrador(clavPri);
        cout << "Clave Publica: " << cifrador.getClavPub() << endl;

        cout << "Nombre de archivo a cifrar: ";
        cin >> input;
        cout << "Nombre del archivo output: ";
        cin >> output;
        cifrador.cifrar(input, output);
    }
    else {

        cout << "Clave: ";
        cin >> clavPub;
        cifradoMod cifrador;
        cout << "Nombre de archivo a descifrar: ";
        cin >> input;
        cout << "Nombre del archivo output: ";
        cin >> output;
        cifrador.descifrar(input, output, clavPub );
    }
    return 0;
}

