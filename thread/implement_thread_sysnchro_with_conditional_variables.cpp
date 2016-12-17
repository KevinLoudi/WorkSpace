#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>
using namespace std;

class Application
{
public:
    Application()
    {
        m_bDataLoaded=false;
    }
    void loadData()
    {
        //sleep this thread for 1 second
        this_thread::sleep_for(chrono::milliseconds(1000));
        cout<<"Loading Data\n";
        lock_guard<mutex>guard(m_mutex); //lock
        m_bDataLoaded=true; //set the flag
        m_convar.notify_one(); //notify the condition variable
    }
    bool isDataLoaded() {return m_bDataLoaded;}
    void threadCommu()
    {
        cout<<"hand shaking\n";
        //acquire the lock
        unique_lock<mutex> mlock(m_mutex);
       // Start waiting for the Condition Variable to get signaled
       // Wait() will internally release the lock and make the thread to block
       // As soon as condition variable get signaled, resume the thread and
       // again acquire the lock. Then check if condition is met or not
       // If condition is met then continue else again go in wait.
        m_convar.wait(mlock, bind(Application::isDataLoaded,this));
        cout<<"processing data\n";
    }
private:
    mutex m_mutex;
    condition_variable m_convar;
    bool m_bDataLoaded;
};

int main()
{
    Application app;
    thread thread1(&Application::threadCommu, &app);
    thread thread2(&Application::loadData, &app);

    if(thread1.joinable())
    {
        thread1.join();
    }
    if(thread2.joinable())
    {
        thread2.join();
    }
    return 0;
}
