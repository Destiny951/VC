
// exp17View.h : Cexp17View ��Ľӿ�
//

#pragma once


class Cexp17View : public CView
{
protected: // �������л�����
	Cexp17View();
	DECLARE_DYNCREATE(Cexp17View)

// ����
public:
	Cexp17Doc* GetDocument() const;

// ����
public:
	int i = 0;
// ��д
public:
	virtual void OnDraw(CDC* pDC);  // ��д�Ի��Ƹ���ͼ
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// ʵ��
public:
	virtual ~Cexp17View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnCircle();
	afx_msg void OnTimer(UINT_PTR nIDEvent);
};

#ifndef _DEBUG  // exp17View.cpp �еĵ��԰汾
inline Cexp17Doc* Cexp17View::GetDocument() const
   { return reinterpret_cast<Cexp17Doc*>(m_pDocument); }
#endif

