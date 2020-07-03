// Edit.cpp : 实现文件
//

#include "stdafx.h"
#include "expAll.h"
#include "Edit.h"
#include "afxdialogex.h"


// Edit 对话框

IMPLEMENT_DYNAMIC(Edit, CDialogEx)

Edit::Edit(CWnd* pParent /*=NULL*/)
	: CDialogEx(Edit::IDD, pParent)
	, name(_T(""))
	, number(_T(""))
	, major(_T(""))
	, sex(_T(""))
	, birth(_T(""))
	, phone(_T(""))
	, address(_T(""))
	, picture(_T(""))
{

}

Edit::~Edit()
{
}

void Edit::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT10, name);
	DDX_Text(pDX, IDC_EDIT11, number);
	DDX_Text(pDX, IDC_EDIT12, major);
	DDX_Text(pDX, IDC_EDIT14, sex);
	DDX_Text(pDX, IDC_EDIT13, birth);
	DDX_Text(pDX, IDC_EDIT15, phone);
	DDX_Text(pDX, IDC_EDIT16, address);
	DDX_Text(pDX, IDC_EDIT17, picture);
}


BEGIN_MESSAGE_MAP(Edit, CDialogEx)
END_MESSAGE_MAP()


// Edit 消息处理程序
