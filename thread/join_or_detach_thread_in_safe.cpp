#include <iostream>
#include <thread>
#include <algorithm>
#include <time.h>
#include "../../thread/pparallelism.h"

const int REPETI_TIMES=10000;
const int DISPLAY_GAP=100;
const int THREAD_NUM=3;

class thread_class
{
public:
    void operator()()
    {
        int ix=0;
        while(ix++<REPETI_TIMES/THREAD_NUM)
        {
            if(ix%DISPLAY_GAP==0) std::cout<<std::this_thread::get_id()<<"function objects thread execute for "
                <<ix<<" steps\n";
        }
    }
};

/**create a thread using function pointer */
void thread_fun()
{
    int ix=0;
    while(ix++<REPETI_TIMES/THREAD_NUM)
    {
        if(ix%DISPLAY_GAP==0) std::cout<<std::this_thread::get_id()<<"function pointer thread execute for "
            <<ix<<" steps\n";
    }
}

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

int main()
{
   Paralleism::code_timer main_timer;
   main_timer.Tigger();
   std::thread threadObj((thread_class() ) );
   std::thread threadObj2((thread_class() ) );
   std::thread threadObj3(thread_fun);
   /**join or detach thread with no associated executing thread, or the program will terminate */
   if(threadObj.joinable())
   {
       threadObj.join();
   }
   if(threadObj2.joinable())
   {
       threadObj2.detach();
   }

   /**prevents with we should use RESOURCE ACQUISITION IS INITIALIZATION (RAII) */
   ThreadRAII safe_thread(threadObj3);

   main_timer.Collect();
   std::cout<<"exit from main thread with time cost of "<<main_timer.GetTime()<<"\n";
}
