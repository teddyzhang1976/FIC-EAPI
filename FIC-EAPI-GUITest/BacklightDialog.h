#pragma once
#include "afxwin.h"


// BacklightDialog 对话框

class BacklightDialog : public CDialogEx
{
	DECLARE_DYNAMIC(BacklightDialog)

public:
	BacklightDialog(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~BacklightDialog();

// 对话框数据
	enum { IDD = IDD_FICEAPI_BACKLIGHT_DIALOG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButtonEapivgagetbacklightenable();
	CEdit EditGetBacklightEnable;
	CStatic StaticOutput;
	afx_msg void OnBnClickedButtonEapivgasetbacklightenable();
	CEdit EditSetBacklightEnableID;
	CEdit EditSetBacklightEnableEnable;
	afx_msg void OnBnClickedButtonEapiwdogtrigger();
	afx_msg void OnBnClickedButtonEapivgagetbacklightbrightness();
	afx_msg void OnBnClickedButtonEapivgasetbacklightbrightness();
};
