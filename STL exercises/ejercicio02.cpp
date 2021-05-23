#include <iostream>
#include <string>
#include <map>

using namespace std;

typedef map<char,char> encrypted;

const int Tam_ABC = 26;

void Swap(encrypted & encr)
{
    encrypted aux;
    encrypted::iterator it;
    for(it=encr.begin();it!=encr.end();it++)
    {
        aux.insert(encrypted::value_type(it->second,it->first));
    }
    encr=aux;
}

string Desencripta(const string base, encrypted encr)
{
    encrypted::iterator it;
    string ret;
    Swap(encr);

    for(int i=0;i<base.size();i++)
    {
        it=encr.find(base[i]);
        ret += it->second;
    }

    return ret;
}

void construirEnc(encrypted & encr)
{
    for(int i=0;i<Tam_ABC;i++)
    {
        encr.insert(encrypted::value_type('A'+i,'z'-i));
        encr.insert(encrypted::value_type('a'+i,'Z'-i));
    }
}

int main()
{
    encrypted encr;

    construirEnc(encr);
    encrypted::iterator it;

    string pass="iZGROOZwRUFHRMT";

    string pass_enc=Desencripta(pass,encr);

    cout << pass_enc << endl;

}