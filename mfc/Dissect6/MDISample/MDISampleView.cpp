// MDISampleView.cpp : implementation of the CMDISampleView class
//

#include "stdafx.h"
#include "MDISample.h"

#include "MDISampleDoc.h"
#include "MDISampleView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CMDISampleView

IMPLEMENT_DYNCREATE(CMDISampleView, CView)

BEGIN_MESSAGE_MAP(CMDISampleView, CView)
	//{{AFX_MSG_MAP(CMDISampleView)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMDISampleView construction/destruction

CMDISampleView::CMDISampleView()
{
	// TODO: add construction code here

}

CMDISampleView::~CMDISampleView()
{
}

BOOL CMDISampleView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CMDISampleView drawing

void CMDISampleView::OnDraw(CDC* pDC)
{
	CMDISampleDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	// TODO: add draw code for native data here
}

/////////////////////////////////////////////////////////////////////////////
// CMDISampleView printing

BOOL CMDISampleView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CMDISampleView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CMDISampleView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

/////////////////////////////////////////////////////////////////////////////
// CMDISampleView diagnostics

#ifdef _DEBUG
void CMDISampleView::AssertValid() const
{
	CView::AssertValid();
}

void CMDISampleView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMDISampleDoc* CMDISampleView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMDISampleDoc)));
	return (CMDISampleDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CMDISampleView message handlers
