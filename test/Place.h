#ifndef PLACE_H
#define PLACE_H

#include<string>
#include<iostream>
using namespace std;

typedef unsigned long UINT;

class Place
{
	private:

	protected:
		//Basic properties of a place
		double _Latitude;
		double _Longitude; 
		double _High;
		UINT  _PopulationDensity;
		string _ProductType;
		UINT _Area;	
	public:
		//customized construct with parmeters-list and default value
		Place(double lat=0.0,double lon=0.0,double high=0.0,UINT pd=0,string pr="null products",UINT area=0):_Latitude(lat),
		_Longitude(lon),_High(high),_PopulationDensity(pd),_ProductType(pr),_Area(area)
		{ 
		 //cout<<"build a place."<<endl;
		}
		
		//pure virtual function with no implementation and reserved for dynamic binding
		virtual ostream & GetInfo(ostream & os) const=0;
		
		//destructor
		virtual ~Place()
		{
			//cout<<"remove a place"<<endl;
		}
};


#endif
