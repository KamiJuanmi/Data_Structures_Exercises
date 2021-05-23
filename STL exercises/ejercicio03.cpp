#include <iostream>
#include <string>
#include <map>
#include <fstream>

using namespace std;

typedef map<string,int> dicc_Arch;

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

void mostrarMapa(const dicc_Arch & mapa)
{
    dicc_Arch::const_iterator it;
    for(it=mapa.begin();it!=mapa.end();it++)
    {
        cout << it->first << "," << it->second << endl;
    }
}

int main()
{
    string aux="prueba.txt"; //CREAR ARCHIVO QUE SE LLAME ASI
    dicc_Arch prueba=extraerPalabras(aux);
    mostrarMapa(prueba);
}