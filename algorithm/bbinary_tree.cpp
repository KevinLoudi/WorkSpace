#include "bbinary_tree.h"

namespace DataStructure
{

  template<typename T>
  inline BTnode<T>::BTnode()
  {
      parent=left_child=right_child=NULL;
  }

  template<typename T>
  inline BTnode<T>::BTnode(const T& ele)
  {
      data=ele;
      parent=left_child=right_child=NULL;
  }

  template<typename T>
  BTnode<T>::~BTnode()
  {

  }

  template<typename T>
  BTnode<T> BTnode<T>::operator=(const BTnode<T> &other)
  {
      this->data=other.data;
      return *this;
  }

  template<typename T>
  bool BTnode<T>::operator<(const BTnode<T> &other) const
  {
      return (data<other.data);
  }

  template<typename T>
  bool BTnode<T>::operator>(const BTnode<T> &other) const
  {
      return (data>other.data);
  }

  template<typename T>
  bool BTnode<T>::operator==(const BTnode<T> &other) const
  {
      return !(data>other.data)&&!(data<other.data);
  }

  template<typename T>
  inline BTree<T>::BTree(UINT given_max_size): max_size(given_max_size)
  {
      root=NULL;
      size=0;
  }

  template<typename T>
  BTree<T>::BTree(const T* arr, const UINT& arr_size, UINT given_max_size):max_size(given_max_size)
  {
     root=NULL;
     for(UINT i=0; i<arr_size; ++i)
     {
         insert_helper(arr[i]);
     }
  }

  template<typename T>
  BTree<T>::~BTree()
  {

  }

  template<typename T>
  bool BTree<T>::insert_helper(const T& val)
  {
      return insert(root, val);
  }

  template<typename T>
  bool BTree<T>::insert(const BTnode<T>* curnode, const T& val)
  {
    if(size>max_size) return false; //memory used up
    if(curnode==NULL)
    {
        curnode=new BTnode<T>(val);
        ++size;
    }
    //recursive insertion
    else if(curnode->data <= val)
    {
        insert(curnode->right_child, val);
    }
    else if(curnode->data > val)
    {
        insert(curnode->left_child,val);
    }
    return true;
  }

  template<typename T>
  std::ostream & BTree<T>::print_helper(std::ostream & ros) const
  {
      return print(root, ros);
  }

  template<typename T>
  std::ostream & BTree<T>::print(const BTnode<T>* curnode, std::ostream & ros) const
  {
        if(curnode&&curnode->left_child)
            ros<<print(curnode, ros);
        if(curnode)
            ros<<curnode->data<<"\n ";
        if(curnode&&curnode->right_child)
            ros<<print(curnode,ros);
        return ros;
  }
};
