
// exp18View.h : Cexp18View ��Ľӿ�
//

#pragma once


class Cexp18View : public CView
{
protected: // �������л�����
	Cexp18View();
	DECLARE_DYNCREATE(Cexp18View)

// ����
public:
	Cexp18Doc* GetDocument() const;

// ����
public:

// ��д
public:
	virtual void OnDraw(CDC* pDC);  // ��д�Ի��Ƹ���ͼ
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// ʵ��
public:
	virtual ~Cexp18View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnName();
};

#ifndef _DEBUG  // exp18View.cpp �еĵ��԰汾
inline Cexp18Doc* Cexp18View::GetDocument() const
   { return reinterpret_cast<Cexp18Doc*>(m_pDocument); }
#endif

