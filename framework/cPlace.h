#ifndef CPLACE_H_INCLUDED
#define CPLACE_H_INCLUDED

namespace FrameWork
{
    using namespace std;
    class PlaceInfo
    {
    public:
  	 explicit PlaceInfo(double lat=0.0,double lon=0.0,double high=0.0,UINT pd=0,string pr="null products",UINT area=0):_Latitude(lat),
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
		explicit Place(PlaceInfo* p= new PlaceInfo()):_placeInfo(p){_itemNum++;}
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
};



#endif // CPLACE_H_INCLUDED
