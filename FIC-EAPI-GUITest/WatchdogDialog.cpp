// WatchdogDialog.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "FIC-EAPI-GUITest.h"
#include "WatchdogDialog.h"
#include "afxdialogex.h"


// WatchdogDialog �Ի���

IMPLEMENT_DYNAMIC(WatchdogDialog, CDialogEx)

WatchdogDialog::WatchdogDialog(CWnd* pParent /*=NULL*/)
	: CDialogEx(WatchdogDialog::IDD, pParent)
{

}

WatchdogDialog::~WatchdogDialog()
{
}

void WatchdogDialog::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(WatchdogDialog, CDialogEx)
END_MESSAGE_MAP()


// WatchdogDialog ��Ϣ�������
