#ifndef COMMONMETHODS_H
#define COMMONMETHODS_H

#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include "basicPlaces.h"
#include <cstdlib>
#include <ctime>
using namespace std;
typedef unsigned long UINT;
typedef pair<string, UINT> Pair;
typedef multimap<string,UINT> Map;

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

    	vector<City>::iterator it_city;
    	vector<string>::iterator it_name;
    	Map _city_popluation_rank;

	protected:
		bool is_rank_empty() const {return _city.size()==0;}
		bool is_rank_full() const {return _city.size()==_max_elements;}
	public:
		bool is_ranked(const string cityname);
		bool push_city(const City &);
		bool pop_city(string &);
		bool peek_city(City &);

		ostream & printHelper(ostream &os);
		ostream & printRankedCity(ostream &os,vector<City>::iterator it,vector<City>::iterator it_end);
		ostream & printRankedCity(ostream &os,UINT & start_ix,UINT & stop_ix);
		//print method for xcode
		void printRankedCity_x(UINT & start_ix,UINT & stop_ix);

		//key: city name value: population
		void sort_city_by_population(bool ascend_or_descend);

		//construct a describe for the rank
		void print_a_cityinfo(const string &cityname);


};

//we can implement SQL-like enquiry through map container
void Ranking::print_a_cityinfo(const string &cityname="Xianyang")
{
    //the rank map has not yet been built
	if (_city_popluation_rank.empty()&&_city.empty())
	{
        exit(EXIT_FAILURE);
	}
	Map::iterator it;
    pair<Map::iterator, Map::iterator> range = _city_popluation_rank.equal_range(cityname);
    //cout<<"Population of "<<cityname<<" is ";
    for(it=range.first;it!=range.second;++it)
    {
        cout<<(*it).second<<endl;
    }

    string output(cityname);
    
    //find the city's object in vector _city
    //we can replace it with find
    UINT total_city_num=0;
    UINT total_population=0;
    UINT this_population=0;
    string holder="";
    int defence=0;
    
    //range-base for loop
    for(auto i: _city)
    {
        total_population+=i.GetPopulation();
    	if (i.GetCityName()==cityname)
    	{
    		holder=i.GetCityHolder();
            defence=i.GetDenfenceLevel();
            this_population=i.GetPopulation();
    		break;
    	}
    }
    
    //get city num from the public static member
    total_city_num=City::_City_num;

    output = output + " is holded by " + holder ;
    output += ", and this city have a denfence level of "+ to_string((int)total_city_num)+"\n";
    output += "now, " + to_string((int)this_population)+" of inhabitants live here when the whole map have a population of " + to_string((int)total_population)+" in "+ to_string((int)total_city_num)+" cities.\n";

    
    cout<<output<<endl;
}

void Ranking::sort_city_by_population(bool ascend_or_descend)
{
	it_city=_city.begin();
	for (; it_city!=_city.end(); it_city++)
	{
		_city_popluation_rank.insert(Pair(it_city->GetCityName(),it_city->GetPopulation()));
	} 
}

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
	// vector<City>::iterator it=_city.begin();
	// vector<City>::iterator it_end=_city.end();
	// return printRankedCity(os,it,it_end);

	UINT start_ix=0;
	UINT stop_ix=_city.size();
	return printRankedCity(os,start_ix,stop_ix);
}

ostream & Ranking::printRankedCity(ostream &os,vector<City>::iterator it,vector<City>::iterator it_end)
{
	//recursive, occur runtime error
	//base problem
	if (it==it_end)
	{
		return (*it).GetInfo(os);
	}
	//separet into subproblems
	else
	{
		printRankedCity(os,++it,it_end);
	}
	return os;
}

ostream & Ranking::printRankedCity(ostream &os,UINT & start_ix,UINT & stop_ix)
{
	for(UINT i=start_ix;i<stop_ix;i++)
	{
		_city[i].GetInfo(os);
	}
	return os;
}

void Ranking::printRankedCity_x(UINT & start_ix,UINT & stop_ix)
{
	for(UINT i=start_ix;i<stop_ix;i++)
	{
        cout<<_city[i].GetCityName()<<" "<<_city[i].GetPopulation()<<endl;
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
