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
    inline T Sstack<T>::top() const
    {
        if(isEmpty()) return data.default_element;
        return data.end_();
    }

    template<typename T>
    inline bool Sstack<T>::push(const T& ele)
    {
        if(isFull()) return false;
        data.addLast(ele); //automatic add 1 in list
        return true;
    }

    template<typename T>
    inline std::ostream & Sstack<T>::printInfo(std::ostream & ros) const
    {
        ros<<"Stack Information:\t\n"<<"Current Size:\t "<<size_()
            <<" Capacity:\t "<<capacity_()<<"\nElements:\t ";
        //there is a problem, I can not chain the output of following line with first line
        //it works when I separate them
        ros<<data.print_reverse(ros);
        return ros;
    }

};
