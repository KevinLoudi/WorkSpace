#include <iostream>
#include "mfc.h"
using namespace std;

//App
class CMyWinApp : public CWinApp
{
public:
  CMyWinApp::CMyWinApp()   {
                              cout << "CMyWinApp Constructor \n";
                           }
  CMyWinApp::~CMyWinApp()  {
                              cout << "CMyWinApp Destructor \n";
                           }            
};

//Frame
class CMyFrameWnd : public CFrameWnd
{
public:
  CMyFrameWnd()   {
                     cout << "CMyFrameWnd Constructor \n";
                  }
  ~CMyFrameWnd()  {
                     cout << "CMyFrameWnd Destructor \n";
                  }
};

