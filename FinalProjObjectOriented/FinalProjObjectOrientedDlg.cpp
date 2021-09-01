
// FinalProjObjectOrientedDlg.cpp : implementation file
//

#include "pch.h"
#include "framework.h"
#include "FinalProjObjectOriented.h"
#include "FinalProjObjectOrientedDlg.h"
#include "afxdialogex.h"
#include "createClientDLG.h"
#include <fstream> 

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
	: CDialogEx(IDD_FINALPROJOBJECTORIENTED_DIALOG, pParent), 
	QiryatShmona("Qiryat-Shmona", 175, true), TA("Tel-Aviv", 0, true), Holon("Holon", 10, true), Haifa("Haifa", 91, true),
	Jerusalem("Jerusalem", 68, true), RishonLezion("Rishon-Lezion", 20, true), Yeruham("Yeruham", 140, true), 
	BeerSheva("Beer-Sheva", 11, true),Herzeliya("Herzeliya", 11, true), Azor("Azor", 7, true), BatYam("Bat-Yam", 10, true),
	Paris("Paris", 3000, false), Cyprus("Cyprus", 360, false), Barcelona("Barcelona", 3000, false), Madrid("Madrid", 3500, false), Thailand("Thailand", 7000, false), Eilat("Eilat", 350, true)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
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
	DDX_Control(pDX, PIC_1, pic_res1);
	DDX_Control(pDX, PIC2, pic_res2);
	DDX_Control(pDX, PIC3, pic_res3);
}

BEGIN_MESSAGE_MAP(CFinalProjObjectOrientedDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_CBN_SELCHANGE(DD_Dest, &CFinalProjObjectOrientedDlg::OnCbnSelchangeDest)
	ON_CBN_SELCHANGE(DD_source, &CFinalProjObjectOrientedDlg::OnCbnSelchangesource)
	ON_BN_CLICKED(IDOK, &CFinalProjObjectOrientedDlg::OnBnClickedOk)
	ON_BN_CLICKED(IDC_BUTTON1, &CFinalProjObjectOrientedDlg::OnBnClickedButton1)
	ON_STN_CLICKED(PIC_1, &CFinalProjObjectOrientedDlg::OnStnClicked1)
	ON_STN_CLICKED(PIC2, &CFinalProjObjectOrientedDlg::OnStnClickedPic2)
	ON_EN_CHANGE(TXT_MAIL, &CFinalProjObjectOrientedDlg::OnEnChangeMail)
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

	// TODO: Add extra initialization here


	Location busArr[] = { Eilat, QiryatShmona, TA, Holon, Haifa, Jerusalem, RishonLezion,Yeruham, BeerSheva,Herzeliya,Azor,BatYam };
	Location flyArr[] = { Eilat, TA, Haifa, Paris, Cyprus, Barcelona, Madrid, Thailand };
	Location trainArr[] = { QiryatShmona, TA, Holon, Haifa, Jerusalem, RishonLezion, BeerSheva,Herzeliya,BatYam };

	for (int i = 0; i < 12; i++)
	{
		stationsForBus.push_front(busArr[i]);
		dest.AddString(busArr[i].getName());
		source.AddString(busArr[i].getName());
	}
	for (int i = 0; i < 8; i++)
	{
		stationsForFly.push_front(flyArr[i]);
		if (!flyArr[i].GetInIsrael())
		{
			dest.AddString(flyArr[i].getName());
			source.AddString(flyArr[i].getName());
		}
	}
	for (int i = 0; i < 9; i++)
		stationsForRail.push_front(trainArr[i]);

	BusCompany Eged(stationsForBus, "Bus", 0.2, "Eged", 1, 1948, "Eged@support.com", "039142237", 8);
	Bus b1(18, "Bus", 10, true, 2015, 100000);
	Bus b2(365, "Bus", 11, true, 2018, 80000);
	Bus b3(95, "Bus", 12, true, 2016, 180000);
	Eged.addAvailableInstrument(b1);
	Eged.addAvailableInstrument(b2);
	Eged.addAvailableInstrument(b3);


	BusCompany Metropolin(stationsForBus, "Bus", 0.17, "Metropolin", 2, 1970, "Metropolin@support.com", "0732634938", 7);
	Bus b4(1, "Bus", 13, true, 2020, 30000);
	Bus b5(900, "Bus", 14, true, 2019, 64500);
	Bus b6(450, "Bus", 15, true, 2016, 122000);
	Metropolin.addAvailableInstrument(b4);
	Metropolin.addAvailableInstrument(b5);
	Metropolin.addAvailableInstrument(b6);

	FlyCompany Elal(stationsForFly, "Plane", 0.5, "Elal", 3, 1949, "Elal@support.com", "039771111", 8);
	Plane p1(Date(16, 4, 2021), "Plane", 20, true, 2020, 30000);
	Plane p2(Date(28, 8, 2021), "Plane", 21, true, 2021, 500500);
	Elal.addAvailableInstrument(p1);
	Elal.addAvailableInstrument(p2);

	FlyCompany Arkia(stationsForFly, "Plane", 0.48, "Arkia", 4, 1960, "Arkia@support.com", "036902222", 6);
	Plane p3(Date(1, 5, 2021), "Plane", 22, true, 2021, 10000);
	Plane p4(Date(1, 9, 2021), "Plane", 23, true, 2019, 475900);
	Arkia.addAvailableInstrument(p3);
	Arkia.addAvailableInstrument(p4);

	TrainCompany IsraelRail(stationsForRail, "Train", 0.3, "IsraelRail", 5, 1935, "IsraelRail@support.com", "086831222", 9);
	Train t1(Date(6, 1, 2021), "Electric", "Train", 30, true, 2021, 106000);
	Train t2(Date(20, 5, 2021), "Fuel", "Train", 31, true, 2020, 475900);
	IsraelRail.addAvailableInstrument(t1);
	IsraelRail.addAvailableInstrument(t2);


	CarCompany ShlomoSixt("Car", 0.35, "ShlomoSixt", 6, 1990, "ShlomoSixt@support.com", "089191400", 7);
	Car c1(Date(6, 8, 2021), "Electric", true, "Car", 40, true, 2021, 8000);
	Car c2(Date(20, 5, 2021), "Fuel", false, "Car", 41, true, 2021, 15000);
	ShlomoSixt.addAvailableInstrument(c1);
	ShlomoSixt.addAvailableInstrument(c2);

	CarCompany Eldan("Car", 0.342, "Eldan", 7, 1993, "Eldan@support.com", "086848333", 8);
	Car c3(Date(25, 3, 2021), "Electric", true, "Car", 42, true, 2021, 8000);
	Car c4(Date(1, 7, 2021), "Fuel", false, "Car", 43, true, 2021, 19050);
	Eldan.addAvailableInstrument(c3);
	Eldan.addAvailableInstrument(c4);

	ScooterCompany Bird("Scooter", 1, "Bird", 8, 2018, "Bird@support.com", "035195454", 9);
	Scooter s1(true, "Scooter", 50, true, 2021, 700);
	Scooter s2(true, "Scooter", 51, true, 2021, 999);
	Bird.addAvailableInstrument(s1);
	Bird.addAvailableInstrument(s2);

	ScooterCompany Wind("Scooter", 0.8, "Wind", 9, 2019, "Wind@support.com", "036186543", 8);
	Scooter s3(true, "Scooter", 52, true, 2021, 555);
	Scooter s4(false, "Scooter", 53, true, 2021, 780);
	Wind.addAvailableInstrument(s3);
	Wind.addAvailableInstrument(s4);

	//list<Location>::iterator iter;
	//for (iter = stationsForBus.begin(); iter != stationsForBus.end(); ++iter)
	//{
	//	
	//}

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


void CFinalProjObjectOrientedDlg::OnBnClickedOk()
{
	// TODO: Add your control notification handler code here
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
		//CStatic*  m_picture;    // pointer to a picture control
		//CFileFind finder;       // for file loading
		//BOOL      bLastFile;

		//m_picture = (CStatic *)GetDlgItem(PIC2);
		//BOOL bWorking = finder.FindFile(L"test.bmp");
		//if (bWorking)
		//{
		//	finder.FindNextFile();
		//	HBITMAP hb = (HBITMAP)::LoadImage(AfxGetInstanceHandle(), finder.GetFilePath(), IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
		//	m_picture->ModifyStyle(0x0000F, SS_BITMAP, SWP_NOSIZE);
		//	m_picture->SetBitmap(hb);
		//	bLastFile = FALSE;
		//}
		
	}

	//CDialogEx::OnOK();
}


void CFinalProjObjectOrientedDlg::OnBnClickedButton1()
{
	// TODO: Add your control notification handler code here
	CString st_dest;
	int nSel = dest.GetCurSel();
	dest.GetLBText(nSel, st_dest);

	CString st_source;
	nSel = source.GetCurSel();
	source.GetLBText(nSel, st_source);

	if (st_dest == st_source)
	{
		AfxMessageBox(_T("The source and the destination are identical! \n Please change one of them"), MB_OK | MB_ICONSTOP);
	}
	else{
		createClientDLG dlg;
		dlg.DoModal();
		Client c(dlg.name, dlg.id, dlg.email, dlg.hasDiscount);
	
		bool found = (std::find(clientList.begin(), clientList.end(), c) != clientList.end());
		if (!found)
			clientList.push_front(c);
		else
			AfxMessageBox(_T("The client already exist"), MB_OK | MB_ICONSTOP);
	}


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
