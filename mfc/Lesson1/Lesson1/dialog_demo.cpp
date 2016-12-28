/*create a dialog box*/
#include <afxwin.h>
#include "resource.h"

class CExample : public CWinApp {
   public:
      BOOL InitInstance();
};
   
class CExampleDlg : public CDialog {
   public:
      enum { IDD = IDD_INTERFACE };
   
      CExampleDlg();
     ~CExampleDlg();
};

//CDialog is the base class for screen displaying
CExampleDlg::CExampleDlg():CDialog(CExampleDlg::IDD) 
{

}

CExampleDlg::~CExampleDlg() 
{

}

BOOL CExample::InitInstance() 
{
   //instantiate this dialog
   CExampleDlg myDlg;
   m_pMainWnd = &myDlg;
   myDlg.DoModal(); //modal dialog
   return TRUE;
}
CExample MyApp;