#include<iostream>
using namespace std;

void fswap(int *A,int *B)
{
    int *temp;
    if(*A>*B)
    {
        *temp=*A;
        *A=*B;
        *B=*temp;
    }
}

int main()
{
    int *a;
    int a1=8;
    a=&a1;

    int *b;
    int b1=2;
    b=&b1;
    fswap(a,b);
    cout<<*a<<" "<<*b<<endl;
}
