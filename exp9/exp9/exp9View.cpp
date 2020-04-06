
// exp9View.cpp : Cexp9View ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "exp9.h"
#endif

#include "exp9Doc.h"
#include "exp9View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// Cexp9View

IMPLEMENT_DYNCREATE(Cexp9View, CView)

BEGIN_MESSAGE_MAP(Cexp9View, CView)
	ON_WM_LBUTTONDOWN()
END_MESSAGE_MAP()

// Cexp9View ����/����

Cexp9View::Cexp9View()
{
	// TODO:  �ڴ˴���ӹ������
	x = 0;
	y = 0;
}

Cexp9View::~Cexp9View()
{
}

BOOL Cexp9View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO:  �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// Cexp9View ����

void Cexp9View::OnDraw(CDC* pDC)
{
	Cexp9Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	for (int i = 0; i < pDoc->cr.GetSize(); i++)
	{
		pDC->Ellipse(pDoc->cr[i]);
	}
	// TODO:  �ڴ˴�Ϊ����������ӻ��ƴ���
}


// Cexp9View ���

#ifdef _DEBUG
void Cexp9View::AssertValid() const
{
	CView::AssertValid();
}

void Cexp9View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

Cexp9Doc* Cexp9View::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(Cexp9Doc)));
	return (Cexp9Doc*)m_pDocument;
}
#endif //_DEBUG


// Cexp9View ��Ϣ�������


void Cexp9View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO:  �ڴ������Ϣ�����������/�����Ĭ��ֵ
	Cexp9Doc* pDoc = GetDocument();
	int r1 = rand() % 100 + 5;
	int r2 = rand() % 100 + 5;
	x = point.x;
	y = point.y;
	CRect circle(x-r1,y-r2,x+r1,y+r2);
	pDoc->cr.Add(circle);
	Invalidate();
	CView::OnLButtonDown(nFlags, point);
}
