
// exp35View.cpp : Cexp35View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "exp35.h"
#endif

#include "exp35Doc.h"
#include "exp35View.h"
#include "MyDialog.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// Cexp35View

IMPLEMENT_DYNCREATE(Cexp35View, CView)

BEGIN_MESSAGE_MAP(Cexp35View, CView)
	ON_COMMAND(ID_Choose, &Cexp35View::OnChoose)
	ON_COMMAND(ID_Play, &Cexp35View::OnPlay)
END_MESSAGE_MAP()

// Cexp35View 构造/析构

Cexp35View::Cexp35View()
{
	// TODO:  在此处添加构造代码

}

Cexp35View::~Cexp35View()
{
}

BOOL Cexp35View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO:  在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// Cexp35View 绘制

void Cexp35View::OnDraw(CDC* pDC)
{
	Cexp35Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	CString s = _T("先打开选择图片再点击保存以保存文本文件，同理先点击打开再点击显示图片得以显示");
	pDC->TextOutW(200,300,s);
	// TODO:  在此处为本机数据添加绘制代码
}


// Cexp35View 诊断

#ifdef _DEBUG
void Cexp35View::AssertValid() const
{
	CView::AssertValid();
}

void Cexp35View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

Cexp35Doc* Cexp35View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(Cexp35Doc)));
	return (Cexp35Doc*)m_pDocument;
}
#endif //_DEBUG


// Cexp35View 消息处理程序


void Cexp35View::OnChoose()
{
	Cexp35Doc* pDoc = GetDocument();
	CFileDialog cfd(true);
	cfd.DoModal();
	pDoc->filename = cfd.GetPathName();
	// TODO:  在此添加命令处理程序代码
}


void Cexp35View::OnPlay()
{
	Cexp35Doc* pDoc = GetDocument();
	CString s = pDoc->filename;
	MyDialog dlg;
	dlg.filename = s;
	dlg.DoModal();
	// TODO:  在此添加命令处理程序代码
}
