
// exp39View.h : Cexp39View ��Ľӿ�
//

#pragma once

class Cexp39Set;

class Cexp39View : public CRecordView
{
protected: // �������л�����
	Cexp39View();
	DECLARE_DYNCREATE(Cexp39View)

public:
	enum{ IDD = IDD_EXP39_FORM };
	Cexp39Set* m_pSet;

// ����
public:
	Cexp39Doc* GetDocument() const;

// ����
public:

// ��д
public:
	virtual CRecordset* OnGetRecordset();
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��
	virtual void OnInitialUpdate(); // ������һ�ε���
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// ʵ��
public:
	virtual ~Cexp39View();
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
	CString name;
	double number;
	long age;
	long phont;
	afx_msg void OnBnClickedButton1();
};

#ifndef _DEBUG  // exp39View.cpp �еĵ��԰汾
inline Cexp39Doc* Cexp39View::GetDocument() const
   { return reinterpret_cast<Cexp39Doc*>(m_pDocument); }
#endif

