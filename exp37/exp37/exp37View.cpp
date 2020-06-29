
// exp37View.cpp : Cexp37View ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "exp37.h"
#endif

#include "exp37Doc.h"
#include "exp37View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// Cexp37View

IMPLEMENT_DYNCREATE(Cexp37View, CView)

BEGIN_MESSAGE_MAP(Cexp37View, CView)
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
	ON_WM_MOUSEMOVE()
END_MESSAGE_MAP()

// Cexp37View ����/����

Cexp37View::Cexp37View()
{
	// TODO:  �ڴ˴���ӹ������
	start.x = 0;
	start.y = 0;
}

Cexp37View::~Cexp37View()
{
}

BOOL Cexp37View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO:  �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// Cexp37View ����

void Cexp37View::OnDraw(CDC* pDC)
{
	Cexp37Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	for (int i = 0; i < pDoc->ce.GetSize(); i++)
	{
		pDC->Ellipse(pDoc->ce[i]);
	}
	// TODO:  �ڴ˴�Ϊ����������ӻ��ƴ���
}


// Cexp37View ���

#ifdef _DEBUG
void Cexp37View::AssertValid() const
{
	CView::AssertValid();
}

void Cexp37View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

Cexp37Doc* Cexp37View::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(Cexp37Doc)));
	return (Cexp37Doc*)m_pDocument;
}
#endif //_DEBUG


// Cexp37View ��Ϣ�������


void Cexp37View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO:  �ڴ������Ϣ�����������/�����Ĭ��ֵ
	Cexp37Doc* pDoc = GetDocument();
	log++;
	sel = 1;
	start = point;
	pDoc->ce[log].left = start.x;
	pDoc->ce[log].top = start.y;
	CView::OnLButtonDown(nFlags, point);
}


void Cexp37View::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO:  �ڴ������Ϣ�����������/�����Ĭ��ֵ
	sel = 0;
	CView::OnLButtonUp(nFlags, point);
}


void Cexp37View::OnMouseMove(UINT nFlags, CPoint point)
{
	Cexp37Doc* pDoc = GetDocument();
	// TODO:  �ڴ������Ϣ�����������/�����Ĭ��ֵ
	if (sel == 1)
	{
		pDoc->ce[log].right = point.x;
		pDoc->ce[log].bottom = point.y;
		Invalidate();
	}
	CView::OnMouseMove(nFlags, point);
}