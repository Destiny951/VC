
// exp16View.h : Cexp16View ��Ľӿ�
//

#pragma once


class Cexp16View : public CView
{
protected: // �������л�����
	Cexp16View();
	DECLARE_DYNCREATE(Cexp16View)

// ����
public:
	Cexp16Doc* GetDocument() const;

// ����
public:

// ��д
public:
	virtual void OnDraw(CDC* pDC);  // ��д�Ի��Ƹ���ͼ
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// ʵ��
public:
	virtual ~Cexp16View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnTimer(UINT_PTR nIDEvent);
};

#ifndef _DEBUG  // exp16View.cpp �еĵ��԰汾
inline Cexp16Doc* Cexp16View::GetDocument() const
   { return reinterpret_cast<Cexp16Doc*>(m_pDocument); }
#endif

