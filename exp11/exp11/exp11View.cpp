
// exp11View.cpp : Cexp11View ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "exp11.h"
#endif

#include "exp11Doc.h"
#include "exp11View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// Cexp11View

IMPLEMENT_DYNCREATE(Cexp11View, CView)

BEGIN_MESSAGE_MAP(Cexp11View, CView)
	ON_WM_LBUTTONDOWN()
END_MESSAGE_MAP()

// Cexp11View ����/����

Cexp11View::Cexp11View()
{
	// TODO:  �ڴ˴����ӹ������

}

Cexp11View::~Cexp11View()
{
}

BOOL Cexp11View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO:  �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// Cexp11View ����

void Cexp11View::OnDraw(CDC* pDC)
{
	Cexp11Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	pDC->TextOutW(200, 300, s);
	// TODO:  �ڴ˴�Ϊ�����������ӻ��ƴ���
}


// Cexp11View ���

#ifdef _DEBUG
void Cexp11View::AssertValid() const
{
	CView::AssertValid();
}

void Cexp11View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

Cexp11Doc* Cexp11View::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(Cexp11Doc)));
	return (Cexp11Doc*)m_pDocument;
}
#endif //_DEBUG


// Cexp11View ��Ϣ��������


void Cexp11View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO:  �ڴ�������Ϣ������������/�����Ĭ��ֵ
	Cexp11Doc* pDoc = GetDocument();
	s.Format(_T("A+B=%d"),pDoc->A+pDoc->B);
	Invalidate();
	CView::OnLButtonDown(nFlags, point);
}