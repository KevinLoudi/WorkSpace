#include <string>
#include <iostream>
#include <thread>
#include "../../thread/pparallelism.h"

void threadCallback(int x, std::string str)
{
    std::cout<<"Passed Number = "<<x<<std::endl;
    std::cout<<"Passed String = "<<str<<std::endl;
}

void threadCallback_ref(int const &x)
{
    int &y =const_cast<int &>(x);
    y++;
    std::cout<<"Inside thread x="<<x<<"\n";
}

//pass the pointer to member function as callback function
class ThreadWork
{
public:
    ThreadWork() {}
    ~ThreadWork() {}
    void Task(int x)
    {
        std::cout<<"Inside sampleMemberFunction "<<x<<std::endl;
    }
};

int main()
{
    int a = 10;
    std::string str = "Sample String";
    //do not pass addresses of variables from local stack to thread, out of scope
    //and not pass pointer to memory located on the heap to thread, because some thread
    //  might deletes that memory before other thread tries to access it.
    //  so it's safe to pass-by-value
    std::thread threadObj(threadCallback, a, str);
    //threadObj.join();
    Paralleism::ThreadRAII safe_thread(threadObj);

    //try to modify variable inside thread by pass-by-reference
    int x=9;
    std::cout<<"Main thread (before) x="<<x<<std::endl;
    std::thread threadObj2(threadCallback_ref, x);
    Paralleism::ThreadRAII safe_thread2(threadObj2);
    //the inside changes is not visible outside
    std::cout<<"Main thread (after) x="<<x<<std::endl;

    //visible inside changes
    int b=9;
    std::cout<<"Main thread (before) x="<<b<<std::endl;
    std::thread threadObj3(threadCallback_ref, std::ref(b));
    Paralleism::ThreadRAII safe_thread3(threadObj3);
    //the inside changes is not visible outside
    std::cout<<"Main thread (after) x="<<b<<std::endl;

    //using a class and function pointer
    ThreadWork work_obj;
    int c=9;
    std::thread threadObj4(&ThreadWork::Task, &work_obj, c);
    if(threadObj4.joinable()) threadObj4.join();
    return 0;
}
