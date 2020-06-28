
// exp30View.cpp : Cexp30View ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "exp30.h"
#endif

#include "exp30Doc.h"
#include "exp30View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// Cexp30View

IMPLEMENT_DYNCREATE(Cexp30View, CView)

BEGIN_MESSAGE_MAP(Cexp30View, CView)
	ON_WM_LBUTTONDOWN()
//	ON_WM_MBUTTONDBLCLK()
	ON_WM_TIMER()
	ON_WM_LBUTTONDBLCLK()
END_MESSAGE_MAP()

// Cexp30View ����/����

Cexp30View::Cexp30View()
{
	// TODO:  �ڴ˴���ӹ������
	start = 0;
	exp = 1;
}

Cexp30View::~Cexp30View()
{
}

BOOL Cexp30View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO:  �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// Cexp30View ����

void Cexp30View::OnDraw(CDC* pDC)
{
	Cexp30Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	if (start == 0)
	{
		GetClientRect(ce);
		circle.left = 0;
		circle.right = 200;
		circle.top = (ce.bottom - ce.top) / 2 - 100;
		circle.bottom = (ce.bottom - ce.top) / 2 + 100;
		start = 1;
	}
	pDC->Ellipse(circle);
	// TODO:  �ڴ˴�Ϊ����������ӻ��ƴ���
}


// Cexp30View ���

#ifdef _DEBUG
void Cexp30View::AssertValid() const
{
	CView::AssertValid();
}

void Cexp30View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

Cexp30Doc* Cexp30View::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(Cexp30Doc)));
	return (Cexp30Doc*)m_pDocument;
}
#endif //_DEBUG


// Cexp30View ��Ϣ�������


void Cexp30View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO:  �ڴ������Ϣ�����������/�����Ĭ��ֵ
	SetTimer(0,500,NULL);
	CView::OnLButtonDown(nFlags, point);
}


//void Cexp30View::OnMButtonDblClk(UINT nFlags, CPoint point)
//{
//	// TODO:  �ڴ������Ϣ�����������/�����Ĭ��ֵ
//
//	CView::OnMButtonDblClk(nFlags, point);
//}


void Cexp30View::OnTimer(UINT_PTR nIDEvent)
{
	// TODO:  �ڴ������Ϣ�����������/�����Ĭ��ֵ
	if (exp == 1)
	{
		if (circle.right <= ce.right)
		{
			circle.left += 30;
			circle.right += 30;
		}
		else exp = 0;
	}
	else
	{
		if (circle.left >= ce.left)
		{
			circle.left -= 30;
			circle.right -= 30;
		}
		else exp = 1;
	}
	Invalidate();
	CView::OnTimer(nIDEvent);
}


void Cexp30View::OnLButtonDblClk(UINT nFlags, CPoint point)
{
	// TODO:  �ڴ������Ϣ�����������/�����Ĭ��ֵ
	KillTimer(0);
	CClientDC dc(this);
	CString s = _T("stop");
	dc.TextOutW(0, 0, s);
	CView::OnLButtonDblClk(nFlags, point);
}
