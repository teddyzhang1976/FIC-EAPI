// StorageDialog.cpp : 实现文件
//

#include "stdafx.h"
#include "FIC-EAPI-GUITest.h"
#include "StorageDialog.h"
#include "afxdialogex.h"


// StorageDialog 对话框

IMPLEMENT_DYNAMIC(StorageDialog, CDialogEx)

StorageDialog::StorageDialog(CWnd* pParent /*=NULL*/)
	: CDialogEx(StorageDialog::IDD, pParent)
{

}

StorageDialog::~StorageDialog()
{
}

void StorageDialog::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDIT_ID_Cap, EditIDCap);
	DDX_Control(pDX, IDC_STATIC_OUTPUT, StaticOutput);
	DDX_Control(pDX, IDC_EDIT_BufToWrite, EditBufferToWrite);
	DDX_Control(pDX, IDC_EDIT_ID_AreaReadWrite, EditIDReadWrite);
	DDX_Control(pDX, IDC_EDIT_Offset, EditOffsetReadWrite);
	DDX_Control(pDX, IDC_EDIT_ByteCnt, EditByteCntReadWrite);
	DDX_Control(pDX, IDC_EDIT_BufLen, EditBufLen);
}


BEGIN_MESSAGE_MAP(StorageDialog, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON_EApiStorageCap, &StorageDialog::OnBnClickedButtonEapistoragecap)
	ON_BN_CLICKED(IDC_BUTTON_EApiStorageAreaRead, &StorageDialog::OnBnClickedButtonEapistoragearearead)
	ON_BN_CLICKED(IDC_BUTTON_EApiStorageAreaWrite, &StorageDialog::OnBnClickedButtonEapistorageareawrite)
END_MESSAGE_MAP()


// StorageDialog 消息处理程序


void StorageDialog::OnBnClickedButtonEapistoragecap()
{
	EApiStatus_t Ret = 0;
	uint32_t storageSize, blockLength;

	CString i1, i2, i3;
	EditIDCap.GetWindowTextW(i1);
	Ret = EApiStorageCap(_ttoi(i1), &storageSize, &blockLength);

	CString strMsg;

	strMsg.Format(_T("EApiStorageCap:  Ret = [0x%X]; storageSize = 0x%x; blockLength = 0x%x"), Ret,storageSize,blockLength);

	StaticOutput.SetWindowTextW(strMsg);
}


void StorageDialog::OnBnClickedButtonEapistoragearearead()
{
	EApiStatus_t Ret = 0;
	uint32_t i0,i1,i2,i3;

	CString s0,s1, s2, s3;
	EditIDReadWrite.GetWindowTextW(s0);
	EditOffsetReadWrite.GetWindowTextW(s1);
	EditByteCntReadWrite.GetWindowTextW(s2);
	EditBufLen.GetWindowTextW(s3);

	i0 = _ttoi(s0);
	i1 = _ttoi(s1);
	i2 = _ttoi(s2);
	i3 = _ttoi(s3);

	char* buffer = new char[i2*i3];
	
	Ret = EApiStorageAreaRead(i0, i1, buffer, i2, i3);

	CString strMsg;

	strMsg.Format(_T("EApiStorageAreaRead:  Ret = [0x%X]; read buffer = %s"), Ret, buffer);

	StaticOutput.SetWindowTextW(strMsg);

	delete buffer;

}


void StorageDialog::OnBnClickedButtonEapistorageareawrite()
{
	EApiStatus_t Ret = 0;
	uint32_t i0, i1, i2, i3;

	CString s0, s1, s2, s3;
	EditIDReadWrite.GetWindowTextW(s0);
	EditOffsetReadWrite.GetWindowTextW(s1);
	EditByteCntReadWrite.GetWindowTextW(s2);
	EditBufferToWrite.GetWindowTextW(s3);

	i0 = _ttoi(s0);
	i1 = _ttoi(s1);
	i2 = _ttoi(s2);
	


	s3.GetString();

	Ret = EApiStorageAreaWrite(i0, i1, (void *)(s3.GetString()), i2 );

	CString strMsg;

	strMsg.Format(_T("EApiStorageAreaRead:  Ret = [0x%X];"), Ret );

	StaticOutput.SetWindowTextW(strMsg);
}
