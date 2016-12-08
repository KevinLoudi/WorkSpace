#ifndef SSTACK_H_INCLUDED
#define SSTACK_H_INCLUDED

#include <iostream>
#include <stdexcept>
#include "ddlinklist.h"

namespace DataStructure
{
    template<typename T>
    class Sstack
    {
    public:
        Sstack(int space,const T& def);
        Sstack(const Sstack& other_stack);
        ~Sstack();
        Sstack<T>& operator=(const Sstack& other_stack);
        //read and write
        T top() const;
        T pop() {return data.removeTail();}
        bool push(const T& ele)
        //get status
        bool isEmpty() const {return data.isempty();}
        bool isFull() const {return max_size==data.size_();}
        int size_() const{return data.size_();}
        int capacity_() const {return max_size-data.size_();}

    private:
        //use the tail of list as top, add at last for each insertion
        DoubleLinkList<T> data;
        int max_size;
    };

    template class Sstack <std::string>;
    template class Sstack <int>;
    template class Sstack <float>;
    template class Sstack <char*>;

};

#endif // SSTACK_H_INCLUDED
