
// exp8View.cpp : Cexp8View ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "exp8.h"
#endif

#include "exp8Doc.h"
#include "exp8View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// Cexp8View

IMPLEMENT_DYNCREATE(Cexp8View, CView)

BEGIN_MESSAGE_MAP(Cexp8View, CView)
	ON_WM_LBUTTONDOWN()
END_MESSAGE_MAP()

// Cexp8View ����/����

Cexp8View::Cexp8View()
{
	// TODO:  �ڴ˴���ӹ������
	ans = 0;
}

Cexp8View::~Cexp8View()
{
}

BOOL Cexp8View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO:  �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// Cexp8View ����

void Cexp8View::OnDraw(CDC* pDC)
{
	Cexp8Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	if (ans == 1)
	{
		GetClientRect(&circle);
		pDC->Ellipse(circle);
	}

	// TODO:  �ڴ˴�Ϊ����������ӻ��ƴ���
}


// Cexp8View ���

#ifdef _DEBUG
void Cexp8View::AssertValid() const
{
	CView::AssertValid();
}

void Cexp8View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

Cexp8Doc* Cexp8View::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(Cexp8Doc)));
	return (Cexp8Doc*)m_pDocument;
}
#endif //_DEBUG


// Cexp8View ��Ϣ�������


void Cexp8View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO:  �ڴ������Ϣ�����������/�����Ĭ��ֵ
	ans = 1;
	Invalidate();
	CView::OnLButtonDown(nFlags, point);
}
