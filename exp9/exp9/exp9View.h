
// exp9View.h : Cexp9View ��Ľӿ�
//

#pragma once


class Cexp9View : public CView
{
protected: // �������л�����
	Cexp9View();
	DECLARE_DYNCREATE(Cexp9View)

// ����
public:
	Cexp9Doc* GetDocument() const;

// ����
public:
	int x, y;
// ��д
public:
	virtual void OnDraw(CDC* pDC);  // ��д�Ի��Ƹ���ͼ
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// ʵ��
public:
	virtual ~Cexp9View();
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

#ifndef _DEBUG  // exp9View.cpp �еĵ��԰汾
inline Cexp9Doc* Cexp9View::GetDocument() const
   { return reinterpret_cast<Cexp9Doc*>(m_pDocument); }
#endif

