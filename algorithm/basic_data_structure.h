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

    template class Node <std::string>;
    template class Node <int>;
    template class Node <float>;
    template class Node <char*>;

    template<typename T>
    class LinkList
    {
    public:
        LinkList();
        ~LinkList();
        std::ostream & print(std::ostream & ros) const;
        std::ostream & print_reverse_helper(std::ostream & ros, const int ix) const;
        std::ostream & print_reverse(std::ostream & ros,Node<T>* pnode) const;
        void addLast(const T& ele);
        void addFirst(const T& ele);
        void addix(const T& ele, const int ix);
        Node<T>* getHead() const {return head;} //return head or tail pointer to the class outside
        Node<T>* getTail() const;
        const T& getFirst() const {return head->element;} //access first, last and random
        const T& getLast() const;
        const T& getix(const int ix) const; //enable random access
        int getLen() const;
        T removeLast() throw (std::runtime_error); //remove first. last and random
        T removeFirst() throw (std::runtime_error);
        T removeix(const int ix) throw (std::runtime_error);
        int searchix(const T& ele) const; //search the index of an element
        bool isempty() const {return head==NULL;}
        int getsize() const;
        bool clearlist() throw (std::runtime_error); //delete the list
        //cannot revers, segment fault
        void reverselist();

    private:
        Node<T> *head;
    };

    //add lines explicitly instantiating all the relevant templates
    template class LinkList<std::string>;
    template class LinkList<int>;
    template class LinkList<float>;
    template class LinkList<char*>;
};

#endif // BASIC_DATA_STRUCTURE_H_INCLUDED
