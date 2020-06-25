
// exp21View.cpp : Cexp21View ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "exp21.h"
#endif

#include "exp21Doc.h"
#include "exp21View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// Cexp21View

IMPLEMENT_DYNCREATE(Cexp21View, CView)

BEGIN_MESSAGE_MAP(Cexp21View, CView)
	ON_COMMAND(ID_FILE_OPEN, &Cexp21View::OnFileOpen)
END_MESSAGE_MAP()

// Cexp21View ����/����

Cexp21View::Cexp21View()
{
	// TODO:  �ڴ˴���ӹ������

}

Cexp21View::~Cexp21View()
{
}

BOOL Cexp21View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO:  �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// Cexp21View ����

void Cexp21View::OnDraw(CDC* /*pDC*/)
{
	Cexp21Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO:  �ڴ˴�Ϊ����������ӻ��ƴ���
}


// Cexp21View ���

#ifdef _DEBUG
void Cexp21View::AssertValid() const
{
	CView::AssertValid();
}

void Cexp21View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

Cexp21Doc* Cexp21View::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(Cexp21Doc)));
	return (Cexp21Doc*)m_pDocument;
}
#endif //_DEBUG


// Cexp21View ��Ϣ�������


void Cexp21View::OnFileOpen()
{
	// TODO:  �ڴ���������������
	CFileDialog cfd(true);
	int r = cfd.DoModal();
	CClientDC dc(this);
	int w, h, sx, sy;
	if (r == IDOK)
	{
		CString filename = cfd.GetPathName();
		CImage image;
		image.Load(filename);

		CRect rect;
		GetClientRect(&rect);
		float rect_radio = 1.0*rect.Width() / rect.Height();
		float image_radio = 1.0*image.GetWidth() / image.GetHeight();
		if (rect_radio > image_radio)
		{
			h = rect.Height();
			w = image_radio*h;
			sx = (rect.Width() - w) / 2;
			sy = 0;
		}
		else
		{
			w = rect.Width();
			h = w / image_radio;
			sx = 0;
			sy = (rect.Height() - h) / 2;
		}
		image.Draw(dc.m_hDC,sx,sy,w,h);
	}
}
