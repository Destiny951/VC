
// exp5View.h : Cexp5View ��Ľӿ�
//

#pragma once


class Cexp5View : public CView
{
protected: // �������л�����
	Cexp5View();
	DECLARE_DYNCREATE(Cexp5View)

// ����
public:
	Cexp5Doc* GetDocument() const;

// ����
public:

// ��д
public:
	virtual void OnDraw(CDC* pDC);  // ��д�Ի��Ƹ���ͼ
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// ʵ��
public:
	virtual ~Cexp5View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // exp5View.cpp �еĵ��԰汾
inline Cexp5Doc* Cexp5View::GetDocument() const
   { return reinterpret_cast<Cexp5Doc*>(m_pDocument); }
#endif
