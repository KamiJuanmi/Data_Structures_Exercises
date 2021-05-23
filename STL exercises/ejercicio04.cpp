#include <iostream>
#include <string>
#include <map>
#include <fstream>

using namespace std;

typedef map<string,int> dicc_Arch;
typedef multimap<int,string> dicc_Arch1;

dicc_Arch1 Swap(const dicc_Arch & encr)
{
    dicc_Arch1 aux;
    dicc_Arch::const_iterator it;
    for(it=encr.begin();it!=encr.end();it++)
    {
        aux.insert(dicc_Arch1::value_type(it->second,it->first));
    }
    return aux;
}

dicc_Arch extraerPalabras(string nom_arch)
{
    ifstream entrada(nom_arch);
    dicc_Arch ret;
    dicc_Arch::iterator it;
    string aux;
    while(!entrada.eof())
    {
        entrada>>aux;
        it=ret.find(aux);
        if( it==ret.end())
        {
            ret.insert(pair<string,int>(aux,1));
        }else
        {
            it->second++;
        }
        
    }
    entrada.close();
    return ret;
}

void mostrarMapa(const dicc_Arch1 & mapa)
{
    dicc_Arch1::const_iterator it;
    for(it=mapa.begin();it!=mapa.end();it++)
    {
        cout << it->first << "," << it->second << endl;
    }
}

dicc_Arch1 Obtener_N_Repetidas(const dicc_Arch &mapa, int n)
{
    dicc_Arch1 aux=Swap(mapa);
    dicc_Arch1 ret;
    pair<dicc_Arch1::iterator,dicc_Arch1::iterator>
    it=aux.equal_range(n);
    for(it.first;it.first!=it.second;it.first++)
    {
        ret.insert(dicc_Arch1::value_type(it.first->first,it.first->second));
    }
    return ret;
}

int main()
{
    string aux="prueba.txt"; //CREAR ARCHIVO QUE SE LLAME ASI
    dicc_Arch prueba=extraerPalabras(aux);
    dicc_Arch1 ejercicio=Obtener_N_Repetidas(prueba,3);
    mostrarMapa(ejercicio);
}