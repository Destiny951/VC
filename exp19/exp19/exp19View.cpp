
// exp19View.cpp : Cexp19View ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "exp19.h"
#endif

#include "exp19Doc.h"
#include "exp19View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// Cexp19View

IMPLEMENT_DYNCREATE(Cexp19View, CView)

BEGIN_MESSAGE_MAP(Cexp19View, CView)
END_MESSAGE_MAP()

// Cexp19View ����/����

Cexp19View::Cexp19View()
{
	// TODO:  �ڴ˴���ӹ������

}

Cexp19View::~Cexp19View()
{
}

BOOL Cexp19View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO:  �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// Cexp19View ����

void Cexp19View::OnDraw(CDC* pDC)
{
	Cexp19Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	BITMAP BM;
	m_Bitmap.LoadBitmap(IDB_BITMAP1);
	m_Bitmap.GetBitmap(&BM);
	m_nWidth = BM.bmWidth;
	m_nHeight = BM.bmHeight;

	CDC MemDC;
	MemDC.CreateCompatibleDC(NULL);
	MemDC.SelectObject(m_Bitmap);
	pDC->BitBlt(0, 0, m_nWidth, m_nHeight, &MemDC, 0, 0, SRCCOPY);

	// TODO:  �ڴ˴�Ϊ����������ӻ��ƴ���
}


// Cexp19View ���

#ifdef _DEBUG
void Cexp19View::AssertValid() const
{
	CView::AssertValid();
}

void Cexp19View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

Cexp19Doc* Cexp19View::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(Cexp19Doc)));
	return (Cexp19Doc*)m_pDocument;
}
#endif //_DEBUG


// Cexp19View ��Ϣ�������
