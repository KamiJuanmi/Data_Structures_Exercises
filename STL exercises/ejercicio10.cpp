#include <iostream>
#include <string>
#include <list>

using namespace std;

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

template <typename T>
list<T> mezclar(const list<T> &l1, const list<T> &l2)
{
    list<T> ret;
    T aux;
    typename list<T>::const_iterator p;
    typename list<T>::const_iterator q;
    p = l1.begin();
    q = l2.begin();
    while (p != l1.end() && q != l2.end())
    {
        if (*p < *q)
        {
            aux = *p;
            p++;
        }
        else
        {
            aux = *q;
            q++;
        }

        ret.push_back(aux);
    }
    if (p == l1.end())
    {
        ret.push_back(*q);
        q++;
    }
    else
    {
        ret.push_back(*p);
        p++;
    }
    return ret;
}
int main()
{
    list<int> aux;
    aux.push_back(0);
    aux.push_back(1);
    aux.push_back(1);
    aux.push_back(1);
    aux.push_back(1);
    aux.push_back(3);
    aux.push_back(8);
    list<int> aux2;
    aux2.push_back(-1);
    aux2.push_back(2);
    aux2.push_back(7);
    aux2.push_back(10);
    aux2.push_back(1);
    aux2.push_back(3);
    aux2.push_back(8);
    mostrar_lista(aux);
    mostrar_lista(aux2);
    list<int> aux3;
    aux3 = mezclar(aux, aux2);
    mostrar_lista(aux3);
}