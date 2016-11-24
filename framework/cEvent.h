#ifndef CEVENT_H_INCLUDED
#define CEVENT_H_INCLUDED
#include<iostream>
#include "cPlace.h"
#include "cCommunity.h"
typedef unsigned int UINT;

namespace FrameWork
{
    using namespace std;
    class aEvent
    {
    protected:
        City _where;
        const UINT _when;
        vector<Kingdom> _who;
    public:
        aEvent(const City where, const UINT & when, vector<Kingdom> & who ):
            _where(where), _when(when),_who(who){}
        virtual ~aEvent() {}
        virtual ostream & info(ostream & ros) const=0;
    };

    class War: public aEvent
    {
    protected:
        UINT _Casulty;
        const UINT _Period;
    public:
        War(const City where, const UINT & when, vector<Kingdom> & who,const UINT & cas, const UINT & time):
            aEvent(where,when,who),_Casulty(cas),_Period(time){}
        ~War() {}
        ostream & info(ostream & ros) const;
    };
};

#endif // CEVENT_H_INCLUDED
