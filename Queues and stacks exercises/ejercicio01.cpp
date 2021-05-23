#include <stack>
#include <iostream>

using namespace std;

template<typename T>
void sustituye(stack<T> & P, T x, T y){
        stack<T> aux;
        T ayuda;
        while(!P.empty()) {
                ayuda=P.top();
                P.pop();
                if(ayuda == x) {
                        aux.push(y);
                }else
                {
                        aux.push(ayuda);
                }

        }
        while(!aux.empty()) {
                P.push(aux.top());
                aux.pop();
        }
}

int main(){
        stack<char> una;

        una.push('e');
        una.push('i');
        una.push('a');
        una.push('o');
        una.push('a');
        una.push('a');

        sustituye(una, 'a', 'e');

        while(!una.empty())
        {
                cout<<una.top()<<" ";
                una.pop();
        }
}
