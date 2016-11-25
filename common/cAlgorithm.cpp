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
