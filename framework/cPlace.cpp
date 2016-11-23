/*
 Author: Kevin
 Propose:
 Environment:
*/

#include "cPlace.h"

namespace FrameWork
{
    UINT Place::_itemNum=0;
    UINT City::_cityNum=0;

    inline PlaceInfo* Place::getInfo() const
    {
        return _placeInfo;
    }

    inline bool Place::updateInfo(PlaceInfo & P)
    {
        *(this->_placeInfo)=P;
        return true;
    }

    ostream & Place::getInfo(ostream & os) const
    {
        os<<"This is a place with an area of "<<_placeInfo->_Area<<endl;
        return os;
    }

};
