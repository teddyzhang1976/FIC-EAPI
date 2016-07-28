// Watchdog.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "FIC-EAPI-GUITest.h"
#include "Watchdog.h"
#include "afxdialogex.h"


// Watchdog �Ի���

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


// Watchdog ��Ϣ�������


void Watchdog::OnBnClickedButtonBoardinfo()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
}


void Watchdog::OnBnClickedButtonWatchdog()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
}


void Watchdog::OnBnClickedButtonGpio()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
}
