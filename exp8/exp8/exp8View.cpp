
// exp8View.cpp : Cexp8View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "exp8.h"
#endif

#include "exp8Doc.h"
#include "exp8View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// Cexp8View

IMPLEMENT_DYNCREATE(Cexp8View, CView)

BEGIN_MESSAGE_MAP(Cexp8View, CView)
	ON_WM_LBUTTONDOWN()
END_MESSAGE_MAP()

// Cexp8View 构造/析构

Cexp8View::Cexp8View()
{
	// TODO:  在此处添加构造代码
	ans = 0;
}

Cexp8View::~Cexp8View()
{
}

BOOL Cexp8View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO:  在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// Cexp8View 绘制

void Cexp8View::OnDraw(CDC* pDC)
{
	Cexp8Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	if (ans == 1)
	{
		GetClientRect(&circle);
		pDC->Ellipse(circle);
	}

	// TODO:  在此处为本机数据添加绘制代码
}


// Cexp8View 诊断

#ifdef _DEBUG
void Cexp8View::AssertValid() const
{
	CView::AssertValid();
}

void Cexp8View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

Cexp8Doc* Cexp8View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(Cexp8Doc)));
	return (Cexp8Doc*)m_pDocument;
}
#endif //_DEBUG


// Cexp8View 消息处理程序


void Cexp8View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO:  在此添加消息处理程序代码和/或调用默认值
	ans = 1;
	Invalidate();
	CView::OnLButtonDown(nFlags, point);
}
