#pragma once
#include "afxwin.h"


// BoardInfoDialog �Ի���

class BoardInfoDialog : public CDialogEx
{
	DECLARE_DYNAMIC(BoardInfoDialog)

public:
	BoardInfoDialog(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~BoardInfoDialog();

// �Ի�������
	enum { IDD = IDD_FICEAPI_BOARDINFO_DIALOG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	CEdit EditGetStringAID;
	CEdit EditGetValueID;
	afx_msg void OnBnClickedButtonEapiboardgetstringa();
	CStatic StaticOutput;
	afx_msg void OnBnClickedButtonEapiboardgetvalue();
};
