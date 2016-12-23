/**specify the standard C compiler */
#include "stdafx.h"
#include <stdio.h>
#include "../../../algorithm/c_std_string.h"


int _tmain(int argc, _TCHAR* argv[])
{
	char* prom="program running...";

	printf("%s%d\n", prom, strlen_(prom));

	size_t len=10;
	char* str=(char*)memcre_(len);
	char* str2=(char*)memcre_(len);
	str=(char*)memset_((void*)str,'a',len);
	printf("%s\n", str);
	str2=(char*)memcpy_((void*)str2,(void*)str,len);
	printf("%s\n", str2);

	str="asdedfe";
	str2="qooq";
	printf("%d%s%d\n",is_palindrome_(str)," ",is_palindrome_(str2));

	//wait for input 
	getchar();
	return 0;
}

