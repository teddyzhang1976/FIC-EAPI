// Watchdog.cpp : 实现文件
//

#include "stdafx.h"
#include "FIC-EAPI-GUITest.h"
#include "Watchdog.h"
#include "afxdialogex.h"


// Watchdog 对话框

IMPLEMENT_DYNAMIC(Watchdog, CDialogEx)

Watchdog::Watchdog(CWnd* pParent /*=NULL*/)
	: CDialogEx(Watchdog::IDD, pParent)
{

}

Watchdog::~Watchdog()
{
}

void Watchdog::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(Watchdog, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON_BOARDINFO, &Watchdog::OnBnClickedButtonBoardinfo)
	ON_BN_CLICKED(IDC_BUTTON_WATCHDOG, &Watchdog::OnBnClickedButtonWatchdog)
	ON_BN_CLICKED(IDC_BUTTON_GPIO, &Watchdog::OnBnClickedButtonGpio)
END_MESSAGE_MAP()


// Watchdog 消息处理程序


void Watchdog::OnBnClickedButtonBoardinfo()
{
	// TODO:  在此添加控件通知处理程序代码
}


void Watchdog::OnBnClickedButtonWatchdog()
{
	// TODO:  在此添加控件通知处理程序代码
}


void Watchdog::OnBnClickedButtonGpio()
{
	// TODO:  在此添加控件通知处理程序代码
}
