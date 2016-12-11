#include <iostream>
#include <thread>
#include <time.h>

const int REPETI_TIMES=1000;
const int DISPLAY_GAP=100;

void thread_fun();
clock_t main_bgin=0;
clock_t main_end=0;
clock_t sub_begin=0;
clock_t sub_end=0;

class thread_class
{
public:
    void operator()()
    {
        int ix=0;
        while(ix++<REPETI_TIMES)
        {
            if(ix%DISPLAY_GAP==0) std::cout<<std::this_thread::get_id()<<"function objects thread execute for "
                <<ix<<" steps\n";
        }
    }
};

int main()
{
    main_bgin=clock();
    /**function pointer */
    std::thread threadObj(thread_fun);
    /**function objects */
    std::thread threadObj2((thread_class()) ); //avoid parse problem
    /**create thread using lambda functions */
    std::thread threadObj3([] {
                           int ix=0;
                           while(ix++<REPETI_TIMES)
                           {
                               if(ix%DISPLAY_GAP==0) std::cout<<std::this_thread::get_id()<<"lambda thread execute for "
                                <<ix<<" steps\n";
                           }
                           });
    int ix=0;
    while(ix++<REPETI_TIMES)
    {
        if(ix%DISPLAY_GAP==0) std::cout<<std::this_thread::get_id()<<"main thread execute for "
            <<ix<<" steps\n";
    }
    threadObj3.join();
    threadObj2.join();
    threadObj.join();

    std::cout << "Main thread exit\n";
    main_end=clock();
    double main_time=(double)(main_end-main_bgin)/CLOCKS_PER_SEC;
    double sub_time=(double)(sub_end-sub_begin)/CLOCKS_PER_SEC;
    std::cout <<"Main thread time cost: "<<main_time<<"||sub thread time cost: "<<sub_time<<"\n";
    return 0;
}

/**create a thread using function pointer */
void thread_fun()
{
    sub_begin=clock();
    int ix=0;
    while(ix++<REPETI_TIMES)
    {
        if(ix%DISPLAY_GAP==0) std::cout<<std::this_thread::get_id()<<"function pointer thread execute for "
            <<ix<<" steps\n";
    }
    sub_end=clock();
}



