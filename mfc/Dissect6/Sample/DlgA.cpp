// DlgA.cpp : implementation file
//

#include "stdafx.h"
#include "Sample.h"
#include "DlgA.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// DlgA dialog


DlgA::DlgA(CWnd* pParent /*=NULL*/)
	: CDialog(DlgA::IDD, pParent)
{
	//{{AFX_DATA_INIT(DlgA)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void DlgA::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(DlgA)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(DlgA, CDialog)
	//{{AFX_MSG_MAP(DlgA)
		// NOTE: the ClassWizard will add message map macros here
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// DlgA message handlers
