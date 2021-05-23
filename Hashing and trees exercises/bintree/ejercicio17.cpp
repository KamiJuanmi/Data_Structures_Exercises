#include "bintree.h"
#include <iostream>
#include <list>
#include <vector>

using namespace std;

template <class T>
class hash_table
{
private:
    vector<list<T>> fondo;

public:
    class iterador
    {
    private:
        typename list<T>::iterator it_list;
        int pos_vector;
        list<T> aux;

    public:
        iterador &operator++();
        iterador &operator--()
        {
            if (it_list == fondo[pos_vector].begin())
            {
                assert(pos_vector == 0);
                pos_vector--;
                it_list = fondo[pos_vector].end();
            }
            it_list--;
            return *this;
        }
        bool operator==(const iterador &otro) const;
        bool operator!=(const iterador &otro) const;
        T &operator*();
        iterador &operator=(const iterador &otro);

        friend class hash_table<T>;
    };
    iterador begin()
    {
        iterador i;
        i.pos_vector = 0;
        i.it = fondo.front().begin();

        return i;
    };
    iterador end()
    {
        iterador i;
        i.pos_vector = fondo.size() - 1;
        i.it = fondo.back().end();
    };
};

int main()
{
}