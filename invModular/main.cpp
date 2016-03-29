#include "invModular.h"

int main(){
	invModular inverso;
	int num;
	int mod;
	int invMod;

	cout << "Ingrese un numero: ";
	cin >> num;
	cout << "Ingrese el modulo: ";
	cin >> mod;
	invMod = inverso.euclidesEx(num, mod);

	if (invMod)
		cout << "El inverso modular es:  "<< invMod << endl;
	else
		cout << "No tiene inverso" << endl;
	return 0;
}

