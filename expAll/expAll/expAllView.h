
// expAllView.h : CexpAllView ��Ľӿ�
//

#pragma once
#include "afxwin.h"

class CexpAllSet;

class CexpAllView : public CRecordView
{
protected: // �������л�����
	CexpAllView();
	DECLARE_DYNCREATE(CexpAllView)

public:
	enum{ IDD = IDD_EXPALL_FORM };
	CexpAllSet* m_pSet;
	CString path;
	CString s;
// ����
public:
	CexpAllDoc* GetDocument() const;
	void draw_pic(CString s);
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
	virtual ~CexpAllView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnEnChangeEdit6();
	long ID;
	CString name;
	CString number;
	CString major;
	CString sex;
	CString birth;
	CString phone;
	CString address;
	CString picture;
	afx_msg void OnPaint();
	afx_msg void OnRecordFirst();
	afx_msg void OnRecordPrev();
	afx_msg void OnRecordNext();
	afx_msg void OnRecordLast();
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton2();
	afx_msg void OnBnClickedButton3();
	afx_msg void OnBnClickedButton4();
};

#ifndef _DEBUG  // expAllView.cpp �еĵ��԰汾
inline CexpAllDoc* CexpAllView::GetDocument() const
   { return reinterpret_cast<CexpAllDoc*>(m_pDocument); }
#endif

