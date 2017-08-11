#if !defined(AFX_KEVTREECTRLPAGE_H__FB0035AE_50D0_403F_9084_414BF9E6771F__INCLUDED_)
#define AFX_KEVTREECTRLPAGE_H__FB0035AE_50D0_403F_9084_414BF9E6771F__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// KevTreeCtrlPage.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CKevTreeCtrlPage dialog

#include "MTREECTL.H"
#include "NOTIFWDW.H"

class CKevTreeCtrlPage : public CPropertyPage
{
	DECLARE_DYNCREATE(CKevTreeCtrlPage)

// Construction
public:
	CKevTreeCtrlPage();
	~CKevTreeCtrlPage();

// Dialog Data
	//{{AFX_DATA(CKevTreeCtrlPage)
	enum { IDD = IDD_KEVTREECTRL };
	//}}AFX_DATA


// Overrides
	// ClassWizard generate virtual function overrides
	//{{AFX_VIRTUAL(CKevTreeCtrlPage)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	// Generated message map functions
	//{{AFX_MSG(CKevTreeCtrlPage)
		// NOTE: the ClassWizard will add member functions here
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_KEVTREECTRLPAGE_H__FB0035AE_50D0_403F_9084_414BF9E6771F__INCLUDED_)
