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
  bool BTree<T>::insert(BTnode<T>* curnode, const T& val)
  {
      if(size>=max_size) return false;
      if(val<=curnode->data)
      {
          if(curnode->left_child!=NULL)
            insert(curnode->left_child,val);
          else
            BTnode<T>* newnode=new BTnode<T>(val);
            newnode->parent=curnode;
            curnode->left_child=newnode;
            ++size;
      }
      else
      {
           if(curnode->right_child!=NULL)
            insert(curnode->right_child,val);
          else
            BTnode<T>* newnode=new BTnode<T>(val);
            newnode->parent=curnode;
            curnode->right_child=newnode;
            ++size;
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
    if(curnode != NULL)
    {
        if(curnode->left_child!=NULL)
            ros<<print(curnode->left_child, ros);
        ros<<curnode->data<<"\n";
        if(curnode->right_child!=NULL)
            ros<<print(curnode->right_child, ros);
    }
    return ros;
  }
};
