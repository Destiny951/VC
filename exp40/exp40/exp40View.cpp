
// exp40View.cpp : Cexp40View ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "exp40.h"
#endif

#include "exp40Set.h"
#include "exp40Doc.h"
#include "exp40View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// Cexp40View

IMPLEMENT_DYNCREATE(Cexp40View, CRecordView)

BEGIN_MESSAGE_MAP(Cexp40View, CRecordView)
	ON_EN_CHANGE(IDC_EDIT1, &Cexp40View::OnEnChangeEdit1)
	ON_WM_PAINT()
END_MESSAGE_MAP()

// Cexp40View ����/����

Cexp40View::Cexp40View()
	: CRecordView(Cexp40View::IDD)
	, ID(0)
	, name(_T(""))
	, number(0)
	, age(0)
	, phone(0)
{
	m_pSet = NULL;
	// TODO:  �ڴ˴���ӹ������

}

Cexp40View::~Cexp40View()
{
}

void Cexp40View::DoDataExchange(CDataExchange* pDX)
{
	CRecordView::DoDataExchange(pDX);
	// �����ڴ˴����� DDX_Field* �����Խ��ؼ������ӡ������ݿ��ֶΣ�����
	// DDX_FieldText(pDX, IDC_MYEDITBOX, m_pSet->m_szColumn1, m_pSet);
	// DDX_FieldCheck(pDX, IDC_MYCHECKBOX, m_pSet->m_bColumn2, m_pSet);
	// �й���ϸ��Ϣ������� MSDN �� ODBC ʾ��
	DDX_Text(pDX, IDC_EDIT1, m_pSet->m_ID);
	DDX_Text(pDX, IDC_EDIT2, m_pSet->m_1);
	DDX_Text(pDX, IDC_EDIT4, m_pSet->m_2);
	DDX_Text(pDX, IDC_EDIT3, m_pSet->m_3);
	DDX_Text(pDX, IDC_EDIT5, m_pSet->m_4);
	Invalidate();
}

BOOL Cexp40View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO:  �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CRecordView::PreCreateWindow(cs);
}

void Cexp40View::OnInitialUpdate()
{
	m_pSet = &GetDocument()->m_exp40Set;
	CRecordView::OnInitialUpdate();

}


// Cexp40View ���

#ifdef _DEBUG
void Cexp40View::AssertValid() const
{
	CRecordView::AssertValid();
}

void Cexp40View::Dump(CDumpContext& dc) const
{
	CRecordView::Dump(dc);
}

Cexp40Doc* Cexp40View::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(Cexp40Doc)));
	return (Cexp40Doc*)m_pDocument;
}
#endif //_DEBUG


// Cexp40View ���ݿ�֧��
CRecordset* Cexp40View::OnGetRecordset()
{
	return m_pSet;
}



// Cexp40View ��Ϣ�������


void Cexp40View::OnEnChangeEdit1()
{
	// TODO:  ����ÿؼ��� RICHEDIT �ؼ���������
	// ���ʹ�֪ͨ��������д CRecordView::OnInitDialog()
	// ���������� CRichEditCtrl().SetEventMask()��
	// ͬʱ�� ENM_CHANGE ��־�������㵽�����С�

	// TODO:  �ڴ���ӿؼ�֪ͨ����������
}


void Cexp40View::OnPaint()
{
	CPaintDC dc(this); // device context for painting
	CString s;
	m_pSet->GetFieldValue(short(5), s);
	CImage image;
	image.Load(s);
	int w, h, sx, sy;
	CRect rect;
	GetDlgItem(IDC_STATIC)->GetClientRect(&rect);
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
	CDC *pDC = GetDlgItem(IDC_STATIC)->GetDC();
	image.Draw(pDC->m_hDC, sx, sy, w, h);
	
	// TODO:  �ڴ˴������Ϣ����������
	// ��Ϊ��ͼ��Ϣ���� CRecordView::OnPaint()
}
