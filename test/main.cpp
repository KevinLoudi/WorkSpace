#include <iostream>
#include "basicPlace.h"
using namespace std;

//A static data field has to be defined before linking
UINT Place::_itemNum=0;
UINT City::_cityNum=0;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	PlaceInfo pi(0.0, 0.0, 0.0, 0, "null products",0);
	CityInfo ci(0.0, 0.0, 0.0, 0, "null products",0,"null cityname","null holder",0);
	Place p(&pi);
	City c(&ci);
	//dynamic binding
	cout<<p.getInfo(cout)<<endl;
	cout<<c.getInfo(cout)<<endl;
	
	system("pause");
	return 0;
}
