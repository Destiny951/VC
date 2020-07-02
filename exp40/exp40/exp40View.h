
// exp40View.h : Cexp40View 类的接口
//

#pragma once

class Cexp40Set;

class Cexp40View : public CRecordView
{
protected: // 仅从序列化创建
	Cexp40View();
	DECLARE_DYNCREATE(Cexp40View)

public:
	enum{ IDD = IDD_EXP40_FORM };
	Cexp40Set* m_pSet;

// 特性
public:
	Cexp40Doc* GetDocument() const;

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
	virtual ~Cexp40View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
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

#ifndef _DEBUG  // exp40View.cpp 中的调试版本
inline Cexp40Doc* Cexp40View::GetDocument() const
   { return reinterpret_cast<Cexp40Doc*>(m_pDocument); }
#endif

