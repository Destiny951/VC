
// exp29View.h : Cexp29View ��Ľӿ�
//

#pragma once


class Cexp29View : public CView
{
protected: // �������л�����
	Cexp29View();
	DECLARE_DYNCREATE(Cexp29View)

// ����
public:
	Cexp29Doc* GetDocument() const;

// ����
public:

// ��д
public:
	virtual void OnDraw(CDC* pDC);  // ��д�Ի��Ƹ���ͼ
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// ʵ��
public:
	virtual ~Cexp29View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnShow();
};

#ifndef _DEBUG  // exp29View.cpp �еĵ��԰汾
inline Cexp29Doc* Cexp29View::GetDocument() const
   { return reinterpret_cast<Cexp29Doc*>(m_pDocument); }
#endif

