#include <iostream>
#include <string>
#include <list>

using namespace std;

template <typename T>
list<T> invertir_orden(const list<T> &l)
{
    list<T> ret;
    typename list<T>::const_reverse_iterator p;
    for (p = l.rbegin(); p != l.rend(); p++)
    {
        ret.push_back(*p);
    }
    return ret;
}

template <typename T>
void mostrar_lista(const list<T> &l)
{
    typename list<T>::const_iterator p;
    for (p = l.begin(); p != l.end(); p++)
    {
        cout << *p << " ";
    }
    cout << endl;
}

int main()
{
    list<int> aux;
    list<int> aux2;
    aux.push_back(2);
    aux.push_back(1);
    aux.push_back(1);
    aux.push_back(1);
    aux.push_back(1);
    aux.push_back(5);
    aux.push_back(3);
    mostrar_lista(aux);
    aux2=invertir_orden(aux);
    mostrar_lista(aux2);
}