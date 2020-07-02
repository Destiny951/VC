
// exp40View.cpp : Cexp40View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "exp40.h"
#endif

#include "exp40Set.h"
#include "exp40Doc.h"
#include "exp40View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// Cexp40View

IMPLEMENT_DYNCREATE(Cexp40View, CRecordView)

BEGIN_MESSAGE_MAP(Cexp40View, CRecordView)
	ON_EN_CHANGE(IDC_EDIT1, &Cexp40View::OnEnChangeEdit1)
	ON_WM_PAINT()
END_MESSAGE_MAP()

// Cexp40View 构造/析构

Cexp40View::Cexp40View()
	: CRecordView(Cexp40View::IDD)
	, ID(0)
	, name(_T(""))
	, number(0)
	, age(0)
	, phone(0)
{
	m_pSet = NULL;
	// TODO:  在此处添加构造代码

}

Cexp40View::~Cexp40View()
{
}

void Cexp40View::DoDataExchange(CDataExchange* pDX)
{
	CRecordView::DoDataExchange(pDX);
	// 可以在此处插入 DDX_Field* 函数以将控件“连接”到数据库字段，例如
	// DDX_FieldText(pDX, IDC_MYEDITBOX, m_pSet->m_szColumn1, m_pSet);
	// DDX_FieldCheck(pDX, IDC_MYCHECKBOX, m_pSet->m_bColumn2, m_pSet);
	// 有关详细信息，请参阅 MSDN 和 ODBC 示例
	DDX_Text(pDX, IDC_EDIT1, m_pSet->m_ID);
	DDX_Text(pDX, IDC_EDIT2, m_pSet->m_1);
	DDX_Text(pDX, IDC_EDIT4, m_pSet->m_2);
	DDX_Text(pDX, IDC_EDIT3, m_pSet->m_3);
	DDX_Text(pDX, IDC_EDIT5, m_pSet->m_4);
	Invalidate();
}

BOOL Cexp40View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO:  在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CRecordView::PreCreateWindow(cs);
}

void Cexp40View::OnInitialUpdate()
{
	m_pSet = &GetDocument()->m_exp40Set;
	CRecordView::OnInitialUpdate();

}


// Cexp40View 诊断

#ifdef _DEBUG
void Cexp40View::AssertValid() const
{
	CRecordView::AssertValid();
}

void Cexp40View::Dump(CDumpContext& dc) const
{
	CRecordView::Dump(dc);
}

Cexp40Doc* Cexp40View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(Cexp40Doc)));
	return (Cexp40Doc*)m_pDocument;
}
#endif //_DEBUG


// Cexp40View 数据库支持
CRecordset* Cexp40View::OnGetRecordset()
{
	return m_pSet;
}



// Cexp40View 消息处理程序


void Cexp40View::OnEnChangeEdit1()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CRecordView::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码
}


void Cexp40View::OnPaint()
{
	CPaintDC dc(this); // device context for painting
	CString s;
	m_pSet->GetFieldValue(short(5), s);
	CImage image;
	image.Load(s);
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
	
	// TODO:  在此处添加消息处理程序代码
	// 不为绘图消息调用 CRecordView::OnPaint()
}
