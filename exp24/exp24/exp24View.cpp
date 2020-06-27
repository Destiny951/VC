
// exp24View.cpp : Cexp24View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "exp24.h"
#endif

#include "exp24Doc.h"
#include "exp24View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// Cexp24View

IMPLEMENT_DYNCREATE(Cexp24View, CView)

BEGIN_MESSAGE_MAP(Cexp24View, CView)
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_CHAR()
	ON_WM_LBUTTONDOWN()
	ON_WM_SETFOCUS()
END_MESSAGE_MAP()

// Cexp24View 构造/析构

Cexp24View::Cexp24View()
{
	// TODO:  在此处添加构造代码
	mes.left = 300;
	mes.right = 1000;
	mes.top = 100;
	mes.bottom = 140;

	pt.x = mes.left + 2;
	pt.y = mes.top + 10;
}

Cexp24View::~Cexp24View()
{
}

BOOL Cexp24View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO:  在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// Cexp24View 绘制

void Cexp24View::OnDraw(CDC* pDC)
{
	Cexp24Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	pDC->Rectangle(mes);     //画出长方形

	CString str ;            //str存入数字
	for (int i = 0; i < ch.GetSize(); i++)
	{
		str += ch[i];
	}

	pDC->TextOutW(mes.left + 2, pt.y, str);

	// TODO:  在此处为本机数据添加绘制代码
}


// Cexp24View 打印

BOOL Cexp24View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void Cexp24View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO:  添加额外的打印前进行的初始化过程
}

void Cexp24View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO:  添加打印后进行的清理过程
}


// Cexp24View 诊断

#ifdef _DEBUG
void Cexp24View::AssertValid() const
{
	CView::AssertValid();
}

void Cexp24View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

Cexp24Doc* Cexp24View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(Cexp24Doc)));
	return (Cexp24Doc*)m_pDocument;
}
#endif //_DEBUG


// Cexp24View 消息处理程序


void Cexp24View::OnChar(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	// TODO:  在此添加消息处理程序代码和/或调用默认值
	if (pt.x < mes.right - 10)
	{
		TCHAR c = nChar;
		CClientDC dc(this);
		textsize = dc.GetTextExtent((LPCTSTR)&nChar);
		if ((pt.x - mes.left + 2) / textsize.cx < ch.GetSize())
		{
			int i = (pt.x - mes.left + 2) / textsize.cx - 1;
			for (int j = ch.GetSize()-1; j < i; j--)
			{
				ch[j + 1] = ch[j];
			}
			ch[i] = c;
		}
		else
		{
			ch.Add(c);
			pt.x += textsize.cx;
		}
		SetCaretPos(pt);
		ShowCaret();
		Invalidate();
		CView::OnChar(nChar, nRepCnt, nFlags);
	}
}


void Cexp24View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO:  在此添加消息处理程序代码和/或调用默认值
	if (point.x >= mes.left&&point.x <= mes.right)
	{
		if (point.y <= mes.bottom&&point.y >= mes.top)
		{
			for (int i = 0; i < (mes.right - 10 - (mes.left+2) / textsize.cx); i++)
			{
				if (point.x >= mes.left + 2 + (i-1)*textsize.cx&&point.x <= mes.left + 2 + i*textsize.cx)
				{
					if (point.x < (mes.left + 2 + i*textsize.cx - (mes.left + 2 + (i-1)*textsize.cx)) / 2)
					{
						pt.x = mes.left + 2 + (i-1)*textsize.cx;
					}
					else
					{
						pt.x = mes.left + 2 + i*textsize.cx;
					}
				}
			}
			SetCaretPos(pt);
			ShowCaret();
		}
	}
	CView::OnLButtonDown(nFlags, point);
}


void Cexp24View::OnSetFocus(CWnd* pOldWnd)
{
	CView::OnSetFocus(pOldWnd);
	CreateSolidCaret(3, 18);
	SetCaretPos(pt);
	ShowCaret();
	// TODO:  在此处添加消息处理程序代码
}
