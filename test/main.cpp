#include <iostream>
#include "Community.h"
#include "GobalDefine.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	using namespace std;
	Person p;
	p.printInfo(cout);
	
	smart_pointer <Person> pPer(p);
	pPer->printInfo(cout);
	return 0;
}
