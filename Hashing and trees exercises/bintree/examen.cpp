#include "bintree.h"
#include <iostream>

#include <queue>

#include <cmath>
#include <iomanip>

using namespace std;

template <typename T>
int NumCaminos_DesdeNodo(const bintree<T> &A, typename bintree<T>::node v, int k)
{
    int contador = 0;
    int suma = 0;
    typename bintree<T>::node aux = v;
    while (A.root() != aux)
    {
        suma += *aux;
        if (suma == k)
        {
            contador++;
        }
        aux = aux.parent();
    }
    suma += *aux;
    if (suma == k)
    {
        contador++;
    }
    return contador;
}

template <typename T>
int Recorrer(const bintree<T> &A, typename bintree<T>::node v, int k)
{
    static int numero = 0;
    if (v == A.root())
    {
        numero = 0;
    }
    if (!v.null())
    {
        numero += NumCaminos_DesdeNodo(A, v, k);
        Recorrer(A, v.left(), k);
        Recorrer(A, v.right(), k);
        return numero;
    }
}

template <class T>
int NumeroCaminos(const bintree<T> &A, int k)
{
    return Recorrer(A, A.root(), k);
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
    bintree<int> arb(0);

    bintree<int>::node aux;

    //RAMA IZQUIERDA

    arb.insert_left(arb.root(), 25);

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

    arb.insert_right(arb.root(), 8);

    aux = arb.root().right();

    arb.insert_left(aux, 51);

    arb.insert_right(aux, -8);

    aux = aux.left();

    arb.insert_left(aux, 45);

    arb.insert_right(aux, 55);

    aux = aux.parent().right();

    arb.insert_left(aux, 25);

    arb.insert_right(aux, 72);

    cout << "---------------ARBOL ORIGINAL------------------" << endl;

    MostrarArbol(arb, arb.root());
    int suma = 25;

    cout << "Numero de caminos que suman " << suma << "---->" << NumeroCaminos(arb, suma) << endl;
}