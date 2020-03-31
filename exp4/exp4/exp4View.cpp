
// exp4View.cpp : Cexp4View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "exp4.h"
#endif

#include "exp4Doc.h"
#include "exp4View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// Cexp4View

IMPLEMENT_DYNCREATE(Cexp4View, CView)

BEGIN_MESSAGE_MAP(Cexp4View, CView)
END_MESSAGE_MAP()

// Cexp4View 构造/析构

Cexp4View::Cexp4View()
{
	// TODO:  在此处添加构造代码

}

Cexp4View::~Cexp4View()
{
}

BOOL Cexp4View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO:  在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// Cexp4View 绘制

void Cexp4View::OnDraw(CDC* pDC)
{
	Cexp4Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	GetClientRect(&circle);
	
	int red = 150;
	int green = 155;
	int blue = 155;

	CBrush brush(RGB(red, green, blue));//根据自己需要填充颜色
	CBrush *oldbrush;
	oldbrush = pDC->SelectObject(&brush);//选新的画刷
	pDC->Ellipse(circle);
	pDC->SelectObject(oldbrush);//将原来的画刷选回去
	// TODO:  在此处为本机数据添加绘制代码
}


// Cexp4View 诊断

#ifdef _DEBUG
void Cexp4View::AssertValid() const
{
	CView::AssertValid();
}

void Cexp4View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

Cexp4Doc* Cexp4View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(Cexp4Doc)));
	return (Cexp4Doc*)m_pDocument;
}
#endif //_DEBUG


// Cexp4View 消息处理程序
