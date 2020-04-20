
// exp14View.cpp : Cexp14View ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "exp14.h"
#endif

#include "exp14Doc.h"
#include "exp14View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// Cexp14View

IMPLEMENT_DYNCREATE(Cexp14View, CView)

BEGIN_MESSAGE_MAP(Cexp14View, CView)
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
	ON_WM_MOUSEMOVE()
END_MESSAGE_MAP()

// Cexp14View ����/����

Cexp14View::Cexp14View()
{
	// TODO:  �ڴ˴���ӹ������
	sum = 0;
	totalpixel = 0;
	avepixel = 0;
	down = 0;
}

Cexp14View::~Cexp14View()
{
}

BOOL Cexp14View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO:  �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// Cexp14View ����

void Cexp14View::OnDraw(CDC* pDC)
{
	Cexp14Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	CString s;
	s.Format(_T("MouseMove�¼�������%d�Σ������ƶ���%d���ط���һ��"), sum,avepixel);
	pDC->TextOutW(200, 300, s);
	sum = 0;
	// TODO:  �ڴ˴�Ϊ����������ӻ��ƴ���
}


// Cexp14View ���

#ifdef _DEBUG
void Cexp14View::AssertValid() const
{
	CView::AssertValid();
}

void Cexp14View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

Cexp14Doc* Cexp14View::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(Cexp14Doc)));
	return (Cexp14Doc*)m_pDocument;
}
#endif //_DEBUG


// Cexp14View ��Ϣ�������


void Cexp14View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO:  �ڴ������Ϣ�����������/�����Ĭ��ֵ
	down = 1;
	totalpixel = point.x;
	CView::OnLButtonDown(nFlags, point);
}


void Cexp14View::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO:  �ڴ������Ϣ�����������/�����Ĭ��ֵ

	down = 0;
	if (totalpixel > point.x)
	{
		totalpixel = totalpixel - point.x;
	}
	else
	{
		totalpixel = point.x - totalpixel;
	}
	avepixel = totalpixel / sum;
	Invalidate();
	CView::OnLButtonUp(nFlags, point);
}


void Cexp14View::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO:  �ڴ������Ϣ�����������/�����Ĭ��ֵ
	if (down == 1)
	{
		sum++;
	}
	CView::OnMouseMove(nFlags, point);
}
