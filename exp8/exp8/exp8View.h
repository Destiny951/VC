
// exp8View.h : Cexp8View ��Ľӿ�
//

#pragma once


class Cexp8View : public CView
{
protected: // �������л�����
	Cexp8View();
	DECLARE_DYNCREATE(Cexp8View)

// ����
public:
	Cexp8Doc* GetDocument() const;

// ����
public:
	bool ans;
	CRect circle;
// ��д
public:
	virtual void OnDraw(CDC* pDC);  // ��д�Ի��Ƹ���ͼ
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// ʵ��
public:
	virtual ~Cexp8View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
};

#ifndef _DEBUG  // exp8View.cpp �еĵ��԰汾
inline Cexp8Doc* Cexp8View::GetDocument() const
   { return reinterpret_cast<Cexp8Doc*>(m_pDocument); }
#endif

