
// exp17View.cpp : Cexp17View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "exp17.h"
#endif

#include "exp17Doc.h"
#include "exp17View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// Cexp17View

IMPLEMENT_DYNCREATE(Cexp17View, CView)

BEGIN_MESSAGE_MAP(Cexp17View, CView)
	ON_COMMAND(Circle, &Cexp17View::OnCircle)
	ON_WM_TIMER()
END_MESSAGE_MAP()

// Cexp17View 构造/析构

Cexp17View::Cexp17View()
{
	// TODO:  在此处添加构造代码

}

Cexp17View::~Cexp17View()
{
}

BOOL Cexp17View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO:  在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// Cexp17View 绘制

void Cexp17View::OnDraw(CDC* pDC)
{
	Cexp17Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO:  在此处为本机数据添加绘制代码
}


// Cexp17View 诊断

#ifdef _DEBUG
void Cexp17View::AssertValid() const
{
	CView::AssertValid();
}

void Cexp17View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

Cexp17Doc* Cexp17View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(Cexp17Doc)));
	return (Cexp17Doc*)m_pDocument;
}
#endif //_DEBUG


// Cexp17View 消息处理程序


void Cexp17View::OnCircle()
{
	SetTimer(0, 500, NULL);
	// TODO:  在此添加命令处理程序代码
}


void Cexp17View::OnTimer(UINT_PTR nIDEvent)
{
	
	// TODO:  在此添加消息处理程序代码和/或调用默认值
	CClientDC dc(this);
	CRect center;
	Cexp17Doc* pDoc = GetDocument();
	GetClientRect(&center);
	dc.SelectStockObject(NULL_BRUSH);
	if (i < pDoc->cr.GetSize())
	{
		pDoc->cr[i].top = center.Height() / 2 - 30 * (i + 1);
		pDoc->cr[i].bottom = center.Height() / 2 + 30 * (i + 1);
		pDoc->cr[i].left = center.Width() / 2 - 30 * (i + 1);
		pDoc->cr[i].right = center.Width() / 2 + 30 * (i + 1);
		CPen pen;
		CPen *oldPen;
		pen.CreatePen(PS_SOLID, 2, RGB(rand()%255, rand()%255, rand()%255));//创建一个画笔百(这里度是实线画笔)
		oldPen = dc.SelectObject(&pen);//将画笔对象选问入DC，替换oldPen
		dc.Ellipse(&pDoc->cr[i]);
		dc.SelectObject(oldPen);//最后选回答
		i++;
	}

	CView::OnTimer(nIDEvent);
}
