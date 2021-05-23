#include <iostream>
#include <string>
#include <vector>

using namespace std;

template <typename T>
void mostrar_vector(const vector<T> & v)
{
    for(typename vector<T>::const_iterator it=v.cbegin();it!=v.cend();it++)
    {
        cout << (*it) << " ";
    }
    cout << endl;
}

template <typename T>
void intercalar(vector<T> &v, vector<pair<int,T>> pos)
{
    for(typename vector<pair<int,T>>::const_iterator it=pos.cbegin();it!=pos.cend();it++)
    {
        v[(*it).first]=(*it).second;
    }
};

int main()
{
    vector<pair<int,char>> prueba;
    prueba.push_back(make_pair(2,'a'));
    prueba.push_back(make_pair(0,'b'));
    prueba.push_back(make_pair(3,'c'));
    prueba.push_back(make_pair(1,'d'));
    prueba.push_back(make_pair(4,'e'));
    vector<char> ret(5);
    intercalar(ret,prueba);
    mostrar_vector(ret);

}