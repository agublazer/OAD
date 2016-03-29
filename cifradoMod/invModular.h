#ifndef INVMODULAR_H
#define INVMODULAR_H

#include <iostream>
#include <queue>
using namespace std;

class invModular {
private:
    int modResta(int numA, int numB, int mod);
public:
    int euclidesEx(int numA, int numB);
};

#endif // INVMODULAR_H
