
// exp38View.h : Cexp38View ��Ľӿ�
//

#pragma once

class Cexp38Set;

class Cexp38View : public CRecordView
{
protected: // �������л�����
	Cexp38View();
	DECLARE_DYNCREATE(Cexp38View)

public:
	enum{ IDD = IDD_EXP38_FORM };
	Cexp38Set* m_pSet;

// ����
public:
	Cexp38Doc* GetDocument() const;

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
	virtual ~Cexp38View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	DECLARE_MESSAGE_MAP()
public:
	long ID;
	afx_msg void OnEnChangeEdit2();
	CString name;
	double number;
	long age;
	long phone;
};

#ifndef _DEBUG  // exp38View.cpp �еĵ��԰汾
inline Cexp38Doc* Cexp38View::GetDocument() const
   { return reinterpret_cast<Cexp38Doc*>(m_pDocument); }
#endif

