
// exp26View.cpp : Cexp26View ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "exp26.h"
#endif

#include "exp26Doc.h"
#include "exp26View.h"
#include "MyDialog.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// Cexp26View

IMPLEMENT_DYNCREATE(Cexp26View, CView)

BEGIN_MESSAGE_MAP(Cexp26View, CView)
	ON_BN_CLICKED(IDOK, &Cexp26View::OnBnClickedOk)
	ON_COMMAND(SHOW, &Cexp26View::OnShow)
END_MESSAGE_MAP()

// Cexp26View ����/����

Cexp26View::Cexp26View()
{
	// TODO:  �ڴ˴���ӹ������

}

Cexp26View::~Cexp26View()
{
}

BOOL Cexp26View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO:  �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// Cexp26View ����

void Cexp26View::OnDraw(CDC* /*pDC*/)
{
	Cexp26Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO:  �ڴ˴�Ϊ����������ӻ��ƴ���
}


// Cexp26View ���

#ifdef _DEBUG
void Cexp26View::AssertValid() const
{
	CView::AssertValid();
}

void Cexp26View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

Cexp26Doc* Cexp26View::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(Cexp26Doc)));
	return (Cexp26Doc*)m_pDocument;
}
#endif //_DEBUG


// Cexp26View ��Ϣ�������


void Cexp26View::OnBnClickedOk()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
}


void Cexp26View::OnShow()
{
	MyDialog dlg;
	int t = dlg.DoModal();
	CString s;
	s.Format(_T("�����˳��Ի���"));
	if (t == IDOK)
	{
		GetDC()->TextOutW(300, 300, s);
	}
	// TODO:  �ڴ���������������
}
