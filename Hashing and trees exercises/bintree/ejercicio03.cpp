#include "bintree.h"

#include <cmath>
#include <queue>
#include<iomanip>

#include <iostream>

using namespace std;

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
int getMaxProfundidad(const bintree<T> &A, typename bintree<T>::node v){
    static int max_profundidad=0;

    if(v==A.root()) //ES DECIR HEMOS LLAMADO DE NUEVO A LA FUNCION CON OTRO ARBOL
    {
        max_profundidad=0;
    } //HAY QUE RESETEAR LOS DATOS 

    if(!v.null())
    {
        if(esHoja(A,v))
        {
            int prof=profundidad(A,v);
            if(prof>max_profundidad)
            {
                max_profundidad=prof;
            }
        }
        getMaxProfundidad(A,v.left());
        getMaxProfundidad(A,v.right());
    }
    return max_profundidad;
}

int getNodosCompletos(int prof)
{
    static int sum=0;
    sum+=pow(2,prof);
    prof--;
    if(prof<0)
    {
        int aux=sum;
        sum=0;
        return aux;
    }else
    {
        getNodosCompletos(prof);
    }
    
}

template <class T>
bool esCompleto(const bintree<T> &A)
{
    return getNodosCompletos(getMaxProfundidad(A,A.root())) == A.size();
}

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

    MostrarArbol(arb,arb.root());

    if(esCompleto(arb))
    {
        cout << "El arbol binario es completo " << endl;
    }
    else
    {
        cout << "El arbol binario no es completo" << endl;
    }
    
}