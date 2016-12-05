#include "basic_data_structure.h"
#include <iostream>

namespace DataStructure
{
    LinkList::LinkList()
    {
        head=NULL;
        length=0;
    }

    LinkList::~LinkList()
    {
        //delete all elements of the link list
    }

    std::ostream & LinkList::print(std::ostream & ros) const
    {
        Node* tmp=head;
        //read out node one by one
        if(head==NULL)
        {
            ros<<"empty list"<<std::endl;
        }
        else
        {
            /*for(; tmp->next==NULL; tmp=tmp->next)
            {
                ros<<tmp->data<<std::endl;
            } */
          int len=length;
          while(len!=0||tmp==NULL)
          {
              ros<<tmp->data<<std::endl;
              tmp=tmp->next;
              len--;
          }
        }
        return ros;
    }

    Node* LinkList::getNode(const int ix) const
       {
            if(ix<0||ix>length)
                 return NULL;
            else
            {
                Node *tmp=head->next;
                for(int i=0; i<ix; i++, tmp=tmp->next);
                return tmp;
            }
        }

    void LinkList::addLast(T data)
    {
        //initial a new node
        Node *node= new Node;
        node->next=NULL;
        node->data=data;

        //add the new node at the tail and update the tail
        Node* tmp=head;

        if(head==NULL) //(length==0)
        {
            head=node; //link list is waiting to be initialized
            length++;
        }
        else
        {
            //find the tail
            while(tmp->next != NULL)
            {
                tmp=tmp->next;
            }
            tmp->next=node;
            length++;
        }
    }

    bool add(const T* data, const int ix)
    {
        //if()
        return true;
    }
};
