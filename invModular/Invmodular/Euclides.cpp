#include <iostream>
#include <queue>
using namespace std;

int modResta(int numA, int numB,int mod){
    int res = numA - numB;
    while (res < 0){ //Si es negativo se convirte en positivo
        res+=mod;
    }
    res%=mod;
    return res;
}

bool inverso(queue<int> &cocientes, int num, int modu, int &k)   // num%modu
{
    int residuo, tempn, r;
    if(num > modu)
    {
        tempn = num;
        num = modu;
        modu = tempn;

    }
    while(r != 0)
    {
        tempn = modu % num;
        cocientes.push(modu/num);
        modu = num % modu;
        residuo = num; //residuo es el anterior QU3 R1K0l1N0
        num = tempn;
        r = num; //r es el ultimo residuo
        k++;
    }
    if(residuo == 1)
    {
        k -= 2;
        return true;
    }
    return false;
}

int euclides(queue <int> cocientes, int modu, int k)
{
    if(k == 0) {return 0;}
    if(k == 1) {return 1;}
    int Pk;
    queue<int> tempcoci = cocientes;

    for(int i = 0; i < k-2 ; i++)
    {
        tempcoci.pop();
    }
    Pk = modResta(euclides(cocientes,modu,k-2),euclides(cocientes,modu,k-1)*tempcoci.front(),modu);
    return Pk;
}



int main()
{
    queue <int> cocientes ;
    int k = 0, i, x, y;
    cout<<"Ingresa los valores: ";
    cin >> x;
    cout << "Ingresa el segundo valor: ";
    cin >> y; cout << endl;
    if(inverso(cocientes,x,y,k) == true)
    {
        if(x > y){y = x;}
        i = k + 2;
        cout << euclides(cocientes,y,i) << endl;
    }
    else
    {
        cout << "No tiene inverso " << endl;
    }

}
