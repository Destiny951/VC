
// exp29View.cpp : Cexp29View ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "exp29.h"
#endif

#include "exp29Doc.h"
#include "exp29View.h"
#include "MyDialog.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// Cexp29View

IMPLEMENT_DYNCREATE(Cexp29View, CView)

BEGIN_MESSAGE_MAP(Cexp29View, CView)
	ON_COMMAND(ID_Show, &Cexp29View::OnShow)
END_MESSAGE_MAP()

// Cexp29View ����/����

Cexp29View::Cexp29View()
{
	// TODO:  �ڴ˴���ӹ������

}

Cexp29View::~Cexp29View()
{
}

BOOL Cexp29View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO:  �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// Cexp29View ����

void Cexp29View::OnDraw(CDC* /*pDC*/)
{
	Cexp29Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO:  �ڴ˴�Ϊ����������ӻ��ƴ���
}


// Cexp29View ���

#ifdef _DEBUG
void Cexp29View::AssertValid() const
{
	CView::AssertValid();
}

void Cexp29View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

Cexp29Doc* Cexp29View::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(Cexp29Doc)));
	return (Cexp29Doc*)m_pDocument;
}
#endif //_DEBUG


// Cexp29View ��Ϣ�������


void Cexp29View::OnShow()
{
	MyDialog dlg ;
	dlg.DoModal();
	// TODO:  �ڴ���������������
}
