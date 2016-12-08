#include "ddlinklist.h"

namespace DataStructure
{
    template<typename T>
    inline DoubleLinkList<T>::DoubleLinkList(T def):head(NULL), tail(NULL), length(0), default_element(def)
    {
        //set a default value for type T
    }

    template<typename T>
    DoubleLinkList<T>::DoubleLinkList(const T* ele_arr, const int ele_size, T def):head(NULL),
    tail(NULL), length(0), default_element(def)
    {
        for(int ix=0; ix<ele_size; ++ix)
        {
            addLast(*(ele_arr+ix)); //would there be a problem for using class methods within constructor
        }
    }

    template<typename T>
    DoubleLinkList<T>::DoubleLinkList(const DoubleLinkList<T>& other_list):head(NULL),
    tail(NULL), length(0)
    {
        this->default_element=other_list.default_element;
        int other_size=other_list.size_();
        //copy all elements from other_list to this list
        for(int ix=0; ix<other_size; ++ix)
        {
            T tmp=other_list.getAt(ix);
            addLast(tmp);
        }
    }

    template<typename T>
    inline DoubleLinkList<T>& DoubleLinkList<T>::operator=(const DoubleLinkList<T>& other_list)
    {
        //not do copy for indentical list
        if(this==&other_list)
        {
            return *this;
        }
        //delete the old list and renew its nodes
        clear_();
        int other_size=other_list.size_();
        int ix=0;
        //copy all elements from other_list to this list
        while(ix<other_size)
        {
            T tmp=other_list.getAt(ix);
            addLast(tmp);
            ++ix;
        }
        return *this;
    }

    template<typename T>
    DoubleLinkList<T>::~DoubleLinkList()
    {
        clear_(); //release memories allocated for nodes
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
            ros<<"\nempty list\n";
            return ros;
        }
        Dnode<T>* pnode=head;
        ros<<"\nordered print\n list length: "<<length<<std::endl;
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
            ros<<"\nempty list\n";
            return ros;
        }
        Dnode<T>* pnode=tail;
        ros<<"\nreversed print\n list length: "<<length<<std::endl;
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
        if(ix>=(length-1)) {addLast(ele);return true;}
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
            //pprev<=>
            T ele=tail->element;
            tail=pprev;
            tail->next=NULL;

            delete pnode;
            --length;
            return ele;
        }
    }

    template<typename T>
    T DoubleLinkList<T>::removeAt(const int ix) throw (std::runtime_error)
    {
        if(isempty()) throw std::runtime_error("cannot do delete on an empty list");
        if(ix<=0) return removeHead();
        else if(ix>=(length-1)) return removeTail();
        //locate the node through index--ix
        Dnode<T>* pnode=is_(ix);

        //now pnode has been put on the given position
        //pprev<=>pnode<=>pnext  ---> pprev<=>pnext
        Dnode<T>* pprev=pnode->prev;
        Dnode<T>* pnext=pnode->next;
        T ele=pnode->element;
        //build link
        pprev->next=pnext;
        pnext->prev=pprev;
        //release link
        pnode->next=NULL;
        pnode->prev=NULL;
        delete pnode;
        length--;
        return ele;
    }

    template<typename T>
    int DoubleLinkList<T>::findAt(const T& ele) const
    {
        if(isempty()) return -2;
        Dnode<T>* pnode=head;
        int pos=0;

        while(pnode!=NULL)
        {
            if(pnode->element==ele) break;
            pnode=pnode->next;
            ++pos;
        }

        if(pnode==NULL) return -1; //no found until the tail of the list
        return pos;
    }

    template<typename T>
    int DoubleLinkList<T>::removeIf(const T& ele)
    {
        int pos=findAt(ele);
        if(pos==-1 || pos== -2) return pos; //return if not found the element
        removeAt(pos); //remove if found the element
        return pos;
    }

    template<typename T>
    Dnode<T>* DoubleLinkList<T>::is_(const int pos) const
    {
        if(pos<=0) return head;
        else if(pos>=(length-1)) return tail;

        //locate the element
        int ixx=0;
        Dnode<T>* pnode=head;
        while((ixx++)<pos) pnode=pnode->next;
        return pnode;
    }

    template<typename T>
    inline  T DoubleLinkList<T>::getAt(const int ix) const
    {
        Dnode<T>* pnode=NULL;
        pnode=is_(ix);
        return pnode->element;
    }

    template<typename T>
    void DoubleLinkList<T>::clear_() throw (std::runtime_error)
    {
        if(isempty()) return;
        //length of the original list
        int ori_len=length;
        //remove node one by one
        for(int count_=0; count_<ori_len; ++count_)
            removeTail();
        //exception handling
        if(length!=0)
            throw std::runtime_error("delete failure!");
        else
            return;
    }

    template<typename T>
    inline bool DoubleLinkList<T>::setAt(const T& ele, const int ix)
    {
        if(ix>(length-1)||ix<0) return false;
        Dnode<T>* pnode=is_(ix);
        pnode->element=ele;
        return true;
    }

    template<typename T>
    const T DoubleLinkList<T>::getPrev(const T& ele) const throw (std::runtime_error)
    {
        int pos=findAt(ele);
        if(pos==-1||pos==-2) return default_element; //return default if fail to find the element
        Dnode<T>* pnode=is_(pos);
        if(pnode->prev==NULL) //return default if the found element is the head
            return default_element;
        else
            return pnode->prev->element;
    }

    template<typename T>
    const T DoubleLinkList<T>::getNext(const T& ele) const throw (std::runtime_error)
    {
        int pos=findAt(ele);
        if(pos==-1||pos==-2) return default_element; //return if fail to find the element
        Dnode<T>* pnode=is_(pos);
        if(pnode->next==NULL) //return default if the found element is the tail
            return default_element;
        else
            return pnode->next->element;
    }

    template<typename T>
    bool DoubleLinkList<T>::removeRange(const int lowix, const int highix) throw (std::runtime_error)
    {
        if(lowix>highix || highix>length-1) return false; //error input index, out of bound
        for(int ix=lowix; ix<=highix; ++ix)
        {
            removeAt(ix);
        }
        return true;
    }
};
