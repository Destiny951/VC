
// exp24View.cpp : Cexp24View ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "exp24.h"
#endif

#include "exp24Doc.h"
#include "exp24View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// Cexp24View

IMPLEMENT_DYNCREATE(Cexp24View, CView)

BEGIN_MESSAGE_MAP(Cexp24View, CView)
	// ��׼��ӡ����
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_CHAR()
	ON_WM_LBUTTONDOWN()
	ON_WM_SETFOCUS()
END_MESSAGE_MAP()

// Cexp24View ����/����

Cexp24View::Cexp24View()
{
	// TODO:  �ڴ˴���ӹ������
	mes.left = 300;
	mes.right = 1000;
	mes.top = 100;
	mes.bottom = 140;

	pt.x = mes.left + 2;
	pt.y = mes.top + 10;
}

Cexp24View::~Cexp24View()
{
}

BOOL Cexp24View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO:  �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// Cexp24View ����

void Cexp24View::OnDraw(CDC* pDC)
{
	Cexp24Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	pDC->Rectangle(mes);     //����������

	CString str ;            //str��������
	for (int i = 0; i < ch.GetSize(); i++)
	{
		str += ch[i];
	}

	pDC->TextOutW(mes.left + 2, pt.y, str);

	// TODO:  �ڴ˴�Ϊ����������ӻ��ƴ���
}


// Cexp24View ��ӡ

BOOL Cexp24View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// Ĭ��׼��
	return DoPreparePrinting(pInfo);
}

void Cexp24View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO:  ��Ӷ���Ĵ�ӡǰ���еĳ�ʼ������
}

void Cexp24View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO:  ��Ӵ�ӡ����е��������
}


// Cexp24View ���

#ifdef _DEBUG
void Cexp24View::AssertValid() const
{
	CView::AssertValid();
}

void Cexp24View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

Cexp24Doc* Cexp24View::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(Cexp24Doc)));
	return (Cexp24Doc*)m_pDocument;
}
#endif //_DEBUG


// Cexp24View ��Ϣ�������


void Cexp24View::OnChar(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	// TODO:  �ڴ������Ϣ�����������/�����Ĭ��ֵ
	if (pt.x < mes.right - 10)
	{
		TCHAR c = nChar;
		CClientDC dc(this);
		textsize = dc.GetTextExtent((LPCTSTR)&nChar);
		if ((pt.x - mes.left + 2) / textsize.cx < ch.GetSize())
		{
			int i = (pt.x - mes.left + 2) / textsize.cx - 1;
			for (int j = ch.GetSize()-1; j < i; j--)
			{
				ch[j + 1] = ch[j];
			}
			ch[i] = c;
		}
		else
		{
			ch.Add(c);
			pt.x += textsize.cx;
		}
		SetCaretPos(pt);
		ShowCaret();
		Invalidate();
		CView::OnChar(nChar, nRepCnt, nFlags);
	}
}


void Cexp24View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO:  �ڴ������Ϣ�����������/�����Ĭ��ֵ
	if (point.x >= mes.left&&point.x <= mes.right)
	{
		if (point.y <= mes.bottom&&point.y >= mes.top)
		{
			for (int i = 0; i < (mes.right - 10 - (mes.left+2) / textsize.cx); i++)
			{
				if (point.x >= mes.left + 2 + (i-1)*textsize.cx&&point.x <= mes.left + 2 + i*textsize.cx)
				{
					if (point.x < (mes.left + 2 + i*textsize.cx - (mes.left + 2 + (i-1)*textsize.cx)) / 2)
					{
						pt.x = mes.left + 2 + (i-1)*textsize.cx;
					}
					else
					{
						pt.x = mes.left + 2 + i*textsize.cx;
					}
				}
			}
			SetCaretPos(pt);
			ShowCaret();
		}
	}
	CView::OnLButtonDown(nFlags, point);
}


void Cexp24View::OnSetFocus(CWnd* pOldWnd)
{
	CView::OnSetFocus(pOldWnd);
	CreateSolidCaret(3, 18);
	SetCaretPos(pt);
	ShowCaret();
	// TODO:  �ڴ˴������Ϣ����������
}
