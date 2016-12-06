#ifndef BASIC_DATA_STRUCTURE_H_INCLUDED
#define BASIC_DATA_STRUCTURE_H_INCLUDED
#include <iostream>
#include <stdexcept>

namespace DataStructure
{
    //typedef int T; //replace the unfriendly template
    template<typename T>
    class Node
    {
    public:
        T element;
        Node<T>* next;

        Node() {next=NULL;} //no-arg constructor
        Node(const T& ele) // constructor
        {
            this->element=ele;
            next=NULL;
        }
    };

    template<typename T>
    class LinkList
    {
    public:
        LinkList();
        ~LinkList();
        std::ostream & print(std::ostream & ros) const;
        void addLast(const T& ele);
        void addFirst(const T& ele);
        void addix(const T& ele, const int ix);
        const T& getFirst() const {return head->element;}
        const T& getLast() const;
        const T& getix(const int ix) const; //enable random access
        T removeLast() throw (std::runtime_error);
        T removeFirst() throw (std::runtime_error);
        T removeix(const int ix) throw (std::runtime_error);
    private:
        Node<T> *head;
    };

    //add lines explicitly instantiating all the relevant templates
    template class LinkList<std::string>;
};

#endif // BASIC_DATA_STRUCTURE_H_INCLUDED
