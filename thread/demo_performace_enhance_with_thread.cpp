#include <iostream>
#include <thread>
#include <algorithm>
#include <time.h>
/**THREAD_NUM=1, execute time=0.507s, THREAD_NUM=2, execute time=0.482s
     THREAD_NUM=8, execute time=0.447s */
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


int main()
{
   code_timer main_timer;
   main_timer.Tigger();
   std::vector<std::thread> thread_list;
   int ix=0;
   while(ix++<THREAD_NUM)
   {
       thread_list.push_back(std::thread(thread_class() ));
   }
   std::cout<<"waiting for work thread..\n";
   std::for_each(thread_list.begin(), thread_list.end(), std::mem_fn(&std::thread::join));
   main_timer.Collect();
   std::cout<<"exit from main thread with time cost of "<<main_timer.GetTime()<<"\n";
}
