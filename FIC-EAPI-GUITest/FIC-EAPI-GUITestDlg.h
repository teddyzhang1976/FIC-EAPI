
// FIC-EAPI-GUITestDlg.h : ͷ�ļ�
//

#pragma once


// CFICEAPIGUITestDlg �Ի���
class CFICEAPIGUITestDlg : public CDialogEx
{
// ����
public:
	CFICEAPIGUITestDlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
	enum { IDD = IDD_FICEAPIGUITEST_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ֧��


// ʵ��
protected:
	HICON m_hIcon;

	// ���ɵ���Ϣӳ�亯��
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton2();
	afx_msg void OnBnClickedButtonWatchdog();
	afx_msg void OnBnClickedButtonGpio();
};
