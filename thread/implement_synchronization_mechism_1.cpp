#include <thread>
#include <mutex>
#include <iostream>
using namespace std;

/*checking variables consume CPU cycles and will
  also make Thread 1 slow*/

class Application
{
public:
    Application()
    {
        m_bDataLoaded=false;
    }
    void DataLoader()
    {
        //thread sleep for 1 second
        this_thread::sleep_for(chrono::milliseconds(1000));
        cout<<"Loading Data\n";

        //lock
        lock_guard<mutex> guard(m_mutex);

        //data is loaded, set the flag to true
        m_bDataLoaded=true;
    }

    void ThreadCommunication()
    {
        cout<<"Handshaking\n";

        //acquire lock
        m_mutex.lock();
        //check if the flag is true, then
        while(m_bDataLoaded!=true)
        {
            m_mutex.unlock();
            this_thread::sleep_for(chrono::milliseconds(100));
            m_mutex.lock();
        }
        //release the lock
        m_mutex.unlock();
        cout<<"Processing the data\n";
    }
private:
    mutex m_mutex;
    bool m_bDataLoaded; //a gobal variable for thread synchronization
};

int main()
{
    Application app;
    thread thread1(&Application::ThreadCommunication, &app);
    thread thread2(&Application::DataLoader, &app);

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
