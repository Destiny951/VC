
// exp9View.cpp : Cexp9View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "exp9.h"
#endif

#include "exp9Doc.h"
#include "exp9View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// Cexp9View

IMPLEMENT_DYNCREATE(Cexp9View, CView)

BEGIN_MESSAGE_MAP(Cexp9View, CView)
	ON_WM_LBUTTONDOWN()
END_MESSAGE_MAP()

// Cexp9View 构造/析构

Cexp9View::Cexp9View()
{
	// TODO:  在此处添加构造代码
	x = 0;
	y = 0;
}

Cexp9View::~Cexp9View()
{
}

BOOL Cexp9View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO:  在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// Cexp9View 绘制

void Cexp9View::OnDraw(CDC* pDC)
{
	Cexp9Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	for (int i = 0; i < pDoc->cr.GetSize(); i++)
	{
		pDC->Ellipse(pDoc->cr[i]);
	}
	// TODO:  在此处为本机数据添加绘制代码
}


// Cexp9View 诊断

#ifdef _DEBUG
void Cexp9View::AssertValid() const
{
	CView::AssertValid();
}

void Cexp9View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

Cexp9Doc* Cexp9View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(Cexp9Doc)));
	return (Cexp9Doc*)m_pDocument;
}
#endif //_DEBUG


// Cexp9View 消息处理程序


void Cexp9View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO:  在此添加消息处理程序代码和/或调用默认值
	Cexp9Doc* pDoc = GetDocument();
	int r1 = rand() % 100 + 5;
	int r2 = rand() % 100 + 5;
	x = point.x;
	y = point.y;
	CRect circle(x-r1,y-r2,x+r1,y+r2);
	pDoc->cr.Add(circle);
	Invalidate();
	CView::OnLButtonDown(nFlags, point);
}
