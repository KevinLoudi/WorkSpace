// MeunDoc.h : interface of the CMeunDoc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_MEUNDOC_H__A7287E3A_8CC8_4128_96D2_4EA0956046EF__INCLUDED_)
#define AFX_MEUNDOC_H__A7287E3A_8CC8_4128_96D2_4EA0956046EF__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CMeunDoc : public CDocument
{
protected: // create from serialization only
	CMeunDoc();
	DECLARE_DYNCREATE(CMeunDoc)

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMeunDoc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CMeunDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CMeunDoc)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MEUNDOC_H__A7287E3A_8CC8_4128_96D2_4EA0956046EF__INCLUDED_)
