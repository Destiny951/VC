
// exp27View.h : Cexp27View ��Ľӿ�
//

#pragma once


class Cexp27View : public CView
{
protected: // �������л�����
	Cexp27View();
	DECLARE_DYNCREATE(Cexp27View)

// ����
public:
	Cexp27Doc* GetDocument() const;

// ����
public:

// ��д
public:
	virtual void OnDraw(CDC* pDC);  // ��д�Ի��Ƹ���ͼ
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// ʵ��
public:
	virtual ~Cexp27View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButton1();
	afx_msg void OnEdit();
};

#ifndef _DEBUG  // exp27View.cpp �еĵ��԰汾
inline Cexp27Doc* Cexp27View::GetDocument() const
   { return reinterpret_cast<Cexp27Doc*>(m_pDocument); }
#endif

