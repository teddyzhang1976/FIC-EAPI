// WatchdogDialog.cpp : 实现文件
//

#include "stdafx.h"
#include "FIC-EAPI-GUITest.h"
#include "WatchdogDialog.h"
#include "afxdialogex.h"


// WatchdogDialog 对话框

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


// WatchdogDialog 消息处理程序
