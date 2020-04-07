
// exp13View.cpp : Cexp13View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "exp13.h"
#endif

#include "exp13Doc.h"
#include "exp13View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// Cexp13View

IMPLEMENT_DYNCREATE(Cexp13View, CView)

BEGIN_MESSAGE_MAP(Cexp13View, CView)
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
	ON_WM_MOUSEMOVE()
END_MESSAGE_MAP()

// Cexp13View 构造/析构

Cexp13View::Cexp13View()
{
	// TODO:  在此处添加构造代码

}

Cexp13View::~Cexp13View()
{
}

BOOL Cexp13View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO:  在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// Cexp13View 绘制

void Cexp13View::OnDraw(CDC* pDC)
{
	Cexp13Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	CRect cr(x1, y1, x2, y2);
	pDC->Rectangle(cr);
	// TODO:  在此处为本机数据添加绘制代码
}


// Cexp13View 诊断

#ifdef _DEBUG
void Cexp13View::AssertValid() const
{
	CView::AssertValid();
}

void Cexp13View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

Cexp13Doc* Cexp13View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(Cexp13Doc)));
	return (Cexp13Doc*)m_pDocument;
}
#endif //_DEBUG


// Cexp13View 消息处理程序


void Cexp13View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO:  在此添加消息处理程序代码和/或调用默认值
	x1 = point.x;
	y1 = point.y;
	CView::OnLButtonDown(nFlags, point);
}


void Cexp13View::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO:  在此添加消息处理程序代码和/或调用默认值
	x2 = point.x;
	y2 = point.y;
	Invalidate();
	CView::OnLButtonUp(nFlags, point);
}


void Cexp13View::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO:  在此添加消息处理程序代码和/或调用默认值
	CClientDC dc(this);
	CString s;
	s.Format(_T("x=%d,y=%d"), point.x, point.y);
	dc.TextOutW(200, 600, s);
	CView::OnMouseMove(nFlags, point);
}
