
// exp28View.cpp : Cexp28View ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "exp28.h"
#endif

#include "exp28Doc.h"
#include "exp28View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// Cexp28View

IMPLEMENT_DYNCREATE(Cexp28View, CView)

BEGIN_MESSAGE_MAP(Cexp28View, CView)
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
	ON_WM_MOUSEMOVE()
END_MESSAGE_MAP()

// Cexp28View ����/����

Cexp28View::Cexp28View()
{
	// TODO:  �ڴ˴���ӹ������
	select = 0;
	ce.left = 300;
	ce.bottom = 400;
	ce.right = 500;
	ce.top = 300;
	start.x = 0;
	start.y = 0;
}

Cexp28View::~Cexp28View()
{
}

BOOL Cexp28View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO:  �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// Cexp28View ����

void Cexp28View::OnDraw(CDC* pDC)
{
	Cexp28Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	
	pDC->Rectangle(ce);
	// TODO:  �ڴ˴�Ϊ����������ӻ��ƴ���
}


// Cexp28View ���

#ifdef _DEBUG
void Cexp28View::AssertValid() const
{
	CView::AssertValid();
}

void Cexp28View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

Cexp28Doc* Cexp28View::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(Cexp28Doc)));
	return (Cexp28Doc*)m_pDocument;
}
#endif //_DEBUG


// Cexp28View ��Ϣ�������


void Cexp28View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO:  �ڴ������Ϣ�����������/�����Ĭ��ֵ
	if (point.x > ce.left&&point.x<ce.right&&point.y>ce.top&&point.y < ce.bottom)
	{
		select = 1;
		start = point;
	}
	CView::OnLButtonDown(nFlags, point);
}


void Cexp28View::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO:  �ڴ������Ϣ�����������/�����Ĭ��ֵ
	select = 0;
	CView::OnLButtonUp(nFlags, point);
}


void Cexp28View::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO:  �ڴ������Ϣ�����������/�����Ĭ��ֵ
	if (select == 1)
	{
		ce.left += point.x - start.x;
		ce.right += point.x - start.x;
		ce.bottom += point.y - start.y;
		ce.top += point.y - start.y;
		start = point;
	}
	Invalidate();
	CView::OnMouseMove(nFlags, point);
}
