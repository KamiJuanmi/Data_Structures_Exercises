#include <iostream>
#include <string>
#include <list>

using namespace std;

int orden(const list<int> &L)
{
    if(L.size() <2)
    {
        return 0;
    }
    else
    {
        int resultado=-1;
        list<int>::const_iterator it1=L.cbegin();
        list<int>::const_iterator it2=it1;
        it2++;
        while(it2!=L.cend())
        {
            if(*(it1) > *(it2))
            {
                if(resultado==-1)
                {
                    resultado=2;
                }else if(resultado!=2)
                {
                    return 0;
                }
            }else if(*(it1) < *(it2))
            {
                if(resultado==-1)
                {
                    resultado=1;
                }else if(resultado!=1)
                {
                    return 0;
                }
            }
            it1++;
            it2++;
        }
        if(resultado==-1)
        {
            resultado=0;
        }
        return resultado;

    }
    
}