// UIView.cpp : implementation of the CUIView class
//

#include "stdafx.h"
#include "UI.h"

#include "UIDoc.h"
#include "UIView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CUIView

IMPLEMENT_DYNCREATE(CUIView, CView)

BEGIN_MESSAGE_MAP(CUIView, CView)
	//{{AFX_MSG_MAP(CUIView)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CUIView construction/destruction

CUIView::CUIView()
{
	// TODO: add construction code here

}

CUIView::~CUIView()
{
}

BOOL CUIView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CUIView drawing

void CUIView::OnDraw(CDC* pDC)
{
	CUIDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	// TODO: add draw code for native data here
}

/////////////////////////////////////////////////////////////////////////////
// CUIView diagnostics

#ifdef _DEBUG
void CUIView::AssertValid() const
{
	CView::AssertValid();
}

void CUIView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CUIDoc* CUIView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CUIDoc)));
	return (CUIDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CUIView message handlers
