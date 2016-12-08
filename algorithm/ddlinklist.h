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
        bool addAt(const T& ele, const int ix);
        T removeHead() throw (std::runtime_error);
        T removeTail() throw (std::runtime_error);
        //null implement

        bool removeAt(const int ix);
        bool setAt(const int ix);
        const T getAt(const int ix) const;
        int findAt(const T& ele) const;
        const T getPrev(const T& ele) const;
        const T getNext(const T& ele) const;


        T begin_() const {return head->element;}
        T end_() const {return tail->element;}
        bool isempty() const {return head==NULL; }
        std::ostream & print(std::ostream & ros) const;
        std::ostream & print_reverse(std::ostream & ros) const;
    private:
        Dnode<T>* head;
        Dnode<T>* tail;
        int length;
    };

    template class DoubleLinkList <std::string>;
    template class DoubleLinkList <int>;
    template class DoubleLinkList <float>;
    template class DoubleLinkList <char*>;
};

#endif // DDLINKLIST_H_INCLUDED
