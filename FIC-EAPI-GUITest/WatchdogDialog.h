#pragma once
#include "afxwin.h"


// WatchdogDialog �Ի���

class WatchdogDialog : public CDialogEx
{
	DECLARE_DYNAMIC(WatchdogDialog)

public:
	WatchdogDialog(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~WatchdogDialog();

// �Ի�������
	enum { IDD = IDD_FICEAPI_WATCHDOG_DIALOG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButtonEapiwdoggetcap();
	afx_msg void OnEnChangeEdit1();
	// output for function calling
	CStatic StaticOutput;
	CEdit editDelay;
	CEdit editEventTimeout;
	CEdit editResetTimeout;
	afx_msg void OnBnClickedButtonEapiwdogstart();
	afx_msg void OnBnClickedButtonEapiwdogtrigger();
	afx_msg void OnBnClickedButtonEapiwdogstop();
};
