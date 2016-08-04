// BacklightDialog.cpp : 实现文件
//

#include "stdafx.h"
#include "FIC-EAPI-GUITest.h"
#include "BacklightDialog.h"
#include "afxdialogex.h"


// BacklightDialog 对话框

IMPLEMENT_DYNAMIC(BacklightDialog, CDialogEx)

BacklightDialog::BacklightDialog(CWnd* pParent /*=NULL*/)
	: CDialogEx(BacklightDialog::IDD, pParent)
{

}

BacklightDialog::~BacklightDialog()
{
}

void BacklightDialog::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDIT_DELAY2, EditGetBacklightEnable);
	DDX_Control(pDX, IDC_STATIC_OUTPUT, StaticOutput);
	DDX_Control(pDX, IDC_EDIT_DELAY, EditSetBacklightEnableID);
	DDX_Control(pDX, IDC_EDIT_EventTimeout, EditSetBacklightEnableEnable);
}


BEGIN_MESSAGE_MAP(BacklightDialog, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON_EApiVgaGetBacklightEnable, &BacklightDialog::OnBnClickedButtonEapivgagetbacklightenable)
	ON_BN_CLICKED(IDC_BUTTON_EApiVgaSetBacklightEnable, &BacklightDialog::OnBnClickedButtonEapivgasetbacklightenable)
	ON_BN_CLICKED(IDC_BUTTON_EApiVgaGetBacklightBrightness, &BacklightDialog::OnBnClickedButtonEapivgagetbacklightbrightness)
	ON_BN_CLICKED(IDC_BUTTON_EApiVgaSetBacklightBrightness, &BacklightDialog::OnBnClickedButtonEapivgasetbacklightbrightness)
END_MESSAGE_MAP()


// BacklightDialog 消息处理程序


void BacklightDialog::OnBnClickedButtonEapivgagetbacklightenable()
{
	EApiStatus_t Ret = 0;
	uint32_t enabled;

	CString s1;
	EditGetBacklightEnable.GetWindowTextW(s1);
	Ret = EApiVgaGetBacklightEnable(_ttoi(s1), &enabled);

	CString strMsg;

	strMsg.Format(_T("EApiVgaGetBacklightEnable:  Ret = [0x%X]; enabled = %d"), Ret,enabled);

	StaticOutput.SetWindowTextW(strMsg);
	// TODO:  在此添加控件通知处理程序代码
}


void BacklightDialog::OnBnClickedButtonEapivgasetbacklightenable()
{
	EApiStatus_t Ret = 0;

	CString s1, s2;
	EditSetBacklightEnableID.GetWindowTextW(s1);
	EditSetBacklightEnableEnable.GetWindowTextW(s2);

	Ret = EApiVgaSetBacklightEnable(_ttoi(s1), _ttoi(s2));

	CString strMsg;

	strMsg.Format(_T("EApiVgaSetBacklightEnable:  Ret = [0x%X];"), Ret);

	StaticOutput.SetWindowTextW(strMsg);
}




void BacklightDialog::OnBnClickedButtonEapivgagetbacklightbrightness()
{
	EApiStatus_t Ret = 0;
	uint32_t brightness;

	CString s1;
	EditGetBacklightEnable.GetWindowTextW(s1);
	Ret = EApiVgaGetBacklightBrightness(_ttoi(s1), &brightness);

	CString strMsg;

	strMsg.Format(_T("EApiVgaGetBacklightBrightness:  Ret = [0x%X];  brightness = %d"), Ret,brightness);

	StaticOutput.SetWindowTextW(strMsg);
}


void BacklightDialog::OnBnClickedButtonEapivgasetbacklightbrightness()
{
	EApiStatus_t Ret = 0;

	CString s1, s2;
	EditSetBacklightEnableID.GetWindowTextW(s1);
	EditSetBacklightEnableEnable.GetWindowTextW(s2);

	Ret = EApiVgaSetBacklightBrightness(_ttoi(s1), _ttoi(s2));

	CString strMsg;

	strMsg.Format(_T("EApiVgaSetBacklightBrightness:  Ret = [0x%X];"), Ret);

	StaticOutput.SetWindowTextW(strMsg);
}
