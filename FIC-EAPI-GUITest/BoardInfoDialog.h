#pragma once
#include "afxwin.h"


// BoardInfoDialog 对话框

class BoardInfoDialog : public CDialogEx
{
	DECLARE_DYNAMIC(BoardInfoDialog)

public:
	BoardInfoDialog(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~BoardInfoDialog();

// 对话框数据
	enum { IDD = IDD_FICEAPI_BOARDINFO_DIALOG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	CEdit EditGetStringAID;
	CEdit EditGetValueID;
	afx_msg void OnBnClickedButtonEapiboardgetstringa();
	CStatic StaticOutput;
	afx_msg void OnBnClickedButtonEapiboardgetvalue();
};
