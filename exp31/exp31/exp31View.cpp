
// exp31View.cpp : Cexp31View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "exp31.h"
#endif

#include "exp31Doc.h"
#include "exp31View.h"
#include "MyDialog.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// Cexp31View

IMPLEMENT_DYNCREATE(Cexp31View, CView)

BEGIN_MESSAGE_MAP(Cexp31View, CView)
	ON_COMMAND(ID_SHOW, &Cexp31View::OnShow)
END_MESSAGE_MAP()

// Cexp31View 构造/析构

Cexp31View::Cexp31View()
{
	// TODO:  在此处添加构造代码

}

Cexp31View::~Cexp31View()
{
}

BOOL Cexp31View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO:  在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// Cexp31View 绘制

void Cexp31View::OnDraw(CDC* /*pDC*/)
{
	Cexp31Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO:  在此处为本机数据添加绘制代码
}


// Cexp31View 诊断

#ifdef _DEBUG
void Cexp31View::AssertValid() const
{
	CView::AssertValid();
}

void Cexp31View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

Cexp31Doc* Cexp31View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(Cexp31Doc)));
	return (Cexp31Doc*)m_pDocument;
}
#endif //_DEBUG


// Cexp31View 消息处理程序


void Cexp31View::OnShow()
{
	MyDialog dlg;
	dlg.DoModal();
	// TODO:  在此添加命令处理程序代码
}
