#pragma once
#include "afxwin.h"


// StorageDialog �Ի���

class StorageDialog : public CDialogEx
{
	DECLARE_DYNAMIC(StorageDialog)

public:
	StorageDialog(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~StorageDialog();

// �Ի�������
	enum { IDD = IDD_FICEAPI_STORAGE_DIALOG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButtonEapistoragecap();
	CEdit EditIDCap;
	CStatic StaticOutput;
	afx_msg void OnBnClickedButtonEapistoragearearead();
	afx_msg void OnBnClickedButtonEapistorageareawrite();
	CEdit EditBufferToWrite;
	CEdit EditIDReadWrite;
	CEdit EditOffsetReadWrite;
	CEdit EditByteCntReadWrite;
	CEdit EditBufLen;
};
