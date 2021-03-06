/*Create a group of thread */
#include <iostream>
#include <cstdlib>
#include <vector>
#include <pthread.h>
using namespace std;
const int NUM_THREADS=5;

void CheckThreadCreation();
void *ThreadWork(void *threadid);

/*int main()
{
    CheckThreadCreation();
    return 0;
}*/

void CheckThreadCreation()
{
    pthread_t threads[NUM_THREADS];
    int ix=0; int rc=0;
    while(ix<NUM_THREADS)
    {
        cout << "|| main() : creating thread, " << ix <<"||"<< endl;
        rc=pthread_create(threads+ix, NULL, ThreadWork, (void *)ix);

        if(rc)
        {
            cout << "Error:unable to create thread," << rc << endl;
            exit(-1);
        }
        ++ix;
    }

    pthread_exit(NULL);
}

void *ThreadWork(void *threadid)
{
    long tid;
    //avoid miss the pointer badly
    tid=*((int*)(&threadid));
    cout<<"|| Thread ID: "<<tid<<"||"<<endl;
    pthread_exit(NULL);
}
