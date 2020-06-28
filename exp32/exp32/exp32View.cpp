
// exp32View.cpp : Cexp32View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "exp32.h"
#endif

#include "exp32Doc.h"
#include "exp32View.h"
#include "MyDialog.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// Cexp32View

IMPLEMENT_DYNCREATE(Cexp32View, CView)

BEGIN_MESSAGE_MAP(Cexp32View, CView)
	ON_WM_LBUTTONDBLCLK()
	ON_COMMAND(ID_SHOW, &Cexp32View::OnShow)
END_MESSAGE_MAP()

// Cexp32View 构造/析构

Cexp32View::Cexp32View()
{
	// TODO:  在此处添加构造代码
	filename = _T("");
}

Cexp32View::~Cexp32View()
{
}

BOOL Cexp32View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO:  在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// Cexp32View 绘制

void Cexp32View::OnDraw(CDC* /*pDC*/)
{
	Cexp32Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO:  在此处为本机数据添加绘制代码
}


// Cexp32View 诊断

#ifdef _DEBUG
void Cexp32View::AssertValid() const
{
	CView::AssertValid();
}

void Cexp32View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

Cexp32Doc* Cexp32View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(Cexp32Doc)));
	return (Cexp32Doc*)m_pDocument;
}
#endif //_DEBUG


// Cexp32View 消息处理程序


void Cexp32View::OnLButtonDblClk(UINT nFlags, CPoint point)
{
	// TODO:  在此添加消息处理程序代码和/或调用默认值
	CFileDialog cfd(true);
	int r = cfd.DoModal();
	if (r == IDOK)
	{
		 filename =  cfd.GetPathName();
		GetDC()->TextOutW(200, 300, filename);
	}
	CView::OnLButtonDblClk(nFlags, point);
}


void Cexp32View::OnShow()
{
	MyDialog dlg;
	dlg.s1 = filename;
	dlg.DoModal();
	// TODO:  在此添加命令处理程序代码
}
