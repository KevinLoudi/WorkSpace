#ifndef CPLACE_H_INCLUDED
#define CPLACE_H_INCLUDED

#include<iostream>

typedef unsigned int UINT;

namespace FrameWork
{
    using namespace std;
    //abstract class aPlace
    class aPlace
    {
       protected:
          const UINT _Lat;
          const UINT _Lon;
       public:
         aPlace(const UINT & lat,const UINT & lon ):_Lat(lat),_Lon(lon){}
         virtual ~aPlace() {}
         virtual ostream & info(ostream & ros) const=0;
    };

    class City: public aPlace
    {
       protected:
         const string _Name;
         UINT _Population;
       public:
         City(const UINT & lat,const UINT & lon,const string & name, const UINT & pop):
             aPlace(lat,lon),_Name(name),_Population(pop){}
         //copy constructor
         City(const City& c): aPlace(c._Lat, c._Lon),_Name(c._Name),_Population(c._Population) {}
         ~City(){}
         //get name
         string name() const {return this->_Name;}
         ostream & info(ostream & ros) const;
    };

    class Mountian: public aPlace
    {
      protected:
        const UINT _High;
        UINT _Denfence;
      public:
        Mountian(const UINT & lat,const UINT & lon,const UINT & high,const UINT & den):
            aPlace(lat,lon),_High(high),_Denfence(den){}
         ~Mountian() {}
         ostream & info(ostream & ros) const;
    };

    class Farmland: public aPlace
    {
      protected:
        const string _Crop;
        UINT _Productive;
     public:
         Farmland(const UINT & lat,const UINT & lon, const string & crop, const UINT & pro):
            aPlace(lat,lon),_Crop(crop),_Productive(pro){}
         ~Farmland() {}
         ostream & info(ostream & ros) const;
    };
};



#endif // CPLACE_H_INCLUDED
