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

void insertar_x_1(list<int> &l, const int & x)
{
    list<int>::iterator p;
    for(p=l.begin();p!= l.end();p++)
    {
        if(*p==x)
        {
            p++;
            l.insert(p,1,x-1);
            p--;
        }
    }
}

int main()
{
    list<int> aux;
    aux.push_back(2);
    aux.push_back(1);
    aux.push_back(8);
    aux.push_back(1);
    aux.push_back(1);
    aux.push_back(8);
    aux.push_back(8);
    mostrar_lista(aux);
    insertar_x_1(aux,8);
    mostrar_lista(aux);
}