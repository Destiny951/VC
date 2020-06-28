// MyDialog.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "exp31.h"
#include "MyDialog.h"
#include "afxdialogex.h"


// MyDialog �Ի���

IMPLEMENT_DYNAMIC(MyDialog, CDialogEx)

MyDialog::MyDialog(CWnd* pParent /*=NULL*/)
	: CDialogEx(MyDialog::IDD, pParent)
	, c1(_T(""))
	, c2(0)
	, c3(_T(""))
{

}

MyDialog::~MyDialog()
{
}

void MyDialog::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT2, c1);
	DDX_Text(pDX, IDC_EDIT3, c2);
	DDX_Text(pDX, IDC_EDIT1, c3);
}


BEGIN_MESSAGE_MAP(MyDialog, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON1, &MyDialog::OnBnClickedButton1)
END_MESSAGE_MAP()


// MyDialog ��Ϣ�������


void MyDialog::OnBnClickedButton1()
{
	CString s;
	this->UpdateData(true);
	s.Format(_T("%d"), c2);
	c3 = c1 + s;
	this->UpdateData(false);
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
}
