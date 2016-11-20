#include <cstdlib>
#include <ctime>
#include <iostream>
#include "../Community.h"
#include "../GobalDefine.h"
using namespace std;

int gen_random_num(const int low, const int high);
void gen_random_name(char* s, const int len);
void gen_random_name_and_len(char* s, const int low, const int high);

/* still remain some dilemmas that I cannot pack the random generator into a class (tried but failed),
   for it can only be seed once, static memeber might be a solution but other replacement
   from <random.h> or boost could be better since rand() is not a good choice for different
   distributions (only normal-distribution provided).
*/

int main()
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
   system("pause");
	return 0;
}

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

