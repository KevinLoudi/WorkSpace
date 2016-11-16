#include "Community.h"
#include <ctime>

Person::Person()
{
   //random decided an age and gender
  srand (time(NULL));
  int age=(rand()%50); //[0,50] years old
  GENDER gender=GENDER((rand()%2));
  //initial class member
  _age=age;
  _gender=gender;
}

Person::~Person()
{

}

inline ostream & Person::printInfo(ostream & ros) const
{
	if(_gender==MALE)
	{
	  return ros<<"MALE"<<" aged "<<_age<<endl;	
	}
	else
	{
	  return ros<<"FMALE"<<" aged "<<_age<<endl;		
	}
	
}

inline Person* Person::clone() const
{
	//invoke copy constructor to assign a new
	//need to be delete
	return new Person(*this);
}

ERR_CODE Person::update(const Person & rPerson)
{
	this->_age=rPerson._age;
	this->_gender=rPerson._gender;
	return SUCCESS;
}

inline Judge Person::isSatisfied(const GENDER & gender,const USINT & age) const
{
	return Judge(((this->_age>age)&&(this->_gender==gender)));
}

//Community::Community()
//{
//
//}
//
//Community::~Community()
//{
//	
//}
