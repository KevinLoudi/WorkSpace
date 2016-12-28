#include <afxwin.h>
#include <ctime>

//need a frame/window to show the content of our application
class CMyFrame : public CFrameWnd {
   public:
      CMyFrame() {
	     //get current time
      	 std::time_t now=std::time(0);//get time now
      	 std::tm *pt=std::localtime(&now);
      	 char buff[32];
      	 std::strftime(buff,32,"%a, %d.%m.%Y %H:%M:%S", pt);

		 //name of class and name of the window
		 //create a frame/window
		 //NULL means no parent windows
         Create(NULL, _T(buff),WS_SYSMENU, CRect(400, 400, 
            850, 780));
      }
};


//derive a class from the MFC's CWinApp
class CExample : public CWinApp {
   BOOL InitInstance() 
   {
      CMyFrame *Frame = new CMyFrame();  m_pMainWnd = Frame;
      
      //instantiate the dialog
      Frame->ShowWindow(SW_NORMAL);
      Frame->UpdateWindow();
      
      return TRUE;
   }
};

CExample theApp;