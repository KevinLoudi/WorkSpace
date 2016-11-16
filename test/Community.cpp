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

Community::Community()
{

}

Community::~Community()
{
	
}

ostream & NobleFamily::printInfo(ostream & ros) const
{
	ros<<"Noble family "<<_last_name<<" is led by"<<_family_lead_s_first_name
	<<" and has members listed as: "<<endl;
	vector<Noble>::const_iterator it_c = _famliy_members.begin();
	if (_famliy_members.empty())
	{
		ros<<"no family member.\n";
	}
	else
	{
		//family lead must be a member. or return error message
		it_c=find(_famliy_members.begin(),_famliy_members.end(),samperson);
		if(it_c==_famliy_members.end())
		{
			ros<<"family information have error."
			return ros
		}
		else
		{
			for(it_c=_famliy_members.begin();it_c!=_famliy_members.end();
				it_c++)
			{
				ros<<it_c->getName();
			}
		}
	}
}