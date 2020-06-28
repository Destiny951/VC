
// exp34View.cpp : Cexp34View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "exp34.h"
#endif

#include "exp34Doc.h"
#include "exp34View.h"
#include "MyDialog1.h"
#include "MyDialog2.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// Cexp34View

IMPLEMENT_DYNCREATE(Cexp34View, CView)

BEGIN_MESSAGE_MAP(Cexp34View, CView)
	ON_COMMAND(ID_DrawCircle, &Cexp34View::OnDrawcircle)
	ON_COMMAND(ID_DrawColor, &Cexp34View::OnDrawcolor)
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
	ON_WM_MOUSEMOVE()
END_MESSAGE_MAP()

// Cexp34View 构造/析构

Cexp34View::Cexp34View()
{
	// TODO:  在此处添加构造代码
	start.x = 0;
	start.y = 0;
}

Cexp34View::~Cexp34View()
{
}

BOOL Cexp34View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO:  在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// Cexp34View 绘制

void Cexp34View::OnDraw(CDC* pDC)
{
	Cexp34Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	pDC->Ellipse(yuan);

	oldbrush = pDC->SelectObject(&brush);//选新的画刷
	pDC->Ellipse(circle);
	pDC->SelectObject(oldbrush);//将原来的画刷选回去

	CPen* oldPen = pDC->SelectObject(newPen);
	pDC->SelectStockObject(NULL_BRUSH);
	pDC->Rectangle(ce);
	pDC->SelectObject(oldbrush);
	// TODO:  在此处为本机数据添加绘制代码
}


// Cexp34View 诊断

#ifdef _DEBUG
void Cexp34View::AssertValid() const
{
	CView::AssertValid();
}

void Cexp34View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

Cexp34Doc* Cexp34View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(Cexp34Doc)));
	return (Cexp34Doc*)m_pDocument;
}
#endif //_DEBUG


// Cexp34View 消息处理程序


void Cexp34View::OnDrawcircle()
{
	MyDialog1 dlg1;
	int r = dlg1.DoModal();
	if (r == IDOK)
	{
		circle.left = dlg1.x - dlg1.r;
		circle.right = dlg1.x + dlg1.r;
		circle.top = dlg1.y - dlg1.r;
		circle.bottom = dlg1.y + dlg1.r;
	}
	Invalidate();
	// TODO:  在此添加命令处理程序代码
}


void Cexp34View::OnDrawcolor()
{
	MyDialog2 dlg2;
	int r = dlg2.DoModal();
	if (r == IDOK)
	{

	    brush.CreateSolidBrush(RGB(dlg2.red, dlg2.green, dlg2.blue));//根据自己需要填充颜色
	}
	Invalidate();
	// TODO:  在此添加命令处理程序代码
}


void Cexp34View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO:  在此添加消息处理程序代码和/或调用默认值
	start = point;

		

	if (point.x >= circle.left&&point.x <= circle.right)
	{
		if (point.y >= circle.top&&point.y <= circle.bottom)
		{
			log = 1;
			ce = circle;
			Invalidate();
		}
	}
	else
	{
		t = 1;
		yuan.left = point.x;
		yuan.top = point.y;
	}
	CView::OnLButtonDown(nFlags, point);
}


void Cexp34View::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO:  在此添加消息处理程序代码和/或调用默认值
	log = 0;
	t = 0;

	ce.top = 0;
	ce.bottom = 0;
	ce.left = 0;
	ce.right = 0;
	Invalidate();
	CView::OnLButtonUp(nFlags, point);
}


void Cexp34View::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO:  在此添加消息处理程序代码和/或调用默认值
	if (log == 1)
	{
		ce.left += point.x - start.x;
		ce.right += point.x - start.x;
		ce.bottom += point.y - start.y;
		ce.top += point.y - start.y;

		circle.left += point.x - start.x;
		circle.right += point.x - start.x;
		circle.bottom += point.y - start.y;
		circle.top += point.y - start.y;

		start = point;

		Invalidate();
	}
	if (log == 0 && t == 1)
	{
		yuan.right = point.x;
		yuan.bottom = point.y;
		Invalidate();
	}
	CView::OnMouseMove(nFlags, point);
}
