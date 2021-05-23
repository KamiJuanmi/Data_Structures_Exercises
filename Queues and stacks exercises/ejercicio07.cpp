#include <stack>
#include <queue>
#include <iostream>

using namespace std;

template <typename T>
//0<= pos <= P.size()
void insertar(stack<T> & P, int pos, T x){

    stack<T> aux;
    int con=P.size();
    while(con>pos){
        aux.push(P.top());
        P.pop();
        con--;
    }
    aux.push(x);
    while(!aux.empty()){
        P.push(aux.top());
        aux.pop();
    }
}


int main(){
    stack<int> prueba;
    prueba.push(0);
    prueba.push(1);
    prueba.push(2);
    prueba.push(3);
    prueba.push(4);
    prueba.push(5);
    prueba.push(6);
    while(!prueba.empty())
    {
        cout<<prueba.top()<<" ";
        prueba.pop();
    }
    cout << endl;
    prueba.push(0);
    prueba.push(1);
    prueba.push(2);
    prueba.push(3);
    prueba.push(4);
    prueba.push(5);
    prueba.push(6);
    insertar(prueba,8,10);
    while(!prueba.empty())
    {
        cout<<prueba.top()<<" ";
        prueba.pop();
    }

}