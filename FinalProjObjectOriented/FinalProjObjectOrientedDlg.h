
// FinalProjObjectOrientedDlg.h : header file
//

#pragma once


// CFinalProjObjectOrientedDlg dialog
class CFinalProjObjectOrientedDlg : public CDialogEx
{
// Construction
public:
	CFinalProjObjectOrientedDlg(CWnd* pParent = nullptr);	// standard constructor

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_FINALPROJOBJECTORIENTED_DIALOG };
#endif

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
public:
	afx_msg void OnCbnSelchangeDest();
	
	list<Location>stationsForBus;
	list<Location>stationsForFly;
	list<Location>stationsForRail;

	list<Client> clientList;

	Location Eilat;
	Location QiryatShmona;
	Location TA;
	Location Holon;
	Location Haifa;
	Location Jerusalem;
	Location RishonLezion;
	Location Yeruham;
	Location BeerSheva;
	Location Herzeliya;
	Location Azor;
	Location BatYam;
	Location Paris;
	Location Cyprus;
	Location Barcelona;
	Location Madrid;
	Location Thailand;

	CComboBox source;
	CComboBox dest;
	CComboBox DiscountChoice;
	afx_msg void OnCbnSelchangesource();
	afx_msg void OnBnClickedOk();
	CButton search;
	CEdit email_box;
	CEdit id_box;
	CButton createUser_btn;
	afx_msg void OnBnClickedButton1();
	CStatic pic_res1;
	CStatic pic_res2;
	CStatic pic_res3;
	afx_msg void OnStnClicked1();
	afx_msg void OnStnClickedPic2();
	afx_msg void OnEnChangeMail();
};
