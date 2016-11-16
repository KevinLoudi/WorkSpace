#include <iostream>
#include <memory>
#include "Community.h"
#include "GobalDefine.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
//'auto-ptr' has been deprecated in favor of 'std::unique_ptr'
void UsePointer(std::auto_ptr <Person> spObj);

int main(int argc, char** argv) {
	using namespace std;
	Person p;
	p.printInfo(cout);
	
	smart_pointer <Person> pPer(p);
	pPer->printInfo(cout);

	//use built-in auto pointer
	auto_ptr <Person> pPer2(new Person());
	//transfer ownership
	UsePointer(pPer2);
	
	return 0;
}

void UsePointer(std::auto_ptr <Person> spObj)
{
	spObj->printInfo(cout);
}
