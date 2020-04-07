
// exp12View.cpp : Cexp12View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "exp12.h"
#endif

#include "exp12Doc.h"
#include "exp12View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// Cexp12View

IMPLEMENT_DYNCREATE(Cexp12View, CView)

BEGIN_MESSAGE_MAP(Cexp12View, CView)
	ON_WM_LBUTTONDOWN()
//	ON_WM_LBUTTONUP()
//ON_WM_MBUTTONDOWN()
ON_WM_RBUTTONDOWN()
END_MESSAGE_MAP()

// Cexp12View 构造/析构

Cexp12View::Cexp12View()
{
	// TODO:  在此处添加构造代码
}

Cexp12View::~Cexp12View()
{
}

BOOL Cexp12View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO:  在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// Cexp12View 绘制

void Cexp12View::OnDraw(CDC* pDC)
{
	Cexp12Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	int x1 = 100;
	int x2 = 300;

	for (int i = 0; i < 4; i++,x1+=300,x2+=300)
	{
		CRect ca(x1, 100, x2, 300);
		pDoc->cr.Add(ca);
	}
	for (int i = 0; i < 4; i++)
	{
		pDC->Rectangle(pDoc->cr[i]);
	}
	// TODO:  在此处为本机数据添加绘制代码
}


// Cexp12View 诊断

#ifdef _DEBUG
void Cexp12View::AssertValid() const
{
	CView::AssertValid();
}

void Cexp12View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

Cexp12Doc* Cexp12View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(Cexp12Doc)));
	return (Cexp12Doc*)m_pDocument;
}
#endif //_DEBUG


// Cexp12View 消息处理程序


void Cexp12View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO:  在此添加消息处理程序代码和/或调用默认值
	Cexp12Doc* pDoc = GetDocument();
	CString s;
	CClientDC dc(this);
	int a = rand() % 500;
	int b = rand() % 500;
	if (point.x <= pDoc->cr[0].right&&point.x >= pDoc->cr[0].left&&point.y <= pDoc->cr[0].bottom&&point.y >= pDoc->cr[0].top)
	{
		pDoc->xa.Add(a);
		s.Format(_T("%d"),a);
		dc.TextOutW(point.x, point.y, s);
	}
	else if (point.x <= pDoc->cr[1].right&&point.x >= pDoc->cr[1].left&&point.y <= pDoc->cr[1].bottom&&point.y >= pDoc->cr[1].top)
	{
		pDoc->xb.Add(b);
		s.Format(_T("%d"), b);
		dc.TextOutW(point.x, point.y, s);
	}
	else if (point.x <= pDoc->cr[2].right&&point.x >= pDoc->cr[2].left&&point.y <= pDoc->cr[2].bottom&&point.y >= pDoc->cr[2].top)
	{
		sum++;
		if (sum % 4 == 1)
		{
			pDoc->command.Add('+');
			s.Format(_T("+"));
			dc.TextOutW(point.x, point.y, s);
		}
		else if (sum % 4 == 2)
		{
			pDoc->command.Add('-');
			s.Format(_T("-"));
			dc.TextOutW(point.x, point.y, s);
		}
		else if (sum % 4 == 3)
		{
			pDoc->command.Add('*');
			s.Format(_T("*"));
			dc.TextOutW(point.x, point.y, s);
		}
		else if (sum % 4 == 0)
		{
			pDoc->command.Add('/');
			s.Format(_T("/"));
			dc.TextOutW(point.x, point.y, s);
		}
	}
	else if (point.x <= pDoc->cr[3].right&&point.x >= pDoc->cr[3].left&&point.y <= pDoc->cr[3].bottom&&point.y >= pDoc->cr[3].top)
	{

	}
	else
	{
		s.Format(_T("无效"));
		dc.TextOutW(point.x, point.y, s);
	}
	CView::OnLButtonDown(nFlags, point);
}


//void Cexp12View::OnLButtonUp(UINT nFlags, CPoint point)
//{
//	// TODO:  在此添加消息处理程序代码和/或调用默认值
//
//	CView::OnLButtonUp(nFlags, point);
//}


//void Cexp12View::OnMButtonDown(UINT nFlags, CPoint point)
//{
//	// TODO:  在此添加消息处理程序代码和/或调用默认值
//	CView::OnMButtonDown(nFlags, point);
//}


void Cexp12View::OnRButtonDown(UINT nFlags, CPoint point)
{
	// TODO:  在此添加消息处理程序代码和/或调用默认值
	Cexp12Doc* pDoc = GetDocument();
	CString s;
	CClientDC dc(this);
	if (point.x <= pDoc->cr[3].right&&point.x >= pDoc->cr[3].left&&point.y <= pDoc->cr[3].bottom&&point.y >= pDoc->cr[3].top)
	{
			if (pDoc->command[log] == '+')
			{
				pDoc->xc.Add(pDoc->xa[log] + pDoc->xb[log]);
				s.Format(_T("%d"), pDoc->xa[log] + pDoc->xb[log]);
				dc.TextOutW(point.x, point.y, s);
			}
			if (pDoc->command[log] == '-')
			{
				pDoc->xc.Add(pDoc->xa[log] - pDoc->xb[log]);
				s.Format(_T("%d"), pDoc->xa[log] - pDoc->xb[log]);
				dc.TextOutW(point.x, point.y, s);
			}
			if (pDoc->command[log] == '*')
			{
				pDoc->xc.Add(pDoc->xa[log] * pDoc->xb[log]);
				s.Format(_T("%d"), pDoc->xa[log] * pDoc->xb[log]);
				dc.TextOutW(point.x, point.y, s);
			}
			if (pDoc->command[log] == '/')
			{
				pDoc->xc.Add(pDoc->xa[log] / pDoc->xb[log]);
				s.Format(_T("%d"), pDoc->xa[log] / pDoc->xb[log]);
				dc.TextOutW(point.x, point.y, s);
			}
			log++;
	}
	else
	{
		s.Format(_T("无效"));
		dc.TextOutW(point.x, point.y, s);
	}
	CView::OnRButtonDown(nFlags, point);
}
