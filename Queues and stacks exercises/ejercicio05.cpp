#include <stack>
#include <queue>
#include <iostream>

using namespace std;

template <typename T>

class stack2{
    private:
        queue<T> colas[2];
    public:
        //Vacio
        bool empty() const{
            return this->colas[0].empty() && this->colas[1].empty();
        }
        //Tamaño
        int size() const{
            return max(this->colas[0].size(), this->colas[1].size());
        }
        //Top
        const T& top() const{
            if(this->colas[0].empty()){

                return this->colas[1].front();

            }else if(this->colas[1].empty()){

                return this->colas[0].front();

            }
            
        }
        //Push
        void push(const T & nuevo){
            int i=-1,j;
            if(this->colas[0].empty()){
                i=1;
                j=0;
                this->colas[0].push(nuevo);
            }else if(this->colas[1].empty())
            {
                i=0;
                j=1;
                this->colas[1].push(nuevo);
            }else
            {
                this->colas[0].push(nuevo);
            }
            if(i!=-1){
                while(!this->colas[i].empty()){
                    this->colas[j].push(this->colas[i].front());
                    this->colas[i].pop();
                }
            }
            //TIENE UN ORDEN DE EFICIENCIA DE N
        }
        //Pop
        void pop(){
            if(this->colas[0].empty()){

                this->colas[1].pop();

            }else if(this->colas[1].empty()){

                this->colas[0].pop();

            }
        }
        //TIENE UN ORDEN DE EFICIENCIA DE 1
};

int main(){
    stack<int> una;

    una.push(5);
    una.push(7);
    una.push(3);
    una.push(5);
    una.push(8);
    una.push(3);

    while(!una.empty())
    {
        cout<<una.top()<<" ";
        una.pop();
    }
    cout << endl;
    stack2<int> otro;

    otro.push(5);
    otro.push(7);
    otro.push(3);
    otro.push(5);
    otro.push(8);
    otro.push(3);
    cout << otro.size() << endl;

    while(!otro.empty())
    {
        cout<<otro.top()<<" ";
        otro.pop();
    }
}