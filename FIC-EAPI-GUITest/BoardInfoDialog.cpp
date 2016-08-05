// BoardInfoDialog.cpp : 实现文件
//

#include "stdafx.h"
#include "FIC-EAPI-GUITest.h"
#include "BoardInfoDialog.h"
#include "afxdialogex.h"


// BoardInfoDialog 对话框

IMPLEMENT_DYNAMIC(BoardInfoDialog, CDialogEx)

BoardInfoDialog::BoardInfoDialog(CWnd* pParent /*=NULL*/)
	: CDialogEx(BoardInfoDialog::IDD, pParent)
{

}

BoardInfoDialog::~BoardInfoDialog()
{
}

void BoardInfoDialog::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDIT_DELAY2, EditGetStringAID);
	DDX_Control(pDX, IDC_EDIT_DELAY, EditGetValueID);
	DDX_Control(pDX, IDC_STATIC_OUTPUT, StaticOutput);
}


BEGIN_MESSAGE_MAP(BoardInfoDialog, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON_EApiBoardGetStringA, &BoardInfoDialog::OnBnClickedButtonEapiboardgetstringa)
	ON_BN_CLICKED(IDC_BUTTON_EApiBoardGetValue, &BoardInfoDialog::OnBnClickedButtonEapiboardgetvalue)
END_MESSAGE_MAP()


// BoardInfoDialog 消息处理程序


void BoardInfoDialog::OnBnClickedButtonEapiboardgetstringa()
{
	EApiStatus_t Ret = 0;
	uint32_t bufLen;
	char buffer[256];

	CString s1;
	EditGetStringAID.GetWindowTextW(s1);
	Ret = EApiBoardGetStringA(_ttoi(s1), buffer,&bufLen);

	CString strMsg;

	strMsg.Format(_T("EApiBoardGetStringA:  Ret = [0x%X]; buffer = %s"), Ret, buffer);

	StaticOutput.SetWindowTextW(strMsg);
}


void BoardInfoDialog::OnBnClickedButtonEapiboardgetvalue()
{
	EApiStatus_t Ret = 0;
	uint32_t retValue;

	CString s1;
	EditGetStringAID.GetWindowTextW(s1);
	Ret = EApiBoardGetValue(_ttoi(s1), &retValue);

	CString strMsg;

	strMsg.Format(_T("EApiBoardGetValue:  Ret = [0x%X]; retValue = %s"), Ret, retValue);

	StaticOutput.SetWindowTextW(strMsg);
}
