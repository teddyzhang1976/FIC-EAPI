#pragma once


// WatchdogDialog 对话框

class WatchdogDialog : public CDialogEx
{
	DECLARE_DYNAMIC(WatchdogDialog)

public:
	WatchdogDialog(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~WatchdogDialog();

// 对话框数据
	enum { IDD = IDD_FICEAPI_WATCHDOG_DIALOG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
};
