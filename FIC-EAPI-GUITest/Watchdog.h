#pragma once


// Watchdog �Ի���

class Watchdog : public CDialogEx
{
	DECLARE_DYNAMIC(Watchdog)

public:
	Watchdog(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~Watchdog();

// �Ի�������
	enum { IDD = IDD_FICEAPI_GUITEST_MAIN_DIALOG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButtonBoardinfo();
	afx_msg void OnBnClickedButtonWatchdog();
	afx_msg void OnBnClickedButtonGpio();
};
