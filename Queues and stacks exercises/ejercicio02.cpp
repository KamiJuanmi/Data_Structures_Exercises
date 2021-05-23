#include <stack>
#include <queue>
#include <iostream>

using namespace std;

bool parentesis_cor(string test)
{
    stack<char> aux;
    int contador=0;
    bool ret=true;
    for(int i=0;i<test.size();i++)
    {
        aux.push(test[i]);
    }
    while(!aux.empty() && contador >=0)
    {
        if(aux.top()==')')
            contador++;
        if(aux.top()=='(')
            contador--;
        aux.pop();
    }
    if(contador!=0)
        ret=false;
    return ret;
}

int main(){
    string prueba1=")hola()(";

    if(parentesis_cor(prueba1)){
        cout << "yes" ;
    }else
    {
        cout << "no";
    }
    
    cout << endl;
}