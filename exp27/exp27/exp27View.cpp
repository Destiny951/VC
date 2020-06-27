
// exp27View.cpp : Cexp27View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "exp27.h"
#endif

#include "exp27Doc.h"
#include "exp27View.h"
#include "MyDialog.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// Cexp27View

IMPLEMENT_DYNCREATE(Cexp27View, CView)

BEGIN_MESSAGE_MAP(Cexp27View, CView)
	ON_BN_CLICKED(IDC_BUTTON1, &Cexp27View::OnBnClickedButton1)
	ON_COMMAND(ID_EDIT, &Cexp27View::OnEdit)
END_MESSAGE_MAP()

// Cexp27View 构造/析构

Cexp27View::Cexp27View()
{
	// TODO:  在此处添加构造代码

}

Cexp27View::~Cexp27View()
{
}

BOOL Cexp27View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO:  在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// Cexp27View 绘制

void Cexp27View::OnDraw(CDC* /*pDC*/)
{
	Cexp27Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO:  在此处为本机数据添加绘制代码
}


// Cexp27View 诊断

#ifdef _DEBUG
void Cexp27View::AssertValid() const
{
	CView::AssertValid();
}

void Cexp27View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

Cexp27Doc* Cexp27View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(Cexp27Doc)));
	return (Cexp27Doc*)m_pDocument;
}
#endif //_DEBUG


// Cexp27View 消息处理程序


void Cexp27View::OnBnClickedButton1()
{

	// TODO:  在此添加控件通知处理程序代码
}


void Cexp27View::OnEdit()
{
	MyDialog dlg;
	int t = dlg.DoModal();
	// TODO:  在此添加命令处理程序代码
}
