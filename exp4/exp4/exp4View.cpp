
// exp4View.cpp : Cexp4View ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "exp4.h"
#endif

#include "exp4Doc.h"
#include "exp4View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// Cexp4View

IMPLEMENT_DYNCREATE(Cexp4View, CView)

BEGIN_MESSAGE_MAP(Cexp4View, CView)
END_MESSAGE_MAP()

// Cexp4View ����/����

Cexp4View::Cexp4View()
{
	// TODO:  �ڴ˴���ӹ������

}

Cexp4View::~Cexp4View()
{
}

BOOL Cexp4View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO:  �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// Cexp4View ����

void Cexp4View::OnDraw(CDC* pDC)
{
	Cexp4Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	GetClientRect(&circle);
	
	int red = 150;
	int green = 155;
	int blue = 155;

	CBrush brush(RGB(red, green, blue));//�����Լ���Ҫ�����ɫ
	CBrush *oldbrush;
	oldbrush = pDC->SelectObject(&brush);//ѡ�µĻ�ˢ
	pDC->Ellipse(circle);
	pDC->SelectObject(oldbrush);//��ԭ���Ļ�ˢѡ��ȥ
	// TODO:  �ڴ˴�Ϊ����������ӻ��ƴ���
}


// Cexp4View ���

#ifdef _DEBUG
void Cexp4View::AssertValid() const
{
	CView::AssertValid();
}

void Cexp4View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

Cexp4Doc* Cexp4View::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(Cexp4Doc)));
	return (Cexp4Doc*)m_pDocument;
}
#endif //_DEBUG


// Cexp4View ��Ϣ�������
