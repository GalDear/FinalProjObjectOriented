
// FinalProjObjectOrientedDlg.cpp : implementation file
//

#include "pch.h"
#include "framework.h"
#include "FinalProjObjectOriented.h"
#include "FinalProjObjectOrientedDlg.h"
#include "afxdialogex.h"
#include "createClientDLG.h"
#include "createLoadDLG.h"
#include <fstream> 

#define UWM_CUSTOM (WM_APP+1)
#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CAboutDlg dialog used for App About

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

// Implementation
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CFinalProjObjectOrientedDlg dialog



CFinalProjObjectOrientedDlg::CFinalProjObjectOrientedDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_FINALPROJOBJECTORIENTED_DIALOG, pParent), Eged(stationsForBus, L"Bus", 0.2, L"Eged", 1, 1948, L"Eged@support.com", L"039142237", 8),
	Metropolin(stationsForBus, L"Bus", 0.17, L"Metropolin", 2, 1970, L"Metropolin@support.com", L"0732634938", 7),
	Elal(stationsForFly, L"Plane", 0.5, L"Elal", 3, 1949, L"Elal@support.com", L"039771111", 8),
	Arkia(stationsForFly, L"Plane", 0.48, L"Arkia", 4, 1960, L"Arkia@support.com", L"036902222", 6),
	IsraelRail(stationsForRail, L"Train", 0.3, L"IsraelRail", 5, 1935, L"IsraelRail@support.com", L"086831222", 9),
	ShlomoSixt(L"Car", 0.35, L"ShlomoSixt", 6, 1990, L"ShlomoSixt@support.com", L"089191400", 7),
	Eldan(L"Car", 0.342, L"Eldan", 7, 1993, L"Eldan@support.com", L"086848333", 8),
	Bird(L"Scooter", 1, L"Bird", 8, 2018, L"Bird@support.com", L"035195454", 9),
	Wind(L"Scooter", 0.8, L"Wind", 9, 2019, L"Wind@support.com", L"036186543", 8),

	b1(18, L"Bus", 10, true, 2015, 100000), b2(365, L"Bus", 11, true, 2018, 80000),
	b3(95, L"Bus", 12, true, 2016, 180000), b4(1, L"Bus", 13, true, 2020, 30000), b5(900, L"Bus", 14, true, 2019, 64500), b6(450, L"Bus", 15, true, 2016, 122000),
	p3(Date(1, 5, 2021), L"Plane", 22, true, 2021, 10000), p4(Date(1, 9, 2021), L"Plane", 23, true, 2019, 475900), p1(Date(16, 4, 2021), L"Plane", 20, true, 2020, 30000),
	p2(Date(28, 8, 2021), L"Plane", 21, true, 2021, 500500), t1(Date(6, 1, 2021), L"Electric", L"Train", 30, true, 2021, 106000), t2(Date(20, 5, 2021), L"Fuel", L"Train", 31, true, 2020, 475900),
	c1(Date(6, 8, 2021), L"Electric", true, L"Car", 40, true, 2021, 8000), c2(Date(20, 5, 2021), L"Fuel", false, L"Car", 41, true, 2021, 15000), c3(Date(25, 3, 2021), L"Electric", true, L"Car", 42, true, 2021, 8000),
	c4(Date(1, 7, 2021), L"Fuel", false, L"Car", 43, true, 2021, 19050), s1(true, L"Scooter", 50, true, 2021, 700), s3(true, L"Scooter", 52, true, 2021, 555), s4(false, L"Scooter", 53, true, 2021, 780),
	s2(true, L"Scooter", 51, true, 2021, 999)
	

{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
	instrumentLst.push_front(b1);
	instrumentLst.push_front(b2);
	instrumentLst.push_front(b3);
	instrumentLst.push_front(b4);
	instrumentLst.push_front(b5);
	instrumentLst.push_front(b6);
	instrumentLst.push_front(p1);
	instrumentLst.push_front(p2);
	instrumentLst.push_front(p3);
	instrumentLst.push_front(p4);
	instrumentLst.push_front(t1);
	instrumentLst.push_front(t2);
	instrumentLst.push_front(c1);
	instrumentLst.push_front(c2);
	instrumentLst.push_front(c3);
	instrumentLst.push_front(c4);
	instrumentLst.push_front(s1);
	instrumentLst.push_front(s2);
	instrumentLst.push_front(s3);
	instrumentLst.push_front(s4);
}

void CFinalProjObjectOrientedDlg::updateTopResult(Travel t)
{
	list<Travel>::iterator t_iter;
	if (topResult.size() == 4)
	{
		for (t_iter = topResult.begin(); t_iter != topResult.end(); ++t_iter)
		{
			if (t_iter->getTravelTime() > t.getTravelTime())
			{
				this->topResult.erase(t_iter);
				this->topResult.push_front(t);
			}
			else if (t_iter->getTravelTime() == t.getTravelTime())
			{
				if (t_iter->getTravelPrice() > t.getTravelPrice())
				{
					this->topResult.erase(t_iter);
					this->topResult.push_front(t);
				}
			}
		}
	}
	else
	{
		topResult.push_front(t);
	}
	
}
CString CFinalProjObjectOrientedDlg::buildResult(list<Travel>::iterator t_iter)
{
	CString time, price, id, gear, type;
	time.Format(_T("%.2f"), t_iter->getTravelTime());
	price.Format(_T("%.2f"), t_iter->getTravelPrice());
	id.Format(_T("%d"), t_iter->getInstrument()->GetInstrumentID());
	Instrument *i = t_iter->getInstrument();
	gear = i->GetTypeOfGear();
	type = i->GetTypeOfFuel();
	CString fullResult = L"Source: " + t_iter->getSource().getName() + L" Destination: " + t_iter->getDestination().getName() + L"\nCompany: " +
		t_iter->getInstrument()->GetOwner() + L" - " + t_iter->getInstrument()->GetType() + L"(" + id + L"), " + gear + L" " + type
		+L"\nTravel Time: " + time + L", Travel Price: " + price;
	return fullResult;
}



void CFinalProjObjectOrientedDlg::updateResultLabel()
{
	list<Travel>::iterator t_iter = topResult.begin();
	list<CStatic*>::iterator res_iter;
	list<CButton*>::iterator resBtn_iter = resBtn.begin();
	CString fullResult;
	int count = 0;
	for (res_iter = resList.begin(); res_iter != resList.end(); ++res_iter)
	{
		if (count < topResult.size())
		{
			fullResult = buildResult(t_iter);
			(*res_iter)->SetWindowTextW(fullResult);
			(*resBtn_iter)->ShowWindow(SW_SHOW);
			std::advance(t_iter, 1);
			std::advance(resBtn_iter, 1);
		}
		count++;
	}
}

void CFinalProjObjectOrientedDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, DD_Dest, dest);
	DDX_Control(pDX, DD_source, source);
	DDX_Control(pDX, IDOK, search);
	DDX_Control(pDX, TXT_MAIL, email_box);
	DDX_Control(pDX, TXT_ID, id_box);
	DDX_Control(pDX, IDC_BUTTON1, createUser_btn);

	DDX_Control(pDX, TXT_RES1, res1);
	DDX_Control(pDX, TXT_RES2, res2);
	DDX_Control(pDX, TXT_RES3, res3);
	DDX_Control(pDX, TXT_RES4, res4);
	DDX_Control(pDX, BTN_LoadRes, LastRes);
	DDX_Control(pDX, BTN_RES1, res1_btn);
	DDX_Control(pDX, BTN_RES2, res2_btn);
	DDX_Control(pDX, BTN_RES3, res3_btn);
	DDX_Control(pDX, BTN_RES4, res4_btn);
}

BEGIN_MESSAGE_MAP(CFinalProjObjectOrientedDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_CBN_SELCHANGE(DD_Dest, &CFinalProjObjectOrientedDlg::OnCbnSelchangeDest)
	ON_CBN_SELCHANGE(DD_source, &CFinalProjObjectOrientedDlg::OnCbnSelchangesource)
	ON_BN_CLICKED(IDOK, &CFinalProjObjectOrientedDlg::OnBnClickedOk)
	ON_BN_CLICKED(IDC_BUTTON1, &CFinalProjObjectOrientedDlg::OnBnClickedButton1)
	ON_EN_CHANGE(TXT_MAIL, &CFinalProjObjectOrientedDlg::OnEnChangeMail)
	ON_BN_CLICKED(BTN_RES1, &CFinalProjObjectOrientedDlg::OnBnClickedRes1)
	ON_BN_CLICKED(BTN_RES3, &CFinalProjObjectOrientedDlg::OnBnClickedRes3)
	ON_BN_CLICKED(BTN_RES2, &CFinalProjObjectOrientedDlg::OnBnClickedRes2)
	ON_BN_CLICKED(BTN_RES4, &CFinalProjObjectOrientedDlg::OnBnClickedRes4)
	ON_STN_CLICKED(TXT_RES1, &CFinalProjObjectOrientedDlg::OnStnClickedRes1)
	ON_BN_CLICKED(BTN_LoadRes, &CFinalProjObjectOrientedDlg::OnBnClickedLoadres)
END_MESSAGE_MAP()


// CFinalProjObjectOrientedDlg message handlers

BOOL CFinalProjObjectOrientedDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != nullptr)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}
	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon

	Location QiryatShmona("Qiryat-Shmona", 175, true); 
	Location TA("Tel-Aviv", 0, true); 
	Location Holon("Holon", 10, true); 
	Location Haifa("Haifa", 91, true); 
	Location Jerusalem("Jerusalem", 68, true);
	Location RishonLezion("Rishon-Lezion", 20, true); 
	Location Yeruham("Yeruham", 140, true); 
	Location BeerSheva("Beer-Sheva", 110, true); 
	Location Herzeliya("Herzeliya", 11, true); 
	Location Azor("Azor", 7, true), BatYam("Bat-Yam", 10, true); 
	Location Paris("Paris", 3000, false); 
	Location Cyprus("Cyprus", 360, false); 
	Location Barcelona("Barcelona", 3000, false); 
	Location Madrid("Madrid", 3500, false); 
	Location Thailand("Thailand", 7000, false); 
	Location Eilat("Eilat", 350, true);

	Location busArr[] = { Eilat, QiryatShmona, TA, Holon, Haifa, Jerusalem, RishonLezion,Yeruham, BeerSheva,Herzeliya,Azor,BatYam };
	Location flyArr[] = { Eilat, TA, Haifa, Paris, Cyprus, Barcelona, Madrid, Thailand };
	Location trainArr[] = { QiryatShmona, TA, Holon, Haifa, Jerusalem, RishonLezion, BeerSheva,Herzeliya,BatYam };

	resBtn.push_back(&res1_btn);
	resBtn.push_back(&res2_btn);
	resBtn.push_back(&res3_btn);
	resBtn.push_back(&res4_btn);

	resList.push_back(&res1);
	resList.push_back(&res2);
	resList.push_back(&res3);
	resList.push_back(&res4);

	for (int i = 0; i < 12; i++)
	{
		stationsForBus.push_front(busArr[i]);
		allLoc.push_front(busArr[i]);
		dest.AddString(busArr[i].getName());
		source.AddString(busArr[i].getName());
	}
	for (int i = 0; i < 8; i++)
	{
		stationsForFly.push_front(flyArr[i]);
		allLoc.push_front(flyArr[i]);
		if (!flyArr[i].GetInIsrael())
		{
			dest.AddString(flyArr[i].getName());
			source.AddString(flyArr[i].getName());
		}
	}
	for (int i = 0; i < 9; i++)
		stationsForRail.push_front(trainArr[i]);
	
	Eged.addAvailableInstrument(b1);
	Eged.addAvailableInstrument(b2);
	Eged.addAvailableInstrument(b3);

	Eged.setStations(stationsForBus);
	companyList.push_front(&Eged);

	Metropolin.addAvailableInstrument(b4);
	Metropolin.addAvailableInstrument(b5);
	Metropolin.addAvailableInstrument(b6);

	Metropolin.setStations(stationsForBus);
	companyList.push_front(&Metropolin);

	
	Elal.addAvailableInstrument(p1);
	Elal.addAvailableInstrument(p2);

	Elal.setStations(stationsForFly);
	companyList.push_front(&Elal);

	
	Arkia.addAvailableInstrument(p3);
	Arkia.addAvailableInstrument(p4);

	Arkia.setStations(stationsForFly);
	companyList.push_front(&Arkia);

	
	IsraelRail.addAvailableInstrument(t1);
	IsraelRail.addAvailableInstrument(t2);

	IsraelRail.setStations(stationsForRail);
	companyList.push_front(&IsraelRail);

	
	ShlomoSixt.addAvailableInstrument(c1);
	ShlomoSixt.addAvailableInstrument(c2);

	companyList.push_front(&ShlomoSixt);

	
	Eldan.addAvailableInstrument(c3);
	Eldan.addAvailableInstrument(c4);

	companyList.push_front(&Eldan);

	
	Bird.addAvailableInstrument(s1);
	Bird.addAvailableInstrument(s2);

	companyList.push_front(&Bird);
	
	Wind.addAvailableInstrument(s3);
	Wind.addAvailableInstrument(s4);

	companyList.push_front(&Wind);

	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CFinalProjObjectOrientedDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CFinalProjObjectOrientedDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// The system calls this function to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CFinalProjObjectOrientedDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CFinalProjObjectOrientedDlg::OnCbnSelchangeDest()
{
	// TODO: Add your control notification handler code here
	dest.GetCurSel();

}

void CFinalProjObjectOrientedDlg::OnCbnSelchangesource()
{
	// TODO: Add your control notification handler code here
}

void CFinalProjObjectOrientedDlg::hideResults()
{
	topResult.clear();
	list <CStatic*>::iterator res_iter;
	list<CButton*>::iterator resBtn_iter = resBtn.begin();
	for (res_iter = resList.begin(); res_iter != resList.end(); ++res_iter)
	{
		(*res_iter)->SetWindowTextW(L"");
		(*resBtn_iter)->ShowWindow(SW_HIDE);
	}
}

bool CFinalProjObjectOrientedDlg::userExist()
{
	list<Client>::iterator user_iter;
	for (user_iter = clientList.begin(); user_iter != clientList.end(); ++user_iter)
	{
		CString email,id;
		email_box.GetWindowTextW(email);
		id_box.GetWindowTextW(id);
		if (email == user_iter->getEmail() && id == user_iter->getId())
			return true;
	}
	return false;
}

void CFinalProjObjectOrientedDlg::OnBnClickedOk()
{
	// TODO: Add your control notification handler code here
	hideResults();
	if (userExist())
	{
		CString st_dest;
		int nSel = dest.GetCurSel();
		dest.GetLBText(nSel, st_dest);

		CString st_source;
		nSel = source.GetCurSel();
		source.GetLBText(nSel, st_source);

		if (st_dest == st_source)
			AfxMessageBox(_T("The source and the destination are identical! \n Please change one of them"), MB_OK | MB_ICONSTOP);
		else
		{

			list<Location>::iterator loc_iter;
			for (loc_iter = this->allLoc.begin(); loc_iter != this->allLoc.end(); ++loc_iter)
			{
				if (loc_iter->getName() == st_source)
				{
					l_source = *loc_iter;
				}
				if (loc_iter->getName() == st_dest)
				{
					l_dest = *loc_iter;
				}
			}
			double r;
			list<TransportCompany*>::iterator comp_iter;
			for (comp_iter = this->companyList.begin(); comp_iter != this->companyList.end(); ++comp_iter)
			{
				if (topResult.size() == 4)
					break;
				CString tType = (*comp_iter)->GetTypeOfTransportation();
				if (tType == L"Plane" || tType == L"Train" || tType == L"Bus")
				{
					if ((*comp_iter)->hasStation(l_source) && (*comp_iter)->hasStation(l_dest))
					{
						Instrument *i = *(*comp_iter)->GetAvailableInstruments().begin();
						Travel t(l_source, l_dest, i);
						updateTopResult(t);
					}
				}
				if (tType == L"Car")
				{
					if (l_source.GetInIsrael() && l_dest.GetInIsrael())
					{
						Instrument *i = *(*comp_iter)->GetAvailableInstruments().begin();
						Travel t(l_source, l_dest, i);
						updateTopResult(t);
					}
				}
				if (l_dest + l_source < 30)
				{
					if (tType == L"Scooter")
					{
						Instrument *i = *(*comp_iter)->GetAvailableInstruments().begin();
						Travel t(l_source, l_dest, i);
						updateTopResult(t);
					}
				}

			}
			updateResultLabel();
		}
	}
	else
	{
		AfxMessageBox(_T("The User has not registered in the system.\nplease register first."), MB_OK | MB_ICONSTOP);
	}

	//CDialogEx::OnOK();
}


void CFinalProjObjectOrientedDlg::OnBnClickedButton1()
{
	// TODO: Add your control notification handler code here
	/*CString st_dest;
	int nSel = dest.GetCurSel();
	dest.GetLBText(nSel, st_dest);

	CString st_source;
	nSel = source.GetCurSel();
	source.GetLBText(nSel, st_source);*/

	/*if (st_dest == st_source)
	{
		AfxMessageBox(_T("The source and the destination are identical! \n Please change one of them"), MB_OK | MB_ICONSTOP);
	}
	else{*/
		createClientDLG dlg;
		dlg.DoModal();
		Client c(dlg.name, dlg.id, dlg.email, dlg.hasDiscount);
	
		bool found = (std::find(clientList.begin(), clientList.end(), c) != clientList.end());
		if (!found)
			clientList.push_front(c);
		else
			AfxMessageBox(_T("The client already exist"), MB_OK | MB_ICONSTOP);
	//}


}


void CFinalProjObjectOrientedDlg::OnStnClicked1()
{
	// TODO: Add your control notification handler code here
}


void CFinalProjObjectOrientedDlg::OnStnClickedPic2()
{
	// TODO: Add your control notification handler code here
}


void CFinalProjObjectOrientedDlg::OnEnChangeMail()
{
	// TODO:  If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDialogEx::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.

	// TODO:  Add your control notification handler code here
}


void CFinalProjObjectOrientedDlg::OnBnClickedRes1()
{
	CFileDialog dlg(FALSE, _T(".travel"), NULL, 0, _T("Travels (*.travel)|*.travel|All Files (*.*)|*.*||", OnStnClickedRes1()));
	CString filename,emailName;								
	if (dlg.DoModal() == IDOK)
	{
	email_box.GetWindowText(emailName);
	filename = dlg.GetPathName();

	list<Travel>::iterator t = topResult.begin();
	list<Client>::iterator c_iter = clientList.begin();
	
	for (c_iter; c_iter != clientList.end(); ++c_iter)			// function to add travel to the customer
	{
		if (c_iter->getName() == emailName)
		{
			t->attachClient(*c_iter);
		}
	}
	CFile file(filename, CFile::modeCreate | CFile::modeWrite);
	CArchive ar(&file, CArchive::store);
	t->Serialize(ar);
	ar.Close();
	file.Close();
	}
}





void CFinalProjObjectOrientedDlg::OnBnClickedRes2()
{
	// TODO: Add your control notification handler code here

	CFileDialog dlg(FALSE, _T(".travel"), NULL, 0, _T("Travels (*.travel)|*.travel|All Files (*.*)|*.*||", OnStnClickedRes1()));
	CString filename, emailName;
	if (dlg.DoModal() == IDOK)
	{
		email_box.GetWindowText(emailName);
		filename = dlg.GetPathName();

		list<Travel>::iterator t = topResult.begin();
		std::advance(t, 1);
		list<Client>::iterator c_iter = clientList.begin();

		for (c_iter; c_iter != clientList.end(); ++c_iter)			// function to add travel to the customer
		{
			if (c_iter->getName() == emailName)
			{
				t->attachClient(*c_iter);
			}
		}
		CFile file(filename, CFile::modeCreate | CFile::modeWrite);
		CArchive ar(&file, CArchive::store);
		t->Serialize(ar);
		ar.Close();
		file.Close();
	}
}

void CFinalProjObjectOrientedDlg::OnBnClickedRes3()
{
	// TODO: Add your control notification handler code here
	CFileDialog dlg(FALSE, _T(".travel"), NULL, 0, _T("Travels (*.travel)|*.travel|All Files (*.*)|*.*||", OnStnClickedRes1()));
	CString filename, emailName;
	if (dlg.DoModal() == IDOK)
	{
		email_box.GetWindowText(emailName);
		filename = dlg.GetPathName();

		list<Travel>::iterator t = topResult.begin();
		std::advance(t, 2);
		list<Client>::iterator c_iter = clientList.begin();

		for (c_iter; c_iter != clientList.end(); ++c_iter)			// function to add travel to the customer
		{
			if (c_iter->getName() == emailName)
			{
				t->attachClient(*c_iter);
			}
		}
		CFile file(filename, CFile::modeCreate | CFile::modeWrite);
		CArchive ar(&file, CArchive::store);
		t->Serialize(ar);
		ar.Close();
		file.Close();
	}
}


void CFinalProjObjectOrientedDlg::OnBnClickedRes4()
{
	// TODO: Add your control notification handler code here

	CFileDialog dlg(FALSE, _T(".travel"), NULL, 0, _T("Travels (*.travel)|*.travel|All Files (*.*)|*.*||", OnStnClickedRes1()));
	CString filename, emailName;
	if (dlg.DoModal() == IDOK)
	{
		email_box.GetWindowText(emailName);
		filename = dlg.GetPathName();

		list<Travel>::iterator t = topResult.begin();
		std::advance(t, 3);
		list<Client>::iterator c_iter = clientList.begin();

		for (c_iter; c_iter != clientList.end(); ++c_iter)			// function to add travel to the customer
		{
			if (c_iter->getName() == emailName)
			{
				t->attachClient(*c_iter);
			}
		}
		CFile file(filename, CFile::modeCreate | CFile::modeWrite);
		CArchive ar(&file, CArchive::store);
		t->Serialize(ar);
		ar.Close();
		file.Close();
	}
}





void CFinalProjObjectOrientedDlg::OnStnClickedRes1()
{
	// TODO: Add your control notification handler code here
}


void CFinalProjObjectOrientedDlg::OnBnClickedLoadres()
{

	// TODO: Add your control notification handler code here
	CString filename, loadRes;							// file name based on user name mail
	CFileDialog dlg(TRUE, _T(".travel"), NULL, 0, _T("Travels (*.travel)|*.travel|All Files (*.*)|*.*||"));

	if(dlg.DoModal() == IDOK)
	{
	//email_box.GetWindowText(filename);
	filename = dlg.GetPathName();
	CFile file(filename, CFile::modeRead);
	CArchive ar(&file, CArchive::load);
	//list<Travel>::iterator t;
	tr.Serialize(ar);
	
	list<Instrument>::iterator t_iter = instrumentLst.begin();
	for (t_iter; t_iter != instrumentLst.end(); ++t_iter)
	{
		if (t_iter->GetInstrumentID() == tr.getInstrument()->GetInstrumentID())
		{
			break;
		}
	}
	/*t.changeInstrument(&(*t_iter));*/

	createLoadDLG dlg2(tr);
	dlg2.DoModal();
	


	ar.Close();
	file.Close();
	Invalidate();



	/*
	list<Travel>::iterator t;
	UpdateData(TRUE);


	list<Client>::iterator c_iter = clientList.begin(),c;
	for (c_iter; c_iter != clientList.end(); ++c_iter)
	{
		if (c_iter->getEmail() == filename)
		{
			c = c_iter;
			break;
		}
	}
	list<Travel>::iterator t_iter;
	t_iter = c->getTravels().begin();

	CString lastResult = buildResult(t_iter);
	MessageBox(NULL, lastResult);
	

	//AfxMessageBox(_T((SetWindowTextW(lastResult)), MB_OK | MB_ICONSTOP);

	*/
	

	}
}
