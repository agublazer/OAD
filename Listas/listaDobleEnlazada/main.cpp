#include <iostream>
#include "listade.h"

using namespace std;

int main()
{
    ListaDE lista;
    lista.pushBack(1);
    lista.pushBack(3);
    lista.pushBack(52);
    lista.pushBack(123);
    lista.pushBack(2);
    lista.pushBack(324);
    lista.pushBack(51);
    lista.pushBack(12);
    lista.pushBack(109);

    cout << lista.front->val << endl;
    cout << lista.back->val << endl;
    cout << lista.back->prev->val << endl;
    lista.popBack();
    cout << lista.back->val << endl;

    return 0;
}
