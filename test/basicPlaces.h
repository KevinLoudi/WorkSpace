#ifndef BASIC_PLACE_H
#define BASIC_PLACE_H

#include "Place.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
typedef unsigned long UINT;

class City : public Place
{
	private:
		UINT CalculatePopulation() const;
		void Develop(UINT cash);
		bool ChangeHolder(string newHolder);
	protected:
		string _CityName;
		string _CityHolder;
		int _DenfenceLevel;
	public:
		//a const default constructor is needed
		City(double lat=0.0,double lon=0.0,double high=0.0,UINT pd=0,string pr="null products",UINT area=0,
		string cn="null name",string ch="null holder",int df=0):Place(lat,lon,high,pd,pr,area),
		_CityName(cn),_CityHolder(ch),_DenfenceLevel(df)
		{cout<<"\nBuild a city named "<<cn<<endl;}
		void GetInfo() const;
		int GetPopulation() const {return CalculatePopulation();}
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
