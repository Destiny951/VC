
// exp19View.h : Cexp19View ��Ľӿ�
//

#pragma once


class Cexp19View : public CView
{
protected: // �������л�����
	Cexp19View();
	DECLARE_DYNCREATE(Cexp19View)

// ����
public:
	Cexp19Doc* GetDocument() const;

// ����
public:
	CBitmap m_Bitmap;
	int m_nWidth;
	int m_nHeight;
// ��д
public:
	virtual void OnDraw(CDC* pDC);  // ��д�Ի��Ƹ���ͼ
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// ʵ��
public:
	virtual ~Cexp19View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // exp19View.cpp �еĵ��԰汾
inline Cexp19Doc* Cexp19View::GetDocument() const
   { return reinterpret_cast<Cexp19Doc*>(m_pDocument); }
#endif

