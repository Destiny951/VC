
// exp37View.cpp : Cexp37View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "exp37.h"
#endif

#include "exp37Doc.h"
#include "exp37View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// Cexp37View

IMPLEMENT_DYNCREATE(Cexp37View, CView)

BEGIN_MESSAGE_MAP(Cexp37View, CView)
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
	ON_WM_MOUSEMOVE()
END_MESSAGE_MAP()

// Cexp37View 构造/析构

Cexp37View::Cexp37View()
{
	// TODO:  在此处添加构造代码
	start.x = 0;
	start.y = 0;
}

Cexp37View::~Cexp37View()
{
}

BOOL Cexp37View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO:  在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// Cexp37View 绘制

void Cexp37View::OnDraw(CDC* pDC)
{
	Cexp37Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	for (int i = 0; i < pDoc->ce.GetSize(); i++)
	{
		pDC->Ellipse(pDoc->ce[i]);
	}
	// TODO:  在此处为本机数据添加绘制代码
}


// Cexp37View 诊断

#ifdef _DEBUG
void Cexp37View::AssertValid() const
{
	CView::AssertValid();
}

void Cexp37View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

Cexp37Doc* Cexp37View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(Cexp37Doc)));
	return (Cexp37Doc*)m_pDocument;
}
#endif //_DEBUG


// Cexp37View 消息处理程序


void Cexp37View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO:  在此添加消息处理程序代码和/或调用默认值
	Cexp37Doc* pDoc = GetDocument();
	log++;
	sel = 1;
	start = point;
	pDoc->ce[log].left = start.x;
	pDoc->ce[log].top = start.y;
	CView::OnLButtonDown(nFlags, point);
}


void Cexp37View::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO:  在此添加消息处理程序代码和/或调用默认值
	sel = 0;
	CView::OnLButtonUp(nFlags, point);
}


void Cexp37View::OnMouseMove(UINT nFlags, CPoint point)
{
	Cexp37Doc* pDoc = GetDocument();
	// TODO:  在此添加消息处理程序代码和/或调用默认值
	if (sel == 1)
	{
		pDoc->ce[log].right = point.x;
		pDoc->ce[log].bottom = point.y;
		Invalidate();
	}
	CView::OnMouseMove(nFlags, point);
}