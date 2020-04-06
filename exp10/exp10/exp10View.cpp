
// exp10View.cpp : Cexp10View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "exp10.h"
#endif

#include "exp10Doc.h"
#include "exp10View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// Cexp10View

IMPLEMENT_DYNCREATE(Cexp10View, CView)

BEGIN_MESSAGE_MAP(Cexp10View, CView)
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
END_MESSAGE_MAP()

// Cexp10View 构造/析构

Cexp10View::Cexp10View()
{
	// TODO:  在此处添加构造代码

}

Cexp10View::~Cexp10View()
{
}

BOOL Cexp10View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO:  在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// Cexp10View 绘制

void Cexp10View::OnDraw(CDC* pDC)
{
	Cexp10Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	pDC->TextOutW(200, 300, s);
	// TODO:  在此处为本机数据添加绘制代码
}


// Cexp10View 诊断

#ifdef _DEBUG
void Cexp10View::AssertValid() const
{
	CView::AssertValid();
}

void Cexp10View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

Cexp10Doc* Cexp10View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(Cexp10Doc)));
	return (Cexp10Doc*)m_pDocument;
}
#endif //_DEBUG


// Cexp10View 消息处理程序


void Cexp10View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO:  在此添加消息处理程序代码和/或调用默认值
	s.Format(_T("左键正被按下"));
	Invalidate();
	CView::OnLButtonDown(nFlags, point);
}


void Cexp10View::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO:  在此添加消息处理程序代码和/或调用默认值
	s.Format(_T("左键正在抬起"));
	Invalidate();
	CView::OnLButtonUp(nFlags, point);
}
