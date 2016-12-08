#include "sstack.h"

namespace DataStructure
{
    template<typename T>
    inline Sstack<T>::Sstack(const int space, const T& def): max_size(space),data(DoubleLinkList<T>(def))
    {

    }

    template<typename T>
    inline Sstack<T>::Sstack(const Sstack& other_stack): max_size(other_stack.max_size),data(other_stack.data)
    {

    }

    template<typename T>
    Sstack<T>::~Sstack()
    {

    }

    template<typename T>
    Sstack<T>& Sstack<T>::operator=(const Sstack& other_stack)
    {
        if(this==&other_stack)
        {
            return *this;
        }

        this->max_size=other_stack.max_size;
        this->data=other_stack.data; //it's deep copy because we have rewrite copy assignment for DoubleLinkList class
        return *this;
    }

    template<typename T>
    T Sstack<T>::top() const
    {
        return data.end_();
    }

};
