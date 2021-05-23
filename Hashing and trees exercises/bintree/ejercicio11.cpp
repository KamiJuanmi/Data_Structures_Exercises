#include "bintree.h"
#include <iostream>
#include <queue>

#include <cmath>
#include <iomanip>

using namespace std;

template <class T>
void preorden(const bintree<T> &A, typename bintree<T>::node root)
{
    if(!root.null())
    {
        cout << *root << "  ";
        preorden(A,root.left());
        preorden(A,root.right());
    }
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

template <typename T>
void inordenA_B(const bintree<T> &Arbol, typename bintree<T>::node v, T A, T B, queue<T> &dev)
{
    if (!v.null())
    {
        inordenA_B(Arbol, v.left(), A, B, dev);
        if (*v > A && *v < B)
        {
            dev.push(*v);
        }
        inordenA_B(Arbol, v.right(), A, B, dev);
    }
}

template <typename T>
queue<T> comprendidosA_B(const bintree<T> &Arbol, typename bintree<T>::node v, T A, T B)
{
    queue<T> dev;

    inordenA_B(Arbol, Arbol.root(), A, B, dev);

    return dev;
}

int main()
{

    bintree<int> arb(42);

    bintree<int>::node aux;

    //RAMA IZQUIERDA

    arb.insert_left(arb.root(), 24);

    aux = arb.root().left();

    arb.insert_left(aux, 22);

    arb.insert_right(aux, 35);

    aux = aux.left();

    arb.insert_left(aux, 3);

    arb.insert_right(aux, 23);

    aux = aux.parent().right();

    arb.insert_left(aux, 33);

    arb.insert_right(aux, 37);

    //RAMA DERECHA

    arb.insert_right(arb.root(), 57);

    aux = arb.root().right();

    arb.insert_left(aux, 51);

    arb.insert_right(aux, 63);

    aux = aux.left();

    arb.insert_left(aux, 45);

    arb.insert_right(aux, 55);

    aux = aux.parent().right();

    arb.insert_left(aux, 60);

    arb.insert_right(aux, 72);

    cout << "---------------ARBOL BST------------------" << endl;

    MostrarArbol(arb, arb.root());

    int a, b;
    a = 4;
    b = 52;

    cout << "Comprendidos entre " << a << " y " << b << " -->" << endl;

    queue<int> otro = comprendidosA_B(arb, arb.root(), a, b);
    while (!otro.empty())
    {
        cout << otro.front() << " ";
        otro.pop();
    }
    cout << endl;
    preorden(arb,arb.root());
}