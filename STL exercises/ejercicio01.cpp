#include <iostream>
#include <string>
#include <map>

using namespace std;

typedef map<char,char> encrypted;

const int Tam_ABC = 26;

string encripta(const string base, encrypted encr)
{
    encrypted::iterator it;
    string ret;

    for(int i=0;i<base.size();i++)
    {
        it = encr.find(base[i]);
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

    string pass="RatillaDifusing";

    string pass_enc=encripta(pass,encr);

    cout << pass_enc << endl;

}