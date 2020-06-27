
// exp26View.cpp : Cexp26View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "exp26.h"
#endif

#include "exp26Doc.h"
#include "exp26View.h"
#include "MyDialog.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// Cexp26View

IMPLEMENT_DYNCREATE(Cexp26View, CView)

BEGIN_MESSAGE_MAP(Cexp26View, CView)
	ON_BN_CLICKED(IDOK, &Cexp26View::OnBnClickedOk)
	ON_COMMAND(SHOW, &Cexp26View::OnShow)
END_MESSAGE_MAP()

// Cexp26View 构造/析构

Cexp26View::Cexp26View()
{
	// TODO:  在此处添加构造代码

}

Cexp26View::~Cexp26View()
{
}

BOOL Cexp26View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO:  在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// Cexp26View 绘制

void Cexp26View::OnDraw(CDC* /*pDC*/)
{
	Cexp26Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO:  在此处为本机数据添加绘制代码
}


// Cexp26View 诊断

#ifdef _DEBUG
void Cexp26View::AssertValid() const
{
	CView::AssertValid();
}

void Cexp26View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

Cexp26Doc* Cexp26View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(Cexp26Doc)));
	return (Cexp26Doc*)m_pDocument;
}
#endif //_DEBUG


// Cexp26View 消息处理程序


void Cexp26View::OnBnClickedOk()
{
	// TODO:  在此添加控件通知处理程序代码
}


void Cexp26View::OnShow()
{
	MyDialog dlg;
	int t = dlg.DoModal();
	CString s;
	s.Format(_T("你已退出对话框"));
	if (t == IDOK)
	{
		GetDC()->TextOutW(300, 300, s);
	}
	// TODO:  在此添加命令处理程序代码
}
