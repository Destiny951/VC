
// expAllView.cpp : CexpAllView ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "expAll.h"
#endif

#include "expAllSet.h"
#include "expAllDoc.h"
#include "expAllView.h"
#include "MyDialog.h"
#include "ADD.h"
#include "Edit.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CexpAllView

IMPLEMENT_DYNCREATE(CexpAllView, CRecordView)

BEGIN_MESSAGE_MAP(CexpAllView, CRecordView)
	ON_EN_CHANGE(IDC_EDIT6, &CexpAllView::OnEnChangeEdit6)
	ON_WM_PAINT()
	ON_COMMAND(ID_RECORD_FIRST, &CexpAllView::OnRecordFirst)
	ON_COMMAND(ID_RECORD_PREV, &CexpAllView::OnRecordPrev)
	ON_COMMAND(ID_RECORD_NEXT, &CexpAllView::OnRecordNext)
	ON_COMMAND(ID_RECORD_LAST, &CexpAllView::OnRecordLast)
	ON_BN_CLICKED(IDC_BUTTON1, &CexpAllView::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &CexpAllView::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON3, &CexpAllView::OnBnClickedButton3)
	ON_BN_CLICKED(IDC_BUTTON4, &CexpAllView::OnBnClickedButton4)
END_MESSAGE_MAP()

// CexpAllView ����/����

CexpAllView::CexpAllView()
	: CRecordView(CexpAllView::IDD)
	, ID(0)
	, name(_T(""))
	, number(_T(""))
	, sex(_T(""))
	, birth(_T(""))
	, phone(_T(""))
	, address(_T(""))
	, picture(_T(""))
{
	m_pSet = NULL;
	// TODO:  �ڴ˴���ӹ������
	s = _T("C:\\Users\\dagro\\Pictures\\������������\\");
}

CexpAllView::~CexpAllView()
{
}

void CexpAllView::DoDataExchange(CDataExchange* pDX)
{
	CRecordView::DoDataExchange(pDX);
	// �����ڴ˴����� DDX_Field* �����Խ��ؼ������ӡ������ݿ��ֶΣ�����
	// DDX_FieldText(pDX, IDC_MYEDITBOX, m_pSet->m_szColumn1, m_pSet);
	// DDX_FieldCheck(pDX, IDC_MYCHECKBOX, m_pSet->m_bColumn2, m_pSet);
	// �й���ϸ��Ϣ������� MSDN �� ODBC ʾ��
	DDX_Text(pDX, IDC_EDIT8, m_pSet->m_ID);
	DDX_Text(pDX, IDC_EDIT14, m_pSet->m_1);
	DDX_Text(pDX, IDC_EDIT9, m_pSet->m_2);
	DDX_Text(pDX, IDC_EDIT6, m_pSet->m_3);
	DDX_Text(pDX, IDC_EDIT11, m_pSet->m_4);
	DDX_Text(pDX, IDC_EDIT7, m_pSet->m_5);
	DDX_Text(pDX, IDC_EDIT12, m_pSet->m_6);
	DDX_Text(pDX, IDC_EDIT10, m_pSet->m_7);
	DDX_Text(pDX, IDC_EDIT13, m_pSet->m_8);
	Invalidate();
}

BOOL CexpAllView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO:  �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CRecordView::PreCreateWindow(cs);
}

void CexpAllView::OnInitialUpdate()
{
	m_pSet = &GetDocument()->m_expAllSet;
	CRecordView::OnInitialUpdate();

}


// CexpAllView ���

#ifdef _DEBUG
void CexpAllView::AssertValid() const
{
	CRecordView::AssertValid();
}

void CexpAllView::Dump(CDumpContext& dc) const
{
	CRecordView::Dump(dc);
}

CexpAllDoc* CexpAllView::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CexpAllDoc)));
	return (CexpAllDoc*)m_pDocument;
}
#endif //_DEBUG


// CexpAllView ���ݿ�֧��
CRecordset* CexpAllView::OnGetRecordset()
{
	return m_pSet;
}



// CexpAllView ��Ϣ�������


void CexpAllView::OnEnChangeEdit6()
{
	// TODO:  ����ÿؼ��� RICHEDIT �ؼ���������
	// ���ʹ�֪ͨ��������д CRecordView::OnInitDialog()
	// ���������� CRichEditCtrl().SetEventMask()��
	// ͬʱ�� ENM_CHANGE ��־�������㵽�����С�

	// TODO:  �ڴ���ӿؼ�֪ͨ����������
}


void CexpAllView::OnPaint()
{
	CPaintDC dc(this); // device context for painting
	// TODO:  �ڴ˴������Ϣ����������
	// ��Ϊ��ͼ��Ϣ���� CRecordView::OnPaint()
	GetDlgItemText(IDC_EDIT13, path);
	path = s + path;
	draw_pic(path);
}


void CexpAllView::draw_pic(CString s)
{
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
	ReleaseDC(pDC);
}

void CexpAllView::OnRecordFirst()
{
	m_pSet->MoveFirst();
	UpdateData(false);
	// TODO:  �ڴ���������������
}


void CexpAllView::OnRecordPrev()
{

	// TODO:  �ڴ���������������
	m_pSet->MovePrev();
	if (m_pSet->IsBOF())
	{
		m_pSet->MoveFirst();
	}
	UpdateData(false);
}


void CexpAllView::OnRecordNext()
{
	m_pSet->MoveNext();
	if (m_pSet->IsEOF())
	{
		m_pSet->MoveLast();
	}
	UpdateData(false);
	// TODO:  �ڴ���������������
}


void CexpAllView::OnRecordLast()
{
	// TODO:  �ڴ���������������
	m_pSet->MoveLast();
	UpdateData(false);
}


void CexpAllView::OnBnClickedButton1()                  //�Ŵ���ʾ
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	MyDialog dlg;
	dlg.pathname = path;
	dlg.DoModal();
	
	
}


void CexpAllView::OnBnClickedButton2()             //ɾ����ť
{
	m_pSet->Delete();
	m_pSet->MovePrev();
	if (m_pSet->IsBOF())
	{
		m_pSet->MoveFirst();
	}
	UpdateData(false);
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
}


void CexpAllView::OnBnClickedButton3()         //���Ӱ�ť
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	ADD add;
	int r = add.DoModal();
	if (r == IDOK)
	{
		CString nname = add.name;
		CString nnumber = add.number;
		CString mmajor = add.major;
		CString ssex = add.sex;
		CString bbirth = add.birth;
		CString pphone = add.phone;
		CString aaddress = add.address;
		CString ppicture = add.picture;

		m_pSet->AddNew();
		m_pSet->m_1 = nname;
		m_pSet->m_2 = nnumber;
		m_pSet->m_3 = mmajor;
		m_pSet->m_4 = ssex;
		m_pSet->m_5 = bbirth;
		m_pSet->m_6 = pphone;
		m_pSet->m_7 = aaddress;
		m_pSet->m_8 = ppicture;
		m_pSet->Update();

		UpdateData(false);
	}
}


void CexpAllView::OnBnClickedButton4()           //����
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	Edit edit;

	edit.name = m_pSet->m_1;
	edit.number = m_pSet->m_2;
	edit.major = m_pSet->m_3;
	edit.sex = m_pSet->m_4;
	edit.birth = m_pSet->m_5;
	edit.phone = m_pSet->m_6;
	edit.address = m_pSet->m_7;
	edit.picture = m_pSet->m_8;

	int r = edit.DoModal();
	if (r == IDOK)
	{

		CString nname = edit.name;
		CString nnumber = edit.number;
		CString mmajor = edit.major;
		CString ssex = edit.sex;
		CString bbirth = edit.birth;
		CString pphone = edit.phone;
		CString aaddress = edit.address;
		CString ppicture = edit.picture;

		m_pSet->Edit();
		m_pSet->m_1 = nname;
		m_pSet->m_2 = nnumber;
		m_pSet->m_3 = mmajor;
		m_pSet->m_4 = ssex;
		m_pSet->m_5 = bbirth;
		m_pSet->m_6 = pphone;
		m_pSet->m_7 = aaddress;
		m_pSet->m_8 = ppicture;
		m_pSet->Update();

		UpdateData(false);
	}
}
