
// exp28View.cpp : Cexp28View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "exp28.h"
#endif

#include "exp28Doc.h"
#include "exp28View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// Cexp28View

IMPLEMENT_DYNCREATE(Cexp28View, CView)

BEGIN_MESSAGE_MAP(Cexp28View, CView)
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
	ON_WM_MOUSEMOVE()
END_MESSAGE_MAP()

// Cexp28View 构造/析构

Cexp28View::Cexp28View()
{
	// TODO:  在此处添加构造代码
	select = 0;
	ce.left = 300;
	ce.bottom = 400;
	ce.right = 500;
	ce.top = 300;
	start.x = 0;
	start.y = 0;
}

Cexp28View::~Cexp28View()
{
}

BOOL Cexp28View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO:  在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// Cexp28View 绘制

void Cexp28View::OnDraw(CDC* pDC)
{
	Cexp28Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	
	pDC->Rectangle(ce);
	// TODO:  在此处为本机数据添加绘制代码
}


// Cexp28View 诊断

#ifdef _DEBUG
void Cexp28View::AssertValid() const
{
	CView::AssertValid();
}

void Cexp28View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

Cexp28Doc* Cexp28View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(Cexp28Doc)));
	return (Cexp28Doc*)m_pDocument;
}
#endif //_DEBUG


// Cexp28View 消息处理程序


void Cexp28View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO:  在此添加消息处理程序代码和/或调用默认值
	if (point.x > ce.left&&point.x<ce.right&&point.y>ce.top&&point.y < ce.bottom)
	{
		select = 1;
		start = point;
	}
	CView::OnLButtonDown(nFlags, point);
}


void Cexp28View::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO:  在此添加消息处理程序代码和/或调用默认值
	select = 0;
	CView::OnLButtonUp(nFlags, point);
}


void Cexp28View::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO:  在此添加消息处理程序代码和/或调用默认值
	if (select == 1)
	{
		ce.left += point.x - start.x;
		ce.right += point.x - start.x;
		ce.bottom += point.y - start.y;
		ce.top += point.y - start.y;
		start = point;
	}
	Invalidate();
	CView::OnMouseMove(nFlags, point);
}
