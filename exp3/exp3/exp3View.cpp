
// exp3View.cpp : Cexp3View ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "exp3.h"
#endif

#include "exp3Doc.h"
#include "exp3View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// Cexp3View

IMPLEMENT_DYNCREATE(Cexp3View, CView)

BEGIN_MESSAGE_MAP(Cexp3View, CView)
END_MESSAGE_MAP()

// Cexp3View ����/����

Cexp3View::Cexp3View()
{
	// TODO:  �ڴ˴���ӹ������

}

Cexp3View::~Cexp3View()
{
}

BOOL Cexp3View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO:  �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// Cexp3View ����

void Cexp3View::OnDraw(CDC* pDC)
{
	Cexp3Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	GetClientRect(&circle);
	pDC->Ellipse(circle);
	// TODO:  �ڴ˴�Ϊ����������ӻ��ƴ���
}


// Cexp3View ���

#ifdef _DEBUG
void Cexp3View::AssertValid() const
{
	CView::AssertValid();
}

void Cexp3View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

Cexp3Doc* Cexp3View::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(Cexp3Doc)));
	return (Cexp3Doc*)m_pDocument;
}
#endif //_DEBUG


// Cexp3View ��Ϣ�������
