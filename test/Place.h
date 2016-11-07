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
		Place(double lat=0.0,double lon=0.0,double high=0.0,UINT pd=0,string pr="null products",UINT area=0):_Latitude(lat),
		_Longitude(lon),_High(high),_PopulationDensity(pd),_ProductType(pr),_Area(area)
		{ cout<<"this is a place."<<endl;}
		virtual void GetInfo() const;
		virtual ~Place(){cout<<"\nremove a place";}
};

void Place::GetInfo() const
{
	cout<<"a place."<<endl;
}

#endif
