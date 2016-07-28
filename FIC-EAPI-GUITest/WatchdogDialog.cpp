// WatchdogDialog.cpp : 实现文件
//

#include "stdafx.h"
#include "FIC-EAPI-GUITest.h"
#include "WatchdogDialog.h"
#include "afxdialogex.h"


// WatchdogDialog 对话框

IMPLEMENT_DYNAMIC(WatchdogDialog, CDialogEx)

WatchdogDialog::WatchdogDialog(CWnd* pParent /*=NULL*/)
	: CDialogEx(WatchdogDialog::IDD, pParent)
{

}

WatchdogDialog::~WatchdogDialog()
{
}

void WatchdogDialog::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_STATIC_OUTPUT, StaticOutput);
	DDX_Control(pDX, IDC_EDIT_DELAY, editDelay);
	DDX_Control(pDX, IDC_EDIT_EventTimeout, editEventTimeout);
	DDX_Control(pDX, IDC_EDIT_ResetTimeout, editResetTimeout);
}


BEGIN_MESSAGE_MAP(WatchdogDialog, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON_EApiWDogGetCap, &WatchdogDialog::OnBnClickedButtonEapiwdoggetcap)
	ON_BN_CLICKED(IDC_BUTTON_EApiWDogStart, &WatchdogDialog::OnBnClickedButtonEapiwdogstart)
	ON_BN_CLICKED(IDC_BUTTON_EApiWDogTrigger, &WatchdogDialog::OnBnClickedButtonEapiwdogtrigger)
	ON_BN_CLICKED(IDC_BUTTON_EApiWDogStop, &WatchdogDialog::OnBnClickedButtonEapiwdogstop)
END_MESSAGE_MAP()


// WatchdogDialog 消息处理程序



void WatchdogDialog::OnBnClickedButtonEapiwdoggetcap()
{
	uint32_t MaxDelay, MaxEventTimeout, MaxResetTimeout;
	EApiStatus_t Ret = 0;

	Ret = EApiWDogGetCap(&MaxDelay, &MaxEventTimeout, &MaxResetTimeout);

	CString strMsg;

	strMsg.Format(_T("EApiWDogGetCap:  Ret = [0x%X]; MaxDelay = [%d] : MaxEventTimeout = [%d] : MaxResetTimeout = [%d] :"), Ret,MaxDelay, MaxEventTimeout, MaxResetTimeout);

	StaticOutput.SetWindowTextW(strMsg);
	// TODO:  在此添加控件通知处理程序代码
}




void WatchdogDialog::OnBnClickedButtonEapiwdogstart()
{
	EApiStatus_t Ret = 0;

	CString i1, i2, i3;
	editDelay.GetWindowTextW(i1);
	editEventTimeout.GetWindowTextW(i2);
	editResetTimeout.GetWindowTextW(i3);
	Ret = EApiWDogStart(_ttoi(i1), _ttoi(i2), _ttoi(i3));
	
	CString strMsg;

	strMsg.Format(_T("EApiWDogStart:  Ret = [0x%X];"), Ret);

	StaticOutput.SetWindowTextW(strMsg);
	// TODO:  在此添加控件通知处理程序代码
}


void WatchdogDialog::OnBnClickedButtonEapiwdogtrigger()
{
	EApiStatus_t Ret = 0;

	
	Ret = EApiWDogTrigger();

	CString strMsg;

	strMsg.Format(_T("EApiWDogTrigger:  Ret = [0x%X];"), Ret);

	StaticOutput.SetWindowTextW(strMsg);
	// TODO:  在此添加控件通知处理程序代码
}


void WatchdogDialog::OnBnClickedButtonEapiwdogstop()
{
	EApiStatus_t Ret = 0;


	Ret = EApiWDogStop();

	CString strMsg;

	strMsg.Format(_T("EApiWDogStop:  Ret = [0x%X];"), Ret);

	StaticOutput.SetWindowTextW(strMsg);
	// TODO:  在此添加控件通知处理程序代码
}
