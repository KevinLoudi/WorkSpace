#include "cCommunity.h"

namespace FrameWork
{
   UINT aCommunity::_Count=0;

   ostream & Kingdom::info(ostream & ros) const
   {
       ros<<"a kingdom named "<<this->_Name<<" , whose king is "<<this->_King<<" and hold "
       <<this->_Cites.size() <<" cities, and hold ";
       if(_Site->empty())
         return ros;
      else
         return ros;  //<<_Site.begin().;
   }
};
