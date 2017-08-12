#include "SampleUnion.h"

namespace Basics
{
	void Demo(int argc/*=0*/, char* argv[]/*=NULL*/)
	{
		int count = argc;
		NumValue* Values=new NumValue[count];
		NumType* Types=new NumType[count];

		for (int i=0; i<argc; ++i)
		{
			if (strchr(argv[i],'.')!=0)
			{
				//is a float number
				Values[i].dValue=atof(argv[i]);
				Types[i]=KEV_FLOAT;
			}
			else
			{
				if ((atol(argv[i])>INT_MAX)||(atol(argv[i])<0))
				{
					Values[i].dValue=atol(argv[i]);
					Types[i]=KEV_LONG;
				} 
				else
				{
					Values[i].dValue=atol(argv[i]);
					Types[i]=KEV_INT;
				}
			}
		}

		switch( Types[i] )					
		{
		case KEV_INT:				
			printf( "Data type is Integer£¬value is %d\n", Values[i].dValue );
			break;
		case KEV_LONG:				
			printf( "Data type is Long£¬value is %d\n", Values[i].dValue );
			break;
		case KEV_FLOAT:			
			printf( "Data type is Double£¬ value is %f\n", Values[i].dValue );
			break;
		}
	}


}
