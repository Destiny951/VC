
// exp10View.cpp : Cexp10View ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "exp10.h"
#endif

#include "exp10Doc.h"
#include "exp10View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// Cexp10View

IMPLEMENT_DYNCREATE(Cexp10View, CView)

BEGIN_MESSAGE_MAP(Cexp10View, CView)
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
END_MESSAGE_MAP()

// Cexp10View ����/����

Cexp10View::Cexp10View()
{
	// TODO:  �ڴ˴���ӹ������

}

Cexp10View::~Cexp10View()
{
}

BOOL Cexp10View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO:  �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// Cexp10View ����

void Cexp10View::OnDraw(CDC* pDC)
{
	Cexp10Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	pDC->TextOutW(200, 300, s);
	// TODO:  �ڴ˴�Ϊ����������ӻ��ƴ���
}


// Cexp10View ���

#ifdef _DEBUG
void Cexp10View::AssertValid() const
{
	CView::AssertValid();
}

void Cexp10View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

Cexp10Doc* Cexp10View::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(Cexp10Doc)));
	return (Cexp10Doc*)m_pDocument;
}
#endif //_DEBUG


// Cexp10View ��Ϣ�������


void Cexp10View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO:  �ڴ������Ϣ�����������/�����Ĭ��ֵ
	s.Format(_T("�����������"));
	Invalidate();
	CView::OnLButtonDown(nFlags, point);
}


void Cexp10View::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO:  �ڴ������Ϣ�����������/�����Ĭ��ֵ
	s.Format(_T("�������̧��"));
	Invalidate();
	CView::OnLButtonUp(nFlags, point);
}
