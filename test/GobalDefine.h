#ifndef GOBALDEFINE_H
#define GOBALDEFINE_H

#include <string>
#include "Community.h"
#include "GobalDefine.h"
#include "basicModel.h"
#include "basicPlace.h"
#include "basicEvent.h"
using namespace std;

//self-defined smart pointer
template<typename T> //T should have deep copy operation named clone()
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
  	//enable destructive copy
  	smart_pointer(T & ranothorp,bool isDestructivecopy)
  	{
  		_pRawPointer=ranothorp.clone();
  		ranothorp=0;
  	}
  	//assignment operator
  	smart_pointer operator=(const T & ranothorp){_pRawPointer=ranothorp.clone();}
  	//dereference operator
  	T& operator* () const{return *_pRawPointer;}
  	//select member operator
  	T* operator-> () const{return _pRawPointer;}
};

//a functor used in compare two Person-like object with name
//template<typename PersonLike>
//class is_the_same_person
//{
//  public:
//    string _target_name;
//  	is_the_same_person(const string & target):_target_name(target){}
//  	bool operator()(const PersonLike & rp)
//  	{
//  		return _target_name==rp.getName();
//  	}
//  	~is_the_same_person(){}
//};

//A forward declaration only says that a particular class
//will be defined later,
//class find_name : std::unary_function<Noble, bool> {
//  public:
//    string _target_name;
//    find_name(string target):_target_name(target) { }
//    bool operator()(const Noble & N) const
//	{
//        return _target_name == N.getName();
//    }
//};

#endif
