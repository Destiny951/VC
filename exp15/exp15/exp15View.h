
// exp15View.h : Cexp15View ��Ľӿ�
//

#pragma once


class Cexp15View : public CView
{
protected: // �������л�����
	Cexp15View();
	DECLARE_DYNCREATE(Cexp15View)

// ����
public:
	Cexp15Doc* GetDocument() const;

// ����
public:
	CRect m;
	CRect model;
// ��д
public:
	virtual void OnDraw(CDC* pDC);  // ��д�Ի��Ƹ���ͼ
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// ʵ��
public:
	virtual ~Cexp15View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags);
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
};

#ifndef _DEBUG  // exp15View.cpp �еĵ��԰汾
inline Cexp15Doc* Cexp15View::GetDocument() const
   { return reinterpret_cast<Cexp15Doc*>(m_pDocument); }
#endif

