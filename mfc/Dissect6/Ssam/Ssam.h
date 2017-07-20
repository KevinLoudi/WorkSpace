// Ssam.h : main header file for the SSAM application
//

#if !defined(AFX_SSAM_H__5C509CD1_45E0_46D7_9F5F_EF9F4B52372B__INCLUDED_)
#define AFX_SSAM_H__5C509CD1_45E0_46D7_9F5F_EF9F4B52372B__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CSsamApp:
// See Ssam.cpp for the implementation of this class
//

class CSsamApp : public CWinApp
{
public:
	CSsamApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CSsamApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation
	//{{AFX_MSG(CSsamApp)
	afx_msg void OnAppAbout();
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SSAM_H__5C509CD1_45E0_46D7_9F5F_EF9F4B52372B__INCLUDED_)
