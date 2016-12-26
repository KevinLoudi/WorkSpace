#pragma once
#include <time.h>

class code_timer
{
public:
    explicit code_timer():start(0.0),stop(0.0),runtime(0.0) {}
    ~code_timer() {}

    void Tigger() {start=clock();}
    void Collect() {stop=clock();}
    double GetTime() {return runtime=(double)(stop-start)/CLOCKS_PER_SEC;}
private:
    clock_t start;
    clock_t stop;
    double runtime;
};