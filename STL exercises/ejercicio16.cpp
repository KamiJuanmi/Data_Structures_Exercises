#include <iostream>
#include <string>
#include <list>

using namespace std;

template <typename T> using Lista_Comprimida=list<pair<T,int>>;

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
void mostrar_lista(const Lista_Comprimida<T> &l)
{
    typename Lista_Comprimida<T>::const_iterator p;
    for (p = l.begin(); p != l.end(); p++)
    {
        cout << (*p).first << " " << (*p).second << endl;
    }
}


template <typename T>
Lista_Comprimida<T> comprimir (const list<T> &l)
{

    int contador=0;
    Lista_Comprimida<T> ret;
    T aux;
    
    typename list<T>::const_iterator it;
    it=l.cbegin();
    aux=*it;
    for(it;it!=l.cend();it++)
    {
        if(aux==(*it))
        {
            contador++;
        }else
        {
            ret.push_back(make_pair(aux,contador));
            aux=(*it);
            contador=0;
        }
    }
    ret.push_back(make_pair(aux,contador));

    return ret;

}

template <typename T>
list <T> descomprimir (const Lista_Comprimida<T> &lc)
{
    typename Lista_Comprimida<T>::const_iterator it;
    it=lc.cbegin();
    list<T> ret((*it).second,(*it).first);
    typename list<T>::iterator p;
    it++;
    for(it;it!=lc.cend();it++)
    {
        p=ret.end();
        ret.insert(p,(*it).second,(*it).first);
    }
    return ret;

}

int main()
{
    cout << "Prueba 1 " << endl;
    Lista_Comprimida<int> lc1;
    pair<int,int> comp1,comp2,comp3;
    comp1.first=2;
    comp1.second=4;
    comp2.first=3;
    comp2.second=5;
    comp3.first=7;
    comp3.second=2;
    lc1.push_back(comp1);
    lc1.push_back(comp2);
    lc1.push_back(comp3);
    list<int> ld1;
    ld1=descomprimir(lc1);
    mostrar_lista(lc1);
    mostrar_lista(ld1);


    cout << "Prueba 2" << endl;
    list<int> l2;
    l2.push_back(8);
    l2.push_back(8);
    l2.push_back(8);
    l2.push_back(8);
    l2.push_back(8);
    
    l2.push_back(2);
    l2.push_back(2);
    l2.push_back(2);
    
    l2.push_back(4);
    l2.push_back(4);
    l2.push_back(4);
    l2.push_back(4);
    Lista_Comprimida<int> lc2;
    lc2=comprimir(l2);
    mostrar_lista(l2);
    mostrar_lista(lc2);
    
}