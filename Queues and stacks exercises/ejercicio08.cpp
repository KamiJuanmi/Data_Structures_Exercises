#include <stack>
#include <queue>
#include <iostream>

using namespace std;

template <typename T>
//0<= pos <= Q.size()
void insertar(queue<T> & Q, int pos, T x){
    
    queue<T> aux;
    int con=0;
    while(!Q.empty()){
        if(con==pos)
        {
            aux.push(x);
        }
        aux.push(Q.front());
        Q.pop();
        con++;
    }
    if(con==pos){
        aux.push(x);
    }
    while(!aux.empty()){
        Q.push(aux.front());
        aux.pop();
    }
}


int main(){
    queue<int> prueba;
    prueba.push(0);
    prueba.push(1);
    prueba.push(2);
    prueba.push(3);
    prueba.push(4);
    prueba.push(5);
    prueba.push(6);
    while(!prueba.empty())
    {
        cout<<prueba.front()<<" ";
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
    insertar(prueba,7,10);
    while(!prueba.empty())
    {
        cout<<prueba.front()<<" ";
        prueba.pop();
    }
}