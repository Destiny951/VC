
// exp38View.h : Cexp38View 类的接口
//

#pragma once

class Cexp38Set;

class Cexp38View : public CRecordView
{
protected: // 仅从序列化创建
	Cexp38View();
	DECLARE_DYNCREATE(Cexp38View)

public:
	enum{ IDD = IDD_EXP38_FORM };
	Cexp38Set* m_pSet;

// 特性
public:
	Cexp38Doc* GetDocument() const;

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
	virtual ~Cexp38View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
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

#ifndef _DEBUG  // exp38View.cpp 中的调试版本
inline Cexp38Doc* Cexp38View::GetDocument() const
   { return reinterpret_cast<Cexp38Doc*>(m_pDocument); }
#endif

