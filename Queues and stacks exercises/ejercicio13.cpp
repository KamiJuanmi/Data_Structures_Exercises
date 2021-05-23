#include <stack>
#include <queue>
#include <iostream>

using namespace std;

int getNumVocales(string a){ 
    int contador=0;
    for(int i=0;i<a.size();i++)
    {
        char aux=toupper(a[i]);
        if(aux =='A' || aux=='E'|| aux=='I'|| aux=='O'|| aux=='U'){
            contador++;
        }
    }
    return contador;
}

class comp{
    public:

    bool operator() (string a, string b)
    {
        if(getNumVocales(a) == getNumVocales(b)){
            return a>b;
        }
        else
        {
            return getNumVocales(a) < getNumVocales(b);
        }
        
    }
};

int main(){
    priority_queue<string, vector<string>, comp> pq;
    string A="Hola mundo.";
    string B="Hello world";
    string C="Adios pedro";
    string D="Salut monde.";
    string E="AaEeIiOoUu";

    pq.push(A);
    pq.push(B);
    pq.push(C);
    pq.push(D);
    pq.push(E);

    while(!pq.empty()){
        cout << pq.top()<< " con " << getNumVocales(pq.top()) << " vocales" << endl;
        pq.pop();
    }
}