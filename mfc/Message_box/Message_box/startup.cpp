#include "startup.h"

#ifdef _DEBUG
void MessageFrame::AssertValid() const
{
	CFrameWnd::AssertValid();
}

void MessageFrame::Dump(CDumpContext & dc) const
{
	CFrameWnd::Dump(dc);
}
#endif

MessageFrame::MessageFrame()
{
	//use a standard cursor and a standard icon
	HCURSOR hCursor;
	HICON hIcon;
	hCursor=AfxGetApp()->LoadStandardCursor(IDC_SIZEALL);
	hIcon=AfxGetApp()->LoadStandardIcon(IDI_EXCLAMATION);

	//use the AfxRegisterWndClass() function with default values
	const char* RWC=AfxRegisterWndClass(CS_VREDRAW|CS_HREDRAW,hCursor,
		(HBRUSH)::GetStockObject(WHITE_BRUSH),hIcon);
	Create(RWC,"Message Box Demo",WS_OVERLAPPEDWINDOW,
		CRect(200,120,640,400),NULL);
}

int MessageFrame::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if(CFrameWnd::OnCreate(lpCreateStruct)==0)
	{
		//successfully create a window
		MessageBox("Create a window!!");
		return 0;
	}
	return -1;
}

void MessageFrame::OnShowWindow(BOOL bShow, UINT nStatus)
{
	//display frame in full screen
	CFrameWnd::OnShowWindow(bShow,nStatus);
	//Add message handler
	ShowWindow(SW_MAXIMIZE);
}

void MessageFrame::OnActivate(UINT nState, CWnd* pWndOther,BOOL bMinimized)
{
	CFrameWnd::OnActivate(nState, pWndOther, bMinimized);
	//add your message hander
	switch(nState)
	{
		case WA_ACTIVE:
			MessageBox("This window has been activated, without the mouse!");
			break;
		case WA_INACTIVE:
			MessageBox("This window has been deactivated and cannot be changed now!!");
			break;
		case WA_CLICKACTIVE:
			MessageBox("This window has been activated using the mouse!!!");
			break;
	}
}

IMPLEMENT_DYNCREATE(MessageFrame,CFrameWnd)
BEGIN_MESSAGE_MAP(MessageFrame,CFrameWnd)
	ON_WM_CREATE()
	ON_WM_SHOWWINDOW()
	ON_WM_ACTIVATE()
END_MESSAGE_MAP()

BOOL MessageApp::InitInstance()
{
	MessageFrame *frame=new MessageFrame();
	m_pMainWnd=frame;
	if(!PreProccess())
	{
		return FALSE;
	}

	m_pMainWnd->ShowWindow(SW_SHOW);
	m_pMainWnd->UpdateWindow();

	return TRUE;
}

BOOL MessageApp::PreProccess()
{
	CWnd *msg=new CWnd;
	int Ans;
	Ans=msg->MessageBox("Open the App?\n","Prompotion",MB_OKCANCEL|MB_ICONQUESTION);
	
	CWnd *fmsg=new CWnd;
	if(Ans==IDOK)
		fmsg->MessageBox("Yes\n","Message",MB_OK|MB_ICONINFORMATION);
	else if(Ans==IDCANCEL)
		fmsg->MessageBox("Cancel\n","Message",MB_OK|MB_ICONINFORMATION);
	return TRUE;
}


MessageApp theApp;