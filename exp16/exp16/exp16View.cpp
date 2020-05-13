
// exp16View.cpp : Cexp16View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "exp16.h"
#endif

#include "exp16Doc.h"
#include "exp16View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// Cexp16View

IMPLEMENT_DYNCREATE(Cexp16View, CView)

BEGIN_MESSAGE_MAP(Cexp16View, CView)
	ON_WM_TIMER()
END_MESSAGE_MAP()

// Cexp16View 构造/析构

Cexp16View::Cexp16View()
{
	// TODO:  在此处添加构造代码

}

Cexp16View::~Cexp16View()
{
}

BOOL Cexp16View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO:  在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// Cexp16View 绘制

void Cexp16View::OnDraw(CDC* pDC)
{
	Cexp16Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	SetTimer(0,200,NULL);
	pDC->Ellipse(&pDoc->circle);
	// TODO:  在此处为本机数据添加绘制代码
}


// Cexp16View 诊断

#ifdef _DEBUG
void Cexp16View::AssertValid() const
{
	CView::AssertValid();
}

void Cexp16View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

Cexp16Doc* Cexp16View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(Cexp16Doc)));
	return (Cexp16Doc*)m_pDocument;
}
#endif //_DEBUG


// Cexp16View 消息处理程序


void Cexp16View::OnTimer(UINT_PTR nIDEvent)
{
	// TODO:  在此添加消息处理程序代码和/或调用默认值
	Cexp16Doc* pDoc = GetDocument();
	CRect cr;
	GetClientRect(&cr);
	if (pDoc->set == true)
	{

		if (pDoc->circle.bottom<cr.bottom)
		{
			pDoc->circle.top += 30;
			pDoc->circle.bottom += 30;
		}
	}
	if (pDoc->circle.bottom >= cr.bottom)
	{
		pDoc->set = false;
	}
	if (pDoc->set == false)
	{
		if (pDoc->circle.top>cr.top)
		{
			pDoc->circle.top -= 30;
			pDoc->circle.bottom -= 30;
		}
	}
	Invalidate();
	CView::OnTimer(nIDEvent);
}
