
// exp14View.cpp : Cexp14View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "exp14.h"
#endif

#include "exp14Doc.h"
#include "exp14View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// Cexp14View

IMPLEMENT_DYNCREATE(Cexp14View, CView)

BEGIN_MESSAGE_MAP(Cexp14View, CView)
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
	ON_WM_MOUSEMOVE()
END_MESSAGE_MAP()

// Cexp14View 构造/析构

Cexp14View::Cexp14View()
{
	// TODO:  在此处添加构造代码
	sum = 0;
	totalpixel = 0;
	avepixel = 0;
	down = 0;
}

Cexp14View::~Cexp14View()
{
}

BOOL Cexp14View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO:  在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// Cexp14View 绘制

void Cexp14View::OnDraw(CDC* pDC)
{
	Cexp14Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	CString s;
	s.Format(_T("MouseMove事件发生了%d次，横向移动了%d像素发生一次"), sum,avepixel);
	pDC->TextOutW(200, 300, s);
	sum = 0;
	// TODO:  在此处为本机数据添加绘制代码
}


// Cexp14View 诊断

#ifdef _DEBUG
void Cexp14View::AssertValid() const
{
	CView::AssertValid();
}

void Cexp14View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

Cexp14Doc* Cexp14View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(Cexp14Doc)));
	return (Cexp14Doc*)m_pDocument;
}
#endif //_DEBUG


// Cexp14View 消息处理程序


void Cexp14View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO:  在此添加消息处理程序代码和/或调用默认值
	down = 1;
	totalpixel = point.x;
	CView::OnLButtonDown(nFlags, point);
}


void Cexp14View::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO:  在此添加消息处理程序代码和/或调用默认值

	down = 0;
	if (totalpixel > point.x)
	{
		totalpixel = totalpixel - point.x;
	}
	else
	{
		totalpixel = point.x - totalpixel;
	}
	avepixel = totalpixel / sum;
	Invalidate();
	CView::OnLButtonUp(nFlags, point);
}


void Cexp14View::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO:  在此添加消息处理程序代码和/或调用默认值
	if (down == 1)
	{
		sum++;
	}
	CView::OnMouseMove(nFlags, point);
}
