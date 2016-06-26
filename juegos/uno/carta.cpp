#include "carta.h"


CartaUno::CartaUno(int n, char c){
    numero = n;
    color = c;
}

Cancelar::Cancelar(char c): CartaUno(0, c){
    
}

Voltear::Voltear(char c): CartaUno(0, c){

}

Aumentar::Aumentar(char c, int nC): CartaUno(0, c){

}

