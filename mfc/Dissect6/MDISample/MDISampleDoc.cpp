// MDISampleDoc.cpp : implementation of the CMDISampleDoc class
//

#include "stdafx.h"
#include "MDISample.h"

#include "MDISampleDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CMDISampleDoc

IMPLEMENT_DYNCREATE(CMDISampleDoc, CDocument)

BEGIN_MESSAGE_MAP(CMDISampleDoc, CDocument)
	//{{AFX_MSG_MAP(CMDISampleDoc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMDISampleDoc construction/destruction

CMDISampleDoc::CMDISampleDoc()
{
	// TODO: add one-time construction code here
	m_data="Nonsense";

}

CMDISampleDoc::~CMDISampleDoc()
{
}

BOOL CMDISampleDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CMDISampleDoc serialization

void CMDISampleDoc::Serialize(CArchive& ar)
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
// CMDISampleDoc diagnostics

#ifdef _DEBUG
void CMDISampleDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CMDISampleDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CMDISampleDoc commands
