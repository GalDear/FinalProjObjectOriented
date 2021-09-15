#pragma once


// createClientDLG dialog

class createClientDLG : public CDialogEx
{
	DECLARE_DYNAMIC(createClientDLG)

public:
	createClientDLG(CWnd* pParent = nullptr);   // standard constructor
	virtual ~createClientDLG();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG1 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	CEdit name_box;
	CEdit email_box;
	CEdit id_box;

	DECLARE_MESSAGE_MAP()
public:
	CString name;
	CString email;
	CString id;
	bool hasDiscount;
	afx_msg void OnEnChangeEdit2();
	afx_msg void OnBnClickedOk();
	afx_msg void OnBnClickedCheck1();
	afx_msg void OnCbnSelchangeDiscountchoice();
	afx_msg void OnEnChangeEdit1();
	afx_msg void OnCbnSelchangeCombo2();
	CComboBox DiscountChoice;
};
