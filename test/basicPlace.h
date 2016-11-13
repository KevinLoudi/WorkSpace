#ifndef BASIC_PLACE_H
#define BASIC_PLACE_H
#include <string>
#include <iostream>
#include <ctime>
using namespace std;
typedef unsigned long UINT;

//work as a struct
class PlaceInfo
{
  public:
  	PlaceInfo(double lat=0.0,double lon=0.0,double high=0.0,UINT pd=0,string pr="null products",UINT area=0):_Latitude(lat),
		_Longitude(lon),_High(high),_PopulationDensity(pd),_ProductType(pr),_Area(area){}
	//Basic properties of a place
	double _Latitude;
	double _Longitude; 
	double _High;
	UINT  _PopulationDensity;
	string _ProductType;
	UINT _Area;
	~PlaceInfo(){}
};

class Place
{
	private:
		//information about a place
		PlaceInfo* _placeInfo;
	protected:
		//number of actived place
		static UINT _itemNum;
	public:
		//constructor
		Place(PlaceInfo* p= new PlaceInfo()):_placeInfo(p){_itemNum++;}
		//get information of a place
		virtual PlaceInfo* getInfo() const;
		//override getInfo operation to print information
		virtual ostream & getInfo(ostream & os) const;
		//update information of a place
		virtual bool updateInfo(PlaceInfo &  P);
		//access number of actived place
		virtual UINT getObjectNum() const {return _itemNum;}
		
		
		//deconstructor
		virtual ~Place()
		{
			delete _placeInfo;
			_itemNum--;
		}
};



inline PlaceInfo* Place::getInfo() const
{
	return _placeInfo;
}

inline bool Place::updateInfo(PlaceInfo & P)
{
	*(this->_placeInfo)=P;
	return true;
}

class CityInfo: public PlaceInfo
{
  public:
  	//PlaceInfo Pos;
	//a city has name, holder and denfence level
	string _CityName;
	string _CityHolder; 
	int _DenfenceLevel;
	
	CityInfo(double lat=0.0,double lon=0.0,double high=0.0,UINT pd=0,string pr="null products",UINT area=0,
		string cn="null name",string ch="null holder",int df=0):PlaceInfo(lat,lon,high,pd,pr,area),
		_CityName(cn),_CityHolder(ch),_DenfenceLevel(df){}		

	~CityInfo(){}
};

class City : public Place
{
	private:
		CityInfo* _cityInfo;
	protected:
		static UINT _cityNum;
	public:
		City(CityInfo* c=new CityInfo()):_cityInfo(c)
		{
			_cityNum++;
		}

		PlaceInfo* getInfo() const;
		ostream & getInfo(ostream & os) const;
		bool updateInfo(CityInfo &  C);
		UINT getObjectNum() const {return _cityNum;}
		UINT getPopulation() const;
		bool alterHolder(const string &);
		void investMoney(const UINT cash);
		friend class FileIO;
		friend class Rank;
		~City()
		{
			_cityNum--;
			delete _cityInfo;
		}
};

#endif
