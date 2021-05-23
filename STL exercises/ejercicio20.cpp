#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

typedef map<pair<float,float>, int> dicc_Coord;

void mostrar_map(const dicc_Coord & mapa)
{
    dicc_Coord::const_iterator it;
    for(it=mapa.begin();it!=mapa.end();it++)
    {
        cout << "Coordenadas:"<< it->first.first << " " << it->first.second ;
        cout << "\tAparecen:" << it->second;
        cout << endl;
    }
}


int main()
{
    pair<float,float> coord;
    dicc_Coord prueba;
    do{
        cin>>coord.first;
        cin>>coord.second;
        prueba[coord]+=1;
    }while(coord.first!=-1 && coord.second!=-1);
    prueba.erase(coord);

    mostrar_map(prueba);

}