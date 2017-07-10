// MeunView.cpp : implementation of the CMeunView class
//

#include "stdafx.h"
#include "Meun.h"

#include "MeunDoc.h"
#include "MeunView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CMeunView

IMPLEMENT_DYNCREATE(CMeunView, CView)

BEGIN_MESSAGE_MAP(CMeunView, CView)
	//{{AFX_MSG_MAP(CMeunView)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMeunView construction/destruction

CMeunView::CMeunView()
{
	// TODO: add construction code here

}

CMeunView::~CMeunView()
{
}

BOOL CMeunView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CMeunView drawing

void CMeunView::OnDraw(CDC* pDC)
{
	CMeunDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	// TODO: add draw code for native data here
}

/////////////////////////////////////////////////////////////////////////////
// CMeunView diagnostics

#ifdef _DEBUG
void CMeunView::AssertValid() const
{
	CView::AssertValid();
}

void CMeunView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMeunDoc* CMeunView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMeunDoc)));
	return (CMeunDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CMeunView message handlers
