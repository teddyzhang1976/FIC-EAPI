#pragma once


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
};
