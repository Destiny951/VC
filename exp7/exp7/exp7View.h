
// exp7View.h : Cexp7View ��Ľӿ�
//

#pragma once


class Cexp7View : public CView
{
protected: // �������л�����
	Cexp7View();
	DECLARE_DYNCREATE(Cexp7View)

// ����
public:
	Cexp7Doc* GetDocument() const;

// ����
public:
	bool ans;
// ��д
public:
	virtual void OnDraw(CDC* pDC);  // ��д�Ի��Ƹ���ͼ
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// ʵ��
public:
	virtual ~Cexp7View();
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
	afx_msg void OnRButtonDown(UINT nFlags, CPoint point);
};

#ifndef _DEBUG  // exp7View.cpp �еĵ��԰汾
inline Cexp7Doc* Cexp7View::GetDocument() const
   { return reinterpret_cast<Cexp7Doc*>(m_pDocument); }
#endif

