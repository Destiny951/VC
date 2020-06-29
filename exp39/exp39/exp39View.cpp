
// exp39View.cpp : Cexp39View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "exp39.h"
#endif

#include "exp39Set.h"
#include "exp39Doc.h"
#include "exp39View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// Cexp39View

IMPLEMENT_DYNCREATE(Cexp39View, CRecordView)

BEGIN_MESSAGE_MAP(Cexp39View, CRecordView)
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CRecordView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CRecordView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CRecordView::OnFilePrintPreview)
	ON_BN_CLICKED(IDC_BUTTON1, &Cexp39View::OnBnClickedButton1)
END_MESSAGE_MAP()

// Cexp39View 构造/析构

Cexp39View::Cexp39View()
	: CRecordView(Cexp39View::IDD)
	, ID(0)
	, name(_T(""))
	, number(0)
	, age(0)
	, phont(0)
{
	m_pSet = NULL;
	// TODO:  在此处添加构造代码

}

Cexp39View::~Cexp39View()
{
}

void Cexp39View::DoDataExchange(CDataExchange* pDX)
{
	CRecordView::DoDataExchange(pDX);
	// 可以在此处插入 DDX_Field* 函数以将控件“连接”到数据库字段，例如
	// DDX_FieldText(pDX, IDC_MYEDITBOX, m_pSet->m_szColumn1, m_pSet);
	// DDX_FieldCheck(pDX, IDC_MYCHECKBOX, m_pSet->m_bColumn2, m_pSet);
	// 有关详细信息，请参阅 MSDN 和 ODBC 示例
	DDX_Text(pDX, IDC_EDIT1, m_pSet->m_ID);
	DDX_Text(pDX, IDC_EDIT2, m_pSet->m_1);
	DDX_Text(pDX, IDC_EDIT6, m_pSet->m_2);
	DDX_Text(pDX, IDC_EDIT3, m_pSet->m_3);
	DDX_Text(pDX, IDC_EDIT4, m_pSet->m_4);
}

BOOL Cexp39View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO:  在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CRecordView::PreCreateWindow(cs);
}

void Cexp39View::OnInitialUpdate()
{
	m_pSet = &GetDocument()->m_exp39Set;
	CRecordView::OnInitialUpdate();

}


// Cexp39View 打印

BOOL Cexp39View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void Cexp39View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO:  添加额外的打印前进行的初始化过程
}

void Cexp39View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO:  添加打印后进行的清理过程
}


// Cexp39View 诊断

#ifdef _DEBUG
void Cexp39View::AssertValid() const
{
	CRecordView::AssertValid();
}

void Cexp39View::Dump(CDumpContext& dc) const
{
	CRecordView::Dump(dc);
}

Cexp39Doc* Cexp39View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(Cexp39Doc)));
	return (Cexp39Doc*)m_pDocument;
}
#endif //_DEBUG


// Cexp39View 数据库支持
CRecordset* Cexp39View::OnGetRecordset()
{
	return m_pSet;
}



// Cexp39View 消息处理程序


void Cexp39View::OnBnClickedButton1()
{
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
	// TODO:  在此添加控件通知处理程序代码
}
