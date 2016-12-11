#ifndef PPARALLELISM_H_INCLUDED
#define PPARALLELISM_H_INCLUDED

#include <time.h>

namespace Paralleism
{
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

//prevent the forgot call to join or detach associated thread
class ThreadRAII
{
public:
    ThreadRAII(std::thread & thread_obj): m_thread(thread_obj) {}
    ~ThreadRAII()
    {
        if(m_thread.joinable())
            m_thread.join();
    }
    std::thread & m_thread;
};



};

#endif // PPARALLELISM_H_INCLUDED
