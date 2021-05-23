#include <stack>
#include <queue>
#include <iostream>
#include <cmath>

using namespace std;

int main(){

    string expresion="ab*b*d/e+";
    int val_a,val_b,val_c,val_d,val_e;

    double aux;

    //SOLUCION EXPRESION 1=134
    //SOLUCION EXPRESION 2=53
    //SOLUCION EXPRESION 3=207

    val_a=5;
    val_b=3;
    val_c=2;
    val_d=2;
    val_e=9;
    
    stack<double> num;

    for(int i=0;i<expresion.size();i++)
    {
        switch (expresion[i])
        {
            case 'a':
                num.push(val_a);
                break;
            case 'b':
                num.push(val_b);
                break;
            case 'c':
                num.push(val_c);
                break;
            case 'd':
                num.push(val_d);
                break;
            case 'e':
                num.push(val_e);
                break;
            case '+':
                aux=num.top();
                num.pop();
                aux=num.top()+aux;
                num.pop();
                num.push(aux);
                break;
            case '-':
                aux=num.top();
                num.pop();
                aux=num.top()-aux;
                num.pop();
                num.push(aux);
                break;
            case '*':
                aux=num.top();
                num.pop();
                aux=num.top()*aux;
                num.pop();
                num.push(aux);
                break;
            case '/':
                aux=num.top();
                num.pop();
                aux=num.top()/aux;
                num.pop();
                num.push(aux);
                break;
            case '^':
                aux=num.top();
                num.pop();
                aux=pow(num.top(),aux);
                num.pop();
                num.push(aux);
                break;
        }
    }
    cout << num.top() << endl;
}