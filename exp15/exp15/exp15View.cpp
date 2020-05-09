
// exp15View.cpp : Cexp15View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "exp15.h"
#endif

#include "exp15Doc.h"
#include "exp15View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// Cexp15View

IMPLEMENT_DYNCREATE(Cexp15View, CView)

BEGIN_MESSAGE_MAP(Cexp15View, CView)
	ON_WM_KEYDOWN()
	ON_WM_LBUTTONDOWN()
END_MESSAGE_MAP()

// Cexp15View 构造/析构

Cexp15View::Cexp15View()
{
	// TODO:  在此处添加构造代码
	m.left = 300;
	m.top = 300;
	m.bottom = 330;
	m.right =  330;
}

Cexp15View::~Cexp15View()
{
}

BOOL Cexp15View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO:  在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// Cexp15View 绘制

void Cexp15View::OnDraw(CDC* pDC)
{
	Cexp15Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	pDC->Rectangle(m);
	// TODO:  在此处为本机数据添加绘制代码
}


// Cexp15View 诊断

#ifdef _DEBUG
void Cexp15View::AssertValid() const
{
	CView::AssertValid();
}

void Cexp15View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

Cexp15Doc* Cexp15View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(Cexp15Doc)));
	return (Cexp15Doc*)m_pDocument;
}
#endif //_DEBUG


// Cexp15View 消息处理程序


void Cexp15View::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	// TODO:  在此添加消息处理程序代码和/或调用默认值
	GetClientRect(&model);
	switch (nChar)
	{
	case VK_UP:
		if (m.top > 0)
		{
			m.top -= 5;
			m.bottom -= 5;

		}
		break;
	case VK_DOWN:
		if (m.bottom <= (model.bottom - model.top))
		{
			m.top += 5;
			m.bottom += 5;
		}
		break;
	case VK_LEFT:
		if (m.left > 0)
		{
			m.left -= 5;
			m.right -= 5;
		}
		break;
	case VK_RIGHT:
		if (m.right <= (model.right - model.left))
		{
			m.right += 5;
			m.left += 5;
		}
		break;
	case VK_HOME:
		if (m.left > 0 && m.top > 0)
		{
			m.left -= 5;
			m.top -= 5;
		}
		break;
	case VK_END:
		if (m.left < m.right && m.top < m.bottom)
		{
			m.left += 5;
			m.top += 5;
		}
		break;
	}
	InvalidateRect(NULL,TRUE);
	CView::OnKeyDown(nChar, nRepCnt, nFlags);
}


void Cexp15View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO:  在此添加消息处理程序代码和/或调用默认值
	m.left = 300;
	m.top = 300;
	m.bottom = 330;
	m.right = 330;
	InvalidateRect(NULL, TRUE);
	CView::OnLButtonDown(nFlags, point);
}
