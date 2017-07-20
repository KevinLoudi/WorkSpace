// MDISample.h : main header file for the MDISAMPLE application
//

#if !defined(AFX_MDISAMPLE_H__25805A1B_C221_4F2A_BF51_EDC2D10A5588__INCLUDED_)
#define AFX_MDISAMPLE_H__25805A1B_C221_4F2A_BF51_EDC2D10A5588__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CMDISampleApp:
// See MDISample.cpp for the implementation of this class
//

class CMDISampleApp : public CWinApp
{
public:
	CMDISampleApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMDISampleApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation
	//{{AFX_MSG(CMDISampleApp)
	afx_msg void OnAppAbout();
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MDISAMPLE_H__25805A1B_C221_4F2A_BF51_EDC2D10A5588__INCLUDED_)
