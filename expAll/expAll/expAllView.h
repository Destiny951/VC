
// expAllView.h : CexpAllView 类的接口
//

#pragma once
#include "afxwin.h"

class CexpAllSet;

class CexpAllView : public CRecordView
{
protected: // 仅从序列化创建
	CexpAllView();
	DECLARE_DYNCREATE(CexpAllView)

public:
	enum{ IDD = IDD_EXPALL_FORM };
	CexpAllSet* m_pSet;
	CString path;
	CString s;
// 特性
public:
	CexpAllDoc* GetDocument() const;
	void draw_pic(CString s);
// 操作
public:

// 重写
public:
	virtual CRecordset* OnGetRecordset();
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持
	virtual void OnInitialUpdate(); // 构造后第一次调用

// 实现
public:
	virtual ~CexpAllView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
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

#ifndef _DEBUG  // expAllView.cpp 中的调试版本
inline CexpAllDoc* CexpAllView::GetDocument() const
   { return reinterpret_cast<CexpAllDoc*>(m_pDocument); }
#endif

