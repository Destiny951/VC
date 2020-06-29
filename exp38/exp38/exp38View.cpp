
// exp38View.cpp : Cexp38View ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "exp38.h"
#endif

#include "exp38Set.h"
#include "exp38Doc.h"
#include "exp38View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// Cexp38View

IMPLEMENT_DYNCREATE(Cexp38View, CRecordView)

BEGIN_MESSAGE_MAP(Cexp38View, CRecordView)
	ON_EN_CHANGE(IDC_EDIT2, &Cexp38View::OnEnChangeEdit2)
END_MESSAGE_MAP()

// Cexp38View ����/����

Cexp38View::Cexp38View()
	: CRecordView(Cexp38View::IDD)
	, ID(0)
	, name(_T(""))
	, number(0)
	, age(0)
	, phone(0)
{
	m_pSet = NULL;
	// TODO:  �ڴ˴���ӹ������

}

Cexp38View::~Cexp38View()
{
}

void Cexp38View::DoDataExchange(CDataExchange* pDX)
{
	CRecordView::DoDataExchange(pDX);
	// �����ڴ˴����� DDX_Field* �����Խ��ؼ������ӡ������ݿ��ֶΣ�����
	// DDX_FieldText(pDX, IDC_MYEDITBOX, m_pSet->m_szColumn1, m_pSet);
	// DDX_FieldCheck(pDX, IDC_MYCHECKBOX, m_pSet->m_bColumn2, m_pSet);
	// �й���ϸ��Ϣ������� MSDN �� ODBC ʾ��
	DDX_Text(pDX, IDC_EDIT1, m_pSet->m_ID);
	DDX_Text(pDX, IDC_EDIT2, m_pSet->m_1);
	DDX_Text(pDX, IDC_EDIT5, m_pSet->m_2);
	DDX_Text(pDX, IDC_EDIT3, m_pSet->m_3);
	DDX_Text(pDX, IDC_EDIT4, m_pSet->m_4);
}

BOOL Cexp38View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO:  �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CRecordView::PreCreateWindow(cs);
}

void Cexp38View::OnInitialUpdate()
{
	m_pSet = &GetDocument()->m_exp38Set;
	CRecordView::OnInitialUpdate();

}


// Cexp38View ���

#ifdef _DEBUG
void Cexp38View::AssertValid() const
{
	CRecordView::AssertValid();
}

void Cexp38View::Dump(CDumpContext& dc) const
{
	CRecordView::Dump(dc);
}

Cexp38Doc* Cexp38View::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(Cexp38Doc)));
	return (Cexp38Doc*)m_pDocument;
}
#endif //_DEBUG


// Cexp38View ���ݿ�֧��
CRecordset* Cexp38View::OnGetRecordset()
{
	return m_pSet;
}



// Cexp38View ��Ϣ�������


void Cexp38View::OnEnChangeEdit2()
{
	// TODO:  ����ÿؼ��� RICHEDIT �ؼ���������
	// ���ʹ�֪ͨ��������д CRecordView::OnInitDialog()
	// ���������� CRichEditCtrl().SetEventMask()��
	// ͬʱ�� ENM_CHANGE ��־�������㵽�����С�

	// TODO:  �ڴ���ӿؼ�֪ͨ����������
}
