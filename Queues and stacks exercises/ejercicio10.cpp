#include <stack>
#include <queue>
#include <iostream>

using namespace std;

bool esPalindromo(string prueba){
    queue<char> cola_aux;
    stack<char> pila_aux;
    bool ret=true;

    for(int i=0;i<prueba.size();i++){
        cola_aux.push(prueba[i]);
        pila_aux.push(prueba[i]);
    }
    while(ret && !cola_aux.empty())
    {
        ret=cola_aux.front()==pila_aux.top();
        cola_aux.pop();
        pila_aux.pop();
    }

    return ret;

}

int main(){

    string prueba1="ABCBA";
    string prueba2="";
    string prueba3="A";
    string prueba4="ABCCBA";
    string prueba5="ABBCBA";

    if(esPalindromo(prueba5))
        cout << "SI" << endl;
    else
        cout << "NO" << endl;
    




}