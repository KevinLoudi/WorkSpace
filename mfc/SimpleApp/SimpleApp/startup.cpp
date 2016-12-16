#include "startup.h"

#ifdef _DEBUG
void CSimpleFrame::AssertValid() const
{
	CFrameWnd::AssertValid();
}

void CSimpleFrame::Dump(CDumpContext& dc) const
{
	CFrameWnd::Dump(dc);
}
#endif

CSimpleFrame::CSimpleFrame()
{
	//create the window's frame
	//use multi-string code
	//Create(NULL,"Simple Application",WS_VISIBLE);
	//Create(NULL,"Simple Application",WS_CAPTION | WS_SYSMENU|WS_MINIMIZEBOX
	//	|WS_MAXIMIZEBOX|WS_VISIBLE|WS_BORDER|WS_THICKFRAME); //control windows styple
	Create(NULL,"Typical Window",WS_OVERLAPPEDWINDOW);
	//window has borders,  user can control on window-size
}

//let the compiler know that you want 
//your objects to be dynamically created
//two arguments: the name of the class and
//the class drived it from
IMPLEMENT_DYNCREATE(CSimpleFrame,CFrameWnd)

BOOL CSimpleApp::InitInstance() 
{
	//use a pointer to the window's frame 
	//to use it
	CSimpleFrame *frame=new CSimpleFrame();
	m_pMainWnd=frame;

	//show the window
	m_pMainWnd->ShowWindow(SW_SHOW);
	m_pMainWnd->UpdateWindow();
		
	return TRUE;
}

//Nothing will appear because we did 
//not define an expected behavior
CSimpleApp theApp;