#include <iostream>
#include "basicPlace.h"
#include "basicModel.h"
using namespace std;

//A static data field has to be defined before linking
UINT Place::_itemNum=0;
UINT City::_cityNum=0;
UINT FileIO::_IO_Num=0;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	PlaceInfo pi(0.0, 0.0, 0.0, 0, "null products",0);
	CityInfo ci(0.0, 0.0, 0.0, 0, "null products",0,"null cityname","null holder",0);
	Place p(&pi);
	City c(&ci);
	//dynamic binding
	cout<<p.getInfo(cout)<<endl;
	cout<<c.getInfo(cout)<<endl;
	
//	City* cs=new City();
//	FileIO fio("text.txt");
//	fio.saveBinaryFile(cs,1);
//	cout<<cs->getInfo(cout)<<endl;
	
	City* cs2=new City();
	FileIO fio("text.txt");
	string* fn=new string{"handan"};
	fio.readBinaryFile(fn,cs2,1);

	system("pause");
	return 0;
}
