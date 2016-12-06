#include "basic_data_structure.h"
#include <iostream>

namespace DataStructure
{
    template<typename T>
    LinkList<T>::LinkList()
    {
        head=NULL;
    }

    template<typename T>
    LinkList<T>::~LinkList()
    {

    }

    template<typename T>
    void LinkList<T>::addLast(const T& ele)
    {
        if(head==NULL)
        {
            //update head node from NULL to a new node
            head=new Node<T>(ele);
        }
        else
        {
            Node<T>* pnode=head;
            //find the tail of the list
            while(pnode->next!=NULL)
            {
                pnode=pnode->next;
            }
            //add a new node
            pnode->next=new Node<T>(ele);
        }
    }

    template<typename T>
    std::ostream & LinkList<T>::print(std::ostream & ros) const
    {
        Node<T>* pnode=head;
        if(pnode==NULL)
        {
            ros<<"empty list"<<std::endl;
            return ros;
        }
        //find the tail of the list
        ros<<pnode->element<<std::endl;
        while(pnode->next!=NULL)
        {
            pnode=pnode->next;
            ros<<pnode->element<<std::endl;
        }
        return ros;
    }

    template<typename T>
    void LinkList<T>::addFirst(const T& ele)
    {
         if(head==NULL)
        {
            //update head node from NULL to a new node
            head=new Node<T>(ele);
        }
        else
        {
            Node<T>* nnode=new Node<T>(ele);
            //let original head be the next, update head
            nnode->next=head;
            head=nnode;
        }
    }

    template<typename T>
    const T& LinkList<T>::getLast() const
    {
        Node<T>* pnode=head;
        //find the tail
        for(; pnode->next!=NULL; pnode=pnode->next);
        return pnode->element;
    }

    template<typename T>
    T LinkList<T>::removeLast() throw (std::runtime_error)
    {
        Node<T>* pnode=head;
        if(pnode==NULL)
        {
            throw std::runtime_error("cannot remove empty list.");
        }
        else if(pnode->next==NULL)
        {
            T ele=pnode->element;
            head=NULL;
            delete pnode;
            return ele;
        }
        else
        {
            Node<T>* cur=pnode; //cur will point to one element behind pnode
            for(; pnode->next!=NULL; cur=pnode, pnode=pnode->next);
            T ele=pnode->element;
            delete pnode;
            cur->next=NULL; //cur become the new tail
            return ele;
        }
    }

    template<typename T>
    T LinkList<T>::removeFirst() throw (std::runtime_error)
    {
        Node<T>* pnode=head;
        if(pnode==NULL)
        {
            throw std::runtime_error("cannot remove empty list.");
        }
        else
        {
            T ele=head->element;
            head=head->next; //update head
            delete pnode;//delete the original head
            return ele;
        }
    }

    template<typename T>
    void LinkList<T>::addix(const T& ele, const int ix)
    {
        Node<T>* pnode=head;
        int count_=0; //count elements num in the list
        //count element number if it is not an empty list
        if(pnode!=NULL)
        {
            for(; pnode->next!=NULL; pnode=pnode->next, ++count_);
        }
        if(ix>=count_||count_==0)
        {
            addLast(ele); //if the insert position is quite backward, insert at the last
        }
        else if(ix<=0)
        {
            addFirst(ele); //if the list is empty or insert position is forward
        }
        else
        {
            Node<T>* cur=head;
            for(int i=0; i<ix; ++i) //oo2ooo-->0[pnode][cur]000-->0[pnode][nnode][cur]000
            {
                pnode=cur; //the previous element
                cur=cur->next;
            }
            Node<T>* nnode=new Node<T>(ele);
            nnode->next=cur;
            pnode->next=nnode;
        }
    }

     template<typename T>
     T LinkList<T>::removeix(const int ix) throw (std::runtime_error)
     {
        Node<T>* pnode=head;
        T ele;
        int count_=0; //count elements num in the list
        //count element number if it is not an empty list
        if(pnode!=NULL)
        {
            for(; pnode->next!=NULL; pnode=pnode->next, ++count_);
            pnode=head;
        }
        if(count_==0)
        {
            throw std::runtime_error("cannot delete an empty list");
        }

        if(ix<=0)
        {
            ele=removeFirst();
        }
        else if(ix>=count_)
        {
            ele=removeLast();
        }
        else
        {
            Node<T>* cur=head; //cur will point to the would-be delete element
            for(int i=0; i<ix; ++i) //oo2ooo-->0[pnode][cur]000-->0[pnode][nnode][cur]000
            {
                pnode=cur; //the previous element
                cur=cur->next;
            }

            ele=cur->element;
            pnode->next=cur->next;
            delete cur;
        }
        return ele;
     }

     template<typename T>
     const T& LinkList<T>::getix(const int ix) const
     {
         Node<T>* cur=head; //cur will point to the would-be accessed element
         for(int i=0; i<ix; ++i) //oo2ooo-->0[pnode][cur]000-->0[pnode][nnode][cur]000
         {
            cur=cur->next;
         }
         return cur->element;
     }
};
