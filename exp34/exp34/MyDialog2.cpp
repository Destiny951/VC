// MyDialog2.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "exp34.h"
#include "MyDialog2.h"
#include "afxdialogex.h"


// MyDialog2 �Ի���

IMPLEMENT_DYNAMIC(MyDialog2, CDialogEx)

MyDialog2::MyDialog2(CWnd* pParent /*=NULL*/)
	: CDialogEx(MyDialog2::IDD, pParent)
	, red(0)
	, green(0)
	, blue(0)
{

}

MyDialog2::~MyDialog2()
{
}

void MyDialog2::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, red);
	DDV_MinMaxInt(pDX, red, 0, 255);
	DDX_Text(pDX, IDC_EDIT2, green);
	DDV_MinMaxInt(pDX, green, 0, 255);
	DDX_Text(pDX, IDC_EDIT3, blue);
	DDV_MinMaxInt(pDX, blue, 0, 255);
}


BEGIN_MESSAGE_MAP(MyDialog2, CDialogEx)
	ON_BN_CLICKED(IDOK, &MyDialog2::OnBnClickedOk)
END_MESSAGE_MAP()


// MyDialog2 ��Ϣ�������


void MyDialog2::OnBnClickedOk()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	CDialogEx::OnOK();
}
