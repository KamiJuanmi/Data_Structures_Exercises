#include <stack>
#include <queue>
#include <iostream>

using namespace std;

template <typename T>

class queue2{

    private:
        stack<T> frente;
        stack<T> atras;

    public:
        //vacio
        bool empty() const{
            return this->frente.empty();
        }
        //tamaño
        int size() const{
            return this->frente.size();
        }
        //front
        const T& front() const {
            return this->atras.top();
        }
        //back
        const T& back() const {
            return this->frente.top();
        }
        //push
        void push(const T & nuevo){
            this->frente.push(nuevo);
            stack<T> aux,aux2;
            aux2=this->frente;
            while(!aux2.empty()){
                aux.push(aux2.top());
                aux2.pop();
            }
            this->atras=aux;
        }
        //pop
        void pop(){
            this->atras.pop();
            stack<T> aux,aux2;
            aux2=this->atras;
            while(!aux2.empty()){
                aux.push(aux2.top());
                aux2.pop();
            }
            this->frente=aux;
        }
};

int main(){
    queue<int> una;

    una.push(5);
    una.push(7);
    una.push(3);
    una.push(5);
    una.push(8);
    una.push(3);

    while(!una.empty())
    {
        cout<<una.front()<<" ";
        una.pop();
    }
    cout << endl;
    queue2<int> otro;

    otro.push(5);
    otro.push(7);
    otro.push(3);
    otro.push(5);
    otro.push(8);
    otro.push(3);
    cout << otro.size() << endl;

    while(!otro.empty())
    {
        cout<<otro.front()<<" ";
        otro.pop();
    }
}