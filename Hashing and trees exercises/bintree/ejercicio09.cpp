#include "bintree.h"
#include <iostream>
#include <stack>


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
    return (v.left().null() && v.right().null());
}

template <class T>
int profundidad(const bintree<T> &A, const typename bintree<T>::node &v)
{
    int prof = 0;
    typename bintree<T>::node aux = v;
    while (A.root() != aux)
    {
        prof++;
        aux = aux.parent();
    }
    return prof;
}

template <class T>
using stack_node = stack<typename bintree<T>::node>;

template <class T>
int Altura(const bintree<T> &A)
{
    stack_node<T> pila;
    pila.push(A.root());
    typename bintree<T>::node aux;
    int max_profun = 0;
    while (!pila.empty())
    {
        aux = pila.top();
        pila.pop();
        cout << *aux ; //Para realizar pruebas he puesto este cout aqui en medio
        if(esHoja(A,aux))
        {
            int prof=profundidad(A,aux);
            if(prof>max_profun)
            {
                max_profun=prof;
            }
        }
        if (!aux.right().null())
            pila.push(aux.right());
        if (!aux.left().null())
            pila.push(aux.left());
    }
    return max_profun;
}

template <class T>
void postorden(const bintree<T> &A, const typename bintree<T>::node &v)
{
    if (!v.null())
    {
        cout << *v; 
        postorden(A,v.left());
        postorden(A,v.right());
    }
}


int main()
{
    bintree<int> arb(0);
    arb.insert_left(arb.root(),1);
    arb.insert_right(arb.root(),2);

    bintree<int>::node aux = arb.root().left();
    arb.insert_left(aux,3);
    arb.insert_right(aux,4);

    aux = arb.root().right();
    arb.insert_left(aux,5);
    arb.insert_right(aux,6);

    cout << "----------ARBOL ORIGINAL----------" << endl;
    MostrarArbol(arb,arb.root());
    cout << "---------PRUEBA RECURSIVA---------" << endl;
    postorden(arb,arb.root());
    cout << endl;
    cout << "---------PRUEBA CON PILA----------" << endl;
    int h= Altura(arb);
    cout << endl;
    cout << "La altura del arbol es -> " << h << endl;

}