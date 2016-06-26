#ifndef CARTA_H
#define CARTA_H

class CartaUno{
protected:
    int num;
    char color;
public:
    CartaUno(int n, char c);
};

class Cancelar: public CartaUno{
public:
    Cancelar(char c);
};

class Voltear: public CartaUno{
public:
    Voltear(char c);

};

class Aumentar: public CartaUno{
private:
    int nCartas;
public:
    Aumentar(char c, int nC);
};

#endif //CARTA_H