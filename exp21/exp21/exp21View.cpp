
// exp21View.cpp : Cexp21View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "exp21.h"
#endif

#include "exp21Doc.h"
#include "exp21View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// Cexp21View

IMPLEMENT_DYNCREATE(Cexp21View, CView)

BEGIN_MESSAGE_MAP(Cexp21View, CView)
	ON_COMMAND(ID_FILE_OPEN, &Cexp21View::OnFileOpen)
END_MESSAGE_MAP()

// Cexp21View 构造/析构

Cexp21View::Cexp21View()
{
	// TODO:  在此处添加构造代码

}

Cexp21View::~Cexp21View()
{
}

BOOL Cexp21View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO:  在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// Cexp21View 绘制

void Cexp21View::OnDraw(CDC* /*pDC*/)
{
	Cexp21Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO:  在此处为本机数据添加绘制代码
}


// Cexp21View 诊断

#ifdef _DEBUG
void Cexp21View::AssertValid() const
{
	CView::AssertValid();
}

void Cexp21View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

Cexp21Doc* Cexp21View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(Cexp21Doc)));
	return (Cexp21Doc*)m_pDocument;
}
#endif //_DEBUG


// Cexp21View 消息处理程序


void Cexp21View::OnFileOpen()
{
	// TODO:  在此添加命令处理程序代码
	CFileDialog cfd(true);
	int r = cfd.DoModal();
	CClientDC dc(this);
	int w, h, sx, sy;
	if (r == IDOK)
	{
		CString filename = cfd.GetPathName();
		CImage image;
		image.Load(filename);

		CRect rect;
		GetClientRect(&rect);
		float rect_radio = 1.0*rect.Width() / rect.Height();
		float image_radio = 1.0*image.GetWidth() / image.GetHeight();
		if (rect_radio > image_radio)
		{
			h = rect.Height();
			w = image_radio*h;
			sx = (rect.Width() - w) / 2;
			sy = 0;
		}
		else
		{
			w = rect.Width();
			h = w / image_radio;
			sx = 0;
			sy = (rect.Height() - h) / 2;
		}
		image.Draw(dc.m_hDC,sx,sy,w,h);
	}
}
