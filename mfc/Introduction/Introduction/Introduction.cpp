// Introduction.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "Introduction.h"
#include <iostream>

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// 唯一的应用程序对象

CWinApp theApp;

using namespace std;

class CStudent: public CObject
{
public:
	CStudent();
	~CStudent();
	char* name_;
	char* level_;
	int age_;
};

//CWinApp provides all the basic functionality that an application needs.
struct CSimpleApp: public CWinApp
{
	//equipe functions
	BOOL InitInstance() {return TRUE;}
};

int _tmain(int argc, TCHAR* argv[], TCHAR* envp[])
{
	int nRetCode = 0;

	// 初始化 MFC 并在失败时显示错误
	if (!AfxWinInit(::GetModuleHandle(NULL), NULL, ::GetCommandLine(), 0))
	{
		// TODO: 更改错误代码以符合您的需要
		_tprintf(_T("错误: MFC 初始化失败\n"));
		nRetCode = 1;
	}
	else
	{
		cout<<"Introduction of MFC\n";
	}

	system("pause");
	return nRetCode;
}
