
// exp37View.h : Cexp37View ��Ľӿ�
//

#pragma once


class Cexp37View : public CView
{
protected: // �������л�����
	Cexp37View();
	DECLARE_DYNCREATE(Cexp37View)

// ����
public:
	Cexp37Doc* GetDocument() const;

// ����
public:
	bool sel = 0;
	int log = 0;
	CPoint start;
// ��д
public:
	virtual void OnDraw(CDC* pDC);  // ��д�Ի��Ƹ���ͼ
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// ʵ��
public:
	virtual ~Cexp37View();
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
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
};

#ifndef _DEBUG  // exp37View.cpp �еĵ��԰汾
inline Cexp37Doc* Cexp37View::GetDocument() const
   { return reinterpret_cast<Cexp37Doc*>(m_pDocument); }
#endif

