#include <fstream>
#include "invModular.h"
#include "cifradoMod.h"

cifradoMod::cifradoMod(int num) {
    clavPri = num;
    invModular inverso;
    clavPub = inverso.euclidesEx(clavPri, 256);
    while (clavPub == 0) {
        cout << "El numero ingresado no tiene inverso, ingresa otro: \n";
        cin >> clavPri;
        clavPub = inverso.euclidesEx(clavPri, 256);

    }
}

void cifradoMod::cifrar(string nombreIn, string nombreOut) {
    char letra;
    //Abrir archivo y verifica que exista:
    input.open (nombreIn.c_str(), fstream::in | fstream::binary); //.c_str para que pueda leer el string
    output.open (nombreOut.c_str(), fstream::out);
    while (!input.is_open()) {
        cout << "No existe el archivo que quieres cifrar, ingresa otro: ";
        cin >> nombreIn;
        input.open (nombreIn.c_str(), fstream::in);
    }
    //Cifrar:
    while (input >> noskipws >> letra) {
        output.put((letra * clavPri) % 256);
    }
    input.close();
    output.close();
}

void cifradoMod::descifrar(string nombreIn, string nombreOut, int clavePublica) {
    char letra;
    //Abrir archivo y verifica que exista:
    input.open (nombreIn.c_str(), fstream::in | fstream::binary); //.c_str para que pueda leer el string
    output.open (nombreOut.c_str(), fstream::out);
    while (!input.is_open()) {
        cout << "No existe el archivo que quieres descifrar, ingresa otro: ";
        cin >> nombreIn;
        input.open (nombreIn.c_str(), fstream::in);
    }
    //Descifrar:
    while (input >> noskipws >> letra) {
        output.put((letra * clavePublica) % 256);
    }
    input.close();
    output.close();
}

