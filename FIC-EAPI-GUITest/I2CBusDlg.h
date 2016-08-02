#pragma once
#include "afxwin.h"


// I2CBusDlg 对话框

class I2CBusDlg : public CDialogEx
{
	DECLARE_DYNAMIC(I2CBusDlg)

public:
	I2CBusDlg(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~I2CBusDlg();

// 对话框数据
	enum { IDD = IDD_FICEAPI_I2CBUS_DIALOG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButtonEapii2cgetbuscap();
	afx_msg void OnBnClickedButtonEapii2cwritereadraw();
	afx_msg void OnBnClickedButtonEapii2creadtransfer();
	afx_msg void OnBnClickedButtonEapii2cwritetransfer();
	afx_msg void OnBnClickedButtonEapii2cprobedevice();
	CStatic StaticOutput;
	CEdit EditBusCapID;
	CEdit EditWriteReadID;
	CEdit EditWriteReadAdd;
	CEdit EditWriteReadWriteBuf;
	CEdit EditWriteReadWriteCnt;
	CEdit EditWriteReadBufLen;
	CEdit EditWriteReadReadCnt;
	CEdit EditReadTransferID;
	CEdit EditReadTransferAddr;
	CEdit EditReadTransferCmd;
	CEdit EditReadTransferBufLen;
	CEdit EditReadTransferReadCnt;
	CEdit EditWriteTransferID;
	CEdit EditWriteTransferAddr;
	CEdit EditWriteTransferWriteBuf;
	CEdit EditWriteTransferCmd;
	CEdit EditWriteTransferBufLen;
	CEdit EditWriteTransferWriteCnt;
	CEdit EditProbeDeviceID;
	CEdit EditProbeDeviceAddr;
};
