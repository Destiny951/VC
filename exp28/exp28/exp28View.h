
// exp28View.h : Cexp28View ��Ľӿ�
//

#pragma once


class Cexp28View : public CView
{
protected: // �������л�����
	Cexp28View();
	DECLARE_DYNCREATE(Cexp28View)

// ����
public:
	Cexp28Doc* GetDocument() const;

// ����
public:
	bool select;
	CRect ce;
	CPoint start;
// ��д
public:
	virtual void OnDraw(CDC* pDC);  // ��д�Ի��Ƹ���ͼ
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// ʵ��
public:
	virtual ~Cexp28View();
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

#ifndef _DEBUG  // exp28View.cpp �еĵ��԰汾
inline Cexp28Doc* Cexp28View::GetDocument() const
   { return reinterpret_cast<Cexp28Doc*>(m_pDocument); }
#endif

