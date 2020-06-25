
// exp23View.cpp : Cexp23View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "exp23.h"
#endif

#include "exp23Doc.h"
#include "exp23View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// Cexp23View

IMPLEMENT_DYNCREATE(Cexp23View, CView)

BEGIN_MESSAGE_MAP(Cexp23View, CView)
	ON_WM_CHAR()
END_MESSAGE_MAP()

// Cexp23View 构造/析构

Cexp23View::Cexp23View()
{
	// TODO:  在此处添加构造代码
	mes.left = 300;
	mes.bottom = 300;
	mes.right = 1000;
	mes.top = 250;
}

Cexp23View::~Cexp23View()
{
}

BOOL Cexp23View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO:  在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// Cexp23View 绘制

void Cexp23View::OnDraw(CDC* pDC)
{
	Cexp23Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	pDC->Rectangle(mes);
	// TODO:  在此处为本机数据添加绘制代码
}


// Cexp23View 诊断

#ifdef _DEBUG
void Cexp23View::AssertValid() const
{
	CView::AssertValid();
}

void Cexp23View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

Cexp23Doc* Cexp23View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(Cexp23Doc)));
	return (Cexp23Doc*)m_pDocument;
}
#endif //_DEBUG


// Cexp23View 消息处理程序


void Cexp23View::OnChar(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	// TODO:  在此添加消息处理程序代码和/或调用默认值
	TCHAR ch = nChar;
	CClientDC dc(this);
	str1.Format(TEXT("%c"),ch);
	str2 += str1;
	dc.TextOutW(mes.left+2, (mes.bottom - mes.top) / 2 + mes.top-5, str2);
	CView::OnChar(nChar, nRepCnt, nFlags);
}
