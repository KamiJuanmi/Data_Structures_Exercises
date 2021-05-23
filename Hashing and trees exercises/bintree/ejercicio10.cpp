#include "bintree.h"
#include <iostream>

#include <cmath>
#include <queue>
#include <iomanip>

using namespace std;

template <class T>
bool Similares(const bintree<T> &A1, const typename bintree<T>::node &v1, const bintree<T> &A2, const typename bintree<T>::node &v2)
{
    if ((v1.null() && !v2.null()) || (!v1.null() && v2.null()))
    {
        return false;
    }
    if (!v1.null() && !v2.null())
    {
        if(!Similares(A1, v1.left(), A2, v2.left()))
        {
            return false;
        }   
        if(!Similares(A1, v1.right(), A2, v2.right()))
        {
            return false;
        }
    }
    return true;
    
}

template <class T>
void MostrarArbol(const bintree<T> &A, typename bintree<T>::node root)
{
    queue<typename bintree<T>::node> colaNodos;
    int totalNodos = A.size();
    int techo = log2(totalNodos + 1);
    colaNodos.push(root);
    int pot = 0;
    while (colaNodos.size() > 0)
    {
        int niveles = colaNodos.size();
        while (niveles > 0)
        {
            typename bintree<T>::node nodoAux = colaNodos.front();
            colaNodos.pop();
            cout << setw((niveles == pow(2, pot)) ? pow(2, (techo - pot)) : pow(2, (techo - pot + 1)));
            cout << *nodoAux;
            if (!nodoAux.left().null())
                colaNodos.push(nodoAux.left());
            if (!nodoAux.right().null())
                colaNodos.push(nodoAux.right());
            niveles--;
        }
        pot++;
        cout << endl;
    }
}

int main()
{
    //ARBOL1
    bintree<int> arb1(0);
    arb1.insert_left(arb1.root(), 1);
    arb1.insert_right(arb1.root(), 2);
    

    bintree<int>::node aux1 = arb1.root().left();
    arb1.insert_left(aux1, 3);
    arb1.insert_right(aux1, 4);

    aux1 = arb1.root().right();
    arb1.insert_left(aux1, 5);
    arb1.insert_right(aux1, 6);

    //ARBOL 2
    bintree<int> arb2(0);
    arb2.insert_left(arb2.root(), 1);
    arb2.insert_right(arb2.root(), 2);

    bintree<int>::node aux2 = arb2.root().left();
    arb2.insert_left(aux2, 3);
    arb2.insert_right(aux2, 4);

    aux2 = arb2.root().right();
    arb2.insert_left(aux2, 5);
    arb2.insert_right(aux2, 6);

    //ARBOL 3
    bintree<int> arb3(0);
    arb3.insert_left(arb3.root(), 1);
    arb3.insert_right(arb3.root(), 2);

    bintree<int>::node aux3 = arb3.root().left();
    arb3.insert_left(aux3, 3);
    arb3.insert_right(aux3, 4);

    aux3 = arb3.root().right();
    arb3.insert_left(aux3, 5);
    arb3.insert_left(aux3.left(),8);

    cout << "----------ARBOL ORIGINAL----------" << endl;
    MostrarArbol(arb1, arb1.root());
    cout << "----------ARBOL ORIGINAL----------" << endl;
    MostrarArbol(arb2, arb2.root());
    cout << "----------ARBOL ORIGINAL----------" << endl;
    MostrarArbol(arb3, arb3.root());

    if (Similares(arb1, arb1.root(), arb3, arb3.root()))
    {
        cout << "El arbol 1 y el 3 son similares " << endl;
    }
    else
    {
        cout << "El arbol 1 y 3 no son similares " << endl;
    }

    if (Similares(arb1, arb1.root(), arb2, arb2.root()))
    {
        cout << "El arbol 1 y el 2 son similares " << endl;
    }
    else
    {
        cout << "El arbol 1 y 2 no son similares " << endl;
    }
}