// UIView.h : interface of the CUIView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_UIVIEW_H__D905A961_AE20_4B5E_8C20_C6EDFD75BD26__INCLUDED_)
#define AFX_UIVIEW_H__D905A961_AE20_4B5E_8C20_C6EDFD75BD26__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CUIView : public CView
{
protected: // create from serialization only
	CUIView();
	DECLARE_DYNCREATE(CUIView)

// Attributes
public:
	CUIDoc* GetDocument();

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CUIView)
	public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	protected:
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CUIView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CUIView)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in UIView.cpp
inline CUIDoc* CUIView::GetDocument()
   { return (CUIDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_UIVIEW_H__D905A961_AE20_4B5E_8C20_C6EDFD75BD26__INCLUDED_)
