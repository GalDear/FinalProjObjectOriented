
// FinalProjObjectOrientedDlg.h : header file
//

#pragma once


// CFinalProjObjectOrientedDlg dialog
class CFinalProjObjectOrientedDlg : public CDialogEx
{
// Construction
public:
	CFinalProjObjectOrientedDlg(CWnd* pParent = nullptr);	// standard constructor
	void updateTopResult(Travel);
	void updateResultLabel();
	CString buildResult(list<Travel>::iterator);

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
	list<Location> allLoc;

	list<Client> clientList;

	list<TransportCompany*> companyList;
	list<Travel> topResult;

	Location l_source;
	Location l_dest;

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
	afx_msg void OnStnClicked1();
	afx_msg void OnStnClickedPic2();
	afx_msg void OnEnChangeMail();
	afx_msg void OnBnClickedRes1();
	CButton selectRes1;
	CButton selectRes2;
	CButton selectRes3;
	CButton selectRes4;
	afx_msg void OnBnClickedRes3();
	afx_msg void OnBnClickedRes2();
	afx_msg void OnBnClickedRes4();

private:
	BusCompany Eged;
	BusCompany Metropolin;
	FlyCompany Elal;
	FlyCompany Arkia;
	TrainCompany IsraelRail;
	CarCompany ShlomoSixt;
	CarCompany Eldan;
	ScooterCompany Bird;
	ScooterCompany Wind;
public:
	CStatic res1;
	afx_msg void OnStnClickedRes1();
	CStatic res2;
	CStatic res3;
	CStatic res4;

	CButton LastRes;
	afx_msg void OnBnClickedLoadres();

	list<CStatic*> resList;

	Bus b1, b2, b3, b4, b5, b6;
	Plane p1, p2, p3, p4;
	Train t1, t2;
	Car c1, c2, c3, c4;
	Scooter s1, s2, s3, s4;

	list<Instrument> instrumentLst;
	list<Travel> loadResult;
};