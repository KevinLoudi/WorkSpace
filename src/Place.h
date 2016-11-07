#ifndef PLACE_H
#define PLACE_H

#include<string>
#include<iostream>
using namespace std;

typedef unsigned long UINT;

class Place
{
	private:
		double _Latitude;
		double _Longitude; 
		double _High;
	protected:
		UINT  _PopulationDensity;
		string _ProductType;
		UINT _Area;	
	public:
		Place();
		virtual void GetInfo()=0;
		virtual ~Place();
};

#endif
