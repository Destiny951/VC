
// exp20View.cpp : Cexp20View ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "exp20.h"
#endif

#include "exp20Doc.h"
#include "exp20View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// Cexp20View

IMPLEMENT_DYNCREATE(Cexp20View, CView)

BEGIN_MESSAGE_MAP(Cexp20View, CView)
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
	ON_COMMAND(Line, &Cexp20View::OnLine)
	ON_COMMAND(Squire, &Cexp20View::OnSquire)
	ON_COMMAND(Circle, &Cexp20View::OnCircle)
END_MESSAGE_MAP()

// Cexp20View ����/����

Cexp20View::Cexp20View()
{
	// TODO:  �ڴ˴���ӹ������
	i = 0;
	x1 = 0;
	y1 = 0;
	x2 = 0;
	y2 = 0;
}

Cexp20View::~Cexp20View()
{
}

BOOL Cexp20View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO:  �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// Cexp20View ����

void Cexp20View::OnDraw(CDC* pDC)
{
	Cexp20Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	if (i == 1)
	{
		CPen newpen;
		newpen.CreatePen(PS_SOLID, 1, RGB(0, 0, 0));
		CPen *oldpen = pDC->SelectObject(&newpen);
		pDC->MoveTo(x1, y1);
		pDC->LineTo(x2, y2);
		pDC->SelectObject(oldpen);
	}
	else if (i == 2)
	{
		CRect x;
		x.left = x1;
		x.top = y1;
		x.bottom = y2;
		x.right = x2;
		pDC->Rectangle(x);
	}
	else if (i == 3)
	{
		CRect rect;
		rect.left = x1;
		rect.top = y1;
		rect.right = x2;
		rect.bottom = y2;
		pDC->Ellipse(rect);
	}

	// TODO:  �ڴ˴�Ϊ����������ӻ��ƴ���
}


// Cexp20View ���

#ifdef _DEBUG
void Cexp20View::AssertValid() const
{
	CView::AssertValid();
}

void Cexp20View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

Cexp20Doc* Cexp20View::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(Cexp20Doc)));
	return (Cexp20Doc*)m_pDocument;
}
#endif //_DEBUG


// Cexp20View ��Ϣ�������


void Cexp20View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO:  �ڴ������Ϣ�����������/�����Ĭ��ֵ

	x1 = point.x;
	y1 = point.y;
	CView::OnLButtonDown(nFlags, point);
}


void Cexp20View::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO:  �ڴ������Ϣ�����������/�����Ĭ��ֵ
	x2 = point.x;
	y2 = point.y;
	Invalidate();
	CView::OnLButtonUp(nFlags, point);
}


void Cexp20View::OnLine()
{
	i = 1;
	// TODO:  �ڴ���������������
}


void Cexp20View::OnSquire()
{
	i = 2;
	// TODO:  �ڴ���������������
}


void Cexp20View::OnCircle()
{
	i = 3;
	// TODO:  �ڴ���������������
}
