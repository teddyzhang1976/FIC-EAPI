#pragma once
#include "afxwin.h"


// BacklightDialog �Ի���

class BacklightDialog : public CDialogEx
{
	DECLARE_DYNAMIC(BacklightDialog)

public:
	BacklightDialog(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~BacklightDialog();

// �Ի�������
	enum { IDD = IDD_FICEAPI_BACKLIGHT_DIALOG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

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
