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
            void _swap(T &a, T &b)
            {
                T tmp=a;
                a=b;
                b=tmp;
            }
           std::ostream& print(std::ostream & ros, T *a, int n)
           {
               int ix=n;
               ros<<std::endl<<"elements as...";
               while(ix--)
               {
                   if(ix%10==0) ros<<std::endl;
                   ros<<a[ix]<<" ";
               }
               return ros;
           }

            void selectsort(T *a, int n)
           {
                for(int i=0;i<n;i++)
                {
                    int _min=i;
                    for(int j=i+1;j<n;j++)
                    {
                       if(a[j]<a[_min]) _min=j;
                    }
                    _swap(a[i],a[_min]);
                }
            }

            void bubblesort(T* a, int n)
            {
                for(int i=0; i<n; i++)
                    for(int j=i;j-1>=0&&a[j]<a[j-1];j--)
                    {
                     _swap(a[j],a[j-1]);
                    }
            }

     };
};

#endif // ALGORITHM_H_INCLUDED
