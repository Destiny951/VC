
// exp39View.cpp : Cexp39View ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "exp39.h"
#endif

#include "exp39Set.h"
#include "exp39Doc.h"
#include "exp39View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// Cexp39View

IMPLEMENT_DYNCREATE(Cexp39View, CRecordView)

BEGIN_MESSAGE_MAP(Cexp39View, CRecordView)
	// ��׼��ӡ����
	ON_COMMAND(ID_FILE_PRINT, &CRecordView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CRecordView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CRecordView::OnFilePrintPreview)
	ON_BN_CLICKED(IDC_BUTTON1, &Cexp39View::OnBnClickedButton1)
END_MESSAGE_MAP()

// Cexp39View ����/����

Cexp39View::Cexp39View()
	: CRecordView(Cexp39View::IDD)
	, ID(0)
	, name(_T(""))
	, number(0)
	, age(0)
	, phont(0)
{
	m_pSet = NULL;
	// TODO:  �ڴ˴���ӹ������

}

Cexp39View::~Cexp39View()
{
}

void Cexp39View::DoDataExchange(CDataExchange* pDX)
{
	CRecordView::DoDataExchange(pDX);
	// �����ڴ˴����� DDX_Field* �����Խ��ؼ������ӡ������ݿ��ֶΣ�����
	// DDX_FieldText(pDX, IDC_MYEDITBOX, m_pSet->m_szColumn1, m_pSet);
	// DDX_FieldCheck(pDX, IDC_MYCHECKBOX, m_pSet->m_bColumn2, m_pSet);
	// �й���ϸ��Ϣ������� MSDN �� ODBC ʾ��
	DDX_Text(pDX, IDC_EDIT1, m_pSet->m_ID);
	DDX_Text(pDX, IDC_EDIT2, m_pSet->m_1);
	DDX_Text(pDX, IDC_EDIT6, m_pSet->m_2);
	DDX_Text(pDX, IDC_EDIT3, m_pSet->m_3);
	DDX_Text(pDX, IDC_EDIT4, m_pSet->m_4);
}

BOOL Cexp39View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO:  �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CRecordView::PreCreateWindow(cs);
}

void Cexp39View::OnInitialUpdate()
{
	m_pSet = &GetDocument()->m_exp39Set;
	CRecordView::OnInitialUpdate();

}


// Cexp39View ��ӡ

BOOL Cexp39View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// Ĭ��׼��
	return DoPreparePrinting(pInfo);
}

void Cexp39View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO:  ��Ӷ���Ĵ�ӡǰ���еĳ�ʼ������
}

void Cexp39View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO:  ��Ӵ�ӡ����е��������
}


// Cexp39View ���

#ifdef _DEBUG
void Cexp39View::AssertValid() const
{
	CRecordView::AssertValid();
}

void Cexp39View::Dump(CDumpContext& dc) const
{
	CRecordView::Dump(dc);
}

Cexp39Doc* Cexp39View::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(Cexp39Doc)));
	return (Cexp39Doc*)m_pDocument;
}
#endif //_DEBUG


// Cexp39View ���ݿ�֧��
CRecordset* Cexp39View::OnGetRecordset()
{
	return m_pSet;
}



// Cexp39View ��Ϣ�������


void Cexp39View::OnBnClickedButton1()
{
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
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
}
