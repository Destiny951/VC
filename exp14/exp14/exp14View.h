
// exp14View.h : Cexp14View ��Ľӿ�
//

#pragma once


class Cexp14View : public CView
{
protected: // �������л�����
	Cexp14View();
	DECLARE_DYNCREATE(Cexp14View)

// ����
public:
	Cexp14Doc* GetDocument() const;

// ����
public:
	int sum;
	int totalpixel;
	int avepixel;
	bool down;
// ��д
public:
	virtual void OnDraw(CDC* pDC);  // ��д�Ի��Ƹ���ͼ
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// ʵ��
public:
	virtual ~Cexp14View();
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

#ifndef _DEBUG  // exp14View.cpp �еĵ��԰汾
inline Cexp14Doc* Cexp14View::GetDocument() const
   { return reinterpret_cast<Cexp14Doc*>(m_pDocument); }
#endif

