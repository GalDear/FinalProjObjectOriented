// createLoadDLG.cpp : implementation file
//

#include "pch.h"
#include "FinalProjObjectOriented.h"
#include "createLoadDLG.h"
#include "afxdialogex.h"


// createLoadDLG dialog

IMPLEMENT_DYNAMIC(createLoadDLG, CDialogEx)

createLoadDLG::createLoadDLG(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_LoadDLG, pParent)
{

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
END_MESSAGE_MAP()


// createLoadDLG message handlers


void createLoadDLG::OnBnClickedOk()
{
	// TODO: Add your control notification handler code here
	CDialogEx::OnOK();
}
