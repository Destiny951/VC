
// exp35View.cpp : Cexp35View ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "exp35.h"
#endif

#include "exp35Doc.h"
#include "exp35View.h"
#include "MyDialog.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// Cexp35View

IMPLEMENT_DYNCREATE(Cexp35View, CView)

BEGIN_MESSAGE_MAP(Cexp35View, CView)
	ON_COMMAND(ID_Choose, &Cexp35View::OnChoose)
	ON_COMMAND(ID_Play, &Cexp35View::OnPlay)
END_MESSAGE_MAP()

// Cexp35View ����/����

Cexp35View::Cexp35View()
{
	// TODO:  �ڴ˴���ӹ������

}

Cexp35View::~Cexp35View()
{
}

BOOL Cexp35View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO:  �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// Cexp35View ����

void Cexp35View::OnDraw(CDC* pDC)
{
	Cexp35Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	CString s = _T("�ȴ�ѡ��ͼƬ�ٵ�������Ա����ı��ļ���ͬ���ȵ�����ٵ����ʾͼƬ������ʾ");
	pDC->TextOutW(200,300,s);
	// TODO:  �ڴ˴�Ϊ����������ӻ��ƴ���
}


// Cexp35View ���

#ifdef _DEBUG
void Cexp35View::AssertValid() const
{
	CView::AssertValid();
}

void Cexp35View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

Cexp35Doc* Cexp35View::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(Cexp35Doc)));
	return (Cexp35Doc*)m_pDocument;
}
#endif //_DEBUG


// Cexp35View ��Ϣ�������


void Cexp35View::OnChoose()
{
	Cexp35Doc* pDoc = GetDocument();
	CFileDialog cfd(true);
	cfd.DoModal();
	pDoc->filename = cfd.GetPathName();
	// TODO:  �ڴ���������������
}


void Cexp35View::OnPlay()
{
	Cexp35Doc* pDoc = GetDocument();
	CString s = pDoc->filename;
	MyDialog dlg;
	dlg.filename = s;
	dlg.DoModal();
	// TODO:  �ڴ���������������
}
