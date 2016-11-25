/*
  Author : kevin
  Propose: Gobally define for the framework
  Environment: GCC 4.9 in IDE Code::Blocks
*/
#ifndef CGOBALDEFINE_H_INCLUDED
#define CGOBALDEFINE_H_INCLUDED

#include "../framework/cPlace.h"
#include "../framework/cCommunity.h"
#include "../framework/cEvent.h"
#include "cAlgorithm.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <thread>

typedef unsigned int UINT;
enum ERR_CODE {FAIL=0, SUCCESS=1};

namespace Gobal
{
    using namespace std;
    using FrameWork::City;
    typedef FrameWork::City City_;
    typedef FrameWork::Kingdom Kingdom_;
    const static string DEFAULT_PATH="D:\\Code\\WorkSpace\\Framework\\data";//"../data";
    class FileIO
    {
     private:
         string _InPath;
         string _OutPath;
     public:
         FileIO(const string & inpath=DEFAULT_PATH, const string & outpath=DEFAULT_PATH):
             _InPath(inpath),_OutPath(outpath) {}
         ~FileIO(){}
         //cannot use
         /*save a City object to binary file*/
         ERR_CODE SaveCitytoBinaryFile(const City & source_city, const string & tragt_name) const;
         /*load a City object from a binary file*/
         ERR_CODE ReadCityfromBinaryFile(const string & source_name, City & target_city, const int & target_size) const;
         /*save each data field of a City object to text file*/
    };

    class TimeLine
    {
    private:
        const UINT _StartPoint;
        UINT _Speed;
        UINT _StopPoint;
        static UINT _CurrentTime;
    public:
        TimeLine(UINT start=758, UINT speed=1, UINT stop=2016):_StartPoint(start),_Speed(speed),_StopPoint(stop){}
        ~TimeLine() {_CurrentTime=_StartPoint;}
        /*return current time*/
        UINT CurrentUniverseTime() {return _CurrentTime;}
        /*pass a year*/
        void UniverseTimePass() {_CurrentTime+=_Speed;}
    };

    /*in this universe, each country stands a thread that run concurrently on the universal time-line, and this powers the
      whole universe*/
    //how to implement multi-thread in class
    class PowerUniverse
    {
    private:
        static UINT _ThreadNum;
    public:
        //do not allow implicit conversion
        explicit PowerUniverse() {}
        ~PowerUniverse() {}
    };
};
#endif // CGOBALDEFINE_H_INCLUDED
