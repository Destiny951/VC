
// exp6View.cpp : Cexp6View ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "exp6.h"
#endif

#include "exp6Doc.h"
#include "exp6View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// Cexp6View

IMPLEMENT_DYNCREATE(Cexp6View, CView)

BEGIN_MESSAGE_MAP(Cexp6View, CView)
END_MESSAGE_MAP()

// Cexp6View ����/����

Cexp6View::Cexp6View()
{
	// TODO:  �ڴ˴���ӹ������

}

Cexp6View::~Cexp6View()
{
}

BOOL Cexp6View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO:  �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// Cexp6View ����

void Cexp6View::OnDraw(CDC* pDC)
{
	Cexp6Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	CString x = pDoc->s;
	pDC->TextOutW(200, 300, x);
	// TODO:  �ڴ˴�Ϊ����������ӻ��ƴ���
}


// Cexp6View ���

#ifdef _DEBUG
void Cexp6View::AssertValid() const
{
	CView::AssertValid();
}

void Cexp6View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

Cexp6Doc* Cexp6View::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(Cexp6Doc)));
	return (Cexp6Doc*)m_pDocument;
}
#endif //_DEBUG


// Cexp6View ��Ϣ�������
