#include <queue>
using namespace std;

class xyz {
private:
    int i;
    int j;
    int k;
public:
    xyz(int a, int b, int c) { i = a; j = b; k = c;}
    int getI() {return i;}
    int getJ() {return j;}
    int getK() {return k;}
};

class fun {
private:
    queue<xyz> cola;
public:
    void operator() (int i, int j, int k) { cola.push(xyz(i, j, k)); }
    void obtener(int &x, int &y, int &z);
    bool empty(){ cola.empty(); }
};


class tres {
private:
    char tab[3][3][4];
    int _i;
    int _j;
    int _k;

    int jugadas;
    bool turno;
    fun validos;

    void printTabl();
    void printPart();
    bool libre(char c);
    bool verificar();
    void lados(int i, int j, int k);
    char simb();
    int lim(int a);

public:
    tres();
    void jugar();
};