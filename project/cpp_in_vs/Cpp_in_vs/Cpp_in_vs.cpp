// Cpp_in_vs.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "Cpp_in_vs.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

CWinApp theApp;

using namespace std;

int calc_tempture(int);
/*generate random array*/
void generate_random_arr(int*, const int, int, int);
/*print array*/
void print_arr(int*, const int);
/*cubic maximum contiguous subsequence sume algorithm*/
int max_subsum(int*, const int);

int _tmain(int argc, TCHAR* argv[], TCHAR* envp[])
{
	int nRetCode = 0;
	srand((unsigned int)time(NULL));

	if (!AfxWinInit(::GetModuleHandle(NULL), NULL, ::GetCommandLine(), 0))
	{
		_tprintf(_T("Hello MFC!!\n"));
		nRetCode = 1;
	}
	else
	{
		clock_t start=clock();
		//printf("%s%d\n","tempture: ",calc_tempture(4));
		const int arr_size=10;
		int* arr=new int(arr_size);
		generate_random_arr(arr,arr_size,-10,10);
		//print_arr(arr,arr_size);
		clock_t stop=clock();
		delete[] arr;
		arr=NULL;
	    printf("%f\n", (double)(stop-start)/CLOCKS_PER_SEC);
		getchar();
	}
	
	return nRetCode;
}

void print_arr(int* arr, const int arr_size)
{
	int i;
	printf("%s\n", "following is the array element...");
	for(i=0;i<arr_size;++i)
	{
		if(i%10==0) printf("\n");
		printf("%d%s", arr[i]," ");	
	}
}

void generate_random_arr(int* arr, const int arr_size,int low, int high)
{
	if(high<low)
	{
		int tmp=high;
		high=low;
		low=tmp;
	}
	int i;
	for(i=0;i<arr_size;++i)
	{
		arr[i]=(rand()%(high-low+1))+low;
	}
}

int max_subsum(int* arr, const int arr_size)
{
	int max_sum=0;

	int i,j;
	for(i=0;i<arr_size;++i)
	{
		for(j=i;j<arr_size;++j)
		{
			int this_sum=0;

			int k;
			for(k=i;k<=j;k++)
				this_sum+=arr[k];

			if(this_sum>max_sum)
				max_sum=this_sum;
		}
	}

  return max_sum;
}

int calc_tempture(int x)
{
	if(x==0)
		return 0;
	else
		//printf("%s%d\n","step: ",x);
		return 2*calc_tempture(x-1)+x*x;
}
