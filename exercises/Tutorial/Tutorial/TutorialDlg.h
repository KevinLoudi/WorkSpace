
// TutorialDlg.h : header file
//

#pragma once


// CTutorialDlg dialog
class CTutorialDlg : public CDialog
{
// Construction
public:
	CTutorialDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	enum { IDD = IDD_ECHOBUTTONEVENT_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support


// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
private:
	// variable
	CString m_EchoText;
	int m_OkCount;
public:
	afx_msg void OnBnClickedBtnAdd();
};
