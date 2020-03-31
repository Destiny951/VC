
// exp5View.cpp : Cexp5View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "exp5.h"
#endif

#include "exp5Doc.h"
#include "exp5View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// Cexp5View

IMPLEMENT_DYNCREATE(Cexp5View, CView)

BEGIN_MESSAGE_MAP(Cexp5View, CView)
END_MESSAGE_MAP()

// Cexp5View 构造/析构

Cexp5View::Cexp5View()
{
	// TODO:  在此处添加构造代码

}

Cexp5View::~Cexp5View()
{
}

BOOL Cexp5View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO:  在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// Cexp5View 绘制

void Cexp5View::OnDraw(CDC* pDC)
{
	Cexp5Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	CString s;
	int A = 10;
	s.Format(_T("我是xxx,%d"),A);
	pDC->TextOutW(200, 300, s);
	// TODO:  在此处为本机数据添加绘制代码
}


// Cexp5View 诊断

#ifdef _DEBUG
void Cexp5View::AssertValid() const
{
	CView::AssertValid();
}

void Cexp5View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

Cexp5Doc* Cexp5View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(Cexp5Doc)));
	return (Cexp5Doc*)m_pDocument;
}
#endif //_DEBUG


// Cexp5View 消息处理程序
