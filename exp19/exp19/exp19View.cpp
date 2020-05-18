
// exp19View.cpp : Cexp19View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "exp19.h"
#endif

#include "exp19Doc.h"
#include "exp19View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// Cexp19View

IMPLEMENT_DYNCREATE(Cexp19View, CView)

BEGIN_MESSAGE_MAP(Cexp19View, CView)
END_MESSAGE_MAP()

// Cexp19View 构造/析构

Cexp19View::Cexp19View()
{
	// TODO:  在此处添加构造代码

}

Cexp19View::~Cexp19View()
{
}

BOOL Cexp19View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO:  在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// Cexp19View 绘制

void Cexp19View::OnDraw(CDC* pDC)
{
	Cexp19Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	BITMAP BM;
	m_Bitmap.LoadBitmap(IDB_BITMAP1);
	m_Bitmap.GetBitmap(&BM);
	m_nWidth = BM.bmWidth;
	m_nHeight = BM.bmHeight;

	CDC MemDC;
	MemDC.CreateCompatibleDC(NULL);
	MemDC.SelectObject(m_Bitmap);
	pDC->BitBlt(0, 0, m_nWidth, m_nHeight, &MemDC, 0, 0, SRCCOPY);

	// TODO:  在此处为本机数据添加绘制代码
}


// Cexp19View 诊断

#ifdef _DEBUG
void Cexp19View::AssertValid() const
{
	CView::AssertValid();
}

void Cexp19View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

Cexp19Doc* Cexp19View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(Cexp19Doc)));
	return (Cexp19Doc*)m_pDocument;
}
#endif //_DEBUG


// Cexp19View 消息处理程序
