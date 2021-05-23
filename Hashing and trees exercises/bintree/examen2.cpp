#include <iostream>
#include <set>

using namespace std;

template<class T> 
void mostrarSet(const multiset<T> &set)
{
    typename multiset<T>::const_iterator it;
    for(it=set.cbegin();it!=set.cend();it++)
    {
        cout << *it << "-";
    }
    cout << endl;
}

multiset<int> multi_interseccion(const multiset<int> &m1,const multiset<int> &m2)
{
    multiset<int>::iterator it1=m1.begin();
    multiset<int>::iterator it2=m2.begin();
    multiset<int> salida;
    while(it1!=m1.end() && it2!=m2.end())
    {
        if(*(it1)<*(it2))
        {
            it1++;
        }
        else if(*it1==*it2)
        {
            salida.insert(*it2);
            it1++;
            it2++;
        }else
        {
            it2++;
        } 
    }
    return salida;
}

int main()
{
    multiset<int> m1;
    m1.insert(2);m1.insert(2);m1.insert(2);
    m1.insert(3);m1.insert(3);
    multiset<int> m2;
    m2.insert(1);
    m2.insert(2);m2.insert(2);m2.insert(2);m2.insert(2);
    m2.insert(3);m2.insert(3);m2.insert(3);
    m2.insert(4);
    multiset<int> eskere;
    eskere=multi_interseccion(m1,m2);
    mostrarSet(eskere);
}