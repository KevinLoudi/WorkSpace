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
//class Place;
//class Noble;
//class NobleFamily;

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
    const std::string _time;
    Place _site;
    //vector<Noble> _people;
public:
    EventModel();
    virtual std::ostream getInfo(std::ostream & os) const=0;
    virtual ~EventModel();
};

class EventObject
{
           protected:
               std::string _name;
               int _population;
               int _production;
           public:
               EventObject(const std::string &s = std::string(),const int po=8000, const int pr=2)
               :_name(s),_population(po),_production(pr){}
               //copy constructor
               EventObject(const EventObject& o):_name(o._name),_population(o._population),
               _production(o._production) {}
               //copy assignment operator
               EventObject & operator=(const EventObject &o)
               {
                   if(this==&o) //not do copy when the input object indentical to this one
                   {
                       this->_name=o._name;
                       this->_population=o._population;
                       this->_production=o._production;
                   }
                   return *this;
               }

               std::ostream getInfo(std::ostream & os) const;
               ~EventObject() {}
};

  namespace GeneralEvent
  {
        class Disaster: public EventModel
        {
            protected:
                int _casualties;
                std::string *_describe;
                EventObject _object;
            public:
                Disaster(const int c, const std::string &d = std::string(), const EventObject & e=EventObject):
                    _casualties(c),_describe(new std::string(d),_object(e){}
                std::ostream getInfo(std::ostream & os) const {}
                ~Disaster() {}
        };

        class Unrest: public EventModel
        {

        };

        class Fortune: public EventModel
        {

        };

    /*namespace SpecificEvent
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
        }*/
  };
};
};


//namespace Object
//{
//    using std::string;
//    using std::ostream;
//    using std::endl;
//    class ObjectModle
//    {
//       protected:
//
//       public:
//           ObjectModle() {}
//           virtual void getInfo(ostream & os) const = 0;
//           virtual ~ObjectModle() {}
//    };
//    namespace GeneralObject
//    {
//
//    }
//}





#endif // BASIC_EVENT_H
