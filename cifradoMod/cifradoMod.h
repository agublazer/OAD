#ifndef CIFRADOMOD_H
#define CIFRADOMOD_H

#include <fstream>
#include <string>
using namespace std;

class cifradoMod {
private:
    int clavPri;
    int clavPub;
    fstream input;
    fstream output;


public:
    cifradoMod(int num);
    cifradoMod() {}
    void cifrar(string nombreIn, string nombreOut);
    void descifrar(string nombreIn, string nombreOut, int clavePublica);
    int getClavPub() {
        return clavPub;
    }
};

#endif // CIFRADOMOD_H
