#include <iostream>
#include <stack>
#include <queue>
#include <string>
using namespace std;


int strToInt(string &input, string oper)
{
    int num = 0;
    int pos = 0;
    while( oper.find(input[pos]) == string::npos and input[pos]!='\0') // string::npos = no se encontró en la busqueda
    {
        num = num*10;
        num += input[pos] - '0';
        pos++;
    }
    input.erase(0,pos);
    return num;
}

string infToRPN(string in, string oper)
{
    stack<char> pila;
    string rpn;
    int findPos;

    while(!in.empty())
    {
        findPos = oper.find(in[0]); 
        if (findPos != string::npos)
        {
            if (oper[findPos] == '(')
            {
                pila.push('(');
            }
            else if (oper[findPos] == ')')
            {
                while(pila.top() != '(')
                {
                    rpn.push_back(pila.top());
                    rpn.push_back('_');
                    pila.pop();
                }
                pila.pop();
            }
            else if (oper[findPos] == '*' or oper[findPos] == '/')
            {
                while(true)
                {
                    if (pila.empty() or pila.top() == '+' or pila.top() == '-' or pila.top() == '(')
                    {
                        pila.push(oper[findPos]);
                        break;
                    }    
                    else
                    {
                        rpn.push_back(pila.top());
                        rpn.push_back('_');
                        pila.pop();
                    }
                    
                }
            }
            else if (oper[findPos] == '+' or oper[findPos] == '-')
            {
                while(true)
                {
                    if (pila.empty() or pila.top() == '(')
                    {
                        pila.push(oper[findPos]);
                        break;
                    }    
                    else
                    {
                        rpn.push_back(pila.top());
                        rpn.push_back('_');
                        pila.pop();
                    }
                    
                }
            }
            in.erase(0,1); // borra el primer elemento del string
        }
        else
        {
            while(oper.find(in[0]) == string::npos and !in.empty())
            {
                rpn.push_back(in[0]);
                in.erase(0,1);
            }
            rpn.push_back('_');
        }
    }
    while (!pila.empty())
    {
        rpn.push_back(pila.top());
        rpn.push_back('_');
        pila.pop();
    }
    return rpn;
}


int calculadora(string in)
{
    stack<int> pila;
    string oper("()+-*/");
    string rpn = infToRPN(in, oper);
    int tmp;
    while(!rpn.empty())
    {
        if(oper.find(rpn[0]) == string::npos)
        {
            pila.push(strToInt(rpn, oper+'_'));
            rpn.erase(0,1); // elimina '_'
        }
        else
        {
            tmp = pila.top();
            pila.pop();

            if(rpn[0] == '+')
                tmp =  pila.top() + tmp; 

            else if(rpn[0] == '-')
                tmp = pila.top() - tmp;

            else if(rpn[0] == '*')
                tmp = pila.top() * tmp;

            else if(rpn[0] == '/')
                tmp = pila.top() / tmp;

            pila.pop();
            pila.push(tmp);
            rpn.erase(0,2); // elimina  operador y '_'
        }
    }
    return pila.top();
}
int main()
{
    string operacion;
    cout << "Ingresa operacion(sin espacios): ";
    cin >> operacion;
    cout << calculadora(operacion) << endl;

}