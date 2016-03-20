#include <iostream>
using namespace std;

int resto(int &num, int dig)
{
    int convertir;
    int divisor = 1;
    for(int it=1; it<dig; it++)
    {
        divisor = divisor*10;
    }
    convertir = num/divisor;
    num = num%divisor;
    return convertir;
}

void romanos(int num, int &dig)
{
    if(dig == 4)
    {
        if(num == 3){ cout<<"MMM";}
        if(num == 2){ cout<<"MM";}
        if(num == 1){ cout<<"M";}
        dig--;
        return;
    }
    if(dig == 3)
    {
        if(num == 9){ cout<<"CM";}
        if(num == 8){ cout<<"DCCC";}
        if(num == 7){ cout<<"DCC";}
        if(num == 6){ cout<<"DC";}
        if(num == 5){ cout<<"D";}
        if(num == 4){ cout<<"CD";}
        if(num == 3){ cout<<"CCC";}
        if(num == 2){ cout<<"CC";}
        if(num == 1){ cout<<"C";}
        dig--;
        return;
    }
    if(dig == 2)
    {
        if(num == 9){ cout<<"XC";}
        if(num == 8){ cout<<"LXXX";}
        if(num == 7){ cout<<"LXX";}
        if(num == 6){ cout<<"LX";}
        if(num == 5){ cout<<"L";}
        if(num == 4){ cout<<"XL";}
        if(num == 3){ cout<<"XXX";}
        if(num == 2){ cout<<"XX";}
        if(num == 1){ cout<<"X";}
        dig--;
        return;
    }
    if(dig == 1)
    {
        if(num == 9){ cout<<"IX";}
        if(num == 8){ cout<<"VIII";}
        if(num == 7){ cout<<"VII";}
        if(num == 6){ cout<<"VI";}
        if(num == 5){ cout<<"V";}
        if(num == 4){ cout<<"IV";}
        if(num == 3){ cout<<"III";}
        if(num == 2){ cout<<"II";}
        if(num == 1){ cout<<"I";}
        dig--;
        return;
    }
}

void conversionaromanos(int &num, int &dig)
{
    int rest;
    while(dig!=0)
    {
        rest = resto(num, dig);
        romanos(rest, dig);

    }
}

int main()
{
    int numero, digitos, convertir;
    cout<<"Ingrese la cantidad de cifras: " ;
    cin>>digitos; cout<<endl;
    cout<<"Ingrese el numero que desea convertir: ";
    cin>>numero; cout<<endl;
    conversionaromanos(numero,digitos);


}
