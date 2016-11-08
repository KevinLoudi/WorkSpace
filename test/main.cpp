#include <iostream>
#include "Place.h"
#include "basicPlaces.h"
using namespace std;

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
void printInfo(const Place &site);//dynamic binding
bool InitCityList(City &acity,const int num);
bool ReadListFiletoCity(City cities[],const int num);
//Initialize a group of cities through file reading
//bool CreateCitiesviaFile(City *pcities, const int num);

int main(int argc, char** argv) 
{
		//City cd;
		//cd.GetInfo();
		//printInfo(cd);
		//InitCityList(cd,10);
		//City hd;
		//ReadListFiletoCity(hd,10);
		//printInfo(hd);
		
		//city group
		const UINT citynum=3;
		City* pcities= new City[citynum];
		ReadListFiletoCity(pcities,citynum);
		
		delete[] pcities;
		return 0;
}

void printInfo(const Place &site)
{
	site.GetInfo();
	return;
}
