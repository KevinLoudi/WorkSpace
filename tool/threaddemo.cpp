/*thread in stl*/
#include <string>
#include <iostream>
#include <thread>

using namespace std;

// The function we want to execute on the new thread.
void task1(string msg)
{
    cout << "task1 says: " << msg;
}

int main()
{
    // Constructs the new thread and runs it. Does not block execution.
    thread t1(task1, "Hello");

    // Makes the main thread wait for the new thread to finish execution, therefore blocks its own execution.
    t1.join();
}


/*Read-write mutex in boost*/
/*#include <iostream>
#include <boost/thread/thread.hpp>
#include <boost/thread/read_write_mutex.hpp>
#include <string>
using namespace std;

const string EMPTY_QUEUE="empty queue! can not dequeue!!";

template<typename T>
class Queue
{
    public:
      //give writers priority
      Queue():_rwMutex(boost::read_write_scheduling_policy::write_priority){}
      ~Queue(){}

      void enQueue(const T & x)
      {
      	//use r/w lock when enQueue update data
      	boost::read_write_mutex::scoped_write_lock writeLock(_rwMutex);
      	_list.push_back(x);
      }

      T getFront()
      {
      	boost::read_write_mutex::scoped_read_lock readLock(_rwMutex);
      	if(_list.empty())
      		throw EMPTY_QUEUE;
      	return (_list.front());
      }

      void deQueue()
      {
      	boost::read_write_mutex::scoped_write_lock writeLock(_rwMutex);
      	if(_list.empty())
      		throw EMPTY_QUEUE;
        T tmp=_list.front();
        _list.pop_front();
      	return(tmp);
      }
    private:
      std::list<T> _list;
      boost::read_write_mutex _rwMutex;
  };

Queue<string> strQueue;

void send()
{
	string instr="Yan";
	for(int i=0;i<10;i++)
    {
  	 strQueue.enQueue(s);
  	 cout<<"enter "<<s<<" to queue."<<endl;
    }
}

void recv()
{

}

void check()
{
   string s;
   for(int i=0;i<10;i++)
   {
    try
    {
    	s=strQueue.getFront();
    	cout<<"the front element is "<<s<<endl;
    }
    catch(string es)
    {
    	cout<<es<<endl;
    }
   }
}

int main()
{
	boost::thread writer(send);
	boost::thread_group grp;

	grp.create_thread(check);
	grp.create_thread(check);
	grp.create_thread(check);
	grp.create_thread(check);
	grp.create_thread(check);
	grp.create_thread(check);
	grp.create_thread(check);

	thr1.join();
	grp.join_all();
}*/

/*#include <boost/thread/thread.hpp>
#include <iostream>
#include <string>
using namespace std;

const string EMPTY_QUEUE="empty queue! can not dequeue!!";

template<typename T>
class Queue
{
    public:
      Queue(){}
      ~Queue(){}

      void enQueue(const T& x)
      {
      	//lock the mutex for this queue, and the scope_lock
      	//is automatically destory after it goes out of range
      	 boost::mutex::scoped_lock lock(_mutex);
      	_list.push_back(x);
      }

      T deQueue()
      {
      	boost::mutex::scoped_lock lock(_mutex);
      	if(_list.empty())
      	{
      		throw EMPTY_QUEUE;
      	}
      	T tmp=_list.front();
      	_list.pop_front();
      	return (tmp);
      }

    private:
      std::list<T> _list;
      boost::mutex _mutex;
};

Queue<string> strQueue;

void send()
{
  string s="Yan";
  for(int i=0;i<10;i++)
  {
  	strQueue.enQueue(s);
  	cout<<"enter "<<s<<" to queue."<<endl;
  }
}

void recv()
{
  string tmpstr;
  for(int i=0;i<10;i++)
  {
  	try
  	{
  		tmpstr=strQueue.deQueue();
  		cout<<"remove "<<tmpstr<<" from the queue."<<endl;
  	}
  	catch(string es)
  	{
  		cout<<es<<endl;
  	}
  }
}

int main()
{
    //only throguh one-by-one way can they
    //conduct in an order
	boost::thread thr1(send);
	thr1.join();

	boost::thread thr2(recv);
	thr2.join();

	return 0;
}*/

// #include <iostream>
// #include <string>
// #include <vector>
// #include <boost/thread/thread.hpp>
// #include <boost/thread/xtime.hpp>
// using namespace std;

// template<typename T>
// class Queue;

// void add_to_queue(const string& s, Queue & q);
// void remove_from_queue(string[] s,Queue & q);

// struct ThreadFunction;
// static int count=0;
// const string EMPTY_QUEUE="empty queue! can not dequeue!!";

// int main()
// {
//   boost::thread aThread(threadFunction);
//   //sleep the current thread
//   boost::thread::yield();
//   //tell the call thread to wait for the end of called thread
//   aThread.join();
//   std::cout<<"print from the main thread."<<std::endl;

//   //create a series of thread
//   boost::thread_group grt;

//   //the first method to add a thread to the group
//   boost::thread* p=new boost::thread(threadFunction);
//   grt.add_thread(p);

//   //the second method to manage a thread group
//   grt.create_thread(threadFunction);
//   grt.create_thread(threadFunction);

//   //join all thread
//   grt.join_all();

//   //find and delet the thread pointer pointed object
//   grt.remove_thread(p);

//   //test for mutex
//   Queue<std::string> strQueue;
//   string instr="Yan";
//   string[12] outstr;
//   boost::thread write(add_to_queue(instr));
//   boost::thread read(remove_from_queue());

//   write.join();
//   read.join();
//   return 0;
// }

// template<typename T>
// class Queue
// {
//     public:
//       Queue(){}
//       ~Queue(){}

//       void enQueue(const T& x)
//       {
//       	//lock the mutex for this queue, and the scope_lock
//       	//is automatically destory after it goes out of range
//       	boost::mutex::scoped_lock;
//       	_list.push_back(x);
//       }

//       T deQueue()
//       {
//       	if(_list.empty())
//       	{
//       		throw EMPTY_QUEUE;
//       	}
//       	//T tmp=_lish.front();
//       	return _list.pop_front();
//       }

//     private:
//       std::list<T> _list;
//       boost::mutex _mutex;
// };

// void add_to_queue(const string& s,Queue & q)
// {
// 	for(int i=0;i<10;i++)
// 	{
// 		q.enQueue(s);
// 	}
// }

// void remove_from_queue(string[] s,Queue & q)
// {
// 	for(int i=10;i>0;i--)
// 	{
// 		try
// 		{
// 			s[i]=q.deQueue();
// 			//immediatly output the contents
// 			cout<<s[i]<<endl;
// 		}
// 		catch(string es)
// 		{
// 			cout<<es<<endl;
// 		}
// 	}
// }

// struct ThreadFunction
// {
//    void operator()()
//    {
//    	 std::cout<<"print from the "<<count++<<" sub thread."<<std::endl;
//    }
// } threadFunction;


