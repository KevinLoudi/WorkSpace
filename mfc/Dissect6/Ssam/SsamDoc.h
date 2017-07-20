// SsamDoc.h : interface of the CSsamDoc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_SSAMDOC_H__8FA680E0_325A_4023_A267_FF37810ACEE4__INCLUDED_)
#define AFX_SSAMDOC_H__8FA680E0_325A_4023_A267_FF37810ACEE4__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CSsamDoc : public CDocument
{
protected: // create from serialization only
	CSsamDoc();
	DECLARE_DYNCREATE(CSsamDoc)

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CSsamDoc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CSsamDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CSsamDoc)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SSAMDOC_H__8FA680E0_325A_4023_A267_FF37810ACEE4__INCLUDED_)
