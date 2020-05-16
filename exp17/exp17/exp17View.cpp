
// exp17View.cpp : Cexp17View ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "exp17.h"
#endif

#include "exp17Doc.h"
#include "exp17View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// Cexp17View

IMPLEMENT_DYNCREATE(Cexp17View, CView)

BEGIN_MESSAGE_MAP(Cexp17View, CView)
	ON_COMMAND(Circle, &Cexp17View::OnCircle)
	ON_WM_TIMER()
END_MESSAGE_MAP()

// Cexp17View ����/����

Cexp17View::Cexp17View()
{
	// TODO:  �ڴ˴���ӹ������

}

Cexp17View::~Cexp17View()
{
}

BOOL Cexp17View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO:  �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// Cexp17View ����

void Cexp17View::OnDraw(CDC* pDC)
{
	Cexp17Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO:  �ڴ˴�Ϊ����������ӻ��ƴ���
}


// Cexp17View ���

#ifdef _DEBUG
void Cexp17View::AssertValid() const
{
	CView::AssertValid();
}

void Cexp17View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

Cexp17Doc* Cexp17View::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(Cexp17Doc)));
	return (Cexp17Doc*)m_pDocument;
}
#endif //_DEBUG


// Cexp17View ��Ϣ�������


void Cexp17View::OnCircle()
{
	SetTimer(0, 500, NULL);
	// TODO:  �ڴ���������������
}


void Cexp17View::OnTimer(UINT_PTR nIDEvent)
{
	
	// TODO:  �ڴ������Ϣ�����������/�����Ĭ��ֵ
	CClientDC dc(this);
	CRect center;
	Cexp17Doc* pDoc = GetDocument();
	GetClientRect(&center);
	dc.SelectStockObject(NULL_BRUSH);
	if (i < pDoc->cr.GetSize())
	{
		pDoc->cr[i].top = center.Height() / 2 - 30 * (i + 1);
		pDoc->cr[i].bottom = center.Height() / 2 + 30 * (i + 1);
		pDoc->cr[i].left = center.Width() / 2 - 30 * (i + 1);
		pDoc->cr[i].right = center.Width() / 2 + 30 * (i + 1);
		CPen pen;
		CPen *oldPen;
		pen.CreatePen(PS_SOLID, 2, RGB(rand()%255, rand()%255, rand()%255));//����һ�����ʰ�(�������ʵ�߻���)
		oldPen = dc.SelectObject(&pen);//�����ʶ���ѡ����DC���滻oldPen
		dc.Ellipse(&pDoc->cr[i]);
		dc.SelectObject(oldPen);//���ѡ�ش�
		i++;
	}

	CView::OnTimer(nIDEvent);
}
