/*
 Author: Kevin
 Propose:
 Environment:
*/

#include "cPlace.h"

namespace FrameWork
{
    ostream & City::info(ostream & ros) const
    {
        return ros<<"a city named "<<this->_Name<<" with a population of "<<this->_Population<<endl;
    }

    ostream & Mountian::info(ostream & ros) const
    {
        return ros<<"a mountain region with high "<<this->_High<<" and denfence level of "<<this->_Denfence<<endl;
    }

    ostream & Farmland::info(ostream & ros) const
    {
        return ros<<"a farmland region plant "<<this->_Crop<<" as a productivity of "<<this->_Productive<<endl;
    }
};
