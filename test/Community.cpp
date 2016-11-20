#include "Community.h"
#include "GobalDefine.h"
#include <ctime>
#include <cstdlib>
#include <map>

Person::Person()
{
   //random decided an age and gender
  //srand(static_cast<unsigned int>(clock()));
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


Noble::~Noble()
{

}

inline ostream & Noble::printInfo(ostream & ros) const
{
  return ros<<"A noble name "<<_first_name<<" and have political influence of "
	  <<_political_influence<<endl;
}

inline Noble* Noble::clone() const
{
	return new Noble(*this);
}

inline ERR_CODE Noble::update(const Noble & rNoble)
{
	*this=rNoble;
	return SUCCESS;
}

inline ERR_CODE Noble::updateInfluence(const USINT & influence_margin)
{
	_political_influence+=influence_margin;
	return SUCCESS;
}

inline string Noble::getName() const
{
	return _first_name;
}

ostream & NobleFamily::printInfo(ostream & ros) const
{
	using namespace std;
	ros<<"Noble family "<<_last_name<<" is led by "<<_leader_name
	<<" and has members listed as: "<<endl;
	vector<Noble>::const_iterator it_c = _famliy_members.begin();
	if (_famliy_members.empty())
	{
		ros<<"no family member.\n";
	}
	else
	{
		size_t ix=0;
	    for(it_c=_famliy_members.begin();it_c!=_famliy_members.end();
			it_c++)
		{
			ros<<it_c->getName()<<" ";
			ix++;
			if(ix%5==0)
			  ros<<endl;
		}
	}
   return ros;
}

inline NobleFamily* NobleFamily::clone() const
{
	return new NobleFamily(*this);
}

ERR_CODE NobleFamily::addMembers(const Noble & rNoble)
{
	if(_famliy_members.empty())
	{
		return FAIL;
	}

	_famliy_members.push_back(rNoble);
	return SUCCESS;
}

string NobleFamily::getName() const
{
	return _last_name;
}

ERR_CODE NobleFamily::updateLeader(const string & rcurLeaderName)
{
	_leader_name=rcurLeaderName;
	return SUCCESS;
}

ERR_CODE NobleFamily::isLeaderValid()
{
	//a leader is valid only if he has the highest influence
	//find the current greatest noble in the family
	vector<Noble>::const_iterator it_c=_famliy_members.begin();
	Noble curLeader=_famliy_members[0];
	Noble oriLeader=_famliy_members[0];
	for(;it_c!=_famliy_members.end();it_c++)
	{
		if((*it_c)>curLeader)
		{
			curLeader=*it_c;
		}

		if((*it_c).getName()==this->getName())
		{
			oriLeader=*it_c;
		}
	}

	//the new leader must be a member of the family
	//string oriLeader(_leader_name);
	//string curLeaderName=curLeader.getName();
	if(curLeader==oriLeader)
	{
		cout<<"The original leader "<<curLeader.getName()<<" remain on power."<<endl;
		return SUCCESS;
	}
	else
	{
		cout<<"The origin leader has been overthrowned by "<<curLeader.getName()<<endl;
		updateLeader(curLeader.getName());
		return FAIL; //the current leader in invalid
	}
  return SUCCESS;
}
// {
// 	map<USINT,string> PoliticalInfluenceRank;
// 	vector<Noble>::const_iterator it_c=_famliy_members.begin();

// 	for(;it_c!=_famliy_members.end();it_c++)
// 	{
// 		PoliticalInfluenceRank.insert(make_pair(it_c->getInfluence(),it_c->getName()));
// 	}
//     return SUCCESS;
// }

// ostream & King::printInfo(ostream & ros) const
// {
// 	//get the family of the king
// 	vector<NobleFamily> familes= _king_s_controlled_families; 
// 	for(int i=0; i<familes.size();i++)
// 	{
// 		vector<NobleFamily>::const_iterator it_c=familes.begin();
// 		//sameperson not implemented
// 		it_c=find(familes.begin(),familes.end();sameperson);
// 		if(it_c!=)
// 	}
// 	ros<<"King "<<this->Noble::getName()<<" from noble family "<<

// }