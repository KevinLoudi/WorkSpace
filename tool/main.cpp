#include <iostream>
#include <fstream>
std::ifstream infile("text.txt");
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	int a,b;
	while(infile>>a>>b)
	{
		std::cout<<a<<" "<<b<<std::endl;
	}
	
	return 0;
}
