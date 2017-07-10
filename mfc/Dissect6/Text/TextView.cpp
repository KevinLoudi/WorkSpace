// TextView.cpp : implementation of the CTextView class
//

#include "stdafx.h"
#include "Text.h"

#include "TextDoc.h"
#include "TextView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CTextView

IMPLEMENT_DYNCREATE(CTextView, CView)

BEGIN_MESSAGE_MAP(CTextView, CView)
	//{{AFX_MSG_MAP(CTextView)
	ON_WM_CREATE()
	ON_WM_LBUTTONDOWN()
	ON_WM_CHAR()
	ON_WM_TIMER()
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CTextView construction/destruction

CTextView::CTextView()
{
	// TODO: add construction code here
	m_strLine="";
	m_originPoint=CPoint(0,0);
	m_nWidth=0;
	SetCaretPos(m_originPoint);
}

CTextView::~CTextView()
{
}

BOOL CTextView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CTextView drawing

void CTextView::OnDraw(CDC* pDC)
{
	CTextDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	// TODO: add draw code for native data here
	/*CString str("VC programming");
	pDC->TextOut(50,50,str); */

	/*CString str;
	str.LoadString(IDS_STRING_PROMTE);
	pDC->TextOut(50,50,str);
	
	CSize sz=pDC->GetTextExtent(str);

	//create rectangle in path bracket
	pDC->BeginPath();
	pDC->Rectangle(50,50,50+sz.cx, 50+sz.cy);
	pDC->EndPath(); 
	pDC->SelectClipPath(RGN_DIFF);
	//pDC->SelectClipPath(RGN_AND);

	//plot grids
	for (int i=0; i<300; i+=10)
	{
		pDC->MoveTo(i,0);
		pDC->LineTo(i,300);
		pDC->MoveTo(0,i);
		pDC->LineTo(300,i);
	} */
}

/////////////////////////////////////////////////////////////////////////////
// CTextView printing

BOOL CTextView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CTextView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CTextView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

/////////////////////////////////////////////////////////////////////////////
// CTextView diagnostics

#ifdef _DEBUG
void CTextView::AssertValid() const
{
	CView::AssertValid();
}

void CTextView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CTextDoc* CTextView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CTextDoc)));
	return (CTextDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CTextView message handlers

int CTextView::OnCreate(LPCREATESTRUCT lpCreateStruct) 
{
	if (CView::OnCreate(lpCreateStruct) == -1)
		return -1;
	
	// TODO: Add your specialized creation code here
	CClientDC Dc(this);

	//Create text input caret
	/*TEXTMETRIC tm;
	Dc.GetTextMetrics(&tm);
	CreateSolidCaret(tm.tmAveCharWidth/8,tm.tmHeight);
	ShowCaret();*/

	//Create bitmap input caret
	bitMap.LoadBitmap(IDB_BITMAP_VC);
	CreateCaret(&bitMap);
	ShowCaret();

	SetTimer(0,1000,NULL);

	return 0;
}

void CTextView::OnLButtonDown(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
	SetCaretPos(point);
	m_strLine.Empty();
	m_originPoint=point;
	
	CView::OnLButtonDown(nFlags, point);
}

void CTextView::OnChar(UINT nChar, UINT nRepCnt, UINT nFlags) 
{
	// TODO: Add your message handler code here and/or call default
	CClientDC dc(this);

	//set show font
	CFont font;
	font.CreatePointFont(300,"»ªÎÄÐÐ¿¬",NULL);
	CFont *pOldFont=dc.SelectObject(&font);

	//get text metric
	TEXTMETRIC tm;
	dc.GetTextMetrics(&tm);

	//Press Enter button
	if (nChar==0x0d)
	{
		m_strLine.Empty();
		m_originPoint.y+=tm.tmHeight;
	}
	//press delet
	else if (nChar==0x08)
	{
		COLORREF clr=dc.SetTextColor(dc.GetBkColor());
		dc.TextOut(m_originPoint.x, m_originPoint.y, m_strLine);
		m_strLine=m_strLine.Left(m_strLine.GetLength()-1);
		dc.SetTextColor(clr);
	}
	else
	{
		m_strLine+=nChar;
	}

	//set carpet position
	CSize sz=dc.GetTextExtent(m_strLine);
	CPoint pt;
	pt.x=m_originPoint.x+sz.cx;
	pt.y=m_originPoint.y;
	SetCaretPos(pt);

	dc.TextOut(m_originPoint.x,m_originPoint.y,m_strLine);

	dc.SelectObject(pOldFont);
	
	CView::OnChar(nChar, nRepCnt, nFlags);
}

void CTextView::OnTimer(UINT nIDEvent) 
{
	// TODO: Add your message handler code here and/or call default
	/*if(nIDEvent!=0)
	{
		MessageBox("Wrong Timer","Timer",MB_OK);
	}*/

	if (nIDEvent==0)
	{
		m_nWidth+=1;

		CClientDC dc(this);
		TEXTMETRIC tm;
		dc.GetTextMetrics(&tm);
		CRect rect;
		rect.left=0; rect.top=200; rect.right=m_nWidth; rect.top+tm.tmHeight;

		dc.SetTextColor(RGB(255,0,0));
		CString str; str.LoadString(IDS_STRING_PROMTE);
		dc.DrawText(str,rect,DT_LEFT);
	}
	
	CView::OnTimer(nIDEvent);
}
