#include <iostream>
#include <string>
#include <list>

using namespace std;

template <typename T>
void elimina_elemento(list<T> &l, const T &elem)
{
    typename list<T>::iterator p = l.begin();
    while (p != l.end())
    {
        if (*p == elem)
            p = l.erase(p);
        else
            p++;
    }
}

template <typename T>
void mostrar_lista(const list<T> &l)
{
    typename list<T>::const_iterator p;
    for(p=l.begin();p!=l.end();p++)
    {
        cout << *p << " ";
    }
    cout << endl;
}

int main()
{
    list<int> aux;
    aux.push_back(2);
    aux.push_back(1);
    aux.push_back(1);
    aux.push_back(1);
    aux.push_back(1);
    aux.push_back(5);
    aux.push_back(3);
    mostrar_lista(aux);
    elimina_elemento(aux,1);
    mostrar_lista(aux);
    
}