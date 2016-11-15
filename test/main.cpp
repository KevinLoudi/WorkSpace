#include <iostream>
#include <vector>
#include "basicPlace.h"
#include "basicModel.h"
#include "Community.h"
using namespace std;

//A static data field has to be defined before linking
UINT Place::_itemNum=0;
UINT City::_cityNum=0;
UINT FileIO::_IO_Num=0;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
//	PlaceInfo pi(0.0, 0.0, 0.0, 0, "null products",0);
//	CityInfo ci(0.0, 0.0, 0.0, 0, "null products",0,"null cityname","null holder",0);
//	Place p(&pi);
//	City c(&ci);
	//dynamic binding
	//cout<<p.getInfo(cout)<<endl;
	//cout<<c.getInfo(cout)<<endl;
	
//	City* cs=new City();
//	FileIO fio("text.txt");
//	fio.saveBinaryFile(cs,1);
//	cout<<cs->getInfo(cout)<<endl;
	
//	City* cs2=new City();
//	FileIO fio("text.txt");
//	fio.readTextFile(cs2,1);
//	cout<<cs2->getInfo(cout)<<endl;
	
	const UINT citynum=10;
	City* cities = new City[citynum];
	FileIO fio("text.txt");
	fio.readTextFile(cities,citynum);
	
	vector<City> cities_v;
	cities_v.assign(&cities[0],&cities[citynum-1]);
	
	//for(auto &x:cities_v)
	  //cout<<x.getInfo(cout)<<endl;

	cout<<"output the rank"<<endl;
	Rank r(cities_v);
	//r.addCityname("Gusu");
	//r.isexist("Gusu");
	//r.removeCityname("Gusu");
	//r.isexist("Gusu");
	r.printCityname();
	r.printRank();
	r.rankbyValue();
	//find and print elements' popluation density larger than 300
	vector<string> find_city;
	vector<UINT> calc_population;
	r.findLargerItems(300,find_city);
	r.transformtoPopluation(citynum-1,calc_population);
	return 0;
}
