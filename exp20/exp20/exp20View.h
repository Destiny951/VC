
// exp20View.h : Cexp20View ��Ľӿ�
//

#pragma once


class Cexp20View : public CView
{
protected: // �������л�����
	Cexp20View();
	DECLARE_DYNCREATE(Cexp20View)

// ����
public:
	Cexp20Doc* GetDocument() const;

// ����
public:
	int i;
	int x1, y1, x2, y2;
// ��д
public:
	virtual void OnDraw(CDC* pDC);  // ��д�Ի��Ƹ���ͼ
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// ʵ��
public:
	virtual ~Cexp20View();
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
	afx_msg void OnLine();
	afx_msg void OnSquire();
	afx_msg void OnCircle();
};

#ifndef _DEBUG  // exp20View.cpp �еĵ��԰汾
inline Cexp20Doc* Cexp20View::GetDocument() const
   { return reinterpret_cast<Cexp20Doc*>(m_pDocument); }
#endif

