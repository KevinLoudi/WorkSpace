#ifndef BASIC_PLACE_H
#define BASIC_PLACE_H

#include "Place.h"
#include <iostream>
using namespace std;

class City : public Place
{
	public:
	 City(string &name="null place",string &holder="null man",Place pl=new Place[20]):_cityName(name)
	 ,_cityHolder(holder),_places(pl)
	 {cout<<"Build a new city named "<<name<<" and holded by "<<holder;}
	
     virtual string getName(){ return _cityName;}
     void show() const;
     int cal_inhabitants() const;
	 ~City(){delete[] _places;}
	private:
	 const string _cityName;
	 string _cityHolder;	//futer we will change it to be a country class
	 static const int _area=20; //a city defaultly have 20 places
	 const Place _places[_area];
	protected:
		   
};



#endif
