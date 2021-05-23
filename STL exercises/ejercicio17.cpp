#include <iostream>
#include <string>
#include <list>

using namespace std;

template <typename T>
class vector_dinamico
{
private:
    list<T> fondo;

public:
    class iterador
    {
    private:
        typename list<T>::iterator it;

    public:
        iterador &operator++()
        {
            it++;
            return *this;
        };
        iterador &operator--()
        {
            it--;
            return *this;
        };
        bool operator==(const iterador &otro) const
        {
            return it == otro.it;
        };
        bool operator!=(const iterador &otro) const
        {
            return it != otro.it;
        };
        T &operator*()
        {
            return *it;
        };
        iterador &operator=(const iterador &otro)
        {
            this->it = otro.it;
            return *this;
        };

        friend class vector_dinamico<T>;
    };

    class const_iterador
    {
    private:
        typename list<T>::const_iterator it;

    public:
        const_iterador &operator++()
        {
            it++;
            return *this;
        };

        const_iterador &operator--()
        {
            it--;
            return *this;
        };

        bool operator==(const const_iterador &otro) const
        {
            return it == otro.it;
        };

        const T &operator*() const
        {
            return *it;
        };

        bool operator!=(const const_iterador &otro) const
        {
            return it != otro.it;
        };

        friend class vector_dinamico<T>;
    };
    vector_dinamico() = default;
    const T &back() const;
    T &back();
    int size() const;
    void push_back(const T &);
    void pop_back();
    const T &operator[](int) const;
    T &operator[](int);
    iterador erase(iterador);
    bool empty() const;
    iterador insert(iterador, const T &);
    void clear();
    void resize(size_t n, T val=T());

    iterador begin()
    {
        iterador i;
        i.it = fondo.begin();

        return i;
    };

    iterador end()
    {
        iterador i;
        i.it = fondo.end();

        return i;
    };

    const_iterador cbegin() const
    {
        const_iterador i;
        i.it = fondo.cbegin();

        return i;
    };

    const_iterador cend() const
    {
        const_iterador i;
        i.it = fondo.cend();

        return i;
    };
};

template <typename T>
ostream &operator<<(ostream &f, const vector_dinamico<T> &vec)
{
    typename vector_dinamico<T>::const_iterador it;
    for(it=vec.cbegin();it!=vec.cend();++it)
    {
        f << (*it) << " ";
    }
    f << endl;
    return f;
}

template <typename T>
const T &vector_dinamico<T>::back() const
{
    return this->fondo.back();
}

template <typename T>
T &vector_dinamico<T>::back()
{
    return this->fondo.back();
}

template <typename T>
int vector_dinamico<T>::size() const
{
    return this->fondo.size();
}

template <typename T>
void vector_dinamico<T>::push_back(const T &x)
{
    this->fondo.push_back(x);
}

template <typename T>
void vector_dinamico<T>::pop_back()
{
    this->fondo.pop_back();
}

template <typename T>
const T &vector_dinamico<T>::operator[](int pos) const
{
    typename list<T>::const_iterator it=this->fondo.begin();
    int i=0;
    while(i<pos)
    {
        it++;
        i++;
    }
    return *it;
}

template <typename T>
T& vector_dinamico<T>::operator[](int pos)
{
    typename list<T>::iterator it=this->fondo.begin();
    int i=0;
    while(i<pos)
    {
        it++;
        i++;
    }
    return *it;
}

template <typename T>
typename vector_dinamico<T>::iterador vector_dinamico<T>::erase(iterador it)
{
    typename list<T>::iterator aux;
    aux=this->fondo.erase(it.it);
    iterador ret;
    ret.it=aux;
    return ret;
}

template <typename T>
bool vector_dinamico<T>::empty() const
{
    return this->fondo.empty();
}

template <typename T>
typename vector_dinamico<T>::iterador vector_dinamico<T>::insert(iterador it, const T &nuevo)
{
    typename list<T>::iterator aux;
    aux=it.it;
    aux=this->fondo.insert(aux,nuevo);
    iterador ret;
    ret.it=aux;
    ++ret;
    return ret;
}

template <typename T>
void vector_dinamico<T>::clear()
{
    this->fondo.clear();
}

template <typename T>
void vector_dinamico<T>::resize(size_t n, T val)
{
    this->fondo.resize(n,val);
}

int main(){
    vector_dinamico<int> prueba1;
    prueba1.push_back(8);
    vector_dinamico<int>::iterador it;
    it=prueba1.begin();
    ++it;
    for(int i=0;i<5;i++)
    {
        it=prueba1.insert(it,i);
    }
    cout << "PRIMERA PRUEBA DE INSERT ->" << prueba1;
    prueba1.pop_back();
    cout << "PRUEBA DE POP_BACK ->" << prueba1;
    prueba1.clear();
    cout << "PRUEBA DE CLEAR ->"<< prueba1;
    prueba1.resize(10);
    for(int i=0;i<10;i++)
    {
        prueba1[i]=i;
    }
    cout << "INTRODUCCION CON []->" << prueba1;
    it=prueba1.begin();
    for(int i=90;i<95;i++)
    {
        it=prueba1.insert(it,i);
        ++it; //PARA INTRODUCIR SALTEADO
    }
    cout << "SEGUNDA PRUEBA DE INSERT ->" <<  prueba1;
    it=prueba1.begin();
    for(it;it!=prueba1.end();)
    {
        it=prueba1.erase(it);
    }
    cout << "PRUEBA DE ERASE ->"<< prueba1 ;
}