#ifndef ALGORITHM_H_INCLUDED
#define ALGORITHM_H_INCLUDED
#include<iostream>

namespace Algorithm
{
    /*template<class T>
    typedef bool (*CMP)(const T& a, const T& b);
    template<class T>
    bool isless(const T& a, const T& b) {a<b;} */

    template<class T>
     class Sort
     {
     public:
            Sort() {}
            ~Sort() {}
            /*swap two elements*/
            void _swap(T &a, T &b)
            {
                T tmp=a;
                a=b;
                b=tmp;
            }
            /*print all elements in order*/
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

           /*select sort algorithm (data, data_size)*/
            void selectsort(T *a, int n)
           {
                for(int i=0;i<n;i++)
                {
                    int _min=i;
                    //find the largest element
                    for(int j=i+1;j<n;j++)
                    {
                       if(a[j]<a[_min]) _min=j;
                       //if(isless(a[j],a[_min])) _min=j;
                    }
                    //swap the largest element with the first position in the unsorted region
                    _swap(a[i],a[_min]);
                }
            }

            /*bubble sort algorithm (data, data_size)*/
            void bubblesort(T* a, int n)
            {
                for(int i=0; i<n; i++)
                    for(int j=i;j-1>=0&&a[j]<a[j-1];j--)
                    {
                      //swap each two elements if they have not in order
                      _swap(a[j],a[j-1]);
                    }
            }

            /*insert sort*/
            void insertsort(T *a, int n, int incre)
            {
                int i,j;
                for(i=incre; i<n ; i+=incre)
                {
                    for(j=i;(j>=incre)&&(a[j]<a[j-incre]);j-=incre)
                    {
                       _swap(a[j],a[j-incre]);
                    }
                }
            }

            /*quick sort*/
            void quicksort(T* a, int low, int high)
            {
                //select a standard
                int pivot=a[(low+high)/2];
                int left=low-1;
                int right=high;

                if(low>=high)
                    return;

                _swap(a[(low+high)/2],a[high]);
                do
                {
                    while(a[++left]<pivot);
                    while(right!=0&&a[--right]>pivot);
                    _swap(a[left],a[right]);
                }while(left<right);

                _swap(a[left],a[right]);
                _swap(a[left],a[high]);

                quicksort(a,low, left-1);
                quicksort(a,left+1,high);
            }

     };
};

#endif // ALGORITHM_H_INCLUDED
