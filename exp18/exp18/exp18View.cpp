
// exp18View.cpp : Cexp18View ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "exp18.h"
#endif

#include "exp18Doc.h"
#include "exp18View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// Cexp18View

IMPLEMENT_DYNCREATE(Cexp18View, CView)

BEGIN_MESSAGE_MAP(Cexp18View, CView)
	ON_COMMAND(NAME, &Cexp18View::OnName)
END_MESSAGE_MAP()

// Cexp18View ����/����

Cexp18View::Cexp18View()
{
	// TODO:  �ڴ˴���ӹ������

}

Cexp18View::~Cexp18View()
{
}

BOOL Cexp18View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO:  �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// Cexp18View ����

void Cexp18View::OnDraw(CDC* /*pDC*/)
{
	Cexp18Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO:  �ڴ˴�Ϊ����������ӻ��ƴ���
}


// Cexp18View ���

#ifdef _DEBUG
void Cexp18View::AssertValid() const
{
	CView::AssertValid();
}

void Cexp18View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

Cexp18Doc* Cexp18View::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(Cexp18Doc)));
	return (Cexp18Doc*)m_pDocument;
}
#endif //_DEBUG


// Cexp18View ��Ϣ�������


void Cexp18View::OnName()
{
	CClientDC dc(this);
	CString s ;
	s.Format(_T("��������־��"));
	dc.TextOutW(30, 50, s);
	// TODO:  �ڴ���������������
}
