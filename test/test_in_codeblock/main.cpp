#include <cstdlib>
#include <ctime>
#include <vector>
#include <iostream>
#include "../GobalDefine.h"

using namespace std;

int gen_random_num(const int low, const int high);
void gen_random_name(char* s, const int len);
void gen_random_name_and_len(char* s, const int low, const int high);
void test_community_module();
void test_event_module();

/* still remain some dilemmas that I cannot pack the random generator into a class (tried but failed),
   for it can only be seed once, static memeber might be a solution but other replacement
   from <random.h> or boost could be better since rand() is not a good choice for different
   distributions (only normal-distribution provided).
*/

int main()
{
   test_event_module();
   system("pause");
	return 0;
}

void test_event_module()
{
    using namespace Event;
    using namespace Event::GeneralEvent;
    EventObject Yan("Yan",28000,15);
    cout<<Yan.getInfo(cout);
    const int death_num=2000;
    const string info="two thousands people die in the illness";
    Disaster Illness(death_num,info,Yan);
    cout<<Illness.getInfo(cout);

    //initial a group of event for the object
    vector<Disaster> BlowWind;

    for(int i=0; i<10; ++i)
    {
        int ca=gen_random_num(100,5000);
        char de[20];
        gen_random_name_and_len(de, 10, 20);
        Disaster d(ca,string(de),Yan);
        cout<<d.getInfo(cout);
        //BlowWind.push_back(Disaster(ca,string(de),Yan));
    }
    return;
}

/*void test_community_module()
{
   vector<Noble> nobles;
   const int noblenum=20;
   size_t ix=noblenum;
   do
   {
   	   char tmpname[10]="Abcd";
   	   USINT tmpinfluence=0;
   	   //generate a name first-upped with random length
	   gen_random_name_and_len(tmpname,3,9);
   	   tmpinfluence=gen_random_num(0,100);

   	   //create a noble
   	   cout<<"noble "<<tmpname<<" has an influence of "<<tmpinfluence<<endl;
   	   Noble tmpNoble(tmpname,tmpinfluence);
   	   nobles.push_back(tmpNoble);

   	   ix--;
   }while(ix);

   char tmpname2[15]="Abcd";
   USINT leaderix=gen_random_num(0,noblenum-1);
   gen_random_name_and_len(tmpname2,5,12);
   //randomly elect a leader, future to sort by influence
   NobleFamily Golden_Family(tmpname2,nobles,nobles[leaderix].getName());
   cout<<Golden_Family.printInfo(cout);
}*/

int gen_random_num(const int low, const int high)
{
	return rand()%(high-low+1)+low;
}

void gen_random_name(char* s, const int len)
{
        const char alphanum[] =
        "abcdefghijklmnopqrstuvwxyz";
         const char ALPHANUM[] =
         "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
         // Generate ten pseudo-random numbers
         s[0]=ALPHANUM[gen_random_num(0,(sizeof(ALPHANUM)-1))];
         for (int i = 1; i < len; i++)
         {
           s[i]=alphanum[gen_random_num(0,(sizeof(alphanum)-1))];
         }
         s[len]=0;
}

void gen_random_name_and_len(char* s, const int low, const int high)
{
    	int len=gen_random_num(low,high);
    	gen_random_name(s,len);
}

