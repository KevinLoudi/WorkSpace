#include <stdio.h>
#include <LIMITS>
#include <string>
#include <STDLIB.H>

namespace Basics
{
	//store types
	enum NumType
	{
		KEV_INT,
		KEV_LONG,
		KEV_FLOAT
	};

	//store values
	union NumValue        			
	{
		int         iValue;  		
		long        lValue;  		
		double      dValue;  		
	};
	
	
	void Demo(int argc=0, char* argv[]=NULL);
}