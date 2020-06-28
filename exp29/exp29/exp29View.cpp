
// exp29View.cpp : Cexp29View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "exp29.h"
#endif

#include "exp29Doc.h"
#include "exp29View.h"
#include "MyDialog.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// Cexp29View

IMPLEMENT_DYNCREATE(Cexp29View, CView)

BEGIN_MESSAGE_MAP(Cexp29View, CView)
	ON_COMMAND(ID_Show, &Cexp29View::OnShow)
END_MESSAGE_MAP()

// Cexp29View 构造/析构

Cexp29View::Cexp29View()
{
	// TODO:  在此处添加构造代码

}

Cexp29View::~Cexp29View()
{
}

BOOL Cexp29View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO:  在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// Cexp29View 绘制

void Cexp29View::OnDraw(CDC* /*pDC*/)
{
	Cexp29Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO:  在此处为本机数据添加绘制代码
}


// Cexp29View 诊断

#ifdef _DEBUG
void Cexp29View::AssertValid() const
{
	CView::AssertValid();
}

void Cexp29View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

Cexp29Doc* Cexp29View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(Cexp29Doc)));
	return (Cexp29Doc*)m_pDocument;
}
#endif //_DEBUG


// Cexp29View 消息处理程序


void Cexp29View::OnShow()
{
	MyDialog dlg ;
	dlg.DoModal();
	// TODO:  在此添加命令处理程序代码
}
