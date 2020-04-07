
// exp12View.cpp : Cexp12View ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "exp12.h"
#endif

#include "exp12Doc.h"
#include "exp12View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// Cexp12View

IMPLEMENT_DYNCREATE(Cexp12View, CView)

BEGIN_MESSAGE_MAP(Cexp12View, CView)
	ON_WM_LBUTTONDOWN()
//	ON_WM_LBUTTONUP()
//ON_WM_MBUTTONDOWN()
ON_WM_RBUTTONDOWN()
END_MESSAGE_MAP()

// Cexp12View ����/����

Cexp12View::Cexp12View()
{
	// TODO:  �ڴ˴���ӹ������
}

Cexp12View::~Cexp12View()
{
}

BOOL Cexp12View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO:  �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// Cexp12View ����

void Cexp12View::OnDraw(CDC* pDC)
{
	Cexp12Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	int x1 = 100;
	int x2 = 300;

	for (int i = 0; i < 4; i++,x1+=300,x2+=300)
	{
		CRect ca(x1, 100, x2, 300);
		pDoc->cr.Add(ca);
	}
	for (int i = 0; i < 4; i++)
	{
		pDC->Rectangle(pDoc->cr[i]);
	}
	// TODO:  �ڴ˴�Ϊ����������ӻ��ƴ���
}


// Cexp12View ���

#ifdef _DEBUG
void Cexp12View::AssertValid() const
{
	CView::AssertValid();
}

void Cexp12View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

Cexp12Doc* Cexp12View::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(Cexp12Doc)));
	return (Cexp12Doc*)m_pDocument;
}
#endif //_DEBUG


// Cexp12View ��Ϣ�������


void Cexp12View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO:  �ڴ������Ϣ�����������/�����Ĭ��ֵ
	Cexp12Doc* pDoc = GetDocument();
	CString s;
	CClientDC dc(this);
	int a = rand() % 500;
	int b = rand() % 500;
	if (point.x <= pDoc->cr[0].right&&point.x >= pDoc->cr[0].left&&point.y <= pDoc->cr[0].bottom&&point.y >= pDoc->cr[0].top)
	{
		pDoc->xa.Add(a);
		s.Format(_T("%d"),a);
		dc.TextOutW(point.x, point.y, s);
	}
	else if (point.x <= pDoc->cr[1].right&&point.x >= pDoc->cr[1].left&&point.y <= pDoc->cr[1].bottom&&point.y >= pDoc->cr[1].top)
	{
		pDoc->xb.Add(b);
		s.Format(_T("%d"), b);
		dc.TextOutW(point.x, point.y, s);
	}
	else if (point.x <= pDoc->cr[2].right&&point.x >= pDoc->cr[2].left&&point.y <= pDoc->cr[2].bottom&&point.y >= pDoc->cr[2].top)
	{
		sum++;
		if (sum % 4 == 1)
		{
			pDoc->command.Add('+');
			s.Format(_T("+"));
			dc.TextOutW(point.x, point.y, s);
		}
		else if (sum % 4 == 2)
		{
			pDoc->command.Add('-');
			s.Format(_T("-"));
			dc.TextOutW(point.x, point.y, s);
		}
		else if (sum % 4 == 3)
		{
			pDoc->command.Add('*');
			s.Format(_T("*"));
			dc.TextOutW(point.x, point.y, s);
		}
		else if (sum % 4 == 0)
		{
			pDoc->command.Add('/');
			s.Format(_T("/"));
			dc.TextOutW(point.x, point.y, s);
		}
	}
	else if (point.x <= pDoc->cr[3].right&&point.x >= pDoc->cr[3].left&&point.y <= pDoc->cr[3].bottom&&point.y >= pDoc->cr[3].top)
	{

	}
	else
	{
		s.Format(_T("��Ч"));
		dc.TextOutW(point.x, point.y, s);
	}
	CView::OnLButtonDown(nFlags, point);
}


//void Cexp12View::OnLButtonUp(UINT nFlags, CPoint point)
//{
//	// TODO:  �ڴ������Ϣ�����������/�����Ĭ��ֵ
//
//	CView::OnLButtonUp(nFlags, point);
//}


//void Cexp12View::OnMButtonDown(UINT nFlags, CPoint point)
//{
//	// TODO:  �ڴ������Ϣ�����������/�����Ĭ��ֵ
//	CView::OnMButtonDown(nFlags, point);
//}


void Cexp12View::OnRButtonDown(UINT nFlags, CPoint point)
{
	// TODO:  �ڴ������Ϣ�����������/�����Ĭ��ֵ
	Cexp12Doc* pDoc = GetDocument();
	CString s;
	CClientDC dc(this);
	if (point.x <= pDoc->cr[3].right&&point.x >= pDoc->cr[3].left&&point.y <= pDoc->cr[3].bottom&&point.y >= pDoc->cr[3].top)
	{
			if (pDoc->command[log] == '+')
			{
				pDoc->xc.Add(pDoc->xa[log] + pDoc->xb[log]);
				s.Format(_T("%d"), pDoc->xa[log] + pDoc->xb[log]);
				dc.TextOutW(point.x, point.y, s);
			}
			if (pDoc->command[log] == '-')
			{
				pDoc->xc.Add(pDoc->xa[log] - pDoc->xb[log]);
				s.Format(_T("%d"), pDoc->xa[log] - pDoc->xb[log]);
				dc.TextOutW(point.x, point.y, s);
			}
			if (pDoc->command[log] == '*')
			{
				pDoc->xc.Add(pDoc->xa[log] * pDoc->xb[log]);
				s.Format(_T("%d"), pDoc->xa[log] * pDoc->xb[log]);
				dc.TextOutW(point.x, point.y, s);
			}
			if (pDoc->command[log] == '/')
			{
				pDoc->xc.Add(pDoc->xa[log] / pDoc->xb[log]);
				s.Format(_T("%d"), pDoc->xa[log] / pDoc->xb[log]);
				dc.TextOutW(point.x, point.y, s);
			}
			log++;
	}
	else
	{
		s.Format(_T("��Ч"));
		dc.TextOutW(point.x, point.y, s);
	}
	CView::OnRButtonDown(nFlags, point);
}
