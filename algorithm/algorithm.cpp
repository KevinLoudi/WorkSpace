#include "algorithm.h"

namespace Algorithm
{
     template<class T>
     inline void Sort<T>::_swap(T &a, T &b)
     {
         T tmp=a;
         a=b;
         b=tmp;
     }

    template<class T>
    void Sort<T>::selectsort(T *a, int n)
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

    /*template<class T>
    std::ostream& Sort<T>::print(std::ostream & ros, T *a, int n)
    {
        int ix=n;
        while(ix--)
        {
            ros<<a[ix]<<std::endl;
        }
        return ros;
    }*/
};
