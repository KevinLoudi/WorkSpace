// MeunView.h : interface of the CMeunView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_MEUNVIEW_H__BE70B9F7_6CD0_4719_B84A_0BB6C1A0F0DC__INCLUDED_)
#define AFX_MEUNVIEW_H__BE70B9F7_6CD0_4719_B84A_0BB6C1A0F0DC__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CMeunView : public CView
{
protected: // create from serialization only
	CMeunView();
	DECLARE_DYNCREATE(CMeunView)

// Attributes
public:
	CMeunDoc* GetDocument();

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMeunView)
	public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	protected:
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CMeunView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CMeunView)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in MeunView.cpp
inline CMeunDoc* CMeunView::GetDocument()
   { return (CMeunDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MEUNVIEW_H__BE70B9F7_6CD0_4719_B84A_0BB6C1A0F0DC__INCLUDED_)
