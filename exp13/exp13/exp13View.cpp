
// exp13View.cpp : Cexp13View ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "exp13.h"
#endif

#include "exp13Doc.h"
#include "exp13View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// Cexp13View

IMPLEMENT_DYNCREATE(Cexp13View, CView)

BEGIN_MESSAGE_MAP(Cexp13View, CView)
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
	ON_WM_MOUSEMOVE()
END_MESSAGE_MAP()

// Cexp13View ����/����

Cexp13View::Cexp13View()
{
	// TODO:  �ڴ˴���ӹ������

}

Cexp13View::~Cexp13View()
{
}

BOOL Cexp13View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO:  �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// Cexp13View ����

void Cexp13View::OnDraw(CDC* pDC)
{
	Cexp13Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	CRect cr(x1, y1, x2, y2);
	pDC->Rectangle(cr);
	// TODO:  �ڴ˴�Ϊ����������ӻ��ƴ���
}


// Cexp13View ���

#ifdef _DEBUG
void Cexp13View::AssertValid() const
{
	CView::AssertValid();
}

void Cexp13View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

Cexp13Doc* Cexp13View::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(Cexp13Doc)));
	return (Cexp13Doc*)m_pDocument;
}
#endif //_DEBUG


// Cexp13View ��Ϣ�������


void Cexp13View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO:  �ڴ������Ϣ�����������/�����Ĭ��ֵ
	x1 = point.x;
	y1 = point.y;
	CView::OnLButtonDown(nFlags, point);
}


void Cexp13View::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO:  �ڴ������Ϣ�����������/�����Ĭ��ֵ
	x2 = point.x;
	y2 = point.y;
	Invalidate();
	CView::OnLButtonUp(nFlags, point);
}


void Cexp13View::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO:  �ڴ������Ϣ�����������/�����Ĭ��ֵ
	CClientDC dc(this);
	CString s;
	s.Format(_T("x=%d,y=%d"), point.x, point.y);
	dc.TextOutW(200, 600, s);
	CView::OnMouseMove(nFlags, point);
}
