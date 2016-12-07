#ifndef DDLINKLIST_H_INCLUDED
#define DDLINKLIST_H_INCLUDED

#include <iostream>
#include <stdexcept>

namespace DataStructure
{
    template<typename T>
    class Dnode
    {
    public:
        T element;
        Dnode<T>* next;
        Dnode<T>* prev;

        Dnode() {next=NULL; prev=NULL;} //no-arg constructor
        Dnode(const T& ele) // constructor
        {
            this->element=ele;
            next=NULL;
            prev=NULL;
        }
    };

    template class Dnode <std::string>;
    template class Dnode <int>;
    template class Dnode <float>;
    template class Dnode <char*>;

    template<typename T>
    class DoubleLinkList
    {
    public:
        DoubleLinkList();
        ~DoubleLinkList();
        void addFirst(const T& ele);
        void addLast(const T& ele);
        bool isempty() const {return head==NULL; }
        std::ostream & print(std::ostream & ros) const;
    private:
        Dnode<T>* head;
        Dnode<T>* tail;
        int length;
    };

    template class DoubleLinkList <std::string>;
};

#endif // DDLINKLIST_H_INCLUDED
