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
        DoubleLinkList(T def);
        DoubleLinkList(const T* ele_arr, const int ele_size,T def); //initial list with an array of elements
        DoubleLinkList(const DoubleLinkList<T>& other_list);//copy constructor
        DoubleLinkList<T>& operator=(const DoubleLinkList<T>& other_list);//copy assignment
        ~DoubleLinkList();
        //add or set elements
        void addFirst(const T& ele);
        void addLast(const T& ele);
        bool addAt(const T& ele, const int ix);
        bool setAt(const T& ele, const int ix); //set value of node ix as ele
        bool setRange(const T* ele_arr, const int ele_size, const int start_ix);
        //remove elements
        T removeHead() throw (std::runtime_error); //remove the first element
        T removeTail() throw (std::runtime_error); //remove the last element
        T removeAt(const int ix) throw (std::runtime_error); //remove element at a specified position
        bool removeRange(const int lowix, const int highix) throw (std::runtime_error);
        int removeIf(const T& ele); //remove if the element exist
        void clear_() throw (std::runtime_error); //remove all elements
        //search elements
        int findAt(const T& ele) const; //return -1: No found, -2: empty list, [0,length-1]: the first found position
        //get info
        int size_() const {return length;} //return size of the list
        bool isempty() const {return head==NULL; } //see if it is an empty list
        std::ostream & print(std::ostream & ros) const;
        std::ostream & print_reverse(std::ostream & ros) const;
        //random access
        T getAt(const int ix) const; //get element of a specified position
        const T getPrev(const T& ele) const throw (std::runtime_error); //get the previous element before the specified element
        const T getNext(const T& ele) const throw (std::runtime_error);//get the following element after the specified element
        T begin_() const {return head->element;} //get head element
        T end_() const {return tail->element;} //get tail element
        T default_element;
    private:
        Dnode<T>* head;
        Dnode<T>* tail;
        int length;
        Dnode<T>* is_(const int pos) const; //return a node pointer to a specified position
    };

    template class DoubleLinkList <std::string>;
    template class DoubleLinkList <int>;
    template class DoubleLinkList <float>;
    template class DoubleLinkList <char*>;
};

#endif // DDLINKLIST_H_INCLUDED
