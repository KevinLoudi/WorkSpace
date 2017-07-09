// MainFrm.cpp : implementation of the CMainFrame class
//

#include "stdafx.h"
#include "Draw.h"

#include "MainFrm.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CMainFrame

IMPLEMENT_DYNCREATE(CMainFrame, CFrameWnd)

BEGIN_MESSAGE_MAP(CMainFrame, CFrameWnd)
	//{{AFX_MSG_MAP(CMainFrame)
	ON_WM_RBUTTONDOWN()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMainFrame construction/destruction

CMainFrame::CMainFrame()
{
	// TODO: add member initialization code here
	
}

CMainFrame::~CMainFrame()
{
}

//DEL BOOL CMainFrame::PreCreateWindow(CREATESTRUCT& cs)
//DEL {
//DEL 	if( !CFrameWnd::PreCreateWindow(cs) )
//DEL 		return FALSE;
//DEL 	// TODO: Modify the Window class or styles here by modifying
//DEL 	//  the CREATESTRUCT cs
//DEL 
//DEL 	return TRUE;
//DEL }

/////////////////////////////////////////////////////////////////////////////
// CMainFrame diagnostics

#ifdef _DEBUG
void CMainFrame::AssertValid() const
{
	CFrameWnd::AssertValid();
}

void CMainFrame::Dump(CDumpContext& dc) const
{
	CFrameWnd::Dump(dc);
}

#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CMainFrame message handlers


//DEL void CMainFrame::OnLButtonDown(UINT nFlags, CPoint point) 
//DEL {
//DEL 	// TODO: Add your message handler code here and/or call default
//DEL 	MessageBox("Left Button",NULL,MB_OK);
//DEL 	CFrameWnd::OnLButtonDown(nFlags, point);
//DEL }

void CMainFrame::OnRButtonDown(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
	MessageBox("Right Button",NULL,MB_OK);
	CFrameWnd::OnRButtonDown(nFlags, point);
}
