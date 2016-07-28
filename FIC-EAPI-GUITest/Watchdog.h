#pragma once


// Watchdog 对话框

class Watchdog : public CDialogEx
{
	DECLARE_DYNAMIC(Watchdog)

public:
	Watchdog(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~Watchdog();

// 对话框数据
	enum { IDD = IDD_FICEAPI_GUITEST_MAIN_DIALOG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButtonBoardinfo();
	afx_msg void OnBnClickedButtonWatchdog();
	afx_msg void OnBnClickedButtonGpio();
};
