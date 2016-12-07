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
        //clearlist(); //clear list in destructor
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
    void LinkList<T>::addFirst(const T& ele)
    {
        if(head==NULL)
        {
            //update head node from NULL to a new node
            head=new Node<T>(ele);
        }
        else
        {
            Node<T>* pnode=new Node<T>(ele);
            Node<T>* tmp=head; //save the old head
            head=pnode; //update head and link with the old head
            head->next=tmp;
        }
    }

    template<typename T>
    std::ostream & LinkList<T>::print(std::ostream & ros) const
    {
        Node<T>* pnode=head;
        if(pnode==NULL)
        {
            ros<<"empty list"<<std::endl;
            ros<<"current list length: "<<getsize()<<std::endl;
            return ros;
        }
        //find the tail of the list
        ros<<pnode->element<<std::endl;
        while(pnode->next!=NULL)
        {
            pnode=pnode->next;
            ros<<pnode->element<<std::endl;
        }
        ros<<"current list length: "<<getsize()<<std::endl;
        return ros;
    }

    template<typename T>
    std::ostream & LinkList<T>::print_reverse_helper(std::ostream & ros, const int ix) const
    {
        Node<T>* pnode=getHead(); //get address of the head
        int ixx=ix;
        //move to the element at the given ix
        while((ixx--)!=0 && pnode->next!=NULL)
        {
            pnode=pnode->next;
        }
        return print_reverse(ros, pnode);
    }

    template<typename T>
    std::ostream & LinkList<T>::print_reverse(std::ostream & ros,Node<T>* pnode) const
    {
        if(pnode==NULL) return ros;
        print_reverse(ros,pnode->next); //recurse until find the tail
        ros<<pnode->element<<std::endl; //print elements from tail to original pnode
        return ros;
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
    Node<T>* LinkList<T>::getTail() const
    {
        Node<T>* pnode=head;
        //move backward until reach the tail
        while(pnode->next!=NULL)
        {
            pnode=pnode->next;
        }
        return pnode;
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
         const Node<T>* cur=head; //cur will point to the would-be accessed element
         for(int i=0; i<ix; ++i) //oo2ooo-->0[pnode][cur]000-->0[pnode][nnode][cur]000
         {
            cur=cur->next;
         }
         return cur->element;
     }

     template<typename T>
     int LinkList<T>::getLen() const
     {
         const Node<T>* phead=head;
         //const Node<T>* ptail=getTail();
         int count_=0;
         //count until reach NULL
         for(const Node<T>* pnode=phead; pnode!=NULL; pnode=pnode->next, ++count_);
         return count_;
     }

     template<typename T>
     int LinkList<T>::searchix(const T& ele) const
     {
         int ix=0;
         const Node<T>* cur=head; //cur will point to the would-be accessed element
         while((cur->next!=NULL)&&(cur->element!=ele))
         {
             cur=cur->next;
             ++ix;
         }

         if(cur->next==NULL)
         {
             return -1;
         }
         else
         {
             return ix;
         }
     }

     template<typename T>
     bool LinkList<T>::clearlist() throw (std::runtime_error)
     {
         if(head==NULL)
         {
             throw std::runtime_error("cannot clear an empty list");
         }

         Node<T>* pnode=head;
         Node<T>* cur=pnode;
         //release all memory allocated for list except the tail element
         while(pnode->next!=NULL)
         {
            cur=pnode;
            pnode=pnode->next;
            delete cur;
         }
         //release the tail element, the list become empty
         delete pnode;
         head=NULL;
         return true;
     }

     template<typename T>
     int LinkList<T>::getsize() const
     {
         int count_=0;
         if(head==NULL)
         {
             return count_;
         }
         const Node<T>* pnode=head;
         ++count_;
         for(; pnode->next!=NULL; pnode=pnode->next, ++count_);
         return count_;
     }

     template<typename T>
     void LinkList<T>::reverselist()
     {
         if((head==NULL) || (head->next=NULL))
         {
             //do nothing for empty list or a list with only one element
             return;
         }
         Node<T>* curr=head;
         Node<T>* prev=NULL;
         Node<T>* next=NULL;

         while(curr!=getTail()) //break when reach tail
         {
             next=curr->next; //save the original linked node
             curr->next=prev; //reverse link to the previous node

             head=curr; //update head

             prev=curr; //move curr and prev backward
             curr=next;
         }

         /*for(Node<T>* pnode=head; ; prev=pnode, pnode=curr)
         {
             curr=pnode->next;
             pnode->next=prev;
             if(curr==NULL)
             {
                 head=pnode;
                 break;
             }
         }*/
         /*while(curr!=NULL)// 0000 prev next tmp
         {
             Node<T>* tmp=curr->next;
             curr->next=prev; //do reverse
             head=curr; //update head
             //continuing move backward
             prev=curr;
             curr=tmp;
         }*/
     }
};
