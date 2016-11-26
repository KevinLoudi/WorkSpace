#include "cAlgorithm.h"

namespace Algorithm
{
  void Method::DemoClassBuilding()
  {
      Base b1;
      Base b2(10);

      b1=b2;
      Derived d1;
      Derived d2(30,52);
      d1=d2;
  }

  Derived Method::DemoTemporalObject(Base b, Derived d)
  {
      //use copy assignment
      std::cout<<"use copy assignment"<<std::endl;
      Derived tmpd1;
      tmpd1=d;
      std::cout<<"using end"<<std::endl;

      //not use copy assignment
      std::cout<<"use copy constructor"<<std::endl;
      Derived tmpd2=d;
      std::cout<<"using end"<<std::endl;

      Base tmpb;
      tmpb=b;

      return tmpd2;
  }

  void Method::QuickSort(int  a[], int low, int high)
  {
      //assert(low<high);
      int i, j;  int pivot;
      if(low<high)
      {
          pivot=a[low]; //set a standard point
          i=low;
          j=high;
          while(i<j)
          {
              //move the elements smaller than pivot to the low end
              while(i<j && a[j]>=pivot)
              {
                   j--; //find a element that smaller than pivot
              }
              if(i<j)
              {
                  a[i++]=a[j]; //move element
              }

              //move the elements larger than pivot to the high end
              while(i<j && a[i]<=pivot)
              {
                  i++;
              }
              if(i<j)
              {
                  a[j--]=a[i];//move element
              }
              /* low, low, low, pivot, high, high, high */
              a[i]=pivot; //now the standard point should be put in the middle set
              //recursively sort the two part, higher part and lower part
              QuickSort(a,low,i-1);
              QuickSort(a,i+1,high);
          }
      }
  }

void Method::ShellSort(int a[], const int & len)
{
    int l = len;
    //if the array element length is not even, modify to odd to fit the sort method
    const int ADDITION_ELE = -1;
    bool ADDITION_FLAG = false;
    if(l%2!=0)
    {
        ADDITION_FLAG=true;
        a[len] = ADDITION_ELE;
        l++;
    }
    //half divide the array until only one element remain in a sub-array
    for(int h=l/2; h>0; h=h/2)
    {
        //perform selection sort
        for(int i=h; i<l; i++)
        {
            int tmp=a[i]; //search from the ith element
            //move element by a step of h when the current a[i+h] is small
            int j;
            for(j=i-h; (j>=0&&tmp<a[j]); j-=h)
            {
                a[j+h]=a[j];
            }
            a[j+h]=tmp; //set the last element in the sorted array
        }
    }

    //have add an additional element? remove it now
    if(ADDITION_FLAG)
    {
        for(int i=0; i<len+1; ++i)
        {
            if(a[i]==ADDITION_ELE) //find the first element equal ADDITION_ELE
            {
                //remove the additional element by move all element one-place forward
                for(int j=i; j<len; ++j) //the last element has also under consideration, len instead of len+1
                {
                    a[j]=a[j+1];
                }
            }
        }
    }
}

ostream & Method::ArrayPrinter(const int a[], const int & _size, ostream & ros) const
{
    int t=_size;
    while(t>0)
    {
        ros<<a[t]<<" "<<std::endl;
        t--;
    }
    return ros;
}

  void Parallel::start()
 {
    pthread_create(&thread, NULL, Parallel::staticEntryPoint, this);
 }

  void * Parallel::staticEntryPoint(void * c)
 {
    ((Parallel *) c)->entryPoint();
    return NULL;
 }

  void Parallel::entryPoint()
 {
    // thread body
    std::cout<<"this is the "<<this->thread_ix<<"th thread"<<std::endl;
 }
};
