
// exp5View.cpp : Cexp5View ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "exp5.h"
#endif

#include "exp5Doc.h"
#include "exp5View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// Cexp5View

IMPLEMENT_DYNCREATE(Cexp5View, CView)

BEGIN_MESSAGE_MAP(Cexp5View, CView)
END_MESSAGE_MAP()

// Cexp5View ����/����

Cexp5View::Cexp5View()
{
	// TODO:  �ڴ˴���ӹ������

}

Cexp5View::~Cexp5View()
{
}

BOOL Cexp5View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO:  �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// Cexp5View ����

void Cexp5View::OnDraw(CDC* pDC)
{
	Cexp5Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	CString s;
	int A = 10;
	s.Format(_T("����xxx,%d"),A);
	pDC->TextOutW(200, 300, s);
	// TODO:  �ڴ˴�Ϊ����������ӻ��ƴ���
}


// Cexp5View ���

#ifdef _DEBUG
void Cexp5View::AssertValid() const
{
	CView::AssertValid();
}

void Cexp5View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

Cexp5Doc* Cexp5View::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(Cexp5Doc)));
	return (Cexp5Doc*)m_pDocument;
}
#endif //_DEBUG


// Cexp5View ��Ϣ�������
