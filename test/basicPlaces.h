#ifndef BASIC_PLACE_H
#define BASIC_PLACE_H

#include "Place.h"
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <list>
#define CITYLIST "CityList.txt"
using namespace std;
typedef unsigned long UINT;

class City : public Place
{
	private:
		string _CityName;
		string _CityHolder;
		int _DenfenceLevel;
		UINT CalculatePopulation() const;
		void Develop(UINT cash);
		bool ChangeHolder(string newHolder);
	protected:

	public:
		//a const default constructor is needed
		City(double lat=0.0,double lon=0.0,double high=0.0,UINT pd=0,string pr="null products",UINT area=0,
		string cn="null name",string ch="null holder",int df=0):Place(lat,lon,high,pd,pr,area),
		_CityName(cn),_CityHolder(ch),_DenfenceLevel(df)
		{cout<<"\nBuild a city named "<<cn<<endl;}
		void GetInfo() const;
		int GetPopulation() const {return CalculatePopulation();}
		friend bool InitCityList(City &acity,const int num);
		friend bool SaveCityListinFile(const City &acity,const int num);
		friend bool ReadListFiletoCity(City *cities,const int num);
		virtual ~City(){cout<<"\nremove a city."<<endl;}
};

inline UINT City::CalculatePopulation() const
{
	return _Area*_PopulationDensity;
}

void City::Develop(UINT cash)
{
	//mimic the random of development when put into money
	srand(time(0));
	int random=(rand()+cash)%10;
	_PopulationDensity+=random;
	return;
}

inline bool City::ChangeHolder(string newHolder)
{
	_CityHolder=newHolder;
	cout<<"Now the city is charged by "<<newHolder<<endl;
	return true;
}

inline void City::GetInfo() const
{
	cout<<"\nThis is the basic information of the city: "<<endl;
	cout<<"\nCity Name: "<<_CityName<<"\nCity Holder: "<<_CityHolder
	    <<"\nPopulations: "<<CalculatePopulation()<<"\nMajor Products: "<<_ProductType<<endl;
	return;
}

bool InitCityList(City &acity,const int num)
{
	//City *incity = new City(num);
	cout<<"Please input city information.\n";
	list<City> cities;
	string cityname="Handan",cityholder="Zhao",products="Steel";
	int defencelev=8;
	double lat=112,lon=35,high=16;
	UINT pop_den=200, area=1900;
	string states="C";
	while(states!="Q")
	{
		/*cout<<"Please input city name and holder and products...\n";
		cin>>acity._CityName;
		cin>>acity._CityHolder;
		cin>>acity._ProductType;
		cout<<"Please input city lat and lon and high...\n";
		cin>>acity._Latitude;
		cin>>acity._Longitude;
		cin>>acity._High;
		cout<<"Please input city denfencelevel and pop_den and area...\n";
		cin>>acity._DenfenceLevel;
		cin>>acity._PopulationDensity;
		cin>>acity._Area;*/
		acity._CityName=cityname; acity._CityHolder=cityholder; acity._ProductType=products;
		acity._Latitude=lat; acity._Longitude=lon; acity._High=high; acity._DenfenceLevel=defencelev;
		acity._Area=area; acity._PopulationDensity=pop_den;
		
		cout<<"Continue input (Yes=C/No=Q)..."; 
		cin>>states;
		//save the list in file
		SaveCityListinFile(acity,1);
	}
	return true;
}

bool SaveCityListinFile(const City &acity,const int num)
{
	fstream out;
	out.open(CITYLIST,ios::out|ios::app);
	if(out.fail())
	{
		cerr<<"No Save file found!"<<endl;
		return false;
	}
		
	out<<acity._CityName<<" "<<acity._CityHolder<<" "<<acity._ProductType
	<<" "<<acity._Latitude<<" "<<acity._Longitude<<" "<<acity._DenfenceLevel<<" "<<acity._PopulationDensity
	<<" "<<acity._Area<<endl;

	out.close();
	cout<<"Save list of city "<<acity._CityName;
	return true;
}

//input a array of object city
bool ReadListFiletoCity(City *cities,const int num)
{
	ifstream in;
	in.open(CITYLIST);
	
	if(in.fail())
	{
		cerr<<"No Read file found!"<<endl;
		return false;
	}
	for(int i=0;i<num;++i)
	{
		//a logical error once, read when not ineof rather than until eof
		if(!in.eof())
		{
	 		in>>cities[i]._CityName>>cities[i]._CityHolder>>cities[i]._ProductType
			>>cities[i]._Latitude>>cities[i]._Longitude>>cities[i]._DenfenceLevel>>cities[i]._PopulationDensity
			>>cities[i]._Area;
		}
		else
		{
			//there should have more lines, return false
			return false;
		}
	}
	in.close();
	return true;
}

class FramLand: public Place
{
  private:
  	UINT CalculatePopulation() const;
  	void Develop(UINT cash);
	bool ChangeHolder(string newHolder);
  protected:
	string _Landlord;
	int _LandDenfence;
	double _ProductValue;
  public:
};



#endif
