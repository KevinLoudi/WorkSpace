#ifndef BBINARY_TREE_H_INCLUDED
#define BBINARY_TREE_H_INCLUDED

namespace DataStructure
{
   template<typename T>
   class BTnode
   {
   public:
     BTnode();
     BTnode(const T& ele);
     ~BTnode();
   private:
     BTnode<T>* parent;
     BTnode<T>* left_child;
     BTnode<T>* right_child;
     T data;
   };

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
