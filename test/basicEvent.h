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
#include <iostream>
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
    EventModel() {}
    virtual ostream & getInfo(ostream & ros) const=0;
    virtual ~EventModel() {}
};

class EventObject
{
           protected:
               string _name;
               int _population;
               int _production;
           public:
               //number of involved objects
               static USINT _object_num;
               EventObject(const std::string &s = std::string(),const int po=8000, const int pr=2)
               :_name(s),_population(po),_production(pr){_object_num++;}
               //copy constructor
               EventObject(const EventObject& o):_name(o._name),_population(o._population),
               _production(o._production) {_object_num++;}
               //copy assignment operator
               EventObject & operator=(const EventObject &o)
               {
                   if(this==&o) //not do copy when the input object indentical to this one
                   {
                       this->_name=o._name;
                       this->_population=o._population;
                       this->_production=o._production;
                   }
                   _object_num++;
                   return *this;
               }

               ostream & getInfo(ostream & ros) const
               {
                   return ros<<this->_name<<endl;
               }
               ~EventObject() {_object_num--;}
};

  namespace GeneralEvent
  {
        class Disaster: public EventModel
        {
            protected:
                int _casualties;
                std::string *_describe;
                EventObject *_object;
            public:
                size_t *_use_count;
                //copy the content of a pointer rather than its address, especially when the class member is a pointer
                Disaster(const int c=100, const string & de=string(),const EventObject & e=EventObject()):
                    _casualties(c),_describe(new string(de)),_object(new EventObject(e)),_use_count(new size_t(1)){*_use_count++;}
                //copy constructor
                Disaster(const Disaster & di):_casualties(di._casualties), _describe(new string(*di._describe)),
                _object(new EventObject(*di._object)){}
                //always copy pointer oriented to its content, do deep copy
                Disaster & operator=(const Disaster & di)
                {
                    //create a new pointer and delete the old pointer
                    ++*di._use_count;
                    if(--*_use_count==0)
                    {
                        delete _object;
                        delete _describe;
                    }
                    //auto *pnew_de = new string(*di._describe);
                    //auto *pnew_ev = new EventObject(*di._object);
                    _casualties=di._casualties;
                    _describe=di._describe; //copy two pointer
                    _object=di._object;
                    _use_count=di._use_count;
                    return *this;
                }
                ostream & getInfo(ostream & ros) const
                {
                    //string obj_name=
                    return ros<<_casualties<<" in "<<(_object->getInfo(ros))<<"|"<<(*_describe)<<endl;
                }
                ~Disaster() {
                    if(*--_use_count==0)
                    {
                        delete _describe;//explict delete
                        delete _use_count;
                    }
                }
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
            };
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
