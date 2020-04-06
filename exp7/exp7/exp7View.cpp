
// exp7View.cpp : Cexp7View ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "exp7.h"
#endif

#include "exp7Doc.h"
#include "exp7View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// Cexp7View

IMPLEMENT_DYNCREATE(Cexp7View, CView)

BEGIN_MESSAGE_MAP(Cexp7View, CView)
	ON_WM_LBUTTONDOWN()
	ON_WM_RBUTTONDOWN()
END_MESSAGE_MAP()

// Cexp7View ����/����

Cexp7View::Cexp7View()
{
	// TODO:  �ڴ˴���ӹ������
	ans = 0;
}

Cexp7View::~Cexp7View()
{
}

BOOL Cexp7View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO:  �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// Cexp7View ����

void Cexp7View::OnDraw(CDC* pDC)
{
	Cexp7Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	CString s;
	s.Format(_T("count�Ĵ���%d"), pDoc->count);
	if (ans == 1)
	{
		pDC->TextOutW(200, 300, s);
	}
	// TODO:  �ڴ˴�Ϊ����������ӻ��ƴ���
}


// Cexp7View ���

#ifdef _DEBUG
void Cexp7View::AssertValid() const
{
	CView::AssertValid();
}

void Cexp7View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

Cexp7Doc* Cexp7View::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(Cexp7Doc)));
	return (Cexp7Doc*)m_pDocument;
}
#endif //_DEBUG


// Cexp7View ��Ϣ�������


void Cexp7View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO:  �ڴ������Ϣ�����������/�����Ĭ��ֵ
	Cexp7Doc* pDoc = GetDocument();
	pDoc->count++;
	CView::OnLButtonDown(nFlags, point);
}


void Cexp7View::OnRButtonDown(UINT nFlags, CPoint point)
{
	// TODO:  �ڴ������Ϣ�����������/�����Ĭ��ֵ
	ans = 1;
	Invalidate();
	CView::OnRButtonDown(nFlags, point);
}
