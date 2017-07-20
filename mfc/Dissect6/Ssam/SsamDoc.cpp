// SsamDoc.cpp : implementation of the CSsamDoc class
//

#include "stdafx.h"
#include "Ssam.h"

#include "SsamDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CSsamDoc

IMPLEMENT_DYNCREATE(CSsamDoc, CDocument)

BEGIN_MESSAGE_MAP(CSsamDoc, CDocument)
	//{{AFX_MSG_MAP(CSsamDoc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CSsamDoc construction/destruction

CSsamDoc::CSsamDoc()
{
	// TODO: add one-time construction code here

}

CSsamDoc::~CSsamDoc()
{
}

BOOL CSsamDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CSsamDoc serialization

void CSsamDoc::Serialize(CArchive& ar)
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
// CSsamDoc diagnostics

#ifdef _DEBUG
void CSsamDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CSsamDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CSsamDoc commands
