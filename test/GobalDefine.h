#ifndef GOBALDEFINE_H
#define GOBALDEFINE_H

//self-defined smart pointer
template<typename T>
class smart_pointer
{
  private:
  	T* _pRawPointer;
  public:
  	smart_pointer(T* pRaw):_pRawPointer(pRaw){}
  	~smart_pointer(){ delete _pRawPointer;}
  	//the following two have some problems 
  	//copy constructor
  	smart_pointer(const T & ranothorp){_pRawPointer=ranothorp.clone();}
  	//assignment operator
  	smart_pointer operator=(const T & ranothorp){_pRawPointer=ranothorp.clone();}
  	//dereference operator
  	T& operator* () const{return *_pRawPointer;}
  	//select member operator
  	T* operator-> () const{return _pRawPointer;}
};


#endif
