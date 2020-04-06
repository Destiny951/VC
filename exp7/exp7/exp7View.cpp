
// exp7View.cpp : Cexp7View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "exp7.h"
#endif

#include "exp7Doc.h"
#include "exp7View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// Cexp7View

IMPLEMENT_DYNCREATE(Cexp7View, CView)

BEGIN_MESSAGE_MAP(Cexp7View, CView)
	ON_WM_LBUTTONDOWN()
	ON_WM_RBUTTONDOWN()
END_MESSAGE_MAP()

// Cexp7View 构造/析构

Cexp7View::Cexp7View()
{
	// TODO:  在此处添加构造代码
	ans = 0;
}

Cexp7View::~Cexp7View()
{
}

BOOL Cexp7View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO:  在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// Cexp7View 绘制

void Cexp7View::OnDraw(CDC* pDC)
{
	Cexp7Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	CString s;
	s.Format(_T("count的次数%d"), pDoc->count);
	if (ans == 1)
	{
		pDC->TextOutW(200, 300, s);
	}
	// TODO:  在此处为本机数据添加绘制代码
}


// Cexp7View 诊断

#ifdef _DEBUG
void Cexp7View::AssertValid() const
{
	CView::AssertValid();
}

void Cexp7View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

Cexp7Doc* Cexp7View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(Cexp7Doc)));
	return (Cexp7Doc*)m_pDocument;
}
#endif //_DEBUG


// Cexp7View 消息处理程序


void Cexp7View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO:  在此添加消息处理程序代码和/或调用默认值
	Cexp7Doc* pDoc = GetDocument();
	pDoc->count++;
	CView::OnLButtonDown(nFlags, point);
}


void Cexp7View::OnRButtonDown(UINT nFlags, CPoint point)
{
	// TODO:  在此添加消息处理程序代码和/或调用默认值
	ans = 1;
	Invalidate();
	CView::OnRButtonDown(nFlags, point);
}
