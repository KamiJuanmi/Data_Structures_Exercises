#include <iostream>
#include <string>
#include <list>

using namespace std;

template <typename T>
void elimina_duplicados(list<T> &l)
{
    typename list<T>::iterator p;
    typename list<T>::iterator q;
    for(p=l.begin();p!=l.end();p++)
    {
        q=p;
        q++;
        while(q!=l.end())
        {
            if(*p==*q)
            {
                q=l.erase(q);
            }
            else
            {
                q++;
            }
        }
    }
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
    aux.push_back(2);
    aux.push_back(1);
    aux.push_back(1);
    aux.push_back(1);
    aux.push_back(1);
    aux.push_back(5);
    aux.push_back(3);
    mostrar_lista(aux);
    elimina_duplicados(aux);
    mostrar_lista(aux);
}