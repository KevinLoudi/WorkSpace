#include "startup.h"
#include "resource.h"
#include "resource1.h"

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
	
	//The rectangle on the window
	RECT Recto;
	Recto.left = 100;
	Recto.top = 120;
	Recto.right = 620;
	Recto.bottom = 540;

	m_hAccel=::LoadAccelerators(AfxGetInstanceHandle(),
	MAKEINTRESOURCE(IDE_ACCELTEST));

	//the current window has no parent window
	Create(NULL,"Typical Window and Resources Fundamentals",
		 WS_OVERLAPPEDWINDOW,Recto,NULL,MAKEINTRESOURCE(IDR_MENU_RES));
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

	//initial a message box and return the user input value
	OnMsgBox();

	//show the window
	m_pMainWnd->ShowWindow(SW_SHOW);
	m_pMainWnd->UpdateWindow();
		
	return TRUE;
}

void CSimpleApp::OnMsgBox()
{
	int Ans;
	//initial a message box
	CWnd *msg=new CWnd;
	const char* content="We are using MFC shared DLL..\n";
	const char* title="Promotion";	
	Ans=msg->MessageBox(content,title,MB_YESNOCANCEL|MB_ICONINFORMATION);

	if(Ans==IDNO)
		return;
}

//Nothing will appear because we did 
//not define an expected behavior
CSimpleApp theApp;