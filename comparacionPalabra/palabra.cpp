#include <iostream>
using namespace std;

bool compara( char *a, char *b){
    
    while(*a != '\0' ){
        if (*a == *b){
            a++;
            b++;
         
        }
        else
            return false;
    }
    return true;
}

int main(){
    char a[]= "holaz";
    char b[] = "hola";

    cout << compara(a , b) << endl;
}
