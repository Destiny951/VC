
// exp36Dlg.cpp : 实现文件
//

#include "stdafx.h"
#include "exp36.h"
#include "exp36Dlg.h"
#include "afxdialogex.h"
#include <iostream>
#include <string>
#include <fstream>
using namespace std;

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// 用于应用程序“关于”菜单项的 CAboutDlg 对话框

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 对话框数据
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

// 实现
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


// Cexp36Dlg 对话框



Cexp36Dlg::Cexp36Dlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(Cexp36Dlg::IDD, pParent)
	, change(_T(""))
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void Cexp36Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, change);
	DDX_Control(pDX, IDC_LIST1, student);
}

BEGIN_MESSAGE_MAP(Cexp36Dlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON1, &Cexp36Dlg::OnBnClickedButton1)
	ON_LBN_SELCHANGE(IDC_LIST1, &Cexp36Dlg::OnLbnSelchangeList1)
	ON_BN_CLICKED(IDC_BUTTON2, &Cexp36Dlg::OnBnClickedButton2)
END_MESSAGE_MAP()


// Cexp36Dlg 消息处理程序

BOOL Cexp36Dlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 将“关于...”菜单项添加到系统菜单中。

	// IDM_ABOUTBOX 必须在系统命令范围内。
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

	// 设置此对话框的图标。  当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	// TODO:  在此添加额外的初始化代码

	//不知道怎么获取文件的相对路径，所以用按钮选择文件
	/*filename = _T("C:\\Users\\dagro\\Desktop\\abcdefg.txt");
	ifstream ifs(filename);
	string s;
	while (ifs >> s)
	{
		student.AddString(CString(s.c_str()));
	}*/
	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void Cexp36Dlg::OnSysCommand(UINT nID, LPARAM lParam)
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

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。  对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void Cexp36Dlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 用于绘制的设备上下文

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 使图标在工作区矩形中居中
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 绘制图标
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR Cexp36Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void Cexp36Dlg::OnBnClickedButton1()
{

	this->UpdateData(true);
	student.DeleteString(index);
	student.InsertString(index, change);
	this->UpdateData(false);
	ofstream ofs(filename);
	for (int i = 0; i < student.GetCount(); i++)
	{
		CString s;
		student.GetText(i, s);
		ofs << CT2A(s.GetString()) << endl;
	}
	// TODO:  在此添加控件通知处理程序代码
}


void Cexp36Dlg::OnLbnSelchangeList1()
{
	
	this->UpdateData(true);
	index = student.GetCurSel();
	student.GetText(index, change);
	this->UpdateData(false);
	// TODO:  在此添加控件通知处理程序代码
}


void Cexp36Dlg::OnBnClickedButton2()
{
	CFileDialog cfd(true);
	int r = cfd.DoModal();
	if (r == IDOK)
	{
		filename = cfd.GetPathName();
		ifstream ifs(filename);
		string s;
		while (ifs >> s)
		{
			student.AddString(CString(s.c_str()));
		}
	}
	// TODO:  在此添加控件通知处理程序代码
}
