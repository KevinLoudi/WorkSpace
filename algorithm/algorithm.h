#ifndef ALGORITHM_H_INCLUDED
#define ALGORITHM_H_INCLUDED
#include<iostream>

namespace Algorithm
{
     template<class T>
     class Sort
     {
     public:
            Sort() {}
            ~Sort() {}
            void _swap(T &a, T &b);
            //std::ostream& print(std::ostream & ros, T *a, int n);
            void selectsort(T *a, int n);
     };
};

#endif // ALGORITHM_H_INCLUDED
