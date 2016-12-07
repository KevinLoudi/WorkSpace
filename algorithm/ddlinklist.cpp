#include "ddlinklist.h"

namespace DataStructure
{
    template<typename T>
    DoubleLinkList<T>::DoubleLinkList()
    {
        head=tail=NULL;
        length=0;
    }

    template<typename T>
    DoubleLinkList<T>::~DoubleLinkList()
    {

    }

    template<typename T>
    void DoubleLinkList<T>::addFirst(const T& ele)
    {
        if(isempty())
        {
            head=tail=new Dnode<T>(ele);
            length++;
        }
        else
        {
            Dnode<T>* pnode=new Dnode<T>(ele);
            pnode->next=head;
            pnode->prev=NULL;
            head=pnode;
            length++;
        }
    }

    template<typename T>
    void DoubleLinkList<T>::addLast(const T& ele)
    {
       if(isempty())
        {
            head=tail=new Dnode<T>(ele);
            length++;
        }
        else
        {
            Dnode<T>* pnode=new Dnode<T>(ele);
            pnode->next=NULL;
            pnode->prev=tail;
            tail=pnode;
            length++;
        }
    }

    template<typename T>
    std::ostream & DoubleLinkList<T>::print(std::ostream & ros) const
    {
        if(isempty())
        {
            ros<<"empty list"<<std::endl;
            return ros;
        }
        Dnode<T>* pnode=head;
        ros<<"list length: "<<length<<std::endl;
        //traversal elements backwards
        do
        {
            ros<<pnode->element<<std::endl;
            pnode=pnode->next;
        }while(pnode!=tail->next); //
        return ros;
    }
};
