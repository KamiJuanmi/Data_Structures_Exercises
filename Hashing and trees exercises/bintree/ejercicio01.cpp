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
typename bintree<T>::node getHojaProfunda(const bintree<T> &A, typename bintree<T>::node v){
    static int max_profundidad=0;
    static typename bintree<T>::node hoja_prof=A.root();

    if(v==A.root()) //ES DECIR HEMOS LLAMADO DE NUEVO A LA FUNCION CON OTRO ARBOL
    {
        max_profundidad=0;
        hoja_prof=A.root();
    } //HAY QUE RESETEAR LOS DATOS 

    if(!v.null())
    {
        if(esHoja(A,v))
        {
            int prof=profundidad(A,v);
            if(prof>max_profundidad)
            {
                hoja_prof=v;
                max_profundidad=prof;
            }
        }
        getHojaProfunda(A,v.left());
        getHojaProfunda(A,v.right());
    }
    return hoja_prof;
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
    bintree<int> arb(5);
    arb.insert_left(arb.root(), 22);

    bintree<int>::node n = arb.root().left();

    arb.insert_left(n, 481);
    arb.insert_right(n, 125);

    bintree<int>::node mas_prfu1=getHojaProfunda(arb,arb.root());
    MostrarArbol(arb,arb.root());
    cout << *mas_prfu1 << endl;

    bintree<int> aux(1);
    aux.insert_right(aux.root(),128);
    aux.insert_right(aux.root().right(),209);

    bintree<int>::node mas_prfu2=getHojaProfunda(aux,aux.root());
    MostrarArbol(aux,aux.root());
    cout << *mas_prfu2 << endl;
}