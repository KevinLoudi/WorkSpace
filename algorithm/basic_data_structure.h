#ifndef BASIC_DATA_STRUCTURE_H_INCLUDED
#define BASIC_DATA_STRUCTURE_H_INCLUDED
#include <iostream>

namespace DataStructure
{
    typedef int T; //replace the unfriendly template

    struct Node
    {
        T data;
        Node* next;
    };

    class LinkList
    {
    private:
        Node* head;
        //Node* tail;
        int length;
        Node* getNode(const int ix) const;
    public:
       LinkList();
       ~LinkList();
       std::ostream & print(std::ostream & ros) const;
       T get(int ix) const;
       bool add(const T data, const int ix);
       void addFirst(T data);
       void addLast(T data);
       T remove_(int ix);
       T removeFirst();
       T removeLast();
       int size_() const;
    };

};

#endif // BASIC_DATA_STRUCTURE_H_INCLUDED
