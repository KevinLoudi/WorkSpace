#include "cEvent.h"

namespace FrameWork
{
    ostream & War::info(ostream & ros) const
    {
        return ros<<"a war happen in "<<(this->_where.name())<<" and caused "<<this->_Casulty<<" death during the "
        <<this->_Period<<" months"<<endl;
    }
};
