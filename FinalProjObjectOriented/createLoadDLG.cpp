// createLoadDLG.cpp : implementation file
//

#include "pch.h"
#include "FinalProjObjectOriented.h"
#include "createLoadDLG.h"
#include "afxdialogex.h"


// createLoadDLG dialog

IMPLEMENT_DYNAMIC(createLoadDLG, CDialogEx)

createLoadDLG::createLoadDLG(Travel t,CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_LoadDLG, pParent)
{
	res = buildResultFromLoad(t);
	
}


CString createLoadDLG::buildResultFromLoad(Travel t)
{
	CString time, price, id, gear, type;
	time.Format(_T("%.2f"), t.getTravelTime());
	price.Format(_T("%.2f"), t.getTravelPrice());
	id.Format(_T("%d"), t.getInstrument()->GetInstrumentID());
	Instrument *i = t.getInstrument();
	gear = i->GetTypeOfGear();
	type = i->GetTypeOfFuel();
	CString fullResult = L"Hello: " +t.getClient().getName() + L"\nHere you can find all the details about your travel\nSource: " + t.getSource().getName() + L"\nDestination: " + t.getDestination().getName() + L"\nCompany: " +
		t.getInstrument()->GetOwner() + L" - " + t.getInstrument()->GetType() + L"(" + id + L")\nTravel Time: "
		+ time + L"h\nTravel Price: " + price + L" NIS";
	return fullResult;
}


createLoadDLG::~createLoadDLG()
{
}

void createLoadDLG::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);


	DDX_Control(pDX, IDC_LoadRes, LoadRes);
}


BEGIN_MESSAGE_MAP(createLoadDLG, CDialogEx)
	
	ON_BN_CLICKED(IDOK, &createLoadDLG::OnBnClickedOk)
	ON_STN_CLICKED(IDC_LoadRes, &createLoadDLG::OnStnClickedLoadres)
END_MESSAGE_MAP()


// createLoadDLG message handlers
BOOL createLoadDLG::OnInitDialog()
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

	LoadRes.SetWindowTextW(res);
	return TRUE;
}


void createLoadDLG::OnBnClickedOk()
{
	// TODO: Add your control notification handler code here
	CDialogEx::OnOK();
}


void createLoadDLG::OnStnClickedLoadres()
{
	// TODO: Add your control notification handler code here
}
