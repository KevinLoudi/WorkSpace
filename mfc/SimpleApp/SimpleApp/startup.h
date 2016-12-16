#include <afxwin.h>
#include <afx.h>

#define _DEBUG

class CSimpleFrame: public CFrameWnd
{
public:
	CSimpleFrame();
	DECLARE_DYNCREATE(CSimpleFrame)

   #ifdef _DEBUG
		//checking the process with CObject::
		virtual void AssertValid() const;
		//diagnosis services
		virtual void Dump(CDumpContext& dc) const;
	#endif
};

struct CSimpleApp: public CWinApp
{
	BOOL InitInstance();
};