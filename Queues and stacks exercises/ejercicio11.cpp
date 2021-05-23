#include <stack>
#include <queue>
#include <iostream>

using namespace std;

struct Persona{
    string nombre;
    string apellidos;
    int prioridad;
};
class comp{
    public:

    bool operator() (Persona a, Persona b)
    {
        return a.prioridad<b.prioridad;
    }
};

int main(){

    Persona A ={"Eskere","Dice_El_Juanmi",1};
    Persona B ={"Caracoles","Gratinaos",0};
    Persona C ={"Paco","Dineros",3};
    Persona D ={"Matadme", "Por favor", 2};

    priority_queue<Persona, vector<Persona>, comp> pq;

    pq.push(A);
    pq.push(B);
    pq.push(C);
    pq.push(D);

    while(!pq.empty()){
        cout << pq.top().nombre << " ";
        pq.pop();
    }

    cout << endl;

}