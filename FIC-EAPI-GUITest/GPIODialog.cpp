// GPIODialog.cpp : 实现文件
//

#include "stdafx.h"
#include "FIC-EAPI-GUITest.h"
#include "GPIODialog.h"
#include "afxdialogex.h"


// GPIODialog 对话框

IMPLEMENT_DYNAMIC(GPIODialog, CDialogEx)

GPIODialog::GPIODialog(CWnd* pParent /*=NULL*/)
	: CDialogEx(GPIODialog::IDD, pParent)
{

}

GPIODialog::~GPIODialog()
{
}

void GPIODialog::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDIT_DirectionCapID, EditGPIODirectCapID);
	DDX_Control(pDX, IDC_EDIT_ReadWriteID, EditGPIOGetDirectionID);
	DDX_Control(pDX, IDC_EDIT_EditGPIOGetDirectionBitmask, EditGPIOGetDirectionBitmask);
	DDX_Control(pDX, IDC_EDIT_ReadTransferID, EditGPIOSetDirectionID);
	DDX_Control(pDX, IDC_EDIT_ReadTransferAddr, EditGPIOSetDirectionBitmask);
	DDX_Control(pDX, IDC_EDIT_ReadTransferCmd, EditGPIOSetDirectionDirection);
	DDX_Control(pDX, IDC_EDIT_WriteTransferID, EditGPIOGetLevelID);
	DDX_Control(pDX, IDC_EDIT_WriteTransferAddr, EditGPIOGetLevelBitmask);
	DDX_Control(pDX, IDC_EDIT_ProbeDeviceID, EditGPIOSetLevelID);
	DDX_Control(pDX, IDC_EDIT_ProbeDeviceAddr, EditGPIOSetLevelBitmask);
	DDX_Control(pDX, IDC_EDIT_ReadTransferCmd2, EditGPIOSetLevelLevel);
	DDX_Control(pDX, IDC_STATIC_OUTPUT, StaticOutput);
}


BEGIN_MESSAGE_MAP(GPIODialog, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON_EApiGPIOGetDirectionCaps, &GPIODialog::OnBnClickedButtonEapigpiogetdirectioncaps)
	ON_BN_CLICKED(IDC_BUTTON_EApiGPIOGetDirection, &GPIODialog::OnBnClickedButtonEapigpiogetdirection)
	ON_BN_CLICKED(IDC_BUTTON_EApiGPIOSetDirection, &GPIODialog::OnBnClickedButtonEapigpiosetdirection)
	ON_BN_CLICKED(IDC_BUTTON_EApiGPIOGetLevel, &GPIODialog::OnBnClickedButtonEapigpiogetlevel)
	ON_BN_CLICKED(IDC_BUTTON_EApiGPIOSetLevel, &GPIODialog::OnBnClickedButtonEapigpiosetlevel)
END_MESSAGE_MAP()


// GPIODialog 消息处理程序


void GPIODialog::OnBnClickedButtonEapigpiogetdirectioncaps()
{
	EApiStatus_t Ret = 0;
	uint32_t input,output;

	CString i1;
	EditGPIODirectCapID.GetWindowTextW(i1);
	Ret = EApiGPIOGetDirectionCaps(_ttoi(i1), &input,&output);

	CString strMsg;

	strMsg.Format(_T("EApiGPIOGetDirectionCaps:  Ret = [0x%X]; storageSize = 0x%x; input = 0x%x: output= 0x%x"), Ret, input,output);

	StaticOutput.SetWindowTextW(strMsg);
}


void GPIODialog::OnBnClickedButtonEapigpiogetdirection()
{
	EApiStatus_t Ret = 0;
	uint32_t direction;
	CString s1, s2;
	EditGPIOGetDirectionID.GetWindowTextW(s1);
	EditGPIOGetDirectionBitmask.GetWindowTextW(s2);

	Ret = EApiGPIOGetDirection(_ttoi(s1), _ttoi(s2),&direction);

	CString strMsg;

	strMsg.Format(_T("EApiGPIOGetDirection:  Ret = [0x%X]; direction = %d"), Ret,direction);

	StaticOutput.SetWindowTextW(strMsg);
}


void GPIODialog::OnBnClickedButtonEapigpiosetdirection()
{
	EApiStatus_t Ret = 0;
	CString s1, s2,s3;
	EditGPIOSetDirectionID.GetWindowTextW(s1);
	EditGPIOSetDirectionBitmask.GetWindowTextW(s2);
	EditGPIOSetDirectionDirection.GetWindowTextW(s3);

	Ret = EApiGPIOSetDirection(_ttoi(s1), _ttoi(s2),_ttoi(s3));

	CString strMsg;

	strMsg.Format(_T("EApiGPIOGetDirection:  Ret = [0x%X]; "), Ret);

	StaticOutput.SetWindowTextW(strMsg);
}


void GPIODialog::OnBnClickedButtonEapigpiogetlevel()
{
	EApiStatus_t Ret = 0;
	uint32_t level;
	CString s1, s2;
	EditGPIOGetLevelID.GetWindowTextW(s1);
	EditGPIOGetLevelBitmask.GetWindowTextW(s2);

	Ret = EApiGPIOGetLevel(_ttoi(s1), _ttoi(s2), &level);

	CString strMsg;

	strMsg.Format(_T("EApiGPIOGetLevel:  Ret = [0x%X]; level = %d"), Ret, level);

	StaticOutput.SetWindowTextW(strMsg);
}


void GPIODialog::OnBnClickedButtonEapigpiosetlevel()
{
	EApiStatus_t Ret = 0;
	CString s1, s2, s3;
	EditGPIOSetLevelID.GetWindowTextW(s1);
	EditGPIOSetLevelBitmask.GetWindowTextW(s2);
	EditGPIOSetLevelLevel.GetWindowTextW(s3);

	Ret = EApiGPIOSetDirection(_ttoi(s1), _ttoi(s2), _ttoi(s3));

	CString strMsg;

	strMsg.Format(_T("EApiGPIOGetDirection:  Ret = [0x%X]; "), Ret);

	StaticOutput.SetWindowTextW(strMsg);
}
