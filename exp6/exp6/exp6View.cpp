
// exp6View.cpp : Cexp6View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "exp6.h"
#endif

#include "exp6Doc.h"
#include "exp6View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// Cexp6View

IMPLEMENT_DYNCREATE(Cexp6View, CView)

BEGIN_MESSAGE_MAP(Cexp6View, CView)
END_MESSAGE_MAP()

// Cexp6View 构造/析构

Cexp6View::Cexp6View()
{
	// TODO:  在此处添加构造代码

}

Cexp6View::~Cexp6View()
{
}

BOOL Cexp6View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO:  在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// Cexp6View 绘制

void Cexp6View::OnDraw(CDC* pDC)
{
	Cexp6Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	CString x = pDoc->s;
	pDC->TextOutW(200, 300, x);
	// TODO:  在此处为本机数据添加绘制代码
}


// Cexp6View 诊断

#ifdef _DEBUG
void Cexp6View::AssertValid() const
{
	CView::AssertValid();
}

void Cexp6View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

Cexp6Doc* Cexp6View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(Cexp6Doc)));
	return (Cexp6Doc*)m_pDocument;
}
#endif //_DEBUG


// Cexp6View 消息处理程序
