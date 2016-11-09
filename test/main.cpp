#include <iostream>
#include "Place.h"
#include "basicPlaces.h"
#include "commonMethods.h"
using namespace std;

UINT City::_City_num=0;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
void printInfo(const Place &site);//dynamic binding
bool InitCityList(City &acity);
bool ReadListFiletoCity(City cities[],const int num);
//Initialize a group of cities through file reading
//bool CreateCitiesviaFile(City *pcities, const int num);

int main(int argc, char** argv) 
{		
		//city group
		const UINT citynum=4;
		City* pcities= new City[citynum];
		ReadListFiletoCity(pcities,citynum);
		
		Ranking cityrank;
		for(int i=0;i<citynum;++i)
		{
			cityrank.push_city(pcities[i]);
		}
		cout<<cityrank.printHelper(cout);

		//sort city by population via STL::map
		cityrank.sort_city_by_population(true);
		cout<<"\nAfter the sort"<<endl;
		cout<<cityrank.printHelper(cout);
		
		delete[] pcities;
		system("pause");
		return 0;
}

//void printInfo(const Place &site,ostream &os)
//{
//	 cout<<site.GetInfo(os);
//}
