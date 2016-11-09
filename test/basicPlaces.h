#ifndef BASIC_PLACE_H
#define BASIC_PLACE_H

#include "Place.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <cstdlib>
#include <ctime>
#include <list>
#define CITYLIST "CityList.txt"
using namespace std;
typedef unsigned long UINT;

class City : public Place
{
	private:
		//propeties for a city
		string _CityName;
		string _CityHolder; 
		int _DenfenceLevel;
				
		//operations
		UINT CalculatePopulation() const; //return city population
		void Develop(UINT cash); //develop city with investment and in a random way
		bool ChangeHolder(string newHolder); //change holder of the city
	protected:

	public:
		//more complex construct
		City(double lat=0.0,double lon=0.0,double high=0.0,UINT pd=0,string pr="null products",UINT area=0,
		string cn="null name",string ch="null holder",int df=0):Place(lat,lon,high,pd,pr,area),
		_CityName(cn),_CityHolder(ch),_DenfenceLevel(df)
		{
		 //cout<<"Build a city named "<<cn<<endl;
		 _City_num++;
		}
		
		City(const City &anotherCity);

		//access private data field
		string GetCityName() const{ return _CityName;}
		string GetCityHolder() const {return _CityHolder;}
		int GetDenfenceLevel() const {return _DenfenceLevel;}
		
		//redefined virtual operations
		ostream & GetInfo(ostream & os)const;
		
		//public interface for show population
		int GetPopulation() const {return CalculatePopulation();}
		
		//initalize a city via cin
		friend bool InitCityList(City &acity);
		friend bool SaveCityListinFile(const City &acity);
		
		//initalize a set of cities via setting files
		friend bool ReadListFiletoCity(City cities[],const int num);
		
		//current actived city objects num,default as 0
		static UINT _City_num;
		
		//destruct with info
		virtual ~City()
		{
			_City_num--;
			//cout<<"remove a city."<<endl;	
		}
};

// City::City(const City &anotherCity)
// {
// 	// this->_CityName=anotherCity._CityName;
// 	// this->_CityHolder=anotherCity._CityHolder;
// 	// this->_DenfenceLevel=anotherCity._DenfenceLevel;
// 	// this->_Latitude=anotherCity._Latitude;
// 	// this->_Longitude=anotherCity._Longitude;
// 	// this->_High=anotherCity._High;
// 	// this->_PopulationDensity=anotherCity._PopulationDensity;
// 	// this->_ProductType=anotherCity._ProductType;
// 	// this->_Area=anotherCity._Area;

// }

inline UINT City::CalculatePopulation() const
{
	return _Area*_PopulationDensity;
}

void City::Develop(UINT cash)
{
	//mimic the random of development when put into money
	srand((UINT)time(0));
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

inline ostream & City::GetInfo(ostream & os) const
{
	os<<"\nThis is the basic information of the city: "
	 <<"\nCity Name: "<<this->_CityName<<"\nCity Holder: "<<this->_CityHolder
     <<"\nPopulations: "<<this->CalculatePopulation()<<"\nMajor Products: "<<this->_ProductType<<endl;
	return os;
}

bool InitCityList(City &acity)
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
		cout<<"Please input city name and holder and products...\n";
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
		cin>>acity._Area;
		
		/*acity._CityName=cityname; acity._CityHolder=cityholder; acity._ProductType=products;
		acity._Latitude=lat; acity._Longitude=lon; acity._High=high; acity._DenfenceLevel=defencelev;
		acity._Area=area; acity._PopulationDensity=pop_den;*/
		
		cout<<"Continue input (Yes=C/No=Q)..."; 
		cin>>states;
		//save the list in file
		SaveCityListinFile(acity);
	}
	return true;
}

bool SaveCityListinFile(const City &acity)
{
	fstream out;
	//open city source file
	out.open(CITYLIST,ios::out|ios::app);
	if(out.fail())
	{
		cerr<<"No Save file found!"<<endl;
		return false;
	}
	
	//append city info
	out<<acity._CityName<<" "<<acity._CityHolder<<" "<<acity._ProductType
	<<" "<<acity._Latitude<<" "<<acity._Longitude<<" "<<acity._DenfenceLevel<<" "<<acity._PopulationDensity
	<<" "<<acity._Area<<endl;

	out.close();
	cout<<"Save list of city "<<acity._CityName;
	return true;
}

bool ReadListFiletoCity(City cities[],const int num)
{
	ifstream infile(CITYLIST);
	string cityname="Handan",cityholder="Zhao",products="Steel";
	int defencelev=8;
	double lat=112,lon=35,high=16;
	UINT pop_den=200, area=1900;
	UINT i=0;
	while((infile>>cityname>>cityholder>>products>>lat>>lon>>defencelev>>pop_den>>area)||(i<num))
	{
//		cout<<cityname<<" "<<cityholder<<" "<<products<<" "
//		<<lat<<" "<<lon<<" "<<defencelev<<" "<<pop_den<<" "
//		<<area<<endl;
		cities[i]._CityName=cityname; cities[i]._CityHolder=cityholder; 
		cities[i]._ProductType=products; cities[i]._Latitude=lat; 
		cities[i]._Longitude=lon; cities[i]._High=high; cities[i]._DenfenceLevel=defencelev;
		cities[i]._Area=area; cities[i]._PopulationDensity=pop_den;
		//cities[i].GetInfo();
		i++;
	}
	
	infile.close();
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
