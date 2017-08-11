// Basics.cpp : Defines the entry point for the console application.
//


#include "stdafx.h"
#include <IOSTREAM>
using namespace std;

union RecordType    // Declare a simple union type  
{  
    char   ch;  
    int    i;  
    long   l;  
    float  f;  
    double d;  
    int *int_ptr;  
};   

int main()  
{  
    RecordType t;  
    t.i = 5; // t holds an int  
    t.f = 7.25; // t now holds a float 
	return 0;
}
