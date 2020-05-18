
// exp20View.cpp : Cexp20View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "exp20.h"
#endif

#include "exp20Doc.h"
#include "exp20View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// Cexp20View

IMPLEMENT_DYNCREATE(Cexp20View, CView)

BEGIN_MESSAGE_MAP(Cexp20View, CView)
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
	ON_COMMAND(Line, &Cexp20View::OnLine)
	ON_COMMAND(Squire, &Cexp20View::OnSquire)
	ON_COMMAND(Circle, &Cexp20View::OnCircle)
END_MESSAGE_MAP()

// Cexp20View 构造/析构

Cexp20View::Cexp20View()
{
	// TODO:  在此处添加构造代码
	i = 0;
	x1 = 0;
	y1 = 0;
	x2 = 0;
	y2 = 0;
}

Cexp20View::~Cexp20View()
{
}

BOOL Cexp20View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO:  在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// Cexp20View 绘制

void Cexp20View::OnDraw(CDC* pDC)
{
	Cexp20Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	if (i == 1)
	{
		CPen newpen;
		newpen.CreatePen(PS_SOLID, 1, RGB(0, 0, 0));
		CPen *oldpen = pDC->SelectObject(&newpen);
		pDC->MoveTo(x1, y1);
		pDC->LineTo(x2, y2);
		pDC->SelectObject(oldpen);
	}
	else if (i == 2)
	{
		CRect x;
		x.left = x1;
		x.top = y1;
		x.bottom = y2;
		x.right = x2;
		pDC->Rectangle(x);
	}
	else if (i == 3)
	{
		CRect rect;
		rect.left = x1;
		rect.top = y1;
		rect.right = x2;
		rect.bottom = y2;
		pDC->Ellipse(rect);
	}

	// TODO:  在此处为本机数据添加绘制代码
}


// Cexp20View 诊断

#ifdef _DEBUG
void Cexp20View::AssertValid() const
{
	CView::AssertValid();
}

void Cexp20View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

Cexp20Doc* Cexp20View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(Cexp20Doc)));
	return (Cexp20Doc*)m_pDocument;
}
#endif //_DEBUG


// Cexp20View 消息处理程序


void Cexp20View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO:  在此添加消息处理程序代码和/或调用默认值

	x1 = point.x;
	y1 = point.y;
	CView::OnLButtonDown(nFlags, point);
}


void Cexp20View::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO:  在此添加消息处理程序代码和/或调用默认值
	x2 = point.x;
	y2 = point.y;
	Invalidate();
	CView::OnLButtonUp(nFlags, point);
}


void Cexp20View::OnLine()
{
	i = 1;
	// TODO:  在此添加命令处理程序代码
}


void Cexp20View::OnSquire()
{
	i = 2;
	// TODO:  在此添加命令处理程序代码
}


void Cexp20View::OnCircle()
{
	i = 3;
	// TODO:  在此添加命令处理程序代码
}
