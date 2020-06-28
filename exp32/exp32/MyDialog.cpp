// MyDialog.cpp : 实现文件
//

#include "stdafx.h"
#include "exp32.h"
#include "MyDialog.h"
#include "afxdialogex.h"


// MyDialog 对话框

IMPLEMENT_DYNAMIC(MyDialog, CDialogEx)

MyDialog::MyDialog(CWnd* pParent /*=NULL*/)
	: CDialogEx(MyDialog::IDD, pParent)
	, s1(_T(""))
{

}

MyDialog::~MyDialog()
{
}

void MyDialog::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, s1);
	DDX_Control(pDX, IDC_LIST1, s3);
}


BEGIN_MESSAGE_MAP(MyDialog, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON1, &MyDialog::OnBnClickedButton1)
END_MESSAGE_MAP()


// MyDialog 消息处理程序


void MyDialog::OnBnClickedButton1()
{
	this->UpdateData(true);
	this->UpdateData(false);
	// TODO:  在此添加控件通知处理程序代码
}


BOOL MyDialog::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  在此添加额外的初始化
	s3.AddString(s1);
	return TRUE;  // return TRUE unless you set the focus to a control
	// 异常:  OCX 属性页应返回 FALSE
}
