#pragma once


// createLoadDLG dialog
class createLoadDLG : public CDialogEx
{
	DECLARE_DYNAMIC(createLoadDLG)

public:
	createLoadDLG(Travel,CWnd* pParent = nullptr);   // standard constructor
	CString buildResultFromLoad(Travel);
	virtual BOOL OnInitDialog();
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
	CString res;
};
