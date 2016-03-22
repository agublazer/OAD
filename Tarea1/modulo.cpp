#include <iostream>

int modSuma(int numA, int numB, int mod){
    int res = (numA + numB)%mod;
    return res;
}

int modResta(int numA, int numB,int mod){
    int res = (numA) - (numB);
    if (res < 0){ //Si es negativo se convirte en positivo
        res= mod +res;
    }
    res%=mod;
    return res;
}

int modMult(int numA, int numB,int mod){
    int res = (numA*numB)%mod;
    return res;
}

int main(){
    int opcion;
    int numA;
    int numB;
    int mod;

    std::cout << "Elija una opcion:\n";
    std::cout << "1. Sumar\n";
    std::cout << "2. Restar\n";
    std::cout << "3. Multiplicar\n";
    std::cin >> opcion;
    std::cout << "Ingrese el primer numero: ";
    std::cin >> numA;
    std::cout << "Ingrese el segundo numero: ";
    std::cin >> numB;
    std::cout << "Ingrese el modulo: ";
    std::cin >> mod;

    if (opcion == 1){
        std::cout << modSuma(numA, numB, mod) << std::endl;
    }
    if(opcion == 2){
        std::cout << modResta(numA, numB, mod) << std::endl;
    }
    if(opcion == 3){
        std::cout << modMult(numA, numB, mod) << std::endl;
    }
    return 0;
}
