// createClientDLG.cpp : implementation file
//

#include "pch.h"
#include "FinalProjObjectOriented.h"
#include "createClientDLG.h"
#include "afxdialogex.h"


// createClientDLG dialog

IMPLEMENT_DYNAMIC(createClientDLG, CDialogEx)

createClientDLG::createClientDLG(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG1, pParent)
{

}

createClientDLG::~createClientDLG()
{
}

void createClientDLG::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDIT1, name_box);
	DDX_Control(pDX, IDC_EDIT2, email_box);
	DDX_Control(pDX, IDC_EDIT3, id_box);
	DDX_Control(pDX, IDC_CHECK1, is_discount_check);
	DDX_Control(pDX, DD_DiscountChoice, DiscountChoice);
}


BEGIN_MESSAGE_MAP(createClientDLG, CDialogEx)
	ON_EN_CHANGE(IDC_EDIT2, &createClientDLG::OnEnChangeEdit2)
	ON_BN_CLICKED(IDOK, &createClientDLG::OnBnClickedOk)
	ON_BN_CLICKED(IDC_CHECK1, &createClientDLG::OnBnClickedCheck1)
	ON_EN_CHANGE(IDC_EDIT1, &createClientDLG::OnEnChangeEdit1)
	ON_CBN_SELCHANGE(DD_DiscountChoice, &createClientDLG::OnCbnSelchangeCombo2)
END_MESSAGE_MAP()


// createClientDLG message handlers


void createClientDLG::OnEnChangeEdit2()
{
	// TODO:  If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDialogEx::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.

	// TODO:  Add your control notification handler code here
}


void createClientDLG::OnBnClickedOk()
{
	// TODO: Add your control notification handler code here
	name_box.GetWindowText(this->name);
	email_box.GetWindowText(this->email);
	id_box.GetWindowText(this->id);

	CString Discount;
	int nSel = DiscountChoice.GetCurSel();
	DiscountChoice.GetLBText(nSel, Discount);
	if (Discount == "Soldier" || Discount == "Student" || Discount == "Senior citizen")
		this->hasDiscount = true;
	else
		this->hasDiscount = false;
	//this->hasDiscount = is_discount_check.GetCheck();
	CDialogEx::OnOK();
}


void createClientDLG::OnBnClickedCheck1()
{
	// TODO: Add your control notification handler code here
}


void createClientDLG::OnCbnSelchangeDiscountchoice()
{
	// TODO: Add your control notification handler code here
	
}


void createClientDLG::OnEnChangeEdit1()
{
	// TODO:  If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDialogEx::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.

	// TODO:  Add your control notification handler code here
}


void createClientDLG::OnCbnSelchangeCombo2()
{
	// TODO: Add your control notification handler code here
}
