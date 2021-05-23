#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

typedef map<char *, char *> dicc_Arg;

void mostrarMapa(const dicc_Arg & mapa)
{
    dicc_Arg::const_iterator it;
    for(it=mapa.begin();it!=mapa.end();it++)
    {
        cout << "Activado:"<< it->first ;
        if(it->second==NULL)
        {
            cout << "\tSin ningun parametro" << endl;
        }
        else
        {
            cout << "\tCon el argumento: " << it->second << endl;
        }
        
    }
}

void parametros(int argc, char **argv)
{
    dicc_Arg aux;
    for (int i = 1; i < argc; i++)
    {
        if (i + 1 < argc)
        {
            if (argv[i + 1][0] != '-')
            {
                aux[argv[i]] = argv[i + 1];
                i++;
            }
            else
            {
               aux[argv[i]]=NULL; 
            }
        }
        else
        {
            aux[argv[i]]=NULL;
        }
        
    }
    mostrarMapa(aux);
    
}

int main(int argc, char**argv)
{
    parametros(argc,argv);
}