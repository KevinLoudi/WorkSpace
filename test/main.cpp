#include <iostream>
#include <memory>
#include <vector>
#include <ctime>
#include <random>
#include "Community.h"
#include "GobalDefine.h"


/* run this program using the console pauser or add your own getch, system("pause") or input loop */
//'auto-ptr' has been deprecated in favor of 'std::unique_ptr'
// which brings warning
void UsePointer(std::auto_ptr <Person> spObj);
//demostrate the creation of a NobleFamily object
void CreataNobleFamily();
//generate a random string with a length and first character upped
void gen_random_name(char *s, const int len);
//generate a random num within a scope
size_t gen_random_num(const size_t low, const size_t high);
//display person-like object information
void Display(const Community & group);

int main(int argc, char** argv) {
	using namespace std;
	//srand (time());
	Person p;
	p.printInfo(cout);
	
	smart_pointer <Person> pPer(p);
	pPer->printInfo(cout);

	//use built-in auto pointer
	auto_ptr <Person> pPer2(new Person());
	//transfer ownership
	UsePointer(pPer2);

	CreataNobleFamily();
	
	return 0;
}

void CreataNobleFamily()
{
   using namespace std;
   const size_t noblenum=10;
   vector<Noble> nobles;
   size_t ix=noblenum; 
   do
   {
   	 char tmpname[10]="Abcd";
   	 //generate a name first-upped with random length
   	 gen_random_name(tmpname,gen_random_num(3,9));
   	 Noble tmp(string(tmpname),gen_random_num(0,100));
   	 nobles.push_back(tmp);
   	 ix--;
   }while(ix);

   char familyname[15]="Abcd";
   gen_random_name(familyname,gen_random_num(5,10));
   NobleFamily afamily(string(familyname),nobles,nobles[0].getName()); 
   Display(afamily);
   
   //delete[] tmpname;
   //delete[] familyname;
}

void Display(const Community & group)
{
	cout<<group.printInfo(cout);
}

void gen_random_name(char* s, const int len)
{
	using namespace std;
	// Random seed
    random_device rd;

    // Initialize Mersenne Twister pseudo-random number generator
    mt19937 gen(rd());

    // Generate pseudo-random numbers
    // uniformly distributed in range (1, 100)
    uniform_int_distribution<> dis(1, 100);
    
    static const char alphanum[] =
        "abcdefghijklmnopqrstuvwxyz";
    static const char ALPHANUM[] =
         "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

    // Generate ten pseudo-random numbers
    for (int i = 0; i < len; i++)
    {
        int randomX = dis(gen);
        if(i==0)
          s[i]=ALPHANUM[randomX%(sizeof(ALPHANUM)-1)];
        else
          s[i]=alphanum[randomX%(sizeof(alphanum)-1)];
        //cout << "\nRandom X = " << randomX;
    }
    
    s[len]=0;
}

//void gen_random_name(char* s, const int len) 
//{
//	random_device rd;
//	mt19937 gen(rd());
//	uniform_int_distribution<> dis(1, 100);
//		
//	//or we can use ASCII code
//    static const char alphanum[] =
//        "abcdefghijklmnopqrstuvwxyz";
//    static const char ALPHANUM[] =
//         "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
//    //first letter up
//     s[0] = ALPHANUM[dis(gen)%(sizeof(ALPHANUM)-1)];
//
//    //following low
//    for (int i = 1; i < len; ++i) {
//    	uniform_int_distribution<> dis(1, 100);
//        s[i] = alphanum[dis(gen) % (sizeof(alphanum) - 1)];
//    }
//
//    s[len] = 0;      
//}

 void gen_random(char *s, const int len) {
     for (int i = 0; i < len; ++i) {
         int randomChar = rand()%(26+26+10);
         if (randomChar < 26)
             s[i] = 'a' + randomChar;
         else if (randomChar < 26+26)
             s[i] = 'A' + randomChar - 26;
         else
             s[i] = '0' + randomChar - 26 - 26;
     }
     s[len] = 0;
 }

size_t gen_random_num(const size_t low, const size_t high)
{
	srand (time(NULL));
	return rand()%(high-low)+low;
}

void UsePointer(std::auto_ptr <Person> spObj)
{
	spObj->printInfo(cout);
}
