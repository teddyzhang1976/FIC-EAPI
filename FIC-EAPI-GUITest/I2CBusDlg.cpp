// I2CBusDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "FIC-EAPI-GUITest.h"
#include "I2CBusDlg.h"
#include "afxdialogex.h"


// I2CBusDlg 对话框

IMPLEMENT_DYNAMIC(I2CBusDlg, CDialogEx)

I2CBusDlg::I2CBusDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(I2CBusDlg::IDD, pParent)
{

}

I2CBusDlg::~I2CBusDlg()
{
}

void I2CBusDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_STATIC_OUTPUT, StaticOutput);
	DDX_Control(pDX, IDC_EDIT_BusCapID, EditBusCapID);
	DDX_Control(pDX, IDC_EDIT_ReadWriteID, EditWriteReadID);
	DDX_Control(pDX, IDC_EDIT_ReadWriteAddr, EditWriteReadAdd);
	DDX_Control(pDX, IDC_EDIT_ReadWriteWriteBuffer, EditWriteReadWriteBuf);
	DDX_Control(pDX, IDC_EDIT_ReadWriteCnt, EditWriteReadWriteCnt);
	DDX_Control(pDX, IDC_EDIT_ReadWriteBufLen, EditWriteReadBufLen);
	DDX_Control(pDX, IDC_EDIT_ReadWriteReadCnt, EditWriteReadReadCnt);
	DDX_Control(pDX, IDC_EDIT_ReadTransferID, EditReadTransferID);
	DDX_Control(pDX, IDC_EDIT_ReadTransferAddr, EditReadTransferAddr);
	DDX_Control(pDX, IDC_EDIT_ReadTransferCmd, EditReadTransferCmd);
	DDX_Control(pDX, IDC_EDIT_ReadTransferBufLen, EditReadTransferBufLen);
	DDX_Control(pDX, IDC_EDIT_ReadTransferReadCnt, EditReadTransferReadCnt);
	DDX_Control(pDX, IDC_EDIT_WriteTransferID, EditWriteTransferID);
	DDX_Control(pDX, IDC_EDIT_WriteTransferAddr, EditWriteTransferAddr);
	DDX_Control(pDX, IDC_EDIT_WriteTransferWriteBuffer, EditWriteTransferWriteBuf);
	DDX_Control(pDX, IDC_EDIT_WriteTransferCmd, EditWriteTransferCmd);
	DDX_Control(pDX, IDC_EDIT_WriteTransferBufLen, EditWriteTransferBufLen);
	DDX_Control(pDX, IDC_EDIT_WriteTransferWriteCnt, EditWriteTransferWriteCnt);
	DDX_Control(pDX, IDC_EDIT_ProbeDeviceID, EditProbeDeviceID);
	DDX_Control(pDX, IDC_EDIT_ProbeDeviceAddr, EditProbeDeviceAddr);
}


BEGIN_MESSAGE_MAP(I2CBusDlg, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON_EapiI2CGetBusCap, &I2CBusDlg::OnBnClickedButtonEapii2cgetbuscap)
	ON_BN_CLICKED(IDC_BUTTON_EapiI2CWriteReadRaw, &I2CBusDlg::OnBnClickedButtonEapii2cwritereadraw)
	ON_BN_CLICKED(IDC_BUTTON_EapiI2CReadTransfer, &I2CBusDlg::OnBnClickedButtonEapii2creadtransfer)
	ON_BN_CLICKED(IDC_BUTTON_EapiI2CWriteTransfer, &I2CBusDlg::OnBnClickedButtonEapii2cwritetransfer)
	ON_BN_CLICKED(IDC_BUTTON_EApiI2CProbeDevice, &I2CBusDlg::OnBnClickedButtonEapii2cprobedevice)
END_MESSAGE_MAP()


// I2CBusDlg 消息处理程序


void I2CBusDlg::OnBnClickedButtonEapii2cgetbuscap()
{
	EApiStatus_t Ret = 0;
	uint32_t maxBlockLength;

	CString i1;
	EditBusCapID.GetWindowTextW(i1);
	Ret = EApiI2CGetBusCap(_ttoi(i1), &maxBlockLength);

	CString strMsg;

	strMsg.Format(_T("EApiI2CGetBusCap:  Ret = [0x%X]; storageSize = 0x%x; maxblockLength = 0x%x"), Ret, maxBlockLength);

	StaticOutput.SetWindowTextW(strMsg);
	// TODO:  在此添加控件通知处理程序代码
}


void I2CBusDlg::OnBnClickedButtonEapii2cwritereadraw()
{
	EApiStatus_t Ret = 0;
	uint32_t i0, i1, i3,i4,i5;

	CString s0, s1, s2, s3,s4,s5;
	EditWriteReadID.GetWindowTextW(s0);
	EditWriteReadAdd.GetWindowTextW(s1);
	EditWriteReadWriteBuf.GetWindowTextW(s2);
	EditWriteReadWriteCnt.GetWindowTextW(s3);
	EditWriteReadBufLen.GetWindowTextW(s4);
	EditWriteReadReadCnt.GetWindowTextW(s5);


	i0 = _ttoi(s0);
	i1 = _ttoi(s1);
	i3 = _ttoi(s3);
	i4 = _ttoi(s4);
	i5 = _ttoi(s5);

	char* writeBuffer = new char[i3];
	char* readBuffer = new char[i4];

	Ret = EApiI2CWriteReadRaw(i0, i1, (void *)writeBuffer, i3, readBuffer,i4,i5);

	CString strMsg;

	strMsg.Format(_T("EApiI2CWriteReadRaw:  Ret = [0x%X]; read buffer = %s"), Ret, readBuffer);

	StaticOutput.SetWindowTextW(strMsg);

	delete readBuffer;
	delete writeBuffer;
}


void I2CBusDlg::OnBnClickedButtonEapii2creadtransfer()
{
	EApiStatus_t Ret = 0;
	uint32_t i0, i1, i2, i3, i4;

	CString s0, s1, s2, s3, s4;
	EditReadTransferID.GetWindowTextW(s0);
	EditReadTransferAddr.GetWindowTextW(s1);
	EditReadTransferCmd.GetWindowTextW(s2);
	EditReadTransferBufLen.GetWindowTextW(s3);
	EditReadTransferReadCnt.GetWindowTextW(s4);


	i0 = _ttoi(s0);
	i1 = _ttoi(s1);
	i2 = _ttoi(s2);
	i3 = _ttoi(s3);
	i4 = _ttoi(s4);

	char* readBuffer = new char[i3];
	
	Ret = EApiI2CReadTransfer(i0, i1, i2, (void *)readBuffer, i3, i4);

	CString strMsg;

	strMsg.Format(_T("EApiI2CWriteReadRaw:  Ret = [0x%X]; read buffer = %s"), Ret, readBuffer);

	StaticOutput.SetWindowTextW(strMsg);

	delete readBuffer;
}


void I2CBusDlg::OnBnClickedButtonEapii2cwritetransfer()
{
	EApiStatus_t Ret = 0;
	uint32_t i0, i1, i2, i3, i4;

	CString s0, s1, s2, s3, s4;
	EditWriteTransferID.GetWindowTextW(s0);
	EditWriteTransferAddr.GetWindowTextW(s1);
	EditWriteTransferCmd.GetWindowTextW(s2);
	EditWriteTransferBufLen.GetWindowTextW(s3);
	EditWriteTransferWriteCnt.GetWindowTextW(s4);


	i0 = _ttoi(s0);
	i1 = _ttoi(s1);
	i2 = _ttoi(s2);
	i3 = _ttoi(s3);
	i4 = _ttoi(s4);

	

	Ret = EApiI2CWriteTransfer(i0, i1, i2, (void *)s3.GetString(), i4);

	CString strMsg;

	strMsg.Format(_T("EApiI2CWriteReadRaw:  Ret = [0x%X]"), Ret);

	StaticOutput.SetWindowTextW(strMsg);

}


void I2CBusDlg::OnBnClickedButtonEapii2cprobedevice()
{
	EApiStatus_t Ret = 0;

	CString s1,s2;
	EditProbeDeviceID.GetWindowTextW(s1);
	EditProbeDeviceAddr.GetWindowTextW(s2);
	
	Ret = EApiI2CProbeDevice(_ttoi(s1), _ttoi(s2));

	CString strMsg;

	strMsg.Format(_T("EApiI2CProbeDevice:  Ret = [0x%X];"), Ret);

	StaticOutput.SetWindowTextW(strMsg);
}
