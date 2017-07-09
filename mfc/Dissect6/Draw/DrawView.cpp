// DrawView.cpp : implementation of the CDrawView class
//

#include "stdafx.h"
#include "Draw.h"

#include "DrawDoc.h"
#include "DrawView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CDrawView

IMPLEMENT_DYNCREATE(CDrawView, CView)

BEGIN_MESSAGE_MAP(CDrawView, CView)
	//{{AFX_MSG_MAP(CDrawView)
	ON_WM_LBUTTONDOWN()
	ON_WM_RBUTTONDOWN()
	ON_WM_LBUTTONUP()
	ON_WM_MOUSEMOVE()
	ON_WM_CREATE()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDrawView construction/destruction

CDrawView::CDrawView()
{
	// TODO: add construction code here
	mEnDraw=FALSE;

}

CDrawView::~CDrawView()
{
}

BOOL CDrawView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CDrawView drawing

void CDrawView::OnDraw(CDC* pDC)
{
	CDrawDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	// TODO: add draw code for native data here
}

/////////////////////////////////////////////////////////////////////////////
// CDrawView diagnostics

#ifdef _DEBUG
void CDrawView::AssertValid() const
{
	CView::AssertValid();
}

void CDrawView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CDrawDoc* CDrawView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CDrawDoc)));
	return (CDrawDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CDrawView message handlers

void CDrawView::OnLButtonDown(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
	//MessageBox("Start");
	mOriginPoint=point;
	mEnDraw=TRUE;

	CView::OnLButtonDown(nFlags, point);
}

//DEL void CDrawView::OnRButtonDblClk(UINT nFlags, CPoint point) 
//DEL {
//DEL 	// TODO: Add your message handler code here and/or call default
//DEL 	MessageBox("Stop");
//DEL 	CView::OnRButtonDblClk(nFlags, point);
//DEL }

void CDrawView::OnRButtonDown(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
	//MessageBox("Stop");

	//////Plot a line with left and right buttion clicked down

	//SDK
	/*HDC hdc;
	hdc=::GetDC(m_hWnd);
	MoveToEx(hdc,mOriginPoint.x,mOriginPoint.y,NULL);
	LineTo(hdc,point.x,point.y);
	::ReleaseDC(m_hWnd,hdc); */

	//CDC class
	/*CDC* pDc;
	pDc=GetDC();
	pDc->MoveTo(mOriginPoint);
	pDc->LineTo(point);
	ReleaseDC(pDc); */

	//CClientDC class
	/*//CClientDC pDc(this); //PLOT INSIDE THE SPECIFIC VIEW
	CClientDC pDc(GetParent());
	pDc.MoveTo(mOriginPoint);
	pDc.LineTo(point); */

	//CWindow
	/*CPen pen(PS_DASH,1,RGB(255,0,0));
	CWindowDC Dc(this);
	CWindowDC* pDc=&Dc;
	CPen* pOldPen=pDc->SelectObject(&pen);
	pDc->MoveTo(mOriginPoint);
	pDc->LineTo(point);
	pDc->SelectObject(pOldPen);*/

	/////Fill a rectangle
	/*CBrush brush(RGB(255,0,0));
	pDc->FillRect(CRect(mOriginPoint,point),&brush); */
	
	mEnDraw=FALSE;

	CView::OnRButtonDown(nFlags, point);
}

void CDrawView::OnLButtonUp(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
	
	//// Plot in bitmap
	/*CBitmap bitMap;
	bitMap.LoadBitmap(IDB_BITMAP_TEST);
	CBrush brush(&bitMap);
	CClientDC dc(this);
	dc.FillRect(CRect(mOriginPoint,point),&brush);*/
	
	CView::OnLButtonUp(nFlags, point);
}

void CDrawView::OnMouseMove(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
	CClientDC Dc(this);

	CPen pen(PS_SOLID,3,RGB(0,255,0));
	CPen* pOldPen=Dc.SelectObject(&pen);

	//plot continuous line
	if (mEnDraw==TRUE)
	{
		Dc.MoveTo(mOriginPoint);
		Dc.LineTo(point);
		mOriginPoint=point;
	}

	Dc.SelectObject(pOldPen);

	CView::OnMouseMove(nFlags, point);
}

int CDrawView::OnCreate(LPCREATESTRUCT lpCreateStruct) 
{
	if (CView::OnCreate(lpCreateStruct) == -1)
		return -1;
	
	// TODO: Add your specialized creation code here
	return 0;
}
