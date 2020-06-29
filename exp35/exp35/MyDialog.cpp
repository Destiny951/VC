// MyDialog.cpp : 实现文件
//

#include "stdafx.h"
#include "exp35.h"
#include "MyDialog.h"
#include "afxdialogex.h"


// MyDialog 对话框

IMPLEMENT_DYNAMIC(MyDialog, CDialogEx)

MyDialog::MyDialog(CWnd* pParent /*=NULL*/)
	: CDialogEx(MyDialog::IDD, pParent)
{

}

MyDialog::~MyDialog()
{
}

void MyDialog::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(MyDialog, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON1, &MyDialog::OnBnClickedButton1)
END_MESSAGE_MAP()


// MyDialog 消息处理程序


void MyDialog::OnBnClickedButton1()
{
	CImage image;
	image.Load(filename);
	int w, h, sx, sy;
	CRect rect;
	GetDlgItem(IDC_STATIC)->GetClientRect(&rect);
	float rect_radio = 1.0*rect.Width() / rect.Height();
	float image_radio = 1.0*image.GetWidth() / image.GetHeight();
		if (rect_radio > image_radio)
		{
			h = rect.Height();
			w = image_radio*h;
			sx = (rect.Width() - w) / 2;
			sy = 0;
		}
		else
		{
			w = rect.Width();
			h = w / image_radio;
			sx = 0;
			sy = (rect.Height() - h) / 2;
		}
	CDC *pDC = GetDlgItem(IDC_STATIC)->GetDC();
	image.Draw(pDC->m_hDC, sx, sy, w, h);
	// TODO:  在此添加控件通知处理程序代码
}
