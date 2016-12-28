//Example of how to create a minimal MFC application
//1. Create a new Win32 project, select empty project
//2. Go to project options > Use MFC in a shared library (.dll)
//3. Make a new resource file with an empty dialog
//4. Give the dialog the name "IDD_INTERFACE1"
//5. Build and run.
//---------------------------------------
#include <afxwin.h> //MFC core and standard componets
#include "resource.h" //main symbols
//---------------------------------------
//Globals
CEdit* pINPUT;
CEdit* pOUTPUT;
CButton* pSTART;
CButton* pLoad;

class GAME_FORM : public CDialog //class for dialogs
{
public:
	//for class wizard
	GAME_FORM(CWnd* pParent = NULL) : CDialog(GAME_FORM::IDD, pParent) {};
	//Dialog data, name of dialog here
	enum { IDD = IDD_INTEREFACE_1 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX) { CDialog::DoDataExchange(pDX); }
	//Called right after constructor. Initialize things here
	virtual BOOL OnInitDialog()
	{
		CDialog::OnInitDialog();
		pINPUT=(CEdit*)GetDlgItem(CE_INPUT);
		pOUTPUT=(CEdit*)GetDlgItem(CE_OUTPUT);
		pSTART=(CButton*)GetDlgItem(CB_START);

		pINPUT->SetWindowText("Type HERE!");
		pOUTPUT->SetWindowText("Click\\START\\to begin.");
		return true;
	}

public:
	//------------------------
	afx_msg void start() {STARTBUTTON();}
	//------------------------
	void STARTBUTTON()
	{
		MessageBox("BYE!");
		pSTART->EnableWindow(false);
	}
	//------------------------
	DECLARE_MESSAGE_MAP()
};

//Actural App
class TheGame : public CWinApp
{
public:
	TheGame() {};
	virtual BOOL InitInstance()
	{
		CWinApp::InitInstance(); //parent class method
		//SetRegistryKey(_T("Landkartenvertrieb"));
		GAME_FORM dlg;
		m_pMainWnd = &dlg;
		//do pop-up
		INT_PTR nResponse = dlg.DoModal();
		return false;
	}
};

//---------------------------------------------
//Need a Message Map Macro for both CDialog and CWinApp
BEGIN_MESSAGE_MAP(GAME_FORM, CDialog)
	ON_COMMAND(CB_START,start)//function name, no argument
END_MESSAGE_MAP()
//---------------------------------------------

//Start application
TheGame theApp;