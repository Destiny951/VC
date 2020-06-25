
// exp22View.cpp : Cexp22View ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "exp22.h"
#endif

#include "exp22Doc.h"
#include "exp22View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// Cexp22View

IMPLEMENT_DYNCREATE(Cexp22View, CView)

BEGIN_MESSAGE_MAP(Cexp22View, CView)
	ON_COMMAND(ID_FILE_OPEN, &Cexp22View::OnFileOpen)
END_MESSAGE_MAP()

// Cexp22View ����/����

Cexp22View::Cexp22View()
{
	// TODO:  �ڴ˴���ӹ������

}

Cexp22View::~Cexp22View()
{
}

BOOL Cexp22View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO:  �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// Cexp22View ����

void Cexp22View::OnDraw(CDC* pDC)
{
	Cexp22Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO:  �ڴ˴�Ϊ����������ӻ��ƴ���
	int w, h, sx, sy;
	if (log == 1)
	{
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
		image.Draw(pDC->m_hDC, sx, sy, w, h);
	}
}


// Cexp22View ���

#ifdef _DEBUG
void Cexp22View::AssertValid() const
{
	CView::AssertValid();
}

void Cexp22View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

Cexp22Doc* Cexp22View::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(Cexp22Doc)));
	return (Cexp22Doc*)m_pDocument;
}
#endif //_DEBUG


// Cexp22View ��Ϣ�������


void Cexp22View::OnFileOpen()
{
	// TODO:  �ڴ���������������
	CFileDialog cfd(true);
	int r = cfd.DoModal();
	if (r == IDOK)
	{
		filename = cfd.GetPathName();
		log = 1;
	}
	else log = 0;
	Invalidate();
}
