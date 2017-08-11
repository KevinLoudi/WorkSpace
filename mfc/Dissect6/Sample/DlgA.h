#if !defined(AFX_DLGA_H__4DB8F5D5_7725_4E83_BE96_DE877A103A73__INCLUDED_)
#define AFX_DLGA_H__4DB8F5D5_7725_4E83_BE96_DE877A103A73__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// DlgA.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// DlgA dialog

class DlgA : public CDialog
{
// Construction
public:
	DlgA(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(DlgA)
	enum { IDD = IDD_DIALOG_A };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(DlgA)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(DlgA)
		// NOTE: the ClassWizard will add member functions here
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DLGA_H__4DB8F5D5_7725_4E83_BE96_DE877A103A73__INCLUDED_)
