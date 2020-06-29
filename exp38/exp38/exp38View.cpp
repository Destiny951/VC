
// exp38View.cpp : Cexp38View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "exp38.h"
#endif

#include "exp38Set.h"
#include "exp38Doc.h"
#include "exp38View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// Cexp38View

IMPLEMENT_DYNCREATE(Cexp38View, CRecordView)

BEGIN_MESSAGE_MAP(Cexp38View, CRecordView)
	ON_EN_CHANGE(IDC_EDIT2, &Cexp38View::OnEnChangeEdit2)
END_MESSAGE_MAP()

// Cexp38View 构造/析构

Cexp38View::Cexp38View()
	: CRecordView(Cexp38View::IDD)
	, ID(0)
	, name(_T(""))
	, number(0)
	, age(0)
	, phone(0)
{
	m_pSet = NULL;
	// TODO:  在此处添加构造代码

}

Cexp38View::~Cexp38View()
{
}

void Cexp38View::DoDataExchange(CDataExchange* pDX)
{
	CRecordView::DoDataExchange(pDX);
	// 可以在此处插入 DDX_Field* 函数以将控件“连接”到数据库字段，例如
	// DDX_FieldText(pDX, IDC_MYEDITBOX, m_pSet->m_szColumn1, m_pSet);
	// DDX_FieldCheck(pDX, IDC_MYCHECKBOX, m_pSet->m_bColumn2, m_pSet);
	// 有关详细信息，请参阅 MSDN 和 ODBC 示例
	DDX_Text(pDX, IDC_EDIT1, m_pSet->m_ID);
	DDX_Text(pDX, IDC_EDIT2, m_pSet->m_1);
	DDX_Text(pDX, IDC_EDIT5, m_pSet->m_2);
	DDX_Text(pDX, IDC_EDIT3, m_pSet->m_3);
	DDX_Text(pDX, IDC_EDIT4, m_pSet->m_4);
}

BOOL Cexp38View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO:  在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CRecordView::PreCreateWindow(cs);
}

void Cexp38View::OnInitialUpdate()
{
	m_pSet = &GetDocument()->m_exp38Set;
	CRecordView::OnInitialUpdate();

}


// Cexp38View 诊断

#ifdef _DEBUG
void Cexp38View::AssertValid() const
{
	CRecordView::AssertValid();
}

void Cexp38View::Dump(CDumpContext& dc) const
{
	CRecordView::Dump(dc);
}

Cexp38Doc* Cexp38View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(Cexp38Doc)));
	return (Cexp38Doc*)m_pDocument;
}
#endif //_DEBUG


// Cexp38View 数据库支持
CRecordset* Cexp38View::OnGetRecordset()
{
	return m_pSet;
}



// Cexp38View 消息处理程序


void Cexp38View::OnEnChangeEdit2()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CRecordView::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码
}
