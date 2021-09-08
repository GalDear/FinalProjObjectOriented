#pragma once


// createLoadDLG dialog

class createLoadDLG : public CDialogEx
{
	DECLARE_DYNAMIC(createLoadDLG)

public:
	createLoadDLG(CWnd* pParent = nullptr);   // standard constructor
	virtual ~createLoadDLG();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_LoadDLG };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	CStatic LoadRes;
	afx_msg void OnBnClickedOk();
};
