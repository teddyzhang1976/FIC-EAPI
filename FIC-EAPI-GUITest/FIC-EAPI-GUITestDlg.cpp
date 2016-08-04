
// FIC-EAPI-GUITestDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "FIC-EAPI-GUITest.h"
#include "FIC-EAPI-GUITestDlg.h"
#include "afxdialogex.h"

////////////////////////////
//include all components
#include "WatchdogDialog.h"
#include "StorageDialog.h"
#include "I2CBusDlg.h"
#include "GPIODialog.h"
#include "BacklightDialog.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// ����Ӧ�ó��򡰹��ڡ��˵���� CAboutDlg �Ի���
WatchdogDialog *p_WatchdogDlg;
StorageDialog *p_StorageDlg;
I2CBusDlg *p_I2cBusDlg;
GPIODialog *p_GPIODialog;
BacklightDialog *p_BacklightDlg;

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// �Ի�������
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

// ʵ��
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CFICEAPIGUITestDlg �Ի���



CFICEAPIGUITestDlg::CFICEAPIGUITestDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CFICEAPIGUITestDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CFICEAPIGUITestDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CFICEAPIGUITestDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON_WATCHDOG, &CFICEAPIGUITestDlg::OnBnClickedButtonWatchdog)
	ON_BN_CLICKED(IDC_BUTTON_GPIO, &CFICEAPIGUITestDlg::OnBnClickedButtonGpio)
	ON_BN_CLICKED(IDC_BUTTON_STORAGE, &CFICEAPIGUITestDlg::OnBnClickedButtonStorage)
	ON_BN_CLICKED(IDC_BUTTON_I2CBUS, &CFICEAPIGUITestDlg::OnBnClickedButtonI2cbus)
	ON_BN_CLICKED(IDC_BUTTON_BACKLIGHT, &CFICEAPIGUITestDlg::OnBnClickedButtonBacklight)
END_MESSAGE_MAP()


// CFICEAPIGUITestDlg ��Ϣ�������

BOOL CFICEAPIGUITestDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// ��������...���˵�����ӵ�ϵͳ�˵��С�

	// IDM_ABOUTBOX ������ϵͳ���Χ�ڡ�
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// ���ô˶Ի����ͼ�ꡣ  ��Ӧ�ó��������ڲ��ǶԻ���ʱ����ܽ��Զ�
	//  ִ�д˲���
	SetIcon(m_hIcon, TRUE);			// ���ô�ͼ��
	SetIcon(m_hIcon, FALSE);		// ����Сͼ��

	// TODO:  �ڴ���Ӷ���ĳ�ʼ������

	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
}

void CFICEAPIGUITestDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// �����Ի��������С����ť������Ҫ����Ĵ���
//  �����Ƹ�ͼ�ꡣ  ����ʹ���ĵ�/��ͼģ�͵� MFC Ӧ�ó���
//  �⽫�ɿ���Զ���ɡ�

void CFICEAPIGUITestDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // ���ڻ��Ƶ��豸������

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// ʹͼ���ڹ����������о���
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// ����ͼ��
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//���û��϶���С������ʱϵͳ���ô˺���ȡ�ù��
//��ʾ��
HCURSOR CFICEAPIGUITestDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}




void CFICEAPIGUITestDlg::OnBnClickedButtonWatchdog()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	if (p_WatchdogDlg != NULL)
	{
		p_WatchdogDlg->DestroyWindow();
		delete p_WatchdogDlg;
		p_WatchdogDlg = NULL;
	}

	//.RePaint();

	p_WatchdogDlg = new WatchdogDialog();
	INT_PTR nResponse = p_WatchdogDlg->DoModal();
}


void CFICEAPIGUITestDlg::OnBnClickedButtonGpio()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	if (p_GPIODialog != NULL)
	{
		p_GPIODialog->DestroyWindow();
		delete p_GPIODialog;
		p_GPIODialog = NULL;
	}

	//.RePaint();

	p_GPIODialog = new GPIODialog();
	INT_PTR nResponse = p_GPIODialog->DoModal();
}


void CFICEAPIGUITestDlg::OnBnClickedButtonStorage()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	if (p_StorageDlg != NULL)
	{
		p_StorageDlg->DestroyWindow();
		delete p_StorageDlg;
		p_StorageDlg = NULL;
	}

	//.RePaint();

	p_StorageDlg = new StorageDialog();
	INT_PTR nResponse = p_StorageDlg->DoModal();
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
}


void CFICEAPIGUITestDlg::OnBnClickedButtonI2cbus()
{
	if (p_I2cBusDlg != NULL)
	{
		p_I2cBusDlg->DestroyWindow();
		delete p_I2cBusDlg;
		p_I2cBusDlg = NULL;
	}

	//.RePaint();

	p_I2cBusDlg = new I2CBusDlg();
	INT_PTR nResponse = p_I2cBusDlg->DoModal();
}


void CFICEAPIGUITestDlg::OnBnClickedButtonBacklight()
{
	if (p_BacklightDlg != NULL)
	{
		p_BacklightDlg->DestroyWindow();
		delete p_BacklightDlg;
		p_BacklightDlg = NULL;
	}

	//.RePaint();

	p_BacklightDlg = new BacklightDialog();
	INT_PTR nResponse = p_BacklightDlg->DoModal();
}
