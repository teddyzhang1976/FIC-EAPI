#pragma once
#include "afxwin.h"


// GPIODialog 对话框

class GPIODialog : public CDialogEx
{
	DECLARE_DYNAMIC(GPIODialog)

public:
	GPIODialog(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~GPIODialog();

// 对话框数据
	enum { IDD = IDD_FICEAPI_GPIO_DIALOG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButtonEapigpiogetdirectioncaps();
	afx_msg void OnBnClickedButtonEapigpiogetdirection();
	afx_msg void OnBnClickedButtonEapigpiosetdirection();
	afx_msg void OnBnClickedButtonEapigpiogetlevel();
	afx_msg void OnBnClickedButtonEapigpiosetlevel();
	CEdit EditGPIODirectCapID;
	CEdit EditGPIOGetDirectionID;
	CEdit EditGPIOGetDirectionBitmask;
	CEdit EditGPIOSetDirectionID;
	CEdit EditGPIOSetDirectionBitmask;
	CEdit EditGPIOSetDirectionDirection;
	CEdit EditGPIOGetLevelID;
	CEdit EditGPIOGetLevelBitmask;
	CEdit EditGPIOSetLevelID;
	CEdit EditGPIOSetLevelBitmask;
	CEdit EditGPIOSetLevelLevel;
	CStatic StaticOutput;
};
