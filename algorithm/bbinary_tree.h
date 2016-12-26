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

     //data field
     BTnode<T>* parent;
     BTnode<T>* left_child;
     BTnode<T>* right_child;
     T data;
   };

   template class BTnode <double>;

   template<typename T>
   class BTree
   {
   public:
    //initial and destroy the tree
    BTree(UINT given_max_size=100);
    BTree(const T* arr, const UINT& arr_size, UINT given_max_size=100);
    ~BTree();
    //set the tree
    bool insert_helper(const T& val);
    //get information
    bool isempty() const {return root==NULL;}
    bool isfull() const {return size==max_size;}
    bool sizeis() const {return size;}
    std::ostream & print_helper(std::ostream & ros) const;
   private:
    BTnode<T>* root;
    UINT size;
    const UINT max_size; //max number of node a tree can hold
    std::ostream & print(const BTnode<T>* curnode, std::ostream & ros) const;
    bool insert(BTnode<T>* curnode ,const T& val);
   };

   template class BTree <double>;
};

#endif // BBINARY_TREE_H_INCLUDED
