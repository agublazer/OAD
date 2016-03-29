#include "invModular.h"

int invModular::modResta(int numA, int numB,int mod){
	int res = numA - numB;
	while (res < 0)
		res+=mod;
	res%=mod;
	return res;
}

int invModular::euclidesEx(int numA, int numB){
	queue<int> cocientes;
	int residuo = -1;
	int resAnterior = 0;
	int pos;

	int mod = numB;
	int euExtA = 0;
	int euExtB = 1;


	for (pos = 0; residuo != 0; pos++){     //La variable "pos" ya es k+2, ya que la posición del residuo 0 es k+1
		cocientes.push(numB/numA);          //y el for da una vuelta más para comprobar  y suma +1 a pos.
		resAnterior = residuo;
		residuo = numB % numA;
		numB = numA;
		numA = residuo;
	}
	if (resAnterior != 1)
		return 0;

	for (int i = 2; i <= pos; i++){
		int tmp = modResta(euExtA, euExtB*cocientes.front(), mod);
		cocientes.pop();
		euExtA = euExtB;
		euExtB = tmp;
	}
	return euExtB;
}
