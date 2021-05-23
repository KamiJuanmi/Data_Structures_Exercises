#include "bintree.h"
#include <iostream>

#include <cmath>
#include <queue>
#include<iomanip>

using namespace std;

template <class T>
void MostrarArbol(const bintree<T> &A,typename bintree<T>::node root){
    queue<typename bintree<T>::node> colaNodos;
    int totalNodos=A.size();
    int techo=log2(totalNodos+1);
    colaNodos.push(root);
    int pot=0;
    while(colaNodos.size() > 0){
            int niveles = colaNodos.size();
            while(niveles > 0){
                typename bintree<T>::node nodoAux = colaNodos.front(); 
                colaNodos.pop();
                cout<<setw((niveles==pow(2,pot))?pow(2, (techo-pot)):pow(2, (techo-pot+1)));
                cout<<*nodoAux;
                if(!nodoAux.left().null()) colaNodos.push(nodoAux.left());
                if(!nodoAux.right().null()) colaNodos.push(nodoAux.right());
                niveles--;
            }
            pot++;
            cout << endl;
    }
}

template <class T>
bool esHoja(const bintree<T> &A, const typename bintree<T>::node &v)
{
    return ( v.left().null() && v.right().null() );
}

template <class T>
int profundidad(const bintree<T> &A, const typename bintree<T>::node &v)
{
    int prof=0;
    typename bintree<T>::node aux=v;
    while(A.root()!=aux){
        prof++;
        aux=aux.parent();
    }
    return prof;
}

template <class T>
int densidad(const bintree<T> &A, typename bintree<T>::node v){
    static int suma=0;

    if(v==A.root())
    {
        suma=0;
    }

    if(!v.null())
    {
        if(esHoja(A,v))
        {
            suma+=profundidad(A,v);
        }
        densidad(A,v.left());
        densidad(A,v.right());
    }

    return suma;
}

int main()
{
    bintree<int> arb(0);
    arb.insert_left(arb.root(),1);
    arb.insert_right(arb.root(),2);

    bintree<int>::node aux = arb.root().left();
    arb.insert_left(aux,3);
    arb.insert_left(aux.left(),3);
    arb.insert_right(aux,4);

    aux = arb.root().right();
    arb.insert_left(aux,5);
    arb.insert_right(aux,6);

    MostrarArbol(arb,arb.root());

    cout << "La densidad del arbol es -> " << densidad(arb,arb.root()) << endl;
}