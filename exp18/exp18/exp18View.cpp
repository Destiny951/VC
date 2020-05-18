
// exp18View.cpp : Cexp18View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "exp18.h"
#endif

#include "exp18Doc.h"
#include "exp18View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// Cexp18View

IMPLEMENT_DYNCREATE(Cexp18View, CView)

BEGIN_MESSAGE_MAP(Cexp18View, CView)
	ON_COMMAND(NAME, &Cexp18View::OnName)
END_MESSAGE_MAP()

// Cexp18View 构造/析构

Cexp18View::Cexp18View()
{
	// TODO:  在此处添加构造代码

}

Cexp18View::~Cexp18View()
{
}

BOOL Cexp18View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO:  在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// Cexp18View 绘制

void Cexp18View::OnDraw(CDC* /*pDC*/)
{
	Cexp18Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO:  在此处为本机数据添加绘制代码
}


// Cexp18View 诊断

#ifdef _DEBUG
void Cexp18View::AssertValid() const
{
	CView::AssertValid();
}

void Cexp18View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

Cexp18Doc* Cexp18View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(Cexp18Doc)));
	return (Cexp18Doc*)m_pDocument;
}
#endif //_DEBUG


// Cexp18View 消息处理程序


void Cexp18View::OnName()
{
	CClientDC dc(this);
	CString s ;
	s.Format(_T("名字是邱志良"));
	dc.TextOutW(30, 50, s);
	// TODO:  在此添加命令处理程序代码
}
