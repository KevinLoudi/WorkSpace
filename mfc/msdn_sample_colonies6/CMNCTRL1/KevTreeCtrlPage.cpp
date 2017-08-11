// KevTreeCtrlPage.cpp : implementation file
//

#include "stdafx.h"
#include "cmnctrl1.h"
#include "KevTreeCtrlPage.h"
#include "MTREECTL.H"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CKevTreeCtrlPage property page

IMPLEMENT_DYNCREATE(CKevTreeCtrlPage, CPropertyPage)

CKevTreeCtrlPage::CKevTreeCtrlPage() : CPropertyPage(CKevTreeCtrlPage::IDD)
{
	//{{AFX_DATA_INIT(CKevTreeCtrlPage)
	//}}AFX_DATA_INIT
}

CKevTreeCtrlPage::~CKevTreeCtrlPage()
{
}

void CKevTreeCtrlPage::DoDataExchange(CDataExchange* pDX)
{
	CPropertyPage::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CKevTreeCtrlPage)
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CKevTreeCtrlPage, CPropertyPage)
	//{{AFX_MSG_MAP(CKevTreeCtrlPage)
		// NOTE: the ClassWizard will add message map macros here
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CKevTreeCtrlPage message handlers
