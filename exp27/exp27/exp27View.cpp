
// exp27View.cpp : Cexp27View ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "exp27.h"
#endif

#include "exp27Doc.h"
#include "exp27View.h"
#include "MyDialog.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// Cexp27View

IMPLEMENT_DYNCREATE(Cexp27View, CView)

BEGIN_MESSAGE_MAP(Cexp27View, CView)
	ON_BN_CLICKED(IDC_BUTTON1, &Cexp27View::OnBnClickedButton1)
	ON_COMMAND(ID_EDIT, &Cexp27View::OnEdit)
END_MESSAGE_MAP()

// Cexp27View ����/����

Cexp27View::Cexp27View()
{
	// TODO:  �ڴ˴���ӹ������

}

Cexp27View::~Cexp27View()
{
}

BOOL Cexp27View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO:  �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// Cexp27View ����

void Cexp27View::OnDraw(CDC* /*pDC*/)
{
	Cexp27Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO:  �ڴ˴�Ϊ����������ӻ��ƴ���
}


// Cexp27View ���

#ifdef _DEBUG
void Cexp27View::AssertValid() const
{
	CView::AssertValid();
}

void Cexp27View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

Cexp27Doc* Cexp27View::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(Cexp27Doc)));
	return (Cexp27Doc*)m_pDocument;
}
#endif //_DEBUG


// Cexp27View ��Ϣ�������


void Cexp27View::OnBnClickedButton1()
{

	// TODO:  �ڴ���ӿؼ�֪ͨ����������
}


void Cexp27View::OnEdit()
{
	MyDialog dlg;
	int t = dlg.DoModal();
	// TODO:  �ڴ���������������
}
