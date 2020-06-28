
// exp30View.cpp : Cexp30View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "exp30.h"
#endif

#include "exp30Doc.h"
#include "exp30View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// Cexp30View

IMPLEMENT_DYNCREATE(Cexp30View, CView)

BEGIN_MESSAGE_MAP(Cexp30View, CView)
	ON_WM_LBUTTONDOWN()
//	ON_WM_MBUTTONDBLCLK()
	ON_WM_TIMER()
	ON_WM_LBUTTONDBLCLK()
END_MESSAGE_MAP()

// Cexp30View 构造/析构

Cexp30View::Cexp30View()
{
	// TODO:  在此处添加构造代码
	start = 0;
	exp = 1;
}

Cexp30View::~Cexp30View()
{
}

BOOL Cexp30View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO:  在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// Cexp30View 绘制

void Cexp30View::OnDraw(CDC* pDC)
{
	Cexp30Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	if (start == 0)
	{
		GetClientRect(ce);
		circle.left = 0;
		circle.right = 200;
		circle.top = (ce.bottom - ce.top) / 2 - 100;
		circle.bottom = (ce.bottom - ce.top) / 2 + 100;
		start = 1;
	}
	pDC->Ellipse(circle);
	// TODO:  在此处为本机数据添加绘制代码
}


// Cexp30View 诊断

#ifdef _DEBUG
void Cexp30View::AssertValid() const
{
	CView::AssertValid();
}

void Cexp30View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

Cexp30Doc* Cexp30View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(Cexp30Doc)));
	return (Cexp30Doc*)m_pDocument;
}
#endif //_DEBUG


// Cexp30View 消息处理程序


void Cexp30View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO:  在此添加消息处理程序代码和/或调用默认值
	SetTimer(0,500,NULL);
	CView::OnLButtonDown(nFlags, point);
}


//void Cexp30View::OnMButtonDblClk(UINT nFlags, CPoint point)
//{
//	// TODO:  在此添加消息处理程序代码和/或调用默认值
//
//	CView::OnMButtonDblClk(nFlags, point);
//}


void Cexp30View::OnTimer(UINT_PTR nIDEvent)
{
	// TODO:  在此添加消息处理程序代码和/或调用默认值
	if (exp == 1)
	{
		if (circle.right <= ce.right)
		{
			circle.left += 30;
			circle.right += 30;
		}
		else exp = 0;
	}
	else
	{
		if (circle.left >= ce.left)
		{
			circle.left -= 30;
			circle.right -= 30;
		}
		else exp = 1;
	}
	Invalidate();
	CView::OnTimer(nIDEvent);
}


void Cexp30View::OnLButtonDblClk(UINT nFlags, CPoint point)
{
	// TODO:  在此添加消息处理程序代码和/或调用默认值
	KillTimer(0);
	CClientDC dc(this);
	CString s = _T("stop");
	dc.TextOutW(0, 0, s);
	CView::OnLButtonDblClk(nFlags, point);
}
