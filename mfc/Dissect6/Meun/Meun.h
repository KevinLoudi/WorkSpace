// Meun.h : main header file for the MEUN application
//

#if !defined(AFX_MEUN_H__B1564A7B_9F88_480D_969E_4C6DA1776CF6__INCLUDED_)
#define AFX_MEUN_H__B1564A7B_9F88_480D_969E_4C6DA1776CF6__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CMeunApp:
// See Meun.cpp for the implementation of this class
//

class CMeunApp : public CWinApp
{
public:
	CMeunApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMeunApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation
	//{{AFX_MSG(CMeunApp)
	afx_msg void OnAppAbout();
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MEUN_H__B1564A7B_9F88_480D_969E_4C6DA1776CF6__INCLUDED_)
