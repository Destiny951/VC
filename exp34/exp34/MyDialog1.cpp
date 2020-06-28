// MyDialog1.cpp : 实现文件
//

#include "stdafx.h"
#include "exp34.h"
#include "MyDialog1.h"
#include "afxdialogex.h"


// MyDialog1 对话框

IMPLEMENT_DYNAMIC(MyDialog1, CDialogEx)

MyDialog1::MyDialog1(CWnd* pParent /*=NULL*/)
	: CDialogEx(MyDialog1::IDD, pParent)
	, x(0)
	, y(0)
	, r(0)
{

}

MyDialog1::~MyDialog1()
{
}

void MyDialog1::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, x);
	DDX_Text(pDX, IDC_EDIT2, y);
	DDX_Text(pDX, IDC_EDIT3, r);
}


BEGIN_MESSAGE_MAP(MyDialog1, CDialogEx)
	ON_BN_CLICKED(IDOK, &MyDialog1::OnBnClickedOk)
END_MESSAGE_MAP()


// MyDialog1 消息处理程序


void MyDialog1::OnBnClickedOk()
{
	// TODO:  在此添加控件通知处理程序代码
	CDialogEx::OnOK();
}
