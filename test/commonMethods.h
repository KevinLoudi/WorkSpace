#ifndef COMMONMETHODS_H
#define COMMONMETHODS_H

#include <iostream>
#include <vector>
#include <algorithm>
#include "basicPlaces.h"
#include <cstdlib>
#include <ctime>
using namespace std;
typedef unsigned long UINT;

class Methods
{
	private:

	protected:
		
	public:
		Methods(){}
		virtual ~Methods(){} 
};

//the rank works like a stack that can push/pop and sort element
//by a string-type key or int-type key
class Ranking : public Methods 
{
    private:
    	vector<City> _city;
    	vector<string> _cityname;
    	static const UINT _max_elements=100;
	protected:
		bool is_rank_empty() const {return _city.size()==0;}
		bool is_rank_full() const {return _city.size()==_max_elements;}
	public:
		bool is_ranked(const string cityname);
		bool push_city(const City &);
		bool pop_city(string &);
		bool peek_city(City &);
		ostream & printHelper(ostream &os);
		ostream & printRankedCity(ostream &os,vector<City>::iterator it);

};

bool Ranking::push_city(const City & newcity)
{
	if(is_rank_full()) return false;

	_city.push_back(newcity);
	_cityname.push_back(newcity.GetCityName());
	return true;
}

bool Ranking::pop_city(string & deletedcity)
{
	if(is_rank_empty()) return false;
	_city.pop_back();
	return true;
}

bool Ranking::peek_city(City & outcity)
{
	if(is_rank_empty()) return false;

	outcity=_city.back();
	return true;
}

bool Ranking::is_ranked(const string cityname)
{
	vector<string>::iterator found_it;
	vector<string>::iterator end_it=_cityname.end();

	found_it=find(_cityname.begin(),end_it,cityname);
	return found_it != end_it;
}

ostream & Ranking::printHelper(ostream &os)
{
	vector<City>::iterator it=_city.begin();
	return printRankedCity(os,it);

}

ostream & Ranking::printRankedCity(ostream &os,vector<City>::iterator it)
{
	//recursive
	//base problem
	if (it==_city.end())
	{
		return it->GetInfo(os);
	}
	//separet into subproblems
	else
	{
		printRankedCity(os,++it);
	}
}

//class Models
//{
//	private:
//
//	protected:
//		vector<int> seq;
//	public:
//		Models();
//		virtual bool gen_seq(int len)=0;
//		virtual ~Models();
//};

//class PopulationGrowthModel: public Models
//{
//	private:
//
//	protected:
//		vector<int> population_seq;
//	public:
//		virtual bool gen_seq(int len);
//		City _acity; 
//};
//
//bool PopulationGrowthModel::gen_seq(int len)
//{
//	load the current Population of the city
//	if (seq.size()==0)
//	{
//		seq.push_back(_acity.GetPopulation());
//	}
//
//	for (int i = 0; i < len; ++i)
//	{
//		srand(time(0));
//		random bitrh
//		int random_birth=seq[i-1]*(rand())%1;
//		random death
//		int random_death=seq[i-1]*(rand())%1;
//		combine random
//		seq.push_back(seq[i-1]+random_birth-random_death);
//	}
//	return true;
//}
#endif
