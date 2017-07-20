// UIDoc.cpp : implementation of the CUIDoc class
//

#include "stdafx.h"
#include "UI.h"

#include "UIDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CUIDoc

IMPLEMENT_DYNCREATE(CUIDoc, CDocument)

BEGIN_MESSAGE_MAP(CUIDoc, CDocument)
	//{{AFX_MSG_MAP(CUIDoc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CUIDoc construction/destruction

CUIDoc::CUIDoc()
{
	// TODO: add one-time construction code here

}

CUIDoc::~CUIDoc()
{
}

BOOL CUIDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CUIDoc serialization

void CUIDoc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: add storing code here
	}
	else
	{
		// TODO: add loading code here
	}
}

/////////////////////////////////////////////////////////////////////////////
// CUIDoc diagnostics

#ifdef _DEBUG
void CUIDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CUIDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CUIDoc commands
