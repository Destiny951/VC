
// exp40View.h : Cexp40View ��Ľӿ�
//

#pragma once

class Cexp40Set;

class Cexp40View : public CRecordView
{
protected: // �������л�����
	Cexp40View();
	DECLARE_DYNCREATE(Cexp40View)

public:
	enum{ IDD = IDD_EXP40_FORM };
	Cexp40Set* m_pSet;

// ����
public:
	Cexp40Doc* GetDocument() const;

// ����
public:

// ��д
public:
	virtual CRecordset* OnGetRecordset();
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��
	virtual void OnInitialUpdate(); // ������һ�ε���

// ʵ��
public:
	virtual ~Cexp40View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnEnChangeEdit1();
	long ID;
	CString name;
	double number;
	long age;
	long phone;
	afx_msg void OnPaint();
};

#ifndef _DEBUG  // exp40View.cpp �еĵ��԰汾
inline Cexp40Doc* Cexp40View::GetDocument() const
   { return reinterpret_cast<Cexp40Doc*>(m_pDocument); }
#endif

