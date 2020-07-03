// ADD.cpp : 实现文件
//

#include "stdafx.h"
#include "expAll.h"
#include "ADD.h"
#include "afxdialogex.h"


// ADD 对话框

IMPLEMENT_DYNAMIC(ADD, CDialogEx)

ADD::ADD(CWnd* pParent /*=NULL*/)
	: CDialogEx(ADD::IDD, pParent)
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

ADD::~ADD()
{
}

void ADD::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, name);
	DDX_Text(pDX, IDC_EDIT9, number);
	DDX_Text(pDX, IDC_EDIT2, major);
	DDX_Text(pDX, IDC_EDIT4, sex);
	DDX_Text(pDX, IDC_EDIT3, birth);
	DDX_Text(pDX, IDC_EDIT5, phone);
	DDX_Text(pDX, IDC_EDIT8, address);
	DDX_Text(pDX, IDC_EDIT7, picture);
}


BEGIN_MESSAGE_MAP(ADD, CDialogEx)
END_MESSAGE_MAP()


// ADD 消息处理程序
