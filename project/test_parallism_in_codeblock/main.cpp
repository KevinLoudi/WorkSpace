#include <string>
#include <iostream>
#include <thread>
#include "../../thread/pparallelism.h"

void threadCallback(int x, std::string str)
{
    std::cout<<"Passed Number = "<<x<<std::endl;
    std::cout<<"Passed String = "<<str<<std::endl;
}
int main()
{
    int x = 10;
    std::string str = "Sample String";
    std::thread threadObj(threadCallback, x, str);
    //threadObj.join();
    Paralleism::ThreadRAII safe_thread(threadObj);
    return 0;
}
