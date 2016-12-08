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
            //pnode<=>head
            pnode->next=head;
            head->prev=pnode;

            //pnode->prev=NULL;
            //update head
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
            //pnode->next=NULL;
            //tail<=>pnode
            tail->next=pnode;
            pnode->prev=tail;
            //update tail
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
        ros<<"ordered print\n list length: "<<length<<std::endl;
        //traversal elements backwards
        do
        {
            ros<<pnode->element<<std::endl;
            pnode=pnode->next;
        }while(pnode!=NULL); //
        return ros;
    }

    template<typename T>
    std::ostream & DoubleLinkList<T>::print_reverse(std::ostream & ros) const
    {
        if(isempty())
        {
            ros<<"empty list"<<std::endl;
            return ros;
        }
        Dnode<T>* pnode=tail;
        ros<<"reversed print\n list length: "<<length<<std::endl;
        //traversal elements backwards
        do
        {
            ros<<pnode->element<<std::endl;
            pnode=pnode->prev;
        }while(pnode!=NULL); //
        return ros;
    }

    template<typename T>
    bool DoubleLinkList<T>::addAt(const T& ele, const int ix)
    {
        if(ix>length) {addLast(ele);return true;}
        else if (ix<=0) {addFirst(ele); return true;}
        int ixx=ix;
        Dnode<T>* pnode=NULL;
        if(ixx>length/2)
        {
            //start search from head
            pnode=head;
            while((--ixx)!=0)
            {
                pnode=pnode->next;
            }
        }
        else
        {
            //start search from tail
            pnode=tail;
            while((--ixx)!=0)
            {
                pnode=pnode->prev;
            }
        }

        Dnode<T>* anode=new Dnode<T>(ele);
        Dnode<T>* prev=pnode->prev;
        //prev<=>anode<=>pnode
        anode->next=pnode;
        anode->prev=prev;

        prev->next=anode;
        pnode->prev=anode;

        length++;
        return true;
    }

    template<typename T>
    T DoubleLinkList<T>::removeHead() throw (std::runtime_error)
    {
        if(isempty()) throw std::runtime_error("cannot remove an empty list.");
        else if (length==1)
        {
            //delete the head/tail node and return its value
            Dnode<T>* pnode=head;
            T ele=head->element;
            head=tail=NULL;
            delete pnode;
            --length;
            return ele;
        }
        else
        {
            Dnode<T>* pnode=head;
            Dnode<T>* pnext=head->next;
            T ele=head->element;

            head->next=NULL;
            pnext->prev=NULL;
            head=pnext;

            delete pnode;
            --length;
            return ele;
        }
    }

    template<typename T>
    T DoubleLinkList<T>::removeTail() throw (std::runtime_error)
    {
        if(isempty()) throw std::runtime_error("cannot remove an empty list.");
        else if (length==1)
        {
            //delete the head/tail node and return its value
            Dnode<T>* pnode=head;
            T ele=head->element;
            head=tail=NULL;
            delete pnode;
            --length;
            return ele;
        }
        else
        {
            Dnode<T>* pnode=tail;
            Dnode<T>* pprev=tail->prev;
            ///.unfinished
            T ele=tail->element;
        }
    }
};
