//#include <iostream>
#include "Place.h"
#include "basicPlaces.h"
using namespace std;

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
void printInfo(const Place &site);//dynamic binding

int main(int argc, char** argv) {
	{
		City cd;
		//cd.GetInfo();
		printInfo(cd);
		return 0;
	}
}

void printInfo(const Place &site)
{
	site.GetInfo();
	return;
}
