#ifndef BBINARY_TREE_H_INCLUDED
#define BBINARY_TREE_H_INCLUDED

#include <iostream>

typedef unsigned int UINT;

namespace DataStructure
{
   template<typename T>
   class BTnode
   {
   public:
     BTnode();
     BTnode(const T& ele);
     BTnode<T> operator=(const BTnode<T> &other);
     //basic operator of node
     bool operator<(const BTnode<T> &other) const;
     bool operator>(const BTnode<T> &other) const;
     bool operator==(const BTnode<T> &other) const;
     ~BTnode();
   private:
     BTnode<T>* parent;
     BTnode<T>* left_child;
     BTnode<T>* right_child;
     T data;
   };

   template<typename T>
   class BTree
   {
   public:
    BTree();
    ~BTree();
   private:
    BTnode<T>* root;
   };
};

#endif // BBINARY_TREE_H_INCLUDED
