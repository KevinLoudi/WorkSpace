#include "cCommunity.h"

namespace FrameWork
{
   UINT aCommunity::_Count=0;

   ostream & Kingdom::info(ostream & ros) const
   {
       return ros<<"a kingdom named "<<this->_Name<<" , whose king is "<<this->_King<<" and hold "
       <<this->_Cites.size() <<" cities"<<endl;
   }
};
