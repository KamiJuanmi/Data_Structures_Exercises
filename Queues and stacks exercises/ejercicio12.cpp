#include <stack>
#include <queue>
#include <iostream>

using namespace std;

class comp{
    public:

    bool operator() (string a, string b)
    {
        if(a.size() == b.size()){
            return a>b;
        }
        else
        {
            return a.size() < b.size();
        }
        
    }
};

int main(){
    priority_queue<string, vector<string>, comp> pq;

    string A="Hola mundo.";
    string B="Hello world";
    string C="Adios pedro";
    string D="Salut monde.";

 
    pq.push(A);
    pq.push(B);
    pq.push(C);
    pq.push(D);

    while(!pq.empty()){
        cout << pq.top() << "--------con longitud: " << pq.top().size() << endl;
        pq.pop();
    }
}