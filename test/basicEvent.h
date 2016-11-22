/*
 Author: Kevin
 Propose: create a series of event model template to power the map, meanwhile cultivate better program
 habits
 Environment: Code::Block with GCC 4.9 , C++ 11
*/
#ifndef BASIC_EVENT_H
#define BASIC_EVENT_H
#include <iostream>
#include "GobalDefine.h"

typedef unsigned short int USINT;
extern USINT _event_tag;

//using forward declaration to replace abuse of #include instructors
class Place;
class Noble;
class NobleFamily;

//using name space to avoid collision
//Multilayer name space make the class-to-class logical relationship more clear
//Event::EventModel::GeneralEvent::SpecificEvent::DetailedEvent
namespace Event
{
//avoid abuse of "using namespace std" likewise to reduce potential name collision,
using std::string;
using std::ostream;
using std::endl;

class EventModel
{
protected:
    //the simplest event, with only ID and 3W (when, where, who)
    USINT _tag;
    string _time;
    Place _site;
    //vector<Noble> _people;
public:
    EventModel();
    virtual void getInfo(ostream & os) const=0;
    virtual ~EventModel();
};
  namespace GeneralEvent
  {
        class Disaster: public EventModel
        {

        };

        class Unrest: public EventModel
        {

        };

        class Fortune: public EventModel
        {

        };

        namespace SpecificEvent
        {
            class Drought: public Disaster
            {

            };

            class Revolt: public Unrest
            {

            };

            class Harvest: public Fortune
            {

            };

            namespace DetailedEvent
            {
                class NobleRevolt: public Revolt
                {

                };

                class PeasantUprising: public Revolt
                {

                };
            }
        }
  }









}






#endif // BASIC_EVENT_H
