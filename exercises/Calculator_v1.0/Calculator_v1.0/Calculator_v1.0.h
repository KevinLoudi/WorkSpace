
// Calculator_v1.0.h : PROJECT_NAME 应用程序的主头文件
//

#pragma once

#ifndef __AFXWIN_H__
	#error "在包含此文件之前包含“stdafx.h”以生成 PCH 文件"
#endif

#include "resource.h"		// 主符号
typedef unsigned int UINT;


// CCalculator_v10App:
// 有关此类的实现，请参阅 Calculator_v1.0.cpp
//

class CCalculator_v10App : public CWinAppEx
{
public:
	CCalculator_v10App();

// 重写
	public:
	virtual BOOL InitInstance();

// 实现

	DECLARE_MESSAGE_MAP()
};

class MCalculator
{
public:
	MCalculator(UINT n=0.0, UINT r=0.0):num_(n),res_(r){}
	~MCalculator(){}
	void set_num(UINT t_num){num_=t_num;}
	BOOL update_sum(){res_+=num_; return true;}
private:
	UINT num_;
	UINT res_;
};

extern CCalculator_v10App theApp;