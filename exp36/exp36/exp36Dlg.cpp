
// exp36Dlg.cpp : ʵ���ļ�
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


// ����Ӧ�ó��򡰹��ڡ��˵���� CAboutDlg �Ի���

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


// Cexp36Dlg �Ի���



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


// Cexp36Dlg ��Ϣ�������

BOOL Cexp36Dlg::OnInitDialog()
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

	//��֪����ô��ȡ�ļ������·���������ð�ťѡ���ļ�
	/*filename = _T("C:\\Users\\dagro\\Desktop\\abcdefg.txt");
	ifstream ifs(filename);
	string s;
	while (ifs >> s)
	{
		student.AddString(CString(s.c_str()));
	}*/
	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
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

// �����Ի��������С����ť������Ҫ����Ĵ���
//  �����Ƹ�ͼ�ꡣ  ����ʹ���ĵ�/��ͼģ�͵� MFC Ӧ�ó���
//  �⽫�ɿ���Զ���ɡ�

void Cexp36Dlg::OnPaint()
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
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
}


void Cexp36Dlg::OnLbnSelchangeList1()
{
	
	this->UpdateData(true);
	index = student.GetCurSel();
	student.GetText(index, change);
	this->UpdateData(false);
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
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
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
}
