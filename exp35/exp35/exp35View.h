
// exp35View.h : Cexp35View ��Ľӿ�
//

#pragma once


class Cexp35View : public CView
{
protected: // �������л�����
	Cexp35View();
	DECLARE_DYNCREATE(Cexp35View)

// ����
public:
	Cexp35Doc* GetDocument() const;

// ����
public:

// ��д
public:
	virtual void OnDraw(CDC* pDC);  // ��д�Ի��Ƹ���ͼ
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// ʵ��
public:
	virtual ~Cexp35View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnChoose();
	afx_msg void OnPlay();
};

#ifndef _DEBUG  // exp35View.cpp �еĵ��԰汾
inline Cexp35Doc* Cexp35View::GetDocument() const
   { return reinterpret_cast<Cexp35Doc*>(m_pDocument); }
#endif
