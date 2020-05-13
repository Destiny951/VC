
// exp16View.cpp : Cexp16View ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "exp16.h"
#endif

#include "exp16Doc.h"
#include "exp16View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// Cexp16View

IMPLEMENT_DYNCREATE(Cexp16View, CView)

BEGIN_MESSAGE_MAP(Cexp16View, CView)
	ON_WM_TIMER()
END_MESSAGE_MAP()

// Cexp16View ����/����

Cexp16View::Cexp16View()
{
	// TODO:  �ڴ˴���ӹ������

}

Cexp16View::~Cexp16View()
{
}

BOOL Cexp16View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO:  �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// Cexp16View ����

void Cexp16View::OnDraw(CDC* pDC)
{
	Cexp16Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	SetTimer(0,200,NULL);
	pDC->Ellipse(&pDoc->circle);
	// TODO:  �ڴ˴�Ϊ����������ӻ��ƴ���
}


// Cexp16View ���

#ifdef _DEBUG
void Cexp16View::AssertValid() const
{
	CView::AssertValid();
}

void Cexp16View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

Cexp16Doc* Cexp16View::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(Cexp16Doc)));
	return (Cexp16Doc*)m_pDocument;
}
#endif //_DEBUG


// Cexp16View ��Ϣ�������


void Cexp16View::OnTimer(UINT_PTR nIDEvent)
{
	// TODO:  �ڴ������Ϣ�����������/�����Ĭ��ֵ
	Cexp16Doc* pDoc = GetDocument();
	CRect cr;
	GetClientRect(&cr);
	if (pDoc->set == true)
	{

		if (pDoc->circle.bottom<cr.bottom)
		{
			pDoc->circle.top += 30;
			pDoc->circle.bottom += 30;
		}
	}
	if (pDoc->circle.bottom >= cr.bottom)
	{
		pDoc->set = false;
	}
	if (pDoc->set == false)
	{
		if (pDoc->circle.top>cr.top)
		{
			pDoc->circle.top -= 30;
			pDoc->circle.bottom -= 30;
		}
	}
	Invalidate();
	CView::OnTimer(nIDEvent);
}
