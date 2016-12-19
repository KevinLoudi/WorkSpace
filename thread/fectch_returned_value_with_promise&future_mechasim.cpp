/**Author: Kevin  Date: 2016.12.19
    Propose: (Multi-Thread) Fetch a value outside the thread before
    it is set with std::promise and std::future mechanism
*/
#include <iostream>
#include <thread>
#include <future>
using namespace std;

//'promise' object promises to set the value in future
//Each std::promise object has an associated std::future object
void threadWork(promise<int>* promObj)
{
    cout<<"Inside thread\n";
    //realize the promise to set the value
    promObj->set_value(135);
}

//create a 'promise' object and a 'future' object
int main()
{
    promise<int> promObj; //promise object doesn¡¯t have any associated value
    // 'future' object stores the future value, internally stores
    //a value that will be assigned in future and it also provides
    //a mechanism to access that value
    future<int> futerObj=promObj.get_future();
    thread t1(threadWork, &promObj);
    // if somebody tries to access this associated value of future
    //through get() function before it is available, then get() function
    //will block till value is not available.
    cout<<futerObj.get()<<"\n"; //get block until the promise is realized
    if(t1.joinable())
        t1.join();
    return 0;
}
