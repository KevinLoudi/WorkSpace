// MDISampleView.h : interface of the CMDISampleView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_MDISAMPLEVIEW_H__B21BA965_111C_4A8D_9A6F_542F5676FF8E__INCLUDED_)
#define AFX_MDISAMPLEVIEW_H__B21BA965_111C_4A8D_9A6F_542F5676FF8E__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CMDISampleView : public CView
{
protected: // create from serialization only
	CMDISampleView();
	DECLARE_DYNCREATE(CMDISampleView)

// Attributes
public:
	CMDISampleDoc* GetDocument();

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMDISampleView)
	public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CMDISampleView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CMDISampleView)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in MDISampleView.cpp
inline CMDISampleDoc* CMDISampleView::GetDocument()
   { return (CMDISampleDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MDISAMPLEVIEW_H__B21BA965_111C_4A8D_9A6F_542F5676FF8E__INCLUDED_)
