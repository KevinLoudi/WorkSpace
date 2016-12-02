#ifndef ALGORITHM_H_INCLUDED
#define ALGORITHM_H_INCLUDED
#include<iostream>

namespace Algorithm
{
     template<typename T>
     inline _swap(T &a, T &b)
     {
         T tmp=a;
         a=b;
         b=tmp;
     }

     template<class T>
     class Sort
     {
     public:
            Sort() {}
            ~Sort() {}
            std::ostream& print(std::ostream & ros, T *a, const int& n);
            void selectsort(T *a, int n);
     };
};

#endif // ALGORITHM_H_INCLUDED
