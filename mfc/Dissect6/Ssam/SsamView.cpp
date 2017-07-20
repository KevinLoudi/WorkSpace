// SsamView.cpp : implementation of the CSsamView class
//

#include "stdafx.h"
#include "Ssam.h"

#include "SsamDoc.h"
#include "SsamView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

#define DPI 1024

/////////////////////////////////////////////////////////////////////////////
// CSsamView

IMPLEMENT_DYNCREATE(CSsamView, CScrollView)

BEGIN_MESSAGE_MAP(CSsamView, CScrollView)
	//{{AFX_MSG_MAP(CSsamView)
	ON_WM_KEYDOWN()
	ON_WM_LBUTTONDOWN()
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CScrollView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CScrollView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CScrollView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CSsamView construction/destruction

CSsamView::CSsamView()
{
	// TODO: add construction code here
	m_rect=CRect(0,0,DPI*3,-DPI*3);

}

CSsamView::~CSsamView()
{
}

BOOL CSsamView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CScrollView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CSsamView drawing

void CSsamView::OnDraw(CDC* pDC)
{
	CSsamDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	// TODO: add draw code for native data here
	pDC->Ellipse(m_rect);
}

void CSsamView::OnInitialUpdate()
{
	CScrollView::OnInitialUpdate();

	/*CSize sizeTotal;
	// TODO: calculate the total size of this view
	sizeTotal.cx = sizeTotal.cy = 100;
	SetScrollSizes(MM_TEXT, sizeTotal);*/

	//set size of each view
	CSize sizeTotal(40000,30000);
	CSize sizePage(sizeTotal.cx/4,sizeTotal.cy/4);
	CSize sizeLine(sizeTotal.cx/100,sizeTotal.cy/100);
	SetScrollSizes(MM_HIMETRIC,sizeTotal,sizePage,sizeLine);
}

/////////////////////////////////////////////////////////////////////////////
// CSsamView printing

BOOL CSsamView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CSsamView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CSsamView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

/////////////////////////////////////////////////////////////////////////////
// CSsamView diagnostics

#ifdef _DEBUG
void CSsamView::AssertValid() const
{
	CScrollView::AssertValid();
}

void CSsamView::Dump(CDumpContext& dc) const
{
	CScrollView::Dump(dc);
}

CSsamDoc* CSsamView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CSsamDoc)));
	return (CSsamDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CSsamView message handlers

void CSsamView::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags) 
{
	// TODO: Add your message handler code here and/or call default
	//press key to move the view
	switch (nChar)
	{
	case VK_UP:
		OnVScroll(SB_LINEUP,0,NULL);
		break;
	case VK_DOWN:
		OnVScroll(SB_LINEDOWN,0,NULL);
		break;
	case VK_LEFT:
		OnHScroll(SB_LINELEFT,0,NULL);
		break;
	case VK_RIGHT:
		OnHScroll(SB_LINERIGHT,0,NULL);
		break;
	}

	
	CScrollView::OnKeyDown(nChar, nRepCnt, nFlags);
}

void CSsamView::OnLButtonDown(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
	CClientDC dc(this);
	OnPrepareDC(&dc);

	CRect rectDevice=m_rect;
	dc.LPtoDP(rectDevice); //Converts logical units into device units.
	InvalidateRect(rectDevice); //update region
	
	CScrollView::OnLButtonDown(nFlags, point);
}
