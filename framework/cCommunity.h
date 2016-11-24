#ifndef CCOMMUNITY_H_INCLUDED
#define CCOMMUNITY_H_INCLUDED

#include<iostream>
#include<vector>
#include "cPlace.h"
typedef unsigned int UINT;

namespace FrameWork
{
    using namespace std;
    class aCommunity
    {
      protected:
         const UINT _Tag;
         string _Name;
         static UINT _Count;
      public:
        aCommunity(const UINT & tag, const string & name):
           _Tag(tag),_Name(name) {}
        virtual ~aCommunity() {}
        virtual ostream & info(ostream & ros) const=0;
    };

    class Kingdom: public aCommunity
    {
     protected:
        string _King;
        vector<aPlace> *_Cities;
     public:
        Kingdom(const UINT & tag, const string & name, const string & king, vector<City> & cities):
             aCommunity(tag,name),_King(king),_Cities(cities){}
        ~Kingdom() {}
        ostream & info(ostream & ros) const;
    };
};

#endif // CCOMMUNITY_H_INCLUDED
