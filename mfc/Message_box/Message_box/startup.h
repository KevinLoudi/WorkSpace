#include <afxwin.h>
#include <afx.h>

#define _DEBUG

class MessageFrame: public CFrameWnd
{
public:
	MessageFrame();
	DECLARE_DYNCREATE(MessageFrame)
	
	#ifdef _DEBUG
		virtual void AssertValid() const;
		virtual void Dump(CDumpContext & dc) const;
	#endif

protected:
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnShowWindow(BOOL bShow, UINT nStatus);
	afx_msg void OnActivate(UINT nState, CWnd* pWndOther,BOOL bMinimized);
	DECLARE_MESSAGE_MAP() //manage messages
};

class MessageApp: public CWinApp
{
	BOOL InitInstance();
	BOOL PreProccess();
};